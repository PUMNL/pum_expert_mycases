<?php

$bdsa_cg = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'pum_business_dsa'));
$bdsa_table = $bdsa_cg['table_name'];
$bdsa_amount_field = civicrm_api3('CustomField', 'getvalue', array('name' => 'bdsa_amount', 'return' => 'column_name', 'custom_group_id' => $bdsa_cg['id']));
$bdsa_days_field = civicrm_api3('CustomField', 'getvalue', array('name' => 'bdsa_no_of_days', 'return' => 'column_name', 'custom_group_id' => $bdsa_cg['id']));
$bdsa_persons_field = civicrm_api3('CustomField', 'getvalue', array('name' => 'bdsa_no_of_persons', 'return' => 'column_name', 'custom_group_id' => $bdsa_cg['id']));

$view = new view();
$view->name = 'business_dsa_details_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_activity';
$view->human_name = 'Business DSA Details (expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Daily Subsistence Allowances';
$handler->display->display_options['css_class'] = 'pum-list-view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'php';
$handler->display->display_options['access']['php_access'] = '$hasrole = FALSE;
$url = $_SERVER["REQUEST_URI"];
$url_path = parse_url($url, PHP_URL_PATH);
$activity_id = explode("/",$_GET[\'q\']);
civicrm_initialize();
$session = CRM_Core_Session::singleton();
$contact_id = $session->get(\'userID\');
$civi_config = CRM_Core_Config::singleton();
$civi_dsn = DB::parseDSN($civi_config->dsn);
$civicrm_db = $civi_dsn[\'database\'];
$project_relationships = "";

if (!empty($civicrm_db) && !empty($activity_id[3])) {
	$project_relationships = db_query("SELECT c.id AS \'case_id\', rel.contact_id_b AS \'contact_id\', rt.label_b_a AS \'rel_description\' FROM $civicrm_db.civicrm_case_project cp
LEFT JOIN $civicrm_db.civicrm_case c ON cp.case_id = c.id
LEFT JOIN $civicrm_db.civicrm_relationship rel ON c.id = rel.case_id
LEFT JOIN $civicrm_db.civicrm_relationship_type rt ON rel.relationship_type_id = rt.id
LEFT JOIN $civicrm_db.civicrm_case_contact cc ON cc.case_id = c.id
WHERE cp.case_id = (SELECT ca.case_id FROM $civicrm_db.civicrm_case_activity ca WHERE ca.activity_id = :activity_id) AND cp.is_active = :is_active",
array(\':activity_id\'=>check_plain($activity_id[3]),\':is_active\'=>\'1\'))->fetchAll();

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
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: CiviCRM Activities: Activity Type */
$handler->display->display_options['fields']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['fields']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['fields']['activity_type']['exclude'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/expert/dsa" class="button">Go back</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Business DSA: Number of Days */
$handler->display->display_options['fields']['bdsa_no_of_days']['id'] = 'bdsa_no_of_days';
$handler->display->display_options['fields']['bdsa_no_of_days']['table'] = $bdsa_cg['table_name'];
$handler->display->display_options['fields']['bdsa_no_of_days']['field'] = $bdsa_days_field;
$handler->display->display_options['fields']['bdsa_no_of_days']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['bdsa_no_of_days']['separator'] = '';
/* Field: CiviCRM Custom: Business DSA: Number of Persons */
$handler->display->display_options['fields']['bdsa_no_of_persons']['id'] = 'bdsa_no_of_persons';
$handler->display->display_options['fields']['bdsa_no_of_persons']['table'] = $bdsa_cg['table_name'];
$handler->display->display_options['fields']['bdsa_no_of_persons']['field'] = $bdsa_persons_field;
$handler->display->display_options['fields']['bdsa_no_of_persons']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['bdsa_no_of_persons']['separator'] = '';
/* Field: CiviCRM Custom: Business DSA: Amount */
$handler->display->display_options['fields']['bdsa_amount']['id'] = 'bdsa_amount';
$handler->display->display_options['fields']['bdsa_amount']['table'] = $bdsa_cg['table_name'];
$handler->display->display_options['fields']['bdsa_amount']['field'] = $bdsa_amount_field;
$handler->display->display_options['fields']['bdsa_amount']['exclude'] = TRUE;
$handler->display->display_options['fields']['bdsa_amount']['element_label_type'] = 'strong';
/* Field: Signed Amount */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['ui_name'] = 'Signed Amount';
$handler->display->display_options['fields']['php']['label'] = 'Total amount';
$handler->display->display_options['fields']['php']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if ($result[\'values\'][0][\'name\'] == "Business DSA") {
echo $currency." ".$row->bdsa_amount;
} elseif ($result[\'values\'][0][\'name\'] == "Credit Business DSA") {
echo "- ".$currency." ".$row->bdsa_amount;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: CiviCRM Activities: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['label'] = '';
$handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
/* Contextual filter: CiviCRM Activities: Activity ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_activity';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/dsa/business-dsa-details';
$translatables['business_dsa_details_expert_'] = array(
  t('Master'),
  t('Daily Subsistence Allowances'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Activity Type'),
  t('<a href="/expert/dsa" class="button">Go back</a>'),
  t('Number of Days'),
  t('.'),
  t('Number of Persons'),
  t('Amount'),
  t('Total amount'),
  t('All'),
  t('Page'),
);
