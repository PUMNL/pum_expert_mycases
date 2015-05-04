<?php

$view = new view();
$view->name = 'customer_info_projects_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_project';
$view->human_name = 'Projects (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Projects';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'title' => 'title',
  'start_date' => 'start_date',
  'end_date' => 'end_date',
  'reason' => 'reason',
  'expected_results' => 'expected_results',
);
$handler->display->display_options['style_options']['default'] = 'start_date';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'start_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'end_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'reason' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'expected_results' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: CiviCRM Project: Customer */
$handler->display->display_options['relationships']['customer_id']['id'] = 'customer_id';
$handler->display->display_options['relationships']['customer_id']['table'] = 'civicrm_project';
$handler->display->display_options['relationships']['customer_id']['field'] = 'customer_id';
$handler->display->display_options['relationships']['customer_id']['required'] = TRUE;
/* Field: CiviCRM Project: Project ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Project: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = 'expert/project/[id]';
$handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['title']['empty'] = 'No title';
/* Field: CiviCRM Project: Start date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['start_date']['custom_date_format'] = 'd-m-Y';
$handler->display->display_options['fields']['start_date']['second_date_format'] = 'long';
/* Field: CiviCRM Project: End date */
$handler->display->display_options['fields']['end_date']['id'] = 'end_date';
$handler->display->display_options['fields']['end_date']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['end_date']['field'] = 'end_date';
$handler->display->display_options['fields']['end_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['end_date']['custom_date_format'] = 'd-m-Y';
$handler->display->display_options['fields']['end_date']['second_date_format'] = 'long';
/* Field: CiviCRM Project: Reason */
$handler->display->display_options['fields']['reason']['id'] = 'reason';
$handler->display->display_options['fields']['reason']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['reason']['field'] = 'reason';
/* Field: CiviCRM Project: Expected results */
$handler->display->display_options['fields']['expected_results']['id'] = 'expected_results';
$handler->display->display_options['fields']['expected_results']['table'] = 'civicrm_project';
$handler->display->display_options['fields']['expected_results']['field'] = 'expected_results';
/* Contextual filter: CiviCRM Contacts: Contact ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['relationship'] = 'customer_id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Project: Is active */
$handler->display->display_options['filters']['is_active']['id'] = 'is_active';
$handler->display->display_options['filters']['is_active']['table'] = 'civicrm_project';
$handler->display->display_options['filters']['is_active']['field'] = 'is_active';
$handler->display->display_options['filters']['is_active']['value'] = '1';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/customer/projects';
$translatables['projects'] = array(
  t('Master'),
  t('Projects'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('CiviCRM Contact, with custom fields'),
  t('Project ID'),
  t('.'),
  t('Title'),
  t('Start date'),
  t('End date'),
  t('Reason'),
  t('Expected results'),
  t('All'),
  t('Page'),
);
