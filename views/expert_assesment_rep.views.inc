<?php

$intake =civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Intake'));
$intake_gid = $intake['id'];
$intake_table = $intake['table_name'];

$assesment_rep =civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Assessment_Project_Request_by_Rep'));
$gid = $assesment_rep['id'];
$table = $assesment_rep['table_name'];

$view = new view();
$view->name = 'assesment_rep_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_case_project';
$view->human_name = 'Assesment Rep (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Representative Assement';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'php';
$handler->display->display_options['access']['php_access'] = '$hasrole = FALSE;
$url = $_SERVER["REQUEST_URI"];
$url_path = parse_url($url, PHP_URL_PATH);
$project_id = explode("/",$_GET[\'q\']);

civicrm_initialize();
$session = CRM_Core_Session::singleton();
$contact_id = $session->get(\'userID\');
$civi_config = CRM_Core_Config::singleton();
$civi_dsn = DB::parseDSN($civi_config->dsn);
$civicrm_db = $civi_dsn[\'database\'];

if (!empty($civicrm_db) && !empty($project_id[2])) {
	$project_relationships = db_query("SELECT c.id AS \'case_id\', rel.contact_id_b AS \'contact_id\', rt.label_b_a AS \'rel_description\' FROM $civicrm_db.civicrm_case_project cp
LEFT JOIN $civicrm_db.civicrm_case c ON cp.case_id = c.id
LEFT JOIN $civicrm_db.civicrm_relationship rel ON c.id = rel.case_id
LEFT JOIN $civicrm_db.civicrm_relationship_type rt ON rel.relationship_type_id = rt.id
LEFT JOIN $civicrm_db.civicrm_case_contact cc ON cc.case_id = c.id
WHERE cp.project_id = :project_id AND cp.is_active = :is_active",
array(\':project_id\'=>check_plain($project_id[2]),\':is_active\'=>\'1\'))->fetchAll();

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
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: CiviCRM Case Project: Case ID */
$handler->display->display_options['relationships']['case_id']['id'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['table'] = 'civicrm_case_project';
$handler->display->display_options['relationships']['case_id']['field'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Project: Project ID */
$handler->display->display_options['relationships']['project_id']['id'] = 'project_id';
$handler->display->display_options['relationships']['project_id']['table'] = 'civicrm_case_project';
$handler->display->display_options['relationships']['project_id']['field'] = 'project_id';
$handler->display->display_options['relationships']['project_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Activity: Case Activity's Activity ID */
$handler->display->display_options['relationships']['activity_id']['id'] = 'activity_id';
$handler->display->display_options['relationships']['activity_id']['table'] = 'civicrm_case_activity';
$handler->display->display_options['relationships']['activity_id']['field'] = 'activity_id';
$handler->display->display_options['relationships']['activity_id']['relationship'] = 'case_id';
$handler->display->display_options['relationships']['activity_id']['required'] = TRUE;
/* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_activity_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['relationship'] = 'activity_id';
$handler->display->display_options['relationships']['contact_id']['label'] = 'Reported by';
$handler->display->display_options['relationships']['contact_id']['record_type'] = '2';
/* Field: CiviCRM Activities: Activity Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['status']['label'] = '';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['display_name']['label'] = '';
$handler->display->display_options['fields']['display_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Activities: Details */
$handler->display->display_options['fields']['details_1']['id'] = 'details_1';
$handler->display->display_options['fields']['details_1']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['details_1']['field'] = 'details';
$handler->display->display_options['fields']['details_1']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['details_1']['label'] = 'Submitted assesment';
$handler->display->display_options['fields']['details_1']['element_label_type'] = 'h4';
$handler->display->display_options['fields']['details_1']['text_format'] = 'full_html';
/* Sort criterion: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['sorts']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['sorts']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['relationship'] = 'activity_id';
$handler->display->display_options['sorts']['activity_date_time']['order'] = 'DESC';
/* Contextual filter: CiviCRM Project: Project ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_project';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['relationship'] = 'project_id';
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
$handler->display->display_options['filters']['activity_type']['value'] = array(
73 => '73',
);
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
$handler->display->display_options['path'] = 'expert/project-rep-assesment';
$translatables['assesment_rep_for_expert_'] = array(
  t('Master'),
  t('Representative Assement'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('CiviCRM Case'),
  t('CiviCRM Project'),
  t('CiviCRM Activity, with custom fields'),
  t('Reported by'),
  t('Submitted assesment'),
  t('All'),
  t('Page'),
);
