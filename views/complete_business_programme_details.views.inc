<?php
$config = pum_expert_mycases_businessconfig::singleton();
$business_programm_data = $config->custom_groups['Business_Programme'];
$company = $config->custom_groups['Business_Programme']['fields']['Naam_bedrijf']['column_name'];
$location = $config->custom_groups['Business_Programme']['fields']['Location']['column_name'];
$from = $config->custom_groups['Business_Programme']['fields']['Visit_from']['column_name'];
$to = $config->custom_groups['Business_Programme']['fields']['Visit_to']['column_name'];
$aim = $config->custom_groups['Business_Programme']['fields']['Aim_of_Visit']['column_name'];
$thank_you_note = $config->custom_groups['Business_Programme']['fields']['Thank_you_Note']['column_name'];
$cancelled = $config->custom_groups['Business_Programme']['fields']['Business_Visit_Cancelled']['column_name'];
$submitted_status = $config->submitted_status['value'];


$view = new view();
$view->name = 'complete_business_programme_details_for_expert';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_activity';
$view->human_name = 'Complete business programme details (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Complete Business Programme Visits List';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['empty'] = TRUE;
$handler->display->display_options['footer']['area']['content'] = '<a href="/expert/complete-business-programme-visits/!1" class="button">Add a visit</a>';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
$handler->display->display_options['footer']['area']['tokenize'] = TRUE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area_1']['id'] = 'area_1';
$handler->display->display_options['footer']['area_1']['table'] = 'views';
$handler->display->display_options['footer']['area_1']['field'] = 'area';
$handler->display->display_options['footer']['area_1']['empty'] = TRUE;
$handler->display->display_options['footer']['area_1']['content'] = '<p>PUM would like to know the results of the Business link you have organised. We will use this information to find out what our overall impact is.</p><p>Please click on edit behind the name of the company you have visited and fill in the requested information. If the visit did not take place, please click on cancelled. In case you have visited more companies than indicated you can add these by clicking on ‘add a visit’.</p><p>We are not only thankful for your input but we also would like to express our gratitude to the hosting companies. We therefore would like to send the hosts a thank you note. Please indicate whether you would like us to do so on your behalf, or if you would rather do this personally yourself (than indicate ‘no’). Please be aware that we register the companies you have visited in our system. We do so to build up a database of potential partners and business link hosts for future business links. The action ‘Complete Business Programme’ will disappear under ‘my work’ when the Business link is totally completed.</p>';
$handler->display->display_options['footer']['area_1']['format'] = 'full_html';
$handler->display->display_options['footer']['area_1']['tokenize'] = TRUE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No programme available. Use add visits to complete the business programme';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Relationship: CiviCRM Case Activity: Case ID */
$handler->display->display_options['relationships']['case_id']['id'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['table'] = 'civicrm_case_activity';
$handler->display->display_options['relationships']['case_id']['field'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['required'] = TRUE;
/* Field: CiviCRM Activities: Activity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Cases: Case ID */
$handler->display->display_options['fields']['id_1']['id'] = 'id_1';
$handler->display->display_options['fields']['id_1']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['id_1']['field'] = 'id';
$handler->display->display_options['fields']['id_1']['relationship'] = 'case_id';
$handler->display->display_options['fields']['id_1']['label'] = '';
$handler->display->display_options['fields']['id_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['id_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id_1']['separator'] = '';
/* Field: CiviCRM Custom: Business Programme: Visit from */
$handler->display->display_options['fields']['visit_from_869']['id'] = 'visit_from_869';
$handler->display->display_options['fields']['visit_from_869']['table'] = $business_programm_data['table_name'];
$handler->display->display_options['fields']['visit_from_869']['label'] = 'Visit from';
$handler->display->display_options['fields']['visit_from_869']['field'] = $from;
$handler->display->display_options['fields']['visit_from_869']['date_format'] = 'custom';
$handler->display->display_options['fields']['visit_from_869']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['visit_from_869']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Business Programme: Visit ot */
$handler->display->display_options['fields']['visit_ot_870']['id'] = 'visit_ot_870';
$handler->display->display_options['fields']['visit_ot_870']['table'] = $business_programm_data['table_name'];
$handler->display->display_options['fields']['visit_ot_870']['field'] = $to;
$handler->display->display_options['fields']['visit_ot_870']['label'] = 'Visit to';
$handler->display->display_options['fields']['visit_ot_870']['date_format'] = 'custom';
$handler->display->display_options['fields']['visit_ot_870']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['visit_ot_870']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Business Programme: Location */
$handler->display->display_options['fields']['company']['id'] = 'company';
$handler->display->display_options['fields']['company']['table'] = $business_programm_data['table_name'];
$handler->display->display_options['fields']['company']['field'] = $company;
$handler->display->display_options['fields']['company']['label'] = 'Company';
$handler->display->display_options['fields']['company']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Business Programme: Location */
$handler->display->display_options['fields']['location_868']['id'] = 'location_868';
$handler->display->display_options['fields']['location_868']['table'] = $business_programm_data['table_name'];
$handler->display->display_options['fields']['location_868']['field'] = $location;
$handler->display->display_options['fields']['location_868']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['location_868']['empty'] = '<em>No location given</em>';
$handler->display->display_options['fields']['location_868']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Business Programme: Short description Aim of Visit */
$handler->display->display_options['fields']['short_description_aim_of_visit_871']['id'] = 'short_description_aim_of_visit_871';
$handler->display->display_options['fields']['short_description_aim_of_visit_871']['table'] = $business_programm_data['table_name'];
$handler->display->display_options['fields']['short_description_aim_of_visit_871']['field'] = $thank_you_note;
$handler->display->display_options['fields']['short_description_aim_of_visit_871']['label'] = 'Send thank you';
$handler->display->display_options['fields']['short_description_aim_of_visit_871']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Activities: Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['label'] = 'Status';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['path'] = 'expert/complete-business-programme-visits/[id_1]/[id]';
$handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Cancelled';
$handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'expert/cancel-business-programme-visits/[id_1]/[id]';
$handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
/* Contextual filter: CiviCRM Cases: Case ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_case';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['relationship'] = 'case_id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Activities: Activity Type */
$handler->display->display_options['filters']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['value'] = array(
  $config->programme_activity_type_id => $config->programme_activity_type_id,
);
/* Filter criterion: CiviCRM Activities: Current Revision */
$handler->display->display_options['filters']['is_current_revision']['id'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['is_current_revision']['field'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['value'] = '1';
/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/complete-business-programmes-details';
$translatables['business_link_program_details'] = array(
  t('Master'),
  t('Business programme'),
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
  t('CiviCRM Case, with custom fields'),
  t('Visit from'),
  t('Visit ot'),
  t('Location'),
  t('Aim of Visit'),
  t('Result of Visit'),
  t('All'),
  t('Page'),
);
