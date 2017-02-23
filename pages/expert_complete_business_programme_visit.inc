<?php

function pum_expert_mycases_cancel_business_programme_visit($case_id, $activity_id) {
  civicrm_initialize();
  $params['activity_id'] = $activity_id;
  civicrm_api3('Businesslink', 'cancelvisit', $params);

  drupal_set_message('Business Programme cancelled');
  drupal_goto('/expert/complete-business-programmes-details/'.$case_id);
}

function pum_expert_mycases_complete_business_programme_visit($form, &$form_state, $case_id, $activity_id=false) {
  civicrm_initialize();

  $prefixes = civicrm_api3('OptionValue', 'get', array('option_group_id' => 'individual_prefix'));
  $prefixOptions = array();
  foreach($prefixes['values'] as $prefix) {
    $prefixOptions[$prefix['label']] = $prefix['label'];
  }

  $company_name = '';
  $company_address = '';
  $company_postal_code = '';
  $company_city = '';
  $company_email = '';
  $contact_person_prefix = '';
  $contact_person_firstname = '';
  $contact_person_lastname = '';
  $contact_person_email = '';
  $contact_person_phone = '';
  $visit_from = false;
  $visit_to = false;
  $result_of_visit = '';
  $aim_of_visit = '';
  $thank_you_send = false;

  if ($activity_id) {
    $visit = civicrm_api3('Businesslink', 'getvisitdetails', array('activity_id' => $activity_id));
    $visit = reset($visit['values']);
    $company_name = $visit['company_name'];
    $company_address = $visit['company_address'];
    $company_postal_code = $visit['company_postal_code'];
    $company_city = $visit['company_city'];
    $company_email = $visit['company_email'];
    $contact_person_prefix = $visit['contact_person_prefix'];
    $contact_person_firstname = $visit['contact_person_firstname'];
    $contact_person_lastname = $visit['contact_person_lastname'];
    $contact_person_email = $visit['contact_person_email'];
    $contact_person_phone = $visit['contact_person_phone'];
    if (!empty($visit['visit_from'])) {
      $visit_from = new DateTime($visit['visit_from']);
    }
    if (!empty($visit['visit_to'])) {
      $visit_to = new DateTime($visit['visit_to']);
    }
    $aim_of_visit = $visit['aim_of_visit'];
    $result_of_visit = $visit['result_of_visit'];
    $thank_you_send = $visit['thank_you_send'];
  }


  $form = array();

  $form['case_id']['#type'] = 'hidden';
  $form['case_id']['#name'] = 'case_id';
  $form['case_id']['#value'] = $case_id;

  $form['activity_id']['#type'] = 'hidden';
  $form['activity_id']['#name'] = 'activity_id';
  $form['activity_id']['#value'] = $activity_id;

  $form['company']['#type'] = 'fieldset';
  $form['company']['#title'] = 'Company to visit';
  $form['company']['company_name']['#type'] = 'textfield';
  $form['company']['company_name']['#required'] = TRUE;
  $form['company']['company_name']['#title'] = 'Name';
  $form['company']['company_name']['#default_value'] = $company_name;
  $form['company']['company_address']['#type'] = 'textfield';
  $form['company']['company_address']['#required'] = TRUE;
  $form['company']['company_address']['#title'] = 'Address';
  $form['company']['company_address']['#default_value'] = $company_address;
  $form['company']['company_postal_code']['#type'] = 'textfield';
  $form['company']['company_postal_code']['#required'] = TRUE;
  $form['company']['company_postal_code']['#title'] = 'Postal code';
  $form['company']['company_postal_code']['#default_value'] = $company_postal_code;
  $form['company']['company_city']['#type'] = 'textfield';
  $form['company']['company_city']['#required'] = TRUE;
  $form['company']['company_city']['#title'] = 'City';
  $form['company']['company_city']['#default_value'] = $company_city;
  $form['company']['company_email']['#type'] = 'textfield';
  $form['company']['company_email']['#required'] = TRUE;
  $form['company']['company_email']['#title'] = 'E-mail';
  $form['company']['company_email']['#default_value'] = $company_email;

  $form['contact_person']['#type'] = 'fieldset';
  $form['contact_person']['#title'] = 'Contact person';
  $form['contact_person']['contact_person_prefix']['#type'] = 'select';
  $form['contact_person']['contact_person_prefix']['#required'] = TRUE;
  $form['contact_person']['contact_person_prefix']['#title'] = 'Prefix';
  $form['contact_person']['contact_person_prefix']['#options'] = $prefixOptions;
  $form['contact_person']['contact_person_prefix']['#empty_option'] = t(' - Select -');
  $form['contact_person']['contact_person_prefix']['#default_value'] = $contact_person_prefix;
  $form['contact_person']['contact_person_firstname']['#type'] = 'textfield';
  $form['contact_person']['contact_person_firstname']['#required'] = TRUE;
  $form['contact_person']['contact_person_firstname']['#title'] = 'First name';
  $form['contact_person']['contact_person_firstname']['#default_value'] = $contact_person_firstname;
  $form['contact_person']['contact_person_lastname']['#type'] = 'textfield';
  $form['contact_person']['contact_person_lastname']['#required'] = TRUE;
  $form['contact_person']['contact_person_lastname']['#title'] = 'Last name';
  $form['contact_person']['contact_person_lastname']['#default_value'] = $contact_person_lastname;
  $form['contact_person']['contact_person_email']['#type'] = 'textfield';
  $form['contact_person']['contact_person_email']['#required'] = TRUE;
  $form['contact_person']['contact_person_email']['#title'] = 'E-mail';
  $form['contact_person']['contact_person_email']['#default_value'] = $contact_person_email;
  $form['contact_person']['contact_person_phone']['#type'] = 'textfield';
  $form['contact_person']['contact_person_phone']['#required'] = TRUE;
  $form['contact_person']['contact_person_phone']['#title'] = 'Phone';
  $form['contact_person']['contact_person_phone']['#default_value'] = $contact_person_phone;

  $form['visit']['#type'] = 'fieldset';
  $form['visit']['#title'] = 'Visit';

  $form['visit']['visit_from']['#type'] = 'date_popup';
  $form['visit']['visit_from']['#title'] = 'From';
  $form['visit']['visit_from']['#date_label_position'] = 'before';
  $form['visit']['visit_from']['#required'] = TRUE;
  $form['visit']['visit_from']['#date_format'] = 'Y-m-d';
  $form['visit']['visit_from']['#date_increment'] = 1;
  $form['visit']['visit_from']['#date_year_range'] = '-2:+2';
  if ($visit_from) {
    $form['visit']['visit_from']['#default_value'] = $visit_from->format('Y-m-d');
  }

  $form['visit']['visit_to']['#type'] = 'date_popup';
  $form['visit']['visit_to']['#title'] = 'To';
  $form['visit']['visit_to']['#date_label_position'] = 'before';
  $form['visit']['visit_to']['#required'] = TRUE;
  $form['visit']['visit_to']['#date_format'] = 'Y-m-d';
  $form['visit']['visit_to']['#date_increment'] = 1;
  $form['visit']['visit_to']['#date_year_range'] = '-2:+2';
  if ($visit_to) {
    $form['visit']['visit_to']['#default_value'] = $visit_to->format('Y-m-d');
  }

  if ($aim_of_visit) {
    $form['visit']['aim']['#markup'] = '<p>Aim of visit<br /><em>' . $aim_of_visit . '</em></p>';
  }

  $form['visit']['result_of_visit']['#type'] = 'textarea';
  $form['visit']['result_of_visit']['#required'] = true;
  $form['visit']['result_of_visit']['#title'] = 'Result of visit';
  $form['visit']['result_of_visit']['#default_value'] = $result_of_visit;

  $form['visit']['thank_you_send']['#type'] = 'select';
  $form['visit']['thank_you_send']['#required'] = true;
  $form['visit']['thank_you_send']['#title'] = 'Send thank you note?';
  $form['visit']['thank_you_send']['#default_value'] = $thank_you_send ? '1' : '0';
  $form['visit']['thank_you_send']['#options'] = array('0' => 'No', '1' => 'Yes');
  $form['visit']['thank_you_send']['#empty_option'] = t(' - Select -');

  $form['submit_button']['#type'] = 'submit';
  $form['submit_button']['#value'] = 'Submit';

  return $form;
}

