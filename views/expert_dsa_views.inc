<?php

$activity_type_option_group = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'activity_type'));
$dsa_id = civicrm_api3('OptionValue', 'getvalue', array('name' => 'DSA', 'option_group_id' => $activity_type_option_group, 'return' => 'value'));
$business_dsa_id = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Business DSA', 'option_group_id' => $activity_type_option_group, 'return' => 'value'));
$business_credit_dsa_id = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Credit Business DSA', 'option_group_id' => $activity_type_option_group, 'return' => 'value'));

$bdsa_cg = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'pum_business_dsa'));
$bdsa_table = $bdsa_cg['table_name'];
$bdsa_amount_field = civicrm_api3('CustomField', 'getvalue', array('name' => 'bdsa_amount', 'return' => 'column_name', 'custom_group_id' => $bdsa_cg['id']));

$view = new view();
$view->name = 'dsa_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_activity';
$view->human_name = 'DSA (Expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Daily Subsistence Allowances';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
/* Relationship: CiviCRM DSA Compose: ID */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['relationships']['id']['field'] = 'id';
/* Relationship: CiviCRM Case Activity: Case ID */
$handler->display->display_options['relationships']['case_id']['id'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['table'] = 'civicrm_case_activity';
$handler->display->display_options['relationships']['case_id']['field'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['label'] = 'Travel case';
$handler->display->display_options['relationships']['case_id']['required'] = TRUE;
/* Relationship: CiviCRM Parent case: Parent case */
$handler->display->display_options['relationships']['case_id_1']['id'] = 'case_id_1';
$handler->display->display_options['relationships']['case_id_1']['table'] = 'civicrm_value_travel_parent';
$handler->display->display_options['relationships']['case_id_1']['field'] = 'case_id';
$handler->display->display_options['relationships']['case_id_1']['relationship'] = 'case_id';
/* Relationship: CiviCRM Case Contact: Case Contact's Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_case_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['relationship'] = 'case_id_1';
$handler->display->display_options['relationships']['contact_id']['label'] = 'Client';
/* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
$handler->display->display_options['relationships']['contact_id_1']['id'] = 'contact_id_1';
$handler->display->display_options['relationships']['contact_id_1']['table'] = 'civicrm_activity_contact';
$handler->display->display_options['relationships']['contact_id_1']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id_1']['record_type'] = '3';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id_1';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Contact: Case Contact's Contact ID */
$handler->display->display_options['relationships']['contact_id_2']['id'] = 'contact_id_2';
$handler->display->display_options['relationships']['contact_id_2']['table'] = 'civicrm_case_contact';
$handler->display->display_options['relationships']['contact_id_2']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id_2']['relationship'] = 'case_id';
$handler->display->display_options['relationships']['contact_id_2']['label'] = 'Travel case client';
/* Field: CiviCRM Activities: Activity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Cases: Case ID */
$handler->display->display_options['fields']['id_3']['id'] = 'id_3';
$handler->display->display_options['fields']['id_3']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['id_3']['field'] = 'id';
$handler->display->display_options['fields']['id_3']['relationship'] = 'case_id';
$handler->display->display_options['fields']['id_3']['label'] = '';
$handler->display->display_options['fields']['id_3']['exclude'] = TRUE;
$handler->display->display_options['fields']['id_3']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id_3']['separator'] = '';
/* Field: CiviCRM Cases: Case Type */
$handler->display->display_options['fields']['case_type_1']['id'] = 'case_type_1';
$handler->display->display_options['fields']['case_type_1']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['case_type_1']['field'] = 'case_type';
$handler->display->display_options['fields']['case_type_1']['relationship'] = 'case_id';
$handler->display->display_options['fields']['case_type_1']['label'] = '';
$handler->display->display_options['fields']['case_type_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_type_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['case_type_1']['alter']['path'] = 'expert/my-cases/activities/[id_3]';
$handler->display->display_options['fields']['case_type_1']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['case_type_1']['element_label_colon'] = FALSE;
/* Field: CiviCRM Cases: Case ID */
$handler->display->display_options['fields']['id_1']['id'] = 'id_1';
$handler->display->display_options['fields']['id_1']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['id_1']['field'] = 'id';
$handler->display->display_options['fields']['id_1']['relationship'] = 'case_id_1';
$handler->display->display_options['fields']['id_1']['label'] = '';
$handler->display->display_options['fields']['id_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['id_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id_1']['separator'] = '';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id_2']['id'] = 'id_2';
$handler->display->display_options['fields']['id_2']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id_2']['field'] = 'id';
$handler->display->display_options['fields']['id_2']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['id_2']['label'] = '';
$handler->display->display_options['fields']['id_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['id_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id_2']['separator'] = '';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id_4']['id'] = 'id_4';
$handler->display->display_options['fields']['id_4']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id_4']['field'] = 'id';
$handler->display->display_options['fields']['id_4']['relationship'] = 'contact_id_2';
$handler->display->display_options['fields']['id_4']['label'] = '';
$handler->display->display_options['fields']['id_4']['exclude'] = TRUE;
$handler->display->display_options['fields']['id_4']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id_4']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name_1']['id'] = 'display_name_1';
$handler->display->display_options['fields']['display_name_1']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name_1']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name_1']['relationship'] = 'contact_id_2';
$handler->display->display_options['fields']['display_name_1']['label'] = '';
$handler->display->display_options['fields']['display_name_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['display_name_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['display_name_1']['alter']['path'] = 'expert/customer/[id_4]';
$handler->display->display_options['fields']['display_name_1']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['display_name_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name_1']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Custom: Business DSA: Amount */
$handler->display->display_options['fields']['bdsa_amount']['id'] = 'bdsa_amount';
$handler->display->display_options['fields']['bdsa_amount']['table'] = $bdsa_table;
$handler->display->display_options['fields']['bdsa_amount']['field'] = $bdsa_amount_field;
$handler->display->display_options['fields']['bdsa_amount']['exclude'] = TRUE;
$handler->display->display_options['fields']['bdsa_amount']['separator'] = '.';
/* Field: CiviCRM Activities: Activity Type */
$handler->display->display_options['fields']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['fields']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['fields']['activity_type']['label'] = 'Type';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['display_name']['label'] = 'Client';
$handler->display->display_options['fields']['display_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['display_name']['alter']['path'] = 'expert/customer/[id_2]';
$handler->display->display_options['fields']['display_name']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['display_name']['empty'] = '[display_name_1]';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Cases: Case Type */
$handler->display->display_options['fields']['case_type']['id'] = 'case_type';
$handler->display->display_options['fields']['case_type']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['case_type']['field'] = 'case_type';
$handler->display->display_options['fields']['case_type']['relationship'] = 'case_id_1';
$handler->display->display_options['fields']['case_type']['label'] = 'Case';
$handler->display->display_options['fields']['case_type']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['case_type']['alter']['path'] = 'expert/my-cases/activities/[id_1]';
$handler->display->display_options['fields']['case_type']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['case_type']['empty'] = '[case_type_1]';
/* Field: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Date';
$handler->display->display_options['fields']['activity_date_time']['date_format'] = 'custom';
$handler->display->display_options['fields']['activity_date_time']['custom_date_format'] = 'd-m-Y';
$handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'long';
/* Field: CiviCRM Activities: Activity Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['label'] = 'Status';
/* Field: CiviCRM DSA Compose: Amount DSA */
$handler->display->display_options['fields']['amount_dsa']['id'] = 'amount_dsa';
$handler->display->display_options['fields']['amount_dsa']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_dsa']['field'] = 'total_amount';
$handler->display->display_options['fields']['amount_dsa']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_dsa']['empty'] = '[bdsa_amount]';
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = '';
$handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php
if ($row->amount_dsa != null) {
   echo \'<a href="/expert/dsa/details/\'.$row->id.\'">View details</a>\';
} elseif ($row->bdsa_amount != null)  {
   echo \'<a href="/expert/dsa/business-dsa-details/\'.$row->id.\'">View details</a>\';
}
?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Sort criterion: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['sorts']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['sorts']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['order'] = 'DESC';
/* Filter criterion: CiviCRM Activities: Activity Type */
$handler->display->display_options['filters']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['value'] = array(
  $dsa_id => $dsa_id,
  $business_dsa_id => $business_dsa_id,
  $business_credit_dsa_id => $business_credit_dsa_id,
);
/* Filter criterion: CiviCRM Activities: Current Revision */
$handler->display->display_options['filters']['is_current_revision']['id'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['is_current_revision']['field'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['value'] = '1';
/* Filter criterion: CiviCRM Activities: Is Deleted */
$handler->display->display_options['filters']['is_deleted']['id'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['is_deleted']['field'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['value'] = '0';
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/dsa';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Daily Subsistence Allowance (DSA)';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['dsa_expert_'] = array(
  t('Master'),
  t('Daily Subsistence Allowances'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('CiviCRM DSA Compose'),
  t('Travel case'),
  t('CiviCRM Case (parent)'),
  t('Client'),
  t('Activity Contact ID'),
  t('Drupal User'),
  t('Travel case client'),
  t('.'),
  t('Amount'),
  t('Type'),
  t('[display_name_1]'),
  t('Case'),
  t('[case_type_1]'),
  t('Date'),
  t('Status'),
  t('Amount DSA'),
  t('[bdsa_amount]'),
  t('Page'),
);
