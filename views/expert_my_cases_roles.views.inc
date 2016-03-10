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
$handler->display->display_options['access']['type'] = 'none';
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
