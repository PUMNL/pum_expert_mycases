<?php

$custom_group = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Employee_Information'));
$table = $custom_group['table_name'];
$gid = $custom_group['id'];

$view = new view();
$view->name = 'yearly_information_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'Yearly information (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Yearly information';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Custom: Yearly Information: Year */
$handler->display->display_options['fields']['year_371']['id'] = 'year_371';
$handler->display->display_options['fields']['year_371']['table'] = $table;
$handler->display->display_options['fields']['year_371']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Year'));
$handler->display->display_options['fields']['year_371']['separator'] = '';
/* Field: CiviCRM Custom: Yearly Information: Full-time employees */
$handler->display->display_options['fields']['full_time_employees_372']['id'] = 'full_time_employees_372';
$handler->display->display_options['fields']['full_time_employees_372']['table'] = $table;
$handler->display->display_options['fields']['full_time_employees_372']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Full_time_employees'));
/* Field: CiviCRM Custom: Yearly Information: Part-time employees */
$handler->display->display_options['fields']['part_time_employees_373']['id'] = 'part_time_employees_373';
$handler->display->display_options['fields']['part_time_employees_373']['table'] = $table;
$handler->display->display_options['fields']['part_time_employees_373']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Part_time_employees'));
/* Field: CiviCRM Custom: Yearly Information: Total turnover */
$handler->display->display_options['fields']['total_turnover_374']['id'] = 'total_turnover_374';
$handler->display->display_options['fields']['total_turnover_374']['table'] = $table;
$handler->display->display_options['fields']['total_turnover_374']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Total_turnover'));
/* Field: CiviCRM Custom: Yearly Information: Balance sheet total */
$handler->display->display_options['fields']['balance_sheet_total_375']['id'] = 'balance_sheet_total_375';
$handler->display->display_options['fields']['balance_sheet_total_375']['table'] = $table;
$handler->display->display_options['fields']['balance_sheet_total_375']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Balance_sheet_total'));
/* Sort criterion: CiviCRM Custom: Yearly Information: Year */
$handler->display->display_options['sorts']['year_371']['id'] = 'year_371';
$handler->display->display_options['sorts']['year_371']['table'] = $table;
$handler->display->display_options['sorts']['year_371']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Year'));
$handler->display->display_options['sorts']['year_371']['order'] = 'DESC';
/* Contextual filter: CiviCRM Contacts: Contact ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/customer/yearly-information';
$translatables['yearly_information_for_expert_'] = array(
  t('Master'),
  t('Yearly information'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('.'),
  t('Year'),
  t('Full-time employees'),
  t(','),
  t('Part-time employees'),
  t('Total turnover'),
  t('Balance sheet total'),
  t('All'),
  t('Page'),
);
