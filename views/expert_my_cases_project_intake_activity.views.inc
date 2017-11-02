<?php

$config = pum_expert_mycases_config::singleton();
$activities = $config->getDoNotIncludeCaseActivityInList();

$view = new view();
$view->name = 'expert_my_cases_project_intake_activities';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_case_activity';
$view->human_name = 'Case activities of project intake (Expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Case activities';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'php';
$handler->display->display_options['access']['php_access'] = '$hasrole = FALSE;
$url = $_SERVER["REQUEST_URI"];
$url_path = parse_url($url, PHP_URL_PATH);
$case_id = explode("/",$_GET[\'q\']);
civicrm_initialize();
$session = CRM_Core_Session::singleton();
$contact_id = $session->get(\'userID\');
$civi_config = CRM_Core_Config::singleton();
$civi_dsn = DB::parseDSN($civi_config->dsn);
$civicrm_db = $civi_dsn[\'database\'];

if (!empty($civicrm_db) && !empty($case_id[3])) {
	$project_relationships = db_query("SELECT c.id AS \'case_id\', rel.contact_id_b AS \'contact_id\', rt.label_b_a AS \'rel_description\' FROM $civicrm_db.civicrm_case_project cp
LEFT JOIN $civicrm_db.civicrm_case c ON cp.case_id = c.id
LEFT JOIN $civicrm_db.civicrm_relationship rel ON c.id = rel.case_id
LEFT JOIN $civicrm_db.civicrm_relationship_type rt ON rel.relationship_type_id = rt.id
LEFT JOIN $civicrm_db.civicrm_case_contact cc ON cc.case_id = c.id
WHERE cp.project_id = (SELECT ccp.project_id FROM $civicrm_db.civicrm_case_project ccp WHERE ccp.case_id = :case_id) AND cp.is_active = :is_active AND c.is_deleted = :is_deleted",
array(\':case_id\'=>check_plain($case_id[3]),\':is_active\'=>\'1\',\':is_deleted\'=>\'0\'))->fetchAll();

foreach($project_relationships as $rel) {
	if ($rel->contact_id == $contact_id) {
		$hasrole = TRUE;
	}
}
}
return $hasrole;';
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
/* header: Global: PHP */
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
/* header: Global: PHP */
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
$handler->display->display_options['fields']['activity_date_time']['date_format'] = 'short';
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
$handler->display->display_options['fields']['subject']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['subject']['alter']['path'] = 'expert/my-cases/activitiy-detail/[id]';
$handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['subject']['empty'] = '<a href="/expert/my-cases/activitiy-detail/[id]">No subject</a>';
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
$handler->display->display_options['path'] = 'expert/my-cases/projectintake';
$translatables['expert_my_cases_activities'] = array(
    t('Master'),
    t('Contact with customer'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Activity'),
    t('Reporter'),
    t('[display_name] ([activity_date_time])'),
    t('All'),
    t('Page'),
);
