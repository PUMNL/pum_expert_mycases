<?php

$view = new view();
$view->name = 'dsa_details_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_activity';
$view->human_name = 'DSA Details (expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Daily Subsistence Allowances';
$handler->display->display_options['css_class'] = 'pum-list-view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: CiviCRM DSA Compose: ID */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['relationships']['id']['field'] = 'id';
/* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_activity_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['record_type'] = '0';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/expert/dsa" class="button">Go back</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: CiviCRM DSA Compose: Amount DSA */
$handler->display->display_options['fields']['amount_dsa']['id'] = 'amount_dsa';
$handler->display->display_options['fields']['amount_dsa']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_dsa']['field'] = 'amount_dsa';
$handler->display->display_options['fields']['amount_dsa']['label'] = 'Amount DSA';
$handler->display->display_options['fields']['amount_dsa']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_dsa']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Briefing */
$handler->display->display_options['fields']['amount_briefing']['id'] = 'amount_briefing';
$handler->display->display_options['fields']['amount_briefing']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_briefing']['field'] = 'amount_briefing';
$handler->display->display_options['fields']['amount_briefing']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_briefing']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Airport */
$handler->display->display_options['fields']['amount_airport']['id'] = 'amount_airport';
$handler->display->display_options['fields']['amount_airport']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_airport']['field'] = 'amount_airport';
$handler->display->display_options['fields']['amount_airport']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_airport']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Transfer */
$handler->display->display_options['fields']['amount_transfer']['id'] = 'amount_transfer';
$handler->display->display_options['fields']['amount_transfer']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_transfer']['field'] = 'amount_transfer';
$handler->display->display_options['fields']['amount_transfer']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_transfer']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Hotel */
$handler->display->display_options['fields']['amount_hotel']['id'] = 'amount_hotel';
$handler->display->display_options['fields']['amount_hotel']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_hotel']['field'] = 'amount_hotel';
$handler->display->display_options['fields']['amount_hotel']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_hotel']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Visa */
$handler->display->display_options['fields']['amount_visa']['id'] = 'amount_visa';
$handler->display->display_options['fields']['amount_visa']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_visa']['field'] = 'amount_visa';
$handler->display->display_options['fields']['amount_visa']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_visa']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Medical */
$handler->display->display_options['fields']['amount_medical']['id'] = 'amount_medical';
$handler->display->display_options['fields']['amount_medical']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_medical']['field'] = 'amount_medical';
$handler->display->display_options['fields']['amount_medical']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_medical']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Other */
$handler->display->display_options['fields']['amount_other']['id'] = 'amount_other';
$handler->display->display_options['fields']['amount_other']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_other']['field'] = 'amount_other';
$handler->display->display_options['fields']['amount_other']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_other']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Description Other */
$handler->display->display_options['fields']['description_other']['id'] = 'description_other';
$handler->display->display_options['fields']['description_other']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['description_other']['field'] = 'description_other';
$handler->display->display_options['fields']['description_other']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['description_other']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['description_other']['empty_zero'] = TRUE;
$handler->display->display_options['fields']['description_other']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Amount Advance */
$handler->display->display_options['fields']['amount_advance']['id'] = 'amount_advance';
$handler->display->display_options['fields']['amount_advance']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_advance']['field'] = 'amount_advance';
$handler->display->display_options['fields']['amount_advance']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['amount_advance']['relationship'] = 'id';
/* Field: CiviCRM DSA Compose: Total amount */
$handler->display->display_options['fields']['total_amount']['id'] = 'total_amount';
$handler->display->display_options['fields']['total_amount']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['total_amount']['field'] = 'total_amount';
$handler->display->display_options['fields']['total_amount']['label'] = 'Total amount';
$handler->display->display_options['fields']['total_amount']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['total_amount']['relationship'] = 'id';
/* Contextual filter: CiviCRM Activities: Activity ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_activity';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/dsa/details';
$translatables['dsa_details_expert_'] = array(
  t('Master'),
  t('Daily Subsistence Allowances'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('CiviCRM Activity'),
  t('<a href="/expert/dsa" class="button">Go back</a>'),
  t('Total amount'),
  t('Amount Briefing'),
  t('Amount Airport'),
  t('Amount Transfer'),
  t('Amount Hotel'),
  t('Amount Visa'),
  t('Amount Medical'),
  t('Amount Other'),
  t('Description Other'),
  t('Amount Advance'),
  t('All'),
  t('Page'),
);
