<?php

function pum_expert_mycases_see_proposal($case_id) {
  $page = array();
  civicrm_initialize();

  // Retrieve activities types and custom fields.
  $activityTypeOptionGroupId = civicrm_api3('OptionGroup', 'getvalue', array('name' => 'activity_type', 'return' => 'id'));
  $openCaseActivityType = civicrm_api3('OptionValue', 'getvalue', array('option_group_id' => $activityTypeOptionGroupId, 'name' => 'Open case', 'return' => 'value'));
  $assesmentProjectReqByRepActiivityType = civicrm_api3('OptionValue', 'getvalue', array('option_group_id' => $activityTypeOptionGroupId, 'name' => 'Assessment Project Request by Rep', 'return' => 'value'));
  $caseTypeOptionGroupId = civicrm_api3('OptionGroup', 'getvalue', array('name' => 'case_type', 'return' => 'id'));
  $projectIntakeCaseType = civicrm_api3('OptionValue', 'getvalue', array('option_group_id' => $caseTypeOptionGroupId, 'name' => 'Projectintake', 'return' => 'value'));
  $adviceCaseType = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Advice', 'option_group_id' => $caseTypeOptionGroupId, 'return' => 'value'));
  $seminarCaseType = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Seminar', 'option_group_id' => $caseTypeOptionGroupId, 'return' => 'value'));
  $businessCaseType = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Business', 'option_group_id' => $caseTypeOptionGroupId, 'return' => 'value'));
  $remoteCoachingCaseType = civicrm_api3('OptionValue', 'getvalue', array('name' => 'RemoteCoaching', 'option_group_id' => $caseTypeOptionGroupId, 'return' => 'value'));

  $mainActivityCustomGroup = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'main_activity_info'));
  $expectedResultsCustomField = civicrm_api3('CustomField', 'getsingle', array('name' => 'Expected_results', 'custom_group_id' => $mainActivityCustomGroup['id']));
  $objectiveCustomField = civicrm_api3('CustomField', 'getsingle', array('name' => 'Objective_of_this_Activity', 'custom_group_id' => $mainActivityCustomGroup['id']));

  // Retrieve case data and customer data.
  $case = civicrm_api3('Case', 'getsingle', array('id' => $case_id));
  $customer_id = $case['client_id'];
  $customer = civicrm_api3('Contact', 'getsingle', array('id' => $customer_id));
  $address = $customer['street_address']."\n".$customer['postal_code']." ".$customer['city']."\n".$customer['country'];
  $address = preg_replace('/(\n+)/', '<br>', $address);
  $caseTypeLabel = civicrm_api3('OptionValue', 'getvalue', array('value' => $case['case_type_id'], 'return' => 'label', 'option_group_id' => $caseTypeOptionGroupId));

  $expectedResults = '';
  $objective = '';
  $mainActivityInfo = CRM_Core_DAO::executeQuery("SELECT * FROM `".$mainActivityCustomGroup['table_name']."` WHERE entity_id = %1", array(1=>array($case_id, 'Integer')));
  if ($mainActivityInfo->fetch()) {
    $expectedResultsCustomFieldName = $expectedResultsCustomField['column_name'];
    $objectiveCustomFieldName = $objectiveCustomField['column_name'];
    $expectedResults = $mainActivityInfo->$expectedResultsCustomFieldName;
    $objective = $mainActivityInfo->$objectiveCustomFieldName;
  }

  $authorised_person = false;
  $rep = false;
  $proj_off = false;
  $cc = false;
  $sc = false;
  foreach($case['contacts'] as $role) {
    switch ($role['role']) {
      case 'Representative for':
        $rep = $role;
        break;
      case 'Sector Coordinator':
        $sc = $role;
        break;
      case 'Country Coordinator for':
        $cc = $role;
        break;
      case 'Project Officer':
        $proj_off = $role;
        break;
      case 'Authorised contact for':
        $authorised_person = $role;
        break;
    }
  }

  $expert_relationship_type = civicrm_api3('RelationshipType', 'getvalue', array('return' => 'id', 'name_a_b' => 'Expert'));
  $expert_relationship = civicrm_api3('Relationship', 'getsingle', array('relationship_type_id' => $expert_relationship_type, 'case_id' => $case_id));
  $expert = civicrm_api3('Contact', 'getsingle', array('return' => 'display_name,sort_name,email,phone,birth_date', 'id' => $expert_relationship['contact_id_b']));

  $projectIntake = false;
  $assesmentProjectReqByRep = false;
  $project_id = CRM_Threepeas_BAO_PumCaseProject::getProjectIdWithCaseId($case_id);
  $projectCases = CRM_Threepeas_BAO_PumProject::getCasesByProjectId($project_id);
  foreach($projectCases as $projectCase) {
    if ($projectCase['case_type'] == $projectIntakeCaseType) {
      $caseActivities = civicrm_api3('CaseActivity', 'get', array('case_id' => $projectCase['case_id'], 'sequential' => 1, 'option.limit' => 99999));
      foreach($caseActivities['values'] as $caseActivity) {
        if ($caseActivity['activity_type_id'] == $openCaseActivityType) {
          $projectIntake = $caseActivity['details'];
        } elseif ($caseActivity['activity_type_id'] == $assesmentProjectReqByRepActiivityType) {
          $assesmentProjectReqByRep = $caseActivity['details'];
        }
      }
    }
  }

  $acceptProposalLink = false;
  $rejectProposalLink = false;
  if ($adviceCaseType == $case['case_type_id']) {
    $acceptProposalLink = 'expert/accept-advisory-mission';
    $rejectProposalLink = 'expert/reject-advice-proposal';
  } elseif ($seminarCaseType == $case['case_type_id']) {
    $acceptProposalLink = 'expert/accept-seminar';
    $rejectProposalLink = 'expert/reject-seminar-proposal';
  } elseif ($remoteCoachingCaseType == $case['case_type_id']) {
    $acceptProposalLink = 'expert/accept-remote-coaching';
    $rejectProposalLink = 'expert/reject-remote-coaching-proposal';
  } elseif ($businessCaseType == $case['case_type_id']) {
    $acceptProposalLink = 'expert/accept-business';
    $rejectProposalLink = 'expert/reject-business-proposal';
  }
  if ($acceptProposalLink) {
    $acceptProposalLink = url($acceptProposalLink, array(
      'absolute'=> true,
      'query' => array(
        'cid1' => $customer['id'],
        'cid2' => $expert['contact_id'],
        'caseid' => $case_id,
      ),
    ));
    $buttons['accept']['#markup'] = '<a href="'.$acceptProposalLink.'" class="button accept-main-activity-proposal">'.t("Accept").'</a>';
  }
  if ($rejectProposalLink) {
    $rejectProposalLink = url($rejectProposalLink, array(
      'absolute'=> true,
      'query' => array(
        'cid1' => $customer['id'],
        'cid2' => $expert['contact_id'],
        'caseid' => $case_id,
      ),
    ));
    $buttons['reject']['#markup'] = '<a href="'.$rejectProposalLink.'" class="button reject-main-activity-proposal">'.t("Reject").'</a>';
  }
  $questionLink = 'expert/see-proposal/'.$case_id.'/question';
  $buttons['questions']['#markup'] = '<a href="'.url($questionLink, array('absolute'=>true)).'" class="button question-main-activity-proposal">'.t("Questions?").'</a>';

  // Now we have all the relevant information build the page as a Drupal Render array.
  drupal_add_library('system', 'drupal.collapse');
  drupal_add_css(drupal_get_path('module', 'pum_expert_mycases') . '/style.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_set_title($customer['display_name']);

  $page['buttons_top'] = $buttons;

  $page['explain']['#type'] = 'markup';
  $page['explain']['#markup'] = '<p>If you have any questions that need to be answered before you can accept/reject this proposal, please press \'questions\'. This will send an e-mail to the project officer.</p>';

  $page['customer']['#type'] = 'fieldset';
  $page['customer']['case_type']['#markup'] = '<p><strong>Case type:</strong> '.$caseTypeLabel.'</p>';
  $page['customer']['address']['#markup'] = '<p><strong>Address</strong><br>'.$address.'</p>';

  $websites = civicrm_api3('Website', 'get', array('contact_id' => $customer['id']));
  if (count($websites['values']) > 0) {
    $page['customer']['website']['#markup'] = '<p><strong>Website:</strong> ';
    foreach($websites['values'] as $website) {
      $page['customer']['website']['#markup'] .= '<a href="' . $website['url'] . '">' . $website['url'] . '</a>';
    }
    $page['customer']['website']['#markup'] .= '</p>';
  }

  if ($authorised_person) {
    $page['customer']['authorised']['#markup'] = '<br><strong>Contact person:</strong> '.$authorised_person['display_name'];
    if ($authorised_person['email']) {
      $page['customer']['authorised']['#markup'] .= ' (<a href="mailto:'.$authorised_person['email'].'">'.$authorised_person['email'].'</a>)';
    }
    $page['customer']['authorised']['#markup'] .= '';
  }
  if ($rep) {
    $page['customer']['rep']['#markup'] = '<br><strong>Representative:</strong> '.$rep['display_name'];
    if ($rep['email']) {
      $page['customer']['rep']['#markup'] .= ' (<a href="mailto:'.$rep['email'].'">'.$rep['email'].'</a>)';
    }
    $page['customer']['rep']['#markup'] .= '';
  }
  if ($proj_off) {
    $page['customer']['proj_off']['#markup'] = '<br><strong>Project officer:</strong> '.$proj_off['display_name'];
    if ($rep['email']) {
      $page['customer']['proj_off']['#markup'] .= ' (<a href="mailto:'.$proj_off['email'].'">'.$proj_off['email'].'</a>)';
    }
    $page['customer']['proj_off']['#markup'] .= '';
  }
  if ($cc) {
    $page['customer']['cc']['#markup'] = '<br><strong>Country coordinator:</strong> '.$cc['display_name'];
    if ($rep['email']) {
      $page['customer']['cc']['#markup'] .= ' (<a href="mailto:'.$cc['email'].'">'.$cc['email'].'</a>)';
    }
    $page['customer']['cc']['#markup'] .= '';
  }
  if ($sc) {
    $page['customer']['sc']['#markup'] = '<br><strong>Sector coordinator:</strong> '.$sc['display_name'];
    if ($rep['email']) {
      $page['customer']['sc']['#markup'] .= ' (<a href="mailto:'.$sc['email'].'">'.$sc['email'].'</a>)';
    }
    $page['customer']['sc']['#markup'] .= '';
  }

  $page['intake']['#type'] = 'fieldset';
  $page['intake']['#title'] = t('Original project request');
  $page['intake']['details']['#markup'] = $projectIntake;
  $page['intake']['#attributes'] = array (
    'class' => array(
      'collapsible', 'collapsed'
    )
  );

  $page['assesment_project_req_by_rep']['#type'] = 'fieldset';
  $page['assesment_project_req_by_rep']['#title'] = t('Assesment project request by Representative');
  $page['assesment_project_req_by_rep']['details']['#markup'] = $assesmentProjectReqByRep;
  $page['assesment_project_req_by_rep']['#attributes'] = array (
    'class' => array(
      'collapsible', 'collapsed'
    )
  );

  $page['mainactivity']['#type'] = 'fieldset';
  $page['mainactivity']['#title'] = t('Main activity information');
  $page['mainactivity']['expected_results']['#markup'] = '<p><strong>'.$expectedResultsCustomField['label'].'</strong>: '.$expectedResults. '</p>';
  $page['mainactivity']['objective']['#markup'] = '<p><strong>'.$objectiveCustomField['label'].'</strong>: '.$objective.'</p>';
  $page['mainactivity']['#attributes'] = array (
    'class' => array(
      'collapsible', 'collapsed'
    )
  );

  $page['buttons_bottom'] = $buttons;

  return $page;
}