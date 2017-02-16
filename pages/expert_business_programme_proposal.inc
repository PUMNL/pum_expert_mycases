<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

function pum_expert_mycases_business_programme_proposal($form, &$form_state, $case_id) {
  civicrm_initialize();
  $config = CRM_Core_Config::singleton();
  $businessconfig = pum_expert_mycases_businessconfig::singleton();

  $case = civicrm_api3('Case', 'getsingle', array('id' => $case_id));
  $customer_id = $case['client_id'];
  $customer = civicrm_api3('Contact', 'getsingle', array('id' => $customer_id));

  $mainActivityStartDateCustomFieldName = $businessconfig->mainActivityStartDateCustomFieldName;
  $mainActivityEndDateCustomFieldName = $businessconfig->mainActivityEndDateCustomFieldName;
  $startDate = '';
  $endDate = '';
  $dao = CRM_Core_DAO::executeQuery("SELECT * FROM `".$businessconfig->mainActivityInfoCustomGroup['table_name']."` WHERE `entity_id` = %1", array(1=>array($case_id, 'Integer')));
  if ($dao->fetch()) {
    if ($dao->$mainActivityStartDateCustomFieldName) {
      $startDate = new DateTime($dao->$mainActivityStartDateCustomFieldName);
    }
    if ($dao->$mainActivityEndDateCustomFieldName) {
      $endDate = new DateTime($dao->$mainActivityEndDateCustomFieldName);
    }
  }

  $visitSqlParams = array();
  $visitSqlParams[1] = array($case_id, 'Integer');
  $visitSql = "
    SELECT civicrm_activity.id as activity_id, 
    {$businessconfig->custom_groups['Business_Programme']['fields']['Naam_bedrijf']['column_name']} AS `Naam_bedrijf`,
    {$businessconfig->custom_groups['Business_Programme']['fields']['Location']['column_name']} AS `Location`,
    {$businessconfig->custom_groups['Business_Programme']['fields']['Aim_of_Visit']['column_name']} AS `Aim_of_Visit`
    FROM civicrm_activity 
    INNER JOIN civicrm_case_activity ON civicrm_case_activity.activity_id = civicrm_activity.id
    INNER JOIN {$businessconfig->custom_groups['Business_Programme']['table_name']} ON {$businessconfig->custom_groups['Business_Programme']['table_name']}.entity_id = civicrm_activity.id  
    WHERE civicrm_case_activity.case_id = %1 AND civicrm_activity.is_current_revision = '1' AND civicrm_activity.is_deleted != '1'";

  $dao = CRM_Core_DAO::executeQuery($visitSql, $visitSqlParams);
  $visits = array();
  while($dao->fetch()) {
    $naam_bedrijf_input = '<input type="hidden" name="activity_id[]" value="'.$dao->activity_id.'" /><input type="text" name="Naam_bedrijf[]" value="'.$dao->Naam_bedrijf.'" />';
    $location_input = '<input type="text" name="Location[]" value="'.$dao->Location.'" />';
    $aim_of_visit_input = '<textarea name="Aim_of_Visit[]">'.$dao->Aim_of_Visit.'</textarea>';
    $remove_button = '<a href="#" onclick="jQuery(this).parent().parent().remove(); return false;">Remove</a>';

    $visits[] = array(
      $naam_bedrijf_input,
      $location_input,
      $aim_of_visit_input,
      $remove_button
    );
  }
  if (isset($form_state['input']['case_id'])) {
    $visits = array();
  }
  if (isset($form_state['input']['activity_id'])) {
    foreach ($form_state['input']['activity_id'] as $index => $activity_id) {
      $naam_bedrijf_input = '<input type="hidden" name="activity_id[]" value="'.$activity_id.'" /><input type="text" name="Naam_bedrijf[]" value="'.$form_state['input']['Naam_bedrijf'][$index].'" />';
      $location_input = '<input type="text" name="Location[]" value="'.$form_state['input']['Location'][$index].'" />';
      $aim_of_visit_input = '<textarea name="Aim_of_Visit[]">'.$form_state['input']['Aim_of_Visit'][$index].'</textarea>';
      $remove_button = '<a href="#" onclick="jQuery(this).parent().parent().remove(); return false;">Remove</a>';

      $visits[] = array(
        $naam_bedrijf_input,
        $location_input,
        $aim_of_visit_input,
        $remove_button
      );
    }
  }

  drupal_set_title("Business programme proposal ".$customer['display_name']);
  drupal_add_css(drupal_get_path('module', 'pum_expert_mycases') . '/style.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_add_js('function pum_expert_mycases_business_programma_proposal_add_visit(table) { table.append(\'<tr><td><input type="hidden" name="activity_id[]" value="" /><input type="text" name="Naam_bedrijf[]" value="" /></td><td><input type="text" name="Location[]" value="" /></td><td><textarea name="Aim_of_Visit[]"></textarea></td><td><a href="#" onclick="jQuery(this).parent().parent().remove(); return false;">Remove</a></td></tr>\'); }', array('type' => 'inline'));
  $form = array();

  $form['case_id']['#type'] = 'hidden';
  $form['case_id']['#name'] = 'case_id';
  $form['case_id']['#value'] = $case_id;

  $form['proposed_period']['#type'] = 'fieldset';
  $form['proposed_period']['#title'] = 'Proposed period';
  if (empty($startDate) || empty($endDate)) {
    $form['proposed_period']['start_date']['#type'] = 'date_popup';
    $form['proposed_period']['start_date']['#title'] = 'From';
    $form['proposed_period']['start_date']['#date_label_position'] = 'before';
    $form['proposed_period']['start_date']['#required'] = TRUE;
    $form['proposed_period']['start_date']['#date_format'] = 'Y-m-d';
    $form['proposed_period']['start_date']['#date_increment'] = 1;
    $form['proposed_period']['start_date']['#date_year_range'] = '-2:+2';
    if ($startDate) {
      $form['proposed_period']['start_date']['#default_value'] = $startDate->format('Y-m-d');
    }

    $form['proposed_period']['end_date']['#type'] = 'date_popup';
    $form['proposed_period']['end_date']['#required'] = TRUE;
    $form['proposed_period']['end_date']['#title'] = 'To';
    $form['proposed_period']['end_date']['#date_label_position'] = 'before';
    $form['proposed_period']['end_date']['#date_format'] = 'Y-m-d';
    $form['proposed_period']['end_date']['#date_increment'] = 1;
    $form['proposed_period']['end_date']['#date_year_range'] = '-2:+2';
    if ($endDate) {
      $form['proposed_period']['end_date']['#default_value'] = $endDate->format('Y-m-d');
    }
  } else {
    $form['proposed_period']['period']['#type'] = 'markup';
    $form['proposed_period']['period']['#markup'] = '<p>'.$startDate->format('Y-m-d').' to '.$endDate->format('Y-m-d').'</p>';
    $form['proposed_period']['period_description']['#type'] = 'markup';
    $form['proposed_period']['period_description']['#markup'] = '<p><em>If you have any questions about the period or you want to propose a different period, please contact your project officer</em></p>';
  }

  $form['visits']['#type'] = 'fieldset';
  $form['visits']['#title'] = 'Visits';
  $form['visits']['table']['#theme'] = 'table';
  $form['visits']['table']['#header'] = array('Company name', 'Location', 'Aim of visit', '');
  $form['visits']['table']['#attributes'] = array('width' => '100%', 'class' => array('visit_table'));
  $form['visits']['table']['#rows'] = $visits;
  $form['visits']['add_visit']['#markup'] = '<a href="#" class="button" onclick="pum_expert_mycases_business_programma_proposal_add_visit(jQuery(\'.visit_table tbody\')); return false;">Add a visit</a>';

  $form['submit_button']['#type'] = 'submit';
  if (empty($startDate) || empty($endDate)) {
    $form['submit_button']['#value'] = t('Submit business programme');
  } else {
    $form['submit_button']['#value'] = t('Update business programme');
  }

  $form['#validate'][] = 'pum_expert_mycases_business_programme_proposal_validate';

  return $form;
}

function pum_expert_mycases_business_programme_proposal_validate($form, &$form_state) {
  if (!isset($form_state['input']['activity_id']) || !count($form_state['input']['activity_id'])) {
    form_set_error('visits', 'Please add at least one visit');
  } else {
    foreach ($form_state['input']['activity_id'] as $index => $activity_id) {
      if (!empty($activity_id) && isset($visits[$activity_id])) {
        unset($visits[$activity_id]);
      }
      if (empty($form_state['input']['Naam_bedrijf'][$index]) || empty($form_state['input']['Location'][$index]) || empty($form_state['input']['Aim_of_Visit'][$index])) {
        continue;
      }
      if (empty($form_state['input']['Naam_bedrijf'][$index])) {
        form_set_error('visits', 'Company name is required');
      }
      if (empty($form_state['input']['Aim_of_Visit'][$index])) {
        form_set_error('visits', 'Aim of visit is required');
      }
    }
  }
}

function pum_expert_mycases_business_programme_proposal_submit($form, &$form_state) {
  civicrm_initialize();
  $businessconfig = pum_expert_mycases_businessconfig::singleton();
  $case_id = $form_state['values']['case_id'];

  $visitSqlParams = array();
  $visitSqlParams[1] = array($case_id, 'Integer');
  $visitSql = "
    SELECT civicrm_activity.id as activity_id, 
    {$businessconfig->custom_groups['Business_Programme']['fields']['Naam_bedrijf']['column_name']} AS `Naam_bedrijf`,
    {$businessconfig->custom_groups['Business_Programme']['fields']['Location']['column_name']} AS `Location`,
    {$businessconfig->custom_groups['Business_Programme']['fields']['Aim_of_Visit']['column_name']} AS `Aim_of_Visit`
    FROM civicrm_activity 
    INNER JOIN civicrm_case_activity ON civicrm_case_activity.activity_id = civicrm_activity.id
    INNER JOIN {$businessconfig->custom_groups['Business_Programme']['table_name']} ON {$businessconfig->custom_groups['Business_Programme']['table_name']}.entity_id = civicrm_activity.id  
    WHERE civicrm_case_activity.case_id = %1 AND civicrm_activity.is_current_revision = '1' AND civicrm_activity.is_deleted != '1'";

  $dao = CRM_Core_DAO::executeQuery($visitSql, $visitSqlParams);
  $visitsToCancel = array();
  while($dao->fetch()) {
    $visitsToCancel[$dao->activity_id] = $dao->activity_id;
  }

  $mainActivityStartDateCustomFieldName = $businessconfig->mainActivityStartDateCustomFieldName;
  $mainActivityEndDateCustomFieldName = $businessconfig->mainActivityEndDateCustomFieldName;
  $startDate = '';
  $endDate = '';
  $dao = CRM_Core_DAO::executeQuery("SELECT * FROM `".$businessconfig->mainActivityInfoCustomGroup['table_name']."` WHERE `entity_id` = %1", array(1=>array($case_id, 'Integer')));
  if ($dao->fetch()) {
    if ($dao->$mainActivityStartDateCustomFieldName) {
      $startDate = new DateTime($dao->$mainActivityStartDateCustomFieldName);
    }
    if ($dao->$mainActivityEndDateCustomFieldName) {
      $endDate = new DateTime($dao->$mainActivityEndDateCustomFieldName);
    }
  }

  // Only update the period when no period is set. Otherwise the expert is not allowed to update the period.
  if (empty($startDate) || empty($endDate)) {
    $startDate = new DateTime($form_state['values']['start_date']);
    $endDate = new DateTime($form_state['values']['end_date']);

    $caseUpdateParams['custom_' . $businessconfig->mainActivityStartDateCustomField['id']] = $startDate->format('Ymd');
    $caseUpdateParams['custom_' . $businessconfig->mainActivityEndDateCustomField['id']] = $endDate->format('Ymd');
    $caseUpdateParams['entity_id'] = $case_id;
    $caseUpdateParams['entity_table'] = 'civicrm_case';
    civicrm_api3('CustomValue', 'create', $caseUpdateParams);
  }

  foreach($form_state['input']['activity_id'] as $index => $activity_id) {
    if (empty($form_state['input']['Naam_bedrijf'][$index]) || empty($form_state['input']['Location'][$index]) || empty($form_state['input']['Aim_of_Visit'][$index])) {
      continue;
    }

    $activityParams = array();
    $activityParams['case_id'] = $case_id;
    $activityParams['status_id'] = $businessconfig->in_progress_status['value'];
    $activityParams['subject'] = $form_state['input']['Naam_bedrijf'][$index];
    $activityParams['activity_type_id'] = $businessconfig->programme_activity_type_id;
    $activityParams['custom_'.$businessconfig->custom_groups['Business_Programme']['fields']['Naam_bedrijf']['id']] = $form_state['input']['Naam_bedrijf'][$index];
    $activityParams['custom_'.$businessconfig->custom_groups['Business_Programme']['fields']['Location']['id']] = $form_state['input']['Location'][$index];
    $activityParams['custom_'.$businessconfig->custom_groups['Business_Programme']['fields']['Aim_of_Visit']['id']] = $form_state['input']['Aim_of_Visit'][$index];

    if ($activity_id) {
      unset($visitsToCancel[$activity_id]);
      $activityParams['id'] = $activity_id;
    }

    civicrm_api3('Activity', 'create', $activityParams);
  }

  foreach($visitsToCancel as $activity_id) {
    civicrm_api3('Activity', 'delete', array('id' => $activity_id));
  }

  drupal_set_message('Businesse programme proposal is succesfully submitted.');
  drupal_goto('/portal');

}