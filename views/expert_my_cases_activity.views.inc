<?php

$config = pum_expert_mycases_config::singleton();
$activities = $config->getDoNotIncludeCaseActivityInList();

$view = new view();
$view->name = 'expert_my_cases_activities';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_case_activity';
$view->human_name = 'Case activities (Expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Case activities';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert','Representative'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
    'activity_date_time' => 'activity_date_time',
    'subject' => 'subject',
    'details' => 'details',
    'status' => 'status',
);
$handler->display->display_options['style_options']['default'] = 'activity_date_time';
$handler->display->display_options['style_options']['info'] = array(
    'activity_date_time' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'subject' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'details' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'status' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area_ma']['id'] = 'area_ma';
$handler->display->display_options['header']['area_ma']['table'] = 'views';
$handler->display->display_options['header']['area_ma']['field'] = 'area';
$handler->display->display_options['header']['area_ma']['empty'] = TRUE;
$handler->display->display_options['header']['area_ma']['content'] = '<h2>Main activity info</h2>';
$handler->display->display_options['header']['area_ma']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['ma_view']['id'] = 'ma_view';
$handler->display->display_options['header']['ma_view']['table'] = 'views';
$handler->display->display_options['header']['ma_view']['field'] = 'view';
$handler->display->display_options['header']['ma_view']['label'] = 'Main activity info';
$handler->display->display_options['header']['ma_view']['empty'] = TRUE;
$handler->display->display_options['header']['ma_view']['view_to_insert'] = 'main_activity_information_for_expert_:default';
$handler->display->display_options['header']['ma_view']['inherit_arguments'] = TRUE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area_1']['id'] = 'area_1';
$handler->display->display_options['header']['area_1']['table'] = 'views';
$handler->display->display_options['header']['area_1']['field'] = 'area';
$handler->display->display_options['header']['area_1']['empty'] = TRUE;
$handler->display->display_options['header']['area_1']['content'] = '<h2>Documents</h2>';
$handler->display->display_options['header']['area_1']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['view']['id'] = 'view';
$handler->display->display_options['header']['view']['table'] = 'views';
$handler->display->display_options['header']['view']['field'] = 'view';
$handler->display->display_options['header']['view']['label'] = 'Documents';
$handler->display->display_options['header']['view']['empty'] = TRUE;
$handler->display->display_options['header']['view']['view_to_insert'] = 'expert_my_case_documents:default';
$handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area_3']['id'] = 'area_3';
$handler->display->display_options['header']['area_3']['table'] = 'views';
$handler->display->display_options['header']['area_3']['field'] = 'area';
$handler->display->display_options['header']['area_3']['empty'] = TRUE;
$handler->display->display_options['header']['area_3']['content'] = '<h2>Conditions</h2>';
$handler->display->display_options['header']['area_3']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['view_2']['id'] = 'view_2';
$handler->display->display_options['header']['view_2']['table'] = 'views';
$handler->display->display_options['header']['view_2']['field'] = 'view';
$handler->display->display_options['header']['view_2']['label'] = 'Documents';
$handler->display->display_options['header']['view_2']['empty'] = TRUE;
$handler->display->display_options['header']['view_2']['view_to_insert'] = 'expert_my_cases_conditions:default';
$handler->display->display_options['header']['view_2']['inherit_arguments'] = TRUE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area_4']['id'] = 'area_4';
$handler->display->display_options['header']['area_4']['table'] = 'views';
$handler->display->display_options['header']['area_4']['field'] = 'area';
$handler->display->display_options['header']['area_4']['empty'] = TRUE;
$handler->display->display_options['header']['area_4']['content'] = '<h2>Roles</h2>';
$handler->display->display_options['header']['area_4']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['view_3']['id'] = 'view_3';
$handler->display->display_options['header']['view_3']['table'] = 'views';
$handler->display->display_options['header']['view_3']['field'] = 'view';
$handler->display->display_options['header']['view_3']['label'] = 'Documents';
$handler->display->display_options['header']['view_3']['empty'] = TRUE;
$handler->display->display_options['header']['view_3']['view_to_insert'] = 'case_roles_for_expert_:default';
$handler->display->display_options['header']['view_3']['inherit_arguments'] = TRUE;
/* Header: Global: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['label'] = 'Summary';
$handler->display->display_options['header']['php']['php_output'] = '<?php
$summary = pum_expert_mycases_get_mainactivity_summary($view->args[0]);
if (!empty($summary)) {
echo \'<h3>Summary</h3>\';
echo \'<p>\'.nl2br($summary).\'</p>\';
}
?>';
/* Header: Global: PHP */
$handler->display->display_options['header']['php_1']['id'] = 'php_1';
$handler->display->display_options['header']['php_1']['table'] = 'views';
$handler->display->display_options['header']['php_1']['field'] = 'php';
$handler->display->display_options['header']['php_1']['label'] = 'Follow up activities';
$handler->display->display_options['header']['php_1']['php_output'] = '<?php
$follow_up = pum_expert_mycases_get_mainactivity_follow_up($view->args[0]);
if (!empty($follow_up)) {
echo \'<h3>Follow up activities</h3>\';
echo \'<p>\'.nl2br($follow_up).\'</p>\';
}
?>';
/* Header: Global: Text area */
$handler->display->display_options['header']['area_5']['id'] = 'area_5';
$handler->display->display_options['header']['area_5']['table'] = 'views';
$handler->display->display_options['header']['area_5']['field'] = 'area';
$handler->display->display_options['header']['area_5']['empty'] = TRUE;
$handler->display->display_options['header']['area_5']['content'] = '<h2>Activities</h2>';
$handler->display->display_options['header']['area_5']['format'] = 'full_html';
/* Header: Global: PHP */
$handler->display->display_options['header']['php_2']['id'] = 'php_2';
$handler->display->display_options['header']['php_2']['table'] = 'views';
$handler->display->display_options['header']['php_2']['field'] = 'php';
$handler->display->display_options['header']['php_2']['empty'] = TRUE;
$handler->display->display_options['header']['php_2']['php_output'] = '<?php
$case_id = reset($view->args);
if (_pum_expert_has_user_role_on_case($case_id))
{
?>
<a href="/expert/my-cases/new-contact-with-customer/<?php echo $case_id ?>?destination=/expert/my-cases/activities/<?php echo $case_id ?>" class="button">Add summary of contact with customer</a>
<?php
}
?>';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no activities for this case';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Relationship: CiviCRM Case Activity: Case Activity's Activity ID */
$handler->display->display_options['relationships']['activity_id']['id'] = 'activity_id';
$handler->display->display_options['relationships']['activity_id']['table'] = 'civicrm_case_activity';
$handler->display->display_options['relationships']['activity_id']['field'] = 'activity_id';
$handler->display->display_options['relationships']['activity_id']['label'] = 'Activity';
$handler->display->display_options['relationships']['activity_id']['required'] = TRUE;
/* Field: CiviCRM Activities: Activity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Date';
$handler->display->display_options['fields']['activity_date_time']['alter']['text'] = '[display_name] ([activity_date_time])';
$handler->display->display_options['fields']['activity_date_time']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['activity_date_time']['date_format'] = 'custom';
$handler->display->display_options['fields']['activity_date_time']['custom_date_format'] = 'd M Y';
$handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'short';
/* Field: CiviCRM Activities: Activity Type */
$handler->display->display_options['fields']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['fields']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['fields']['activity_type']['relationship'] = 'activity_id';
/* Field: CiviCRM Activities: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['subject']['empty'] = 'No subject';
/* Field: Global: View */
$handler->display->display_options['fields']['view']['id'] = 'view';
$handler->display->display_options['fields']['view']['table'] = 'views';
$handler->display->display_options['fields']['view']['field'] = 'view';
$handler->display->display_options['fields']['view']['label'] = 'With';
$handler->display->display_options['fields']['view']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['view']['view'] = 'activity_contacts_expert_';
$handler->display->display_options['fields']['view']['arguments'] = '3/[!id]';
/* Field: Global: View */
$handler->display->display_options['fields']['view_1']['id'] = 'view_1';
$handler->display->display_options['fields']['view_1']['table'] = 'views';
$handler->display->display_options['fields']['view_1']['field'] = 'view';
$handler->display->display_options['fields']['view_1']['label'] = 'Assigned to';
$handler->display->display_options['fields']['view_1']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['view_1']['view'] = 'activity_contacts_expert_';
$handler->display->display_options['fields']['view_1']['arguments'] = '1/[!id]';
/* Field: Global: View */
$handler->display->display_options['fields']['view_2']['id'] = 'view_2';
$handler->display->display_options['fields']['view_2']['table'] = 'views';
$handler->display->display_options['fields']['view_2']['field'] = 'view';
$handler->display->display_options['fields']['view_2']['label'] = 'Reported by';
$handler->display->display_options['fields']['view_2']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['view_2']['view'] = 'activity_contacts_expert_';
$handler->display->display_options['fields']['view_2']['arguments'] = '2/[!id]';
/* Field: CiviCRM Activities: Activity Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['status']['label'] = 'Status';
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = '';
$handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['text'] = 'View details';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[php]';
$handler->display->display_options['fields']['php']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_value'] = '$destination = "/expert/my-cases/activities/" . $view->args[0];
   return _pum_expert_show_activity_details($row->id, $row->activity_type, $destination);';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Sort criterion: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['sorts']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['sorts']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['relationship'] = 'activity_id';
$handler->display->display_options['sorts']['activity_date_time']['order'] = 'DESC';
/* Contextual filter: CiviCRM Cases: Case ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_case';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['id']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['id']['validate']['type'] = 'php';
$handler->display->display_options['arguments']['id']['validate_options']['code'] = 'return _pum_expert_mycases_user_has_role_on_case_project($handler->argument);';
$handler->display->display_options['arguments']['id']['validate']['fail'] = 'access denied';
/* Filter criterion: CiviCRM Activities: Activity Type */
$handler->display->display_options['filters']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['relationship'] = 'activity_id';
$handler->display->display_options['filters']['activity_type']['operator'] = 'not in';
$handler->display->display_options['filters']['activity_type']['value'] = $activities;
/* Filter criterion: CiviCRM Activities: Current Revision */
$handler->display->display_options['filters']['is_current_revision']['id'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['is_current_revision']['field'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['relationship'] = 'activity_id';
$handler->display->display_options['filters']['is_current_revision']['value'] = '1';
/* Filter criterion: CiviCRM Activities: Is Deleted */
$handler->display->display_options['filters']['is_deleted']['id'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['is_deleted']['field'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['relationship'] = 'activity_id';
$handler->display->display_options['filters']['is_deleted']['value'] = '0';
/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/my-cases/activities';
$translatables['expert_my_cases_activities'] = array(
	t('Master'),
  t('Case activities'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<h2>Main activity info</h2>'),
  t('Main activity info'),
  t('<h2>Documents</h2>'),
  t('Documents'),
  t('<h2>Conditions</h2>'),
  t('<h2>Roles</h2>'),
  t('Summary'),
  t('Follow up activities'),
  t('<h2>Activities</h2>'),
  t('There are no activities for this case'),
  t('Activity'),
  t('.'),
  t('Date'),
  t('[display_name] ([activity_date_time])'),
  t('Activity Type'),
  t('Subject'),
  t('No subject'),
  t('With'),
  t('Assigned to'),
  t('Reported by'),
  t('Status'),
  t('View details'),
  t('All'),
  t('Page'),
);
