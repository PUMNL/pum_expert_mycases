<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

function pum_expert_mycases_question_about_proposal($form, &$form_state, $case_id) {
  $form['case_id']['#type'] = 'hidden';
  $form['case_id']['#name'] = 'case_id';
  $form['case_id']['#value'] = $case_id;

  $form['details'] = array(
    '#type' => 'textarea',
    '#required' => true,
    '#title' => t('Your question'),
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );

  $form_state['redirect'] = array(
    array('query' => drupal_get_destination()),
  );

  return $form;
}

function pum_expert_mycases_question_about_proposal_submit($form, &$form_state) {
  civicrm_initialize();

  $case_id = $form_state['values']['case_id'];

  $activityTypeOptionGroupId = civicrm_api3('OptionGroup', 'getvalue', array('name' => 'activity_type', 'return' => 'id'));
  $emailActivityType = civicrm_api3('OptionValue', 'getvalue', array('option_group_id' => $activityTypeOptionGroupId, 'name' => 'Email', 'return' => 'value'));

  $case = civicrm_api3('Case', 'getsingle', array('id' => $case_id));
  $proj_off = false;
  foreach($case['contacts'] as $role) {
    switch ($role['role']) {
      case 'Project Officer':
        $proj_off = $role;
        break;
    }
  }

  $expert_relationship_type = civicrm_api3('RelationshipType', 'getvalue', array('return' => 'id', 'name_a_b' => 'Expert'));
  $expert_relationship = civicrm_api3('Relationship', 'getsingle', array('relationship_type_id' => $expert_relationship_type, 'case_id' => $case_id));
  $expert = civicrm_api3('Contact', 'getsingle', array('return' => 'display_name,sort_name,email,phone,birth_date', 'id' => $expert_relationship['contact_id_b']));

  $from = CRM_Core_BAO_Domain::getNameAndEmail();
  $from = "$from[0] <$from[1]>";

  $subject = 'Question from '.$expert['display_name']. ' regarding '.$case['subject'];

  $mailParams = array(
    'groupName' => 'Activity Email Sender',
    'from' => $from,
    'toName' => $proj_off['display_name'],
    'toEmail' => $proj_off['email'],
    'subject' => $subject,
    'text' => $form_state['values']['details'],
    'html' => $form_state['values']['details'],
    'replyTo' => $expert['email'],
  );

  if (CRM_Utils_Mail::send($mailParams)) {
    $params['case_id'] = $case_id;
    $params['source_contact_id'] = $expert['contact_id'];
    $params['target_contact_id'] = $proj_off['contact_id'];
    $params['assignee_contact_id'] = $proj_off['contact_id'];
    $params['subject'] = $subject;
    $params['details'] = $form_state['values']['details'];
    $params['activity_type_id'] = $emailActivityType;
    civicrm_api3('Activity', 'create', $params);
    drupal_set_message(t('Sent an e-mail to the project officer'));
  } else {
    drupal_set_message(t('Could not send e-mail'), 'error');
  }

  drupal_goto('expert/see-proposal/'.$case_id);
}