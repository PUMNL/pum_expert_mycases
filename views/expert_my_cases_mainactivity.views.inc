<?php

$main_activity_info = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'main_activity_info'));
$start_date = civicrm_api3('CustomField', 'getsingle', array('name' => 'main_activity_start_date', 'custom_group_id' => $main_activity_info['id']));
$end_date = civicrm_api3('CustomField', 'getsingle', array('name' => 'main_activity_end_date', 'custom_group_id' => $main_activity_info['id']));
$result = civicrm_api3('CustomField', 'getsingle', array('name' => 'Expected_results', 'custom_group_id' => $main_activity_info['id']));
$objective = civicrm_api3('CustomField', 'getsingle', array('name' => 'Objective_of_this_Activity', 'custom_group_id' => $main_activity_info['id']));

$pum_case_number = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'PUM_Case_number'));
$sequence = civicrm_api3('CustomField', 'getsingle', array('name' => 'Case_sequence', 'custom_group_id' => $pum_case_number['id']));
$type = civicrm_api3('CustomField', 'getsingle', array('name' => 'Case_type', 'custom_group_id' => $pum_case_number['id']));
$country = civicrm_api3('CustomField', 'getsingle', array('name' => 'Case_country', 'custom_group_id' => $pum_case_number['id']));

$view = new view();
$view->name = 'main_activity_information_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_case';
$view->human_name = 'Main activity information (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Main activity information';
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
/* Field: CiviCRM Custom: PUM Case Number: Sequence */
$handler->display->display_options['fields']['sequence']['id'] = 'sequence';
$handler->display->display_options['fields']['sequence']['table'] = $pum_case_number['table_name'];
$handler->display->display_options['fields']['sequence']['field'] = $sequence['column_name'];
$handler->display->display_options['fields']['sequence']['label'] = '';
$handler->display->display_options['fields']['sequence']['exclude'] = TRUE;
$handler->display->display_options['fields']['sequence']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['sequence']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['sequence']['separator'] = '';
/* Field: CiviCRM Custom: PUM Case Number: type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = $pum_case_number['table_name'];
$handler->display->display_options['fields']['type']['field'] = $type['column_name'];
$handler->display->display_options['fields']['type']['label'] = '';
$handler->display->display_options['fields']['type']['exclude'] = TRUE;
$handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['type']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: PUM Case Number: country */
$handler->display->display_options['fields']['country']['id'] = 'country';
$handler->display->display_options['fields']['country']['table'] = $pum_case_number['table_name'];
$handler->display->display_options['fields']['country']['field'] = $country['column_name'];
$handler->display->display_options['fields']['country']['label'] = 'PUM Case number';
$handler->display->display_options['fields']['country']['alter']['alter_text'] = true;
$handler->display->display_options['fields']['country']['alter']['text'] = '[sequence]-[type]-[country]';
$handler->display->display_options['fields']['country']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['country']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['country']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: (Main) Activity information: Activity Start Date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = $main_activity_info['table_name'];
$handler->display->display_options['fields']['start_date']['field'] = $start_date['column_name'];
$handler->display->display_options['fields']['start_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['start_date']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['start_date']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: (Main) Activity information: Activity End Date */
$handler->display->display_options['fields']['end_date']['id'] = 'end_date';
$handler->display->display_options['fields']['end_date']['table'] = $main_activity_info['table_name'];
$handler->display->display_options['fields']['end_date']['field'] = $end_date['column_name'];
$handler->display->display_options['fields']['end_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['end_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['end_date']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['end_date']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: (Main) Activity information: Expected results */
$handler->display->display_options['fields']['expected_results_385']['id'] = 'expected_results_385';
$handler->display->display_options['fields']['expected_results_385']['table'] = $main_activity_info['table_name'];
$handler->display->display_options['fields']['expected_results_385']['field'] = $result['column_name'];
$handler->display->display_options['fields']['expected_results_385']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['expected_results_385']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['expected_results_385']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: (Main) Activity information: Objective of this Activity */
$handler->display->display_options['fields']['objective_of_this_activity_404']['id'] = 'objective_of_this_activity_404';
$handler->display->display_options['fields']['objective_of_this_activity_404']['table'] = $main_activity_info['table_name'];
$handler->display->display_options['fields']['objective_of_this_activity_404']['field'] = $objective['column_name'];
$handler->display->display_options['fields']['objective_of_this_activity_404']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['objective_of_this_activity_404']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['objective_of_this_activity_404']['element_label_type'] = 'strong';
/* Contextual filter: CiviCRM Cases: Case ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_case';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/my-cases/main-activity';
$translatables['main_activity_information_for_expert_'] = array(
  t('Master'),
  t('Main activity information'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Activity Start Date'),
  t('Activity End Date'),
  t('Expected results'),
  t('Objective of this Activity'),
  t('All'),
  t('Page'),
);
