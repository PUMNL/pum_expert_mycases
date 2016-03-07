<?php

$custom_group = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Customers_Data'));
$table = $custom_group['table_name'];
$gid = $custom_group['id'];


$view = new view();
$view->name = 'customer_data_additional_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'Customer data additional (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Customer data';
$handler->display->display_options['css_class'] = 'pum-list-view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Custom: Customer Data: How_did_your_company_first_hear_about_CBI_PUM_ */
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['id'] = 'How_did_your_company_first_hear_about_CBI_PUM_';
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['table'] = $table;
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'How_did_your_company_first_hear_about_CBI_PUM_'));
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['label'] = 'How did your company first hear about PUM?';
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['How_did_your_company_first_hear_about_CBI_PUM_']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Additional_comments_Projectrequest */
$handler->display->display_options['fields']['Additional_comments_Projectrequest']['id'] = 'Additional_comments_Projectrequest';
$handler->display->display_options['fields']['Additional_comments_Projectrequest']['table'] = $table;
$handler->display->display_options['fields']['Additional_comments_Projectrequest']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Additional_comments_Projectrequest'));
$handler->display->display_options['fields']['Additional_comments_Projectrequest']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['Additional_comments_Projectrequest']['alter']['strip_tags'] = TRUE;
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
$handler->display->display_options['path'] = 'expert/customer/customer-data-additional';
$translatables['customer_data_for_expert_'] = array(
  t('Master'),
  t('Customer data'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('.'),
  t('What is the operational model of the organisation'),
  t('Products and/or Services offered'),
  t('Where and how are the products or services sold'),
  t('In which year did your organisation started operations?'),
  t(','),
  t('Legal form of the Organisation'),
  t('Other Legal Form'),
  t('Is your company part of a holding/group of companies?'),
  t('Please list the following details for the entire holding'),
  t('Does your company work under a franchising contract?'),
  t('Please explain your relationship with the franchiseholder'),
  t('Is there foreign ownership?'),
  t('Percentage of Foreign Ownership'),
  t('Please list information of foreign owners'),
  t('Percentage of Ownership - Private'),
  t('Percentage of Ownership - Government'),
  t('Percentage of Ownership - Other'),
  t('All'),
  t('Page'),
);
