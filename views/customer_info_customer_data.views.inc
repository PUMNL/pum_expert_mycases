<?php

$custom_group = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Customers_Data'));
$table = $custom_group['table_name'];
$gid = $custom_group['id'];


$view = new view();
$view->name = 'customer_data_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'Customer data (for expert)';
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
/* Field: CiviCRM Custom: Customer Data: What is the operational model of the organisation */
$handler->display->display_options['fields']['what_is_the_operational_model_of_105']['id'] = 'what_is_the_operational_model_of_105';
$handler->display->display_options['fields']['what_is_the_operational_model_of_105']['table'] = $table;
$handler->display->display_options['fields']['what_is_the_operational_model_of_105']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'What_is_the_operational_model_of_the_organisation'));
$handler->display->display_options['fields']['what_is_the_operational_model_of_105']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['what_is_the_operational_model_of_105']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Products and/or Services offered */
$handler->display->display_options['fields']['products_and_or_services_offered_87']['id'] = 'products_and_or_services_offered_87';
$handler->display->display_options['fields']['products_and_or_services_offered_87']['table'] = $table;
$handler->display->display_options['fields']['products_and_or_services_offered_87']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Products_and_or_Services_offered'));
$handler->display->display_options['fields']['products_and_or_services_offered_87']['label'] = 'What are the products and/or services offered?';
$handler->display->display_options['fields']['products_and_or_services_offered_87']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['products_and_or_services_offered_87']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['products_and_or_services_offered_87']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['products_and_or_services_offered_87']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Products and/or Services sold */
$handler->display->display_options['fields']['products_and_or_services_sold_87']['id'] = 'products_and_or_services_sold_87';
$handler->display->display_options['fields']['products_and_or_services_sold_87']['table'] = $table;
$handler->display->display_options['fields']['products_and_or_services_sold_87']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Products_and_or_Services_sold'));
$handler->display->display_options['fields']['products_and_or_services_sold_87']['label'] = 'Where and how are the products and/or services sold?';
$handler->display->display_options['fields']['products_and_or_services_sold_87']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['products_and_or_services_sold_87']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['products_and_or_services_sold_87']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['products_and_or_services_sold_87']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: In which year did your organisation started operations? */
$handler->display->display_options['fields']['in_which_year_did_your_organisat_96']['id'] = 'in_which_year_did_your_organisat_96';
$handler->display->display_options['fields']['in_which_year_did_your_organisat_96']['table'] = $table;
$handler->display->display_options['fields']['in_which_year_did_your_organisat_96']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'In_which_year_was_your_organisation_founded_'));
$handler->display->display_options['fields']['in_which_year_did_your_organisat_96']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['in_which_year_did_your_organisat_96']['empty_zero'] = TRUE;
$handler->display->display_options['fields']['in_which_year_did_your_organisat_96']['separator'] = '';
/* Field: CiviCRM Custom: Customer Data: Legal form of the Organisation */
$handler->display->display_options['fields']['legal_form_of_the_organisation_82']['id'] = 'legal_form_of_the_organisation_82';
$handler->display->display_options['fields']['legal_form_of_the_organisation_82']['table'] = $table;
$handler->display->display_options['fields']['legal_form_of_the_organisation_82']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Legal_form_of_the_Organisation'));
$handler->display->display_options['fields']['legal_form_of_the_organisation_82']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['legal_form_of_the_organisation_82']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Other Legal Form */
$handler->display->display_options['fields']['other_legal_form_103']['id'] = 'other_legal_form_103';
$handler->display->display_options['fields']['other_legal_form_103']['table'] = $table;
$handler->display->display_options['fields']['other_legal_form_103']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Other_Legal_Form'));
$handler->display->display_options['fields']['other_legal_form_103']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['other_legal_form_103']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['other_legal_form_103']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['other_legal_form_103']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Is your company part of a holding/group of companies? */
$handler->display->display_options['fields']['is_your_company_part_of_a_holdin_97']['id'] = 'is_your_company_part_of_a_holdin_97';
$handler->display->display_options['fields']['is_your_company_part_of_a_holdin_97']['table'] = $table;
$handler->display->display_options['fields']['is_your_company_part_of_a_holdin_97']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Is_your_company_part_of_a_holding_group_of_companies_'));
$handler->display->display_options['fields']['is_your_company_part_of_a_holdin_97']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['is_your_company_part_of_a_holdin_97']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Please list the following details for the entire holding */
$handler->display->display_options['fields']['please_list_the_following_detail_98']['id'] = 'please_list_the_following_detail_98';
$handler->display->display_options['fields']['please_list_the_following_detail_98']['table'] = $table;
$handler->display->display_options['fields']['please_list_the_following_detail_98']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Please_list_the_following_details_for_the_entire_holding'));
$handler->display->display_options['fields']['please_list_the_following_detail_98']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['please_list_the_following_detail_98']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['please_list_the_following_detail_98']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['please_list_the_following_detail_98']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Does your company work under a franchising contract? */
$handler->display->display_options['fields']['does_your_company_work_under_a_f_99']['id'] = 'does_your_company_work_under_a_f_99';
$handler->display->display_options['fields']['does_your_company_work_under_a_f_99']['table'] = $table;
$handler->display->display_options['fields']['does_your_company_work_under_a_f_99']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Does_your_company_work_under_a_franchising_contract_'));
$handler->display->display_options['fields']['does_your_company_work_under_a_f_99']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['does_your_company_work_under_a_f_99']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Please explain your relationship with the franchiseholder */
$handler->display->display_options['fields']['please_explain_your_relationship_100']['id'] = 'please_explain_your_relationship_100';
$handler->display->display_options['fields']['please_explain_your_relationship_100']['table'] = $table;
$handler->display->display_options['fields']['please_explain_your_relationship_100']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Please_explain_your_relationship_with_the_franchiseholder'));
$handler->display->display_options['fields']['please_explain_your_relationship_100']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['please_explain_your_relationship_100']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['please_explain_your_relationship_100']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['please_explain_your_relationship_100']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Is there foreign ownership? */
$handler->display->display_options['fields']['is_there_foreign_ownership__101']['id'] = 'is_there_foreign_ownership__101';
$handler->display->display_options['fields']['is_there_foreign_ownership__101']['table'] = $table;
$handler->display->display_options['fields']['is_there_foreign_ownership__101']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Is_there_foreign_ownership_'));
$handler->display->display_options['fields']['is_there_foreign_ownership__101']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['is_there_foreign_ownership__101']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Percentage of Foreign Ownership */
$handler->display->display_options['fields']['percentage_of_foreign_ownership_83']['id'] = 'percentage_of_foreign_ownership_83';
$handler->display->display_options['fields']['percentage_of_foreign_ownership_83']['table'] = $table;
$handler->display->display_options['fields']['percentage_of_foreign_ownership_83']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Percentage_of_Foreign_Ownership'));
$handler->display->display_options['fields']['percentage_of_foreign_ownership_83']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['percentage_of_foreign_ownership_83']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['percentage_of_foreign_ownership_83']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['percentage_of_foreign_ownership_83']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Please list information of foreign owners */
$handler->display->display_options['fields']['please_list_information_of_forei_102']['id'] = 'please_list_information_of_forei_102';
$handler->display->display_options['fields']['please_list_information_of_forei_102']['table'] = $table;
$handler->display->display_options['fields']['please_list_information_of_forei_102']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Please_list_information_of_foreign_owners'));
$handler->display->display_options['fields']['please_list_information_of_forei_102']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['please_list_information_of_forei_102']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['please_list_information_of_forei_102']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['please_list_information_of_forei_102']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Percentage of Ownership - Private */
$handler->display->display_options['fields']['percentage_of_ownership_private_86']['id'] = 'percentage_of_ownership_private_86';
$handler->display->display_options['fields']['percentage_of_ownership_private_86']['table'] = $table;
$handler->display->display_options['fields']['percentage_of_ownership_private_86']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Percentage_of_Ownership_Private'));
$handler->display->display_options['fields']['percentage_of_ownership_private_86']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['percentage_of_ownership_private_86']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Percentage of Ownership - Government */
$handler->display->display_options['fields']['percentage_of_ownership_governme_84']['id'] = 'percentage_of_ownership_governme_84';
$handler->display->display_options['fields']['percentage_of_ownership_governme_84']['table'] = $table;
$handler->display->display_options['fields']['percentage_of_ownership_governme_84']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Percentage_of_Ownership_Government'));
$handler->display->display_options['fields']['percentage_of_ownership_governme_84']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['percentage_of_ownership_governme_84']['empty_zero'] = TRUE;
/* Field: CiviCRM Custom: Customer Data: Percentage of Ownership - Other */
$handler->display->display_options['fields']['percentage_of_ownership_other_85']['id'] = 'percentage_of_ownership_other_85';
$handler->display->display_options['fields']['percentage_of_ownership_other_85']['table'] = $table;
$handler->display->display_options['fields']['percentage_of_ownership_other_85']['field'] = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'custom_group_id' => $gid, 'name' => 'Percentage_of_Ownership_Other'));
$handler->display->display_options['fields']['percentage_of_ownership_other_85']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['percentage_of_ownership_other_85']['empty_zero'] = TRUE;

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
$handler->display->display_options['path'] = 'expert/customer/customer-data';
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