function pum_expert_mycases_complete_business_programme_visit_submit($form, &$form_state) {
  civicrm_initialize();
  $params['case_id'] = $form_state['values']['case_id'];
  if (!empty($form_state['values']['activity_id'])) {
    $params['activity_id'] = $form_state['values']['activity_id'];
  }

  $params['company_name'] = $form_state['values']['company_name'];
  $params['company_address'] = $form_state['values']['company_address'];
  $params['company_postal_code'] = $form_state['values']['company_postal_code'];
  $params['company_city'] = $form_state['values']['company_city'];
  $params['company_email'] = $form_state['values']['company_email'];

  $params['contact_person_prefix'] = $form_state['values']['contact_person_prefix'];
  $params['contact_person_firstname'] = $form_state['values']['contact_person_firstname'];
  $params['contact_person_lastname'] = $form_state['values']['contact_person_lastname'];
  $params['contact_person_email'] = $form_state['values']['contact_person_email'];
  $params['contact_person_phone'] = $form_state['values']['contact_person_phone'];

  $visitFrom = new DateTime($form_state['values']['visit_from']);
  $params['visit_from'] = $visitFrom->format('Ymd');
  $visitTo = new DateTime($form_state['values']['visit_to']);
  $params['visit_to'] = $visitTo->format('Ymd');
  $params['result_of_visit'] = $form_state['values']['result_of_visit'];
  $params['thank_you_send'] = $form_state['values']['thank_you_send'];

  civicrm_api3('Businesslink', 'completevisit', $params);

  drupal_set_message('Business programme visit completed.');
  drupal_goto('/expert/complete-business-programmes-details/'.$form_state['values']['case_id']);
}
