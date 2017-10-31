<?php

require_once 'contact_with_customer.inc';

function _pum_expert_mycases_menu() {
  $items = array();
  $items['expert/my-cases/new-contact-with-customer/%'] = array( //this creates a URL that will call this form at "examples/form-example"
    'title' => 'Contact with customer',
    //page title
    'description' => '',
    'page callback' => 'drupal_get_form',
    //this is the function that will be called when the page is accessed.  for a form, use drupal_get_form
    'page arguments' => array('pum_expert_mycases_contact_with_customer', 3),
    //put the name of the form here
    'access callback' => '_pum_expert_mycases_user_has_role_and_is_on_case',
    'access arguments' => array(array('Expert'), 3),
    // arg 1 loads the user, arg 2 is the role name
  );
  $items['expert/see-proposal/%'] = array(
    'title' => t('Main activity proposal'),
    'type' => MENU_CALLBACK,
    'file' => 'pages/expert_see_proposal.inc',
    'page callback' => 'pum_expert_mycases_see_proposal',
    'page arguments' => array(2),
    'access callback' => '_pum_expert_mycases_user_has_role_and_is_on_case',
    'access arguments' => array(array('Expert'),2),
  );
  $items['expert/see-proposal/%/question'] = array(
    'title' => 'Ask question about proposal',
    'page callback' => 'drupal_get_form',
    'file' => 'pages/expert_question_about_proposal.inc',
    'page arguments' => array('pum_expert_mycases_question_about_proposal', 2),
    'access callback' => '_pum_expert_mycases_user_has_role_and_is_on_case',
    'access arguments' => array(array('Expert'),2),
  );
  $items['expert/my-main-activity-history'] = array(
    'title' => t('My Main Activity History'),
    'type' => MENU_NORMAL_ITEM,
    'file' => 'pages/my_main_activity_history.inc',
    'page callback' => 'pum_expert_mycases_my_main_activity_history',
    'access callback' => '_pum_expert_mycases_user_has_role',
    'access arguments' => array(array('Expert')),
    'menu_name' => 'menu-my-profile',
    'weight' => -1,
  );
  $items['expert/business-programme-proposal/%'] = array(
    'title' => t('Business programme proposal'),
    'type' => MENU_CALLBACK,
    'file' => 'pages/expert_business_programme_proposal.inc',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('pum_expert_mycases_business_programme_proposal', 2),
    'access callback' => '_pum_expert_mycases_user_has_role_and_is_on_case',
    'access arguments' => array(array('Expert'),2),
  );
  $items['expert/complete-business-programme-visits/%/%'] = array(
    'title' => t('Complete Business programme visit'),
    'type' => MENU_CALLBACK,
    'file' => 'pages/expert_complete_business_programme_visit.inc',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('pum_expert_mycases_complete_business_programme_visit', 2, 3),
    'access callback' => '_pum_expert_mycases_user_has_role_and_is_on_case',
    'access arguments' => array(array('Expert'),2),
  );
  $items['expert/cancel-business-programme-visits/%/%'] = array(
    'title' => t('Cancel Business programme visit'),
    'type' => MENU_CALLBACK,
    'file' => 'pages/expert_complete_business_programme_visit.inc',
    'page callback' => 'pum_expert_mycases_cancel_business_programme_visit',
    'page arguments' => array(2, 3),
    'access callback' => '_pum_expert_mycases_user_has_role_and_is_on_case',
    'access arguments' => array(array('Expert'),2),
  );
  $items['expert/complete-business-programme-visits/%'] = array(
    'title' => t('Complete Business programme visit'),
    'type' => MENU_CALLBACK,
    'file' => 'pages/expert_complete_business_programme_visit.inc',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('pum_expert_mycases_complete_business_programme_visit', 2),
    'access callback' => '_pum_expert_mycases_user_has_role_and_is_on_case',
    'access arguments' => array(array('Expert'),2),
  );
  
  return $items;
}

/**
 * Returns true when the user has a certain drupal role and is connected to the
 * case.
 *
 * @param $roles
 * @param $case_id
 * @return bool
 */
function _pum_expert_mycases_user_has_role_and_is_on_case($roles = array(), $case_id) {
  if (!_pum_expert_mycases_user_has_role($roles)) {
    return false;
  }
  if (!_pum_expert_mycases_user_has_role_on_case($case_id)) {
    return false;
  }
  return true;
}

/**
 * Returns true when a user has a role on the case.
 *
 * @param $case_id
 * @return bool
 */
function _pum_expert_mycases_user_has_role_on_case($case_id) {
  civicrm_initialize();
  $session = CRM_Core_Session::singleton();
  $contact_id = $session->get('userID');
  $case = civicrm_api3('Case', 'getsingle', array('id' => $case_id));
  
  foreach($case['contacts'] as $contact) {
    if ($contact['contact_id'] == $contact_id) {
      return true;
    }
  }
  return false;
}

function _pum_expert_mycases_user_has_role($roles = array()) {
  global $user;
  foreach ($roles as $role) {
    if (in_array($role, $user->roles)) {
      return TRUE;
    }
  }
  return FALSE;
}