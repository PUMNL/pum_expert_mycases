<?php

$view = new view();
$view->name = 'case_roles_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'Case roles (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Case roles';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'php';
$handler->display->display_options['access']['php_access'] = '$hasrole = FALSE;
$url = $_SERVER["REQUEST_URI"];
$url_path = parse_url($url, PHP_URL_PATH);
$case_id = explode("/",$_GET[\'q\']);

civicrm_initialize();
$contact_id = CRM_Core_Session::singleton()->getLoggedInContactID(); //$session->get(\'userID\');
$civi_config = CRM_Core_Config::singleton();
$civi_dsn = DB::parseDSN($civi_config->dsn);
$civicrm_db = $civi_dsn[\'database\'];

if (!empty($civicrm_db) && !empty($case_id[3])) {
	$relationships = db_query("SELECT case_id, contact_id FROM (
	SELECT rel.case_id AS \'case_id\', rel.contact_id_b AS \'contact_id\' FROM '.$civicrm_db.'.civicrm_case c
	LEFT JOIN '.$civicrm_db.'.civicrm_relationship rel ON c.id = rel.case_id
	LEFT JOIN '.$civicrm_db.'.civicrm_relationship_type rt ON rel.relationship_type_id = rt.id
	LEFT JOIN '.$civicrm_db.'.civicrm_case_contact cc ON cc.case_id = c.id
	WHERE rel.case_id = :case_id OR rel.case_id = (SELECT case_id FROM '.$civicrm_db.'.civicrm_value_travel_parent WHERE entity_id = :case_id) AND rel.is_active = :is_active
	GROUP BY rel.contact_id_b
	UNION ALL
	SELECT ccc.case_id, ccc.contact_id FROM '.$civicrm_db.'.civicrm_case_contact ccc WHERE ccc.case_id = :case_id OR ccc.case_id = (SELECT case_id FROM '.$civicrm_db.'.civicrm_value_travel_parent WHERE entity_id = :case_id) GROUP BY ccc.contact_id
	UNION ALL
	SELECT rel2.case_id AS \'case_id\', rel2.contact_id_b AS \'contact_id\' FROM '.$civicrm_db.'.civicrm_case c2
	LEFT JOIN '.$civicrm_db.'.civicrm_relationship rel2 ON c2.id = rel2.case_id
	LEFT JOIN '.$civicrm_db.'.civicrm_relationship_type rt2 ON rel2.relationship_type_id = rt2.id
	LEFT JOIN '.$civicrm_db.'.civicrm_case_contact cc2 ON cc2.case_id = c2.id
	WHERE rel2.case_id = (SELECT case_id FROM '.$civicrm_db.'.civicrm_value_travel_parent WHERE entity_id = :case_id) AND rel2.is_active = :is_active
) result
GROUP BY contact_id",
array(\':case_id\'=>check_plain($case_id[3]),\':is_active\'=>\'1\'))->fetchAll();

foreach($relationships as $rel) {
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
/* Relationship: CiviCRM Contacts: CiviCRM Relationship (starting from Contact B) */
$handler->display->display_options['relationships']['relationship_id_b']['id'] = 'relationship_id_b';
$handler->display->display_options['relationships']['relationship_id_b']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['relationship_id_b']['field'] = 'relationship_id_b';
$handler->display->display_options['relationships']['relationship_id_b']['label'] = 'relationship';
$handler->display->display_options['relationships']['relationship_id_b']['required'] = TRUE;
//$handler->display->display_options['relationships']['relationship_id_b']['relationship_type'] = '0';
$handler->display->display_options['relationships']['relationship_id_b']['relationship_state'] = 0;
/* Field: CiviCRM Relationships: Relationship Type A-to-B */
$handler->display->display_options['fields']['relationship_type']['id'] = 'relationship_type';
$handler->display->display_options['fields']['relationship_type']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['relationship_type']['field'] = 'relationship_type';
$handler->display->display_options['fields']['relationship_type']['relationship'] = 'relationship_id_b';
$handler->display->display_options['fields']['relationship_type']['label'] = 'Role';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Name';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['label'] = 'E-mail address';
$handler->display->display_options['fields']['email']['location_type'] = '0';
$handler->display->display_options['fields']['email']['location_op'] = '0';
$handler->display->display_options['fields']['email']['is_primary'] = 1;
/* Field: CiviCRM Phone Details: Phone Number */
$handler->display->display_options['fields']['phone']['id'] = 'phone';
$handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone']['field'] = 'phone';
$handler->display->display_options['fields']['phone']['label'] = 'Phone';
$handler->display->display_options['fields']['phone']['location_type'] = '0';
$handler->display->display_options['fields']['phone']['location_op'] = '0';
$handler->display->display_options['fields']['phone']['is_primary'] = 1;
$handler->display->display_options['fields']['phone']['phone_type'] = '0';
/* Contextual filter: CiviCRM Relationships: Case ID */
$handler->display->display_options['arguments']['case_id']['id'] = 'case_id';
$handler->display->display_options['arguments']['case_id']['table'] = 'civicrm_relationship';
$handler->display->display_options['arguments']['case_id']['field'] = 'case_id';
$handler->display->display_options['arguments']['case_id']['relationship'] = 'relationship_id_b';
$handler->display->display_options['arguments']['case_id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['case_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['case_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['case_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['case_id']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/my-cases/case-roles';
$translatables['case_roles_for_expert_'] = array(
    t('Master'),
    t('Case roles'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('relationship'),
    t('Role'),
    t('Name'),
    t('E-mail address'),
    t('Phone'),
    t('All'),
    t('Page'),
);
