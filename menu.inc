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
    'access callback' => '_pum_expert_mycases_user_has_role',
    'access arguments' => array(array('Expert')),
    // arg 1 loads the user, arg 2 is the role name
  );
  $items['expert/see-proposal/%'] = array(
    'title' => t('Main activity proposal'),
    'type' => MENU_CALLBACK,
    'file' => 'pages/expert_see_proposal.inc',
    'page callback' => 'pum_expert_mycases_see_proposal',
    'page arguments' => array(2),
    'access callback' => '_pum_expert_mycases_user_has_role',
    'access arguments' => array(array('Expert')),
  );
  $items['expert/see-proposal/%/question'] = array(
    'title' => 'Ask question about proposal',
    'page callback' => 'drupal_get_form',
    'file' => 'pages/expert_question_about_proposal.inc',
    'page arguments' => array('pum_expert_mycases_question_about_proposal', 2),
    'access callback' => '_pum_expert_mycases_user_has_role',
    'access arguments' => array(array('Expert')),
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
  return $items;
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