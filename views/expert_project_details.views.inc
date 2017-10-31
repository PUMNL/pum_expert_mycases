<?php

$view = new view();
$view->name = 'project_details_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_project';
$view->human_name = 'Project details (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Project details';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['css_class'] = 'pum-grid-view';
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: CiviCRM Project: Project ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Project: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: CiviCRM Project: Start date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['start_date']['custom_date_format'] = 'j F Y';
$handler->display->display_options['fields']['start_date']['second_date_format'] = 'long';
/* Field: CiviCRM Project: End date */
$handler->display->display_options['fields']['end_date']['id'] = 'end_date';
$handler->display->display_options['fields']['end_date']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['end_date']['field'] = 'end_date';
$handler->display->display_options['fields']['end_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['end_date']['custom_date_format'] = 'j F Y';
$handler->display->display_options['fields']['end_date']['second_date_format'] = 'long';
/* Field: CiviCRM Project: Reason */
$handler->display->display_options['fields']['reason']['id'] = 'reason';
$handler->display->display_options['fields']['reason']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['reason']['field'] = 'reason';
$handler->display->display_options['fields']['reason']['element_label_type'] = 'h3';
/* Field: CiviCRM Project: Work description */
$handler->display->display_options['fields']['work_description']['id'] = 'work_description';
$handler->display->display_options['fields']['work_description']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['work_description']['field'] = 'work_description';
$handler->display->display_options['fields']['work_description']['element_label_type'] = 'h3';
/* Field: CiviCRM Project: Project plan */
$handler->display->display_options['fields']['projectplan']['id'] = 'projectplan';
$handler->display->display_options['fields']['projectplan']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['projectplan']['field'] = 'projectplan';
$handler->display->display_options['fields']['projectplan']['element_label_type'] = 'h3';
/* Field: CiviCRM Project: Qualifications */
$handler->display->display_options['fields']['qualifications']['id'] = 'qualifications';
$handler->display->display_options['fields']['qualifications']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['qualifications']['field'] = 'qualifications';
$handler->display->display_options['fields']['qualifications']['element_label_type'] = 'h3';
/* Field: CiviCRM Project: Expected results */
$handler->display->display_options['fields']['expected_results']['id'] = 'expected_results';
$handler->display->display_options['fields']['expected_results']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['expected_results']['field'] = 'expected_results';
$handler->display->display_options['fields']['expected_results']['element_label_type'] = 'h3';
/* Field: Global: View */
$handler->display->display_options['fields']['rep_assesment']['id'] = 'rep_assesment';
$handler->display->display_options['fields']['rep_assesment']['table'] = 'views';
$handler->display->display_options['fields']['rep_assesment']['field'] = 'view';
$handler->display->display_options['fields']['rep_assesment']['label'] = 'Assesment by representative';
$handler->display->display_options['fields']['rep_assesment']['element_label_type'] = 'h3';
$handler->display->display_options['fields']['rep_assesment']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['rep_assesment']['view'] = 'assesment_rep_for_expert_';
$handler->display->display_options['fields']['rep_assesment']['arguments'] = '!1';
/* Field: Global: View */
$handler->display->display_options['fields']['cases']['id'] = 'cases';
$handler->display->display_options['fields']['cases']['table'] = 'views';
$handler->display->display_options['fields']['cases']['field'] = 'view';
$handler->display->display_options['fields']['cases']['label'] = 'Cases';
$handler->display->display_options['fields']['cases']['element_label_type'] = 'h3';
$handler->display->display_options['fields']['cases']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cases']['view'] = 'project_cases_for_expert_';
$handler->display->display_options['fields']['cases']['arguments'] = '!1';
/* Contextual filter: CiviCRM Project: Project ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_project';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/project';
$translatables['project_details_for_expert_'] = array(
  t('Master'),
  t('Project details'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('.'),
  t('Start date'),
  t('End date'),
  t('Reason'),
  t('Work description'),
  t('Project plan'),
  t('Qualifications'),
  t('Expected results'),
  t('Assesment by representative'),
  t('Cases'),
  t('All'),
  t('Page'),
);
