<?php

$view = new view();
$view->name = 'customer_documents_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_document';
$view->human_name = 'Customer documents (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Customer documents';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no documents';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Relationship: CiviCRM Document contact: Contact ID of document contact */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_document_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['required'] = TRUE;
/* Relationship: CiviCRM Document: Added by */
$handler->display->display_options['relationships']['added_by']['id'] = 'added_by';
$handler->display->display_options['relationships']['added_by']['table'] = 'civicrm_document';
$handler->display->display_options['relationships']['added_by']['field'] = 'added_by';
$handler->display->display_options['relationships']['added_by']['label'] = 'Added by';
/* Relationship: CiviCRM Document: Updated by */
$handler->display->display_options['relationships']['updated_by']['id'] = 'updated_by';
$handler->display->display_options['relationships']['updated_by']['table'] = 'civicrm_document';
$handler->display->display_options['relationships']['updated_by']['field'] = 'updated_by';
$handler->display->display_options['relationships']['updated_by']['label'] = 'Updated by';
/* Relationship: CiviCRM Document case: Case ID of document case */
$handler->display->display_options['relationships']['case_id']['id'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['table'] = 'civicrm_document_case';
$handler->display->display_options['relationships']['case_id']['field'] = 'case_id';
/* Field: CiviCRM Document: Document ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_document';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Document: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'civicrm_document';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
/* Field: CiviCRM Document: Date added */
$handler->display->display_options['fields']['date_added']['id'] = 'date_added';
$handler->display->display_options['fields']['date_added']['table'] = 'civicrm_document';
$handler->display->display_options['fields']['date_added']['field'] = 'date_added';
$handler->display->display_options['fields']['date_added']['date_format'] = 'short';
$handler->display->display_options['fields']['date_added']['second_date_format'] = 'long';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'added_by';
$handler->display->display_options['fields']['display_name']['label'] = 'Added by';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Document: Date updated */
$handler->display->display_options['fields']['date_updated']['id'] = 'date_updated';
$handler->display->display_options['fields']['date_updated']['table'] = 'civicrm_document';
$handler->display->display_options['fields']['date_updated']['field'] = 'date_updated';
$handler->display->display_options['fields']['date_updated']['date_format'] = 'short';
$handler->display->display_options['fields']['date_updated']['second_date_format'] = 'long';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name_1']['id'] = 'display_name_1';
$handler->display->display_options['fields']['display_name_1']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name_1']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name_1']['relationship'] = 'updated_by';
$handler->display->display_options['fields']['display_name_1']['label'] = 'Updated by';
$handler->display->display_options['fields']['display_name_1']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Document: Document Download link */
$handler->display->display_options['fields']['download_link']['id'] = 'download_link';
$handler->display->display_options['fields']['download_link']['table'] = 'civicrm_document';
$handler->display->display_options['fields']['download_link']['field'] = 'download_link';
$handler->display->display_options['fields']['download_link']['label'] = 'Download';
$handler->display->display_options['fields']['download_link']['separator'] = '';
$handler->display->display_options['fields']['download_link']['download_link'] = TRUE;
/* Contextual filter: CiviCRM Contacts: Contact ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['relationship'] = 'contact_id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Cases: Case ID */
$handler->display->display_options['filters']['id']['id'] = 'id';
$handler->display->display_options['filters']['id']['table'] = 'civicrm_case';
$handler->display->display_options['filters']['id']['field'] = 'id';
$handler->display->display_options['filters']['id']['relationship'] = 'case_id';
$handler->display->display_options['filters']['id']['operator'] = 'empty';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/customer/documents';
$translatables['customer_documents_for_expert_'] = array(
  t('Master'),
  t('Customer documents'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Contact ID of document contact'),
  t('Added by'),
  t('Updated by'),
  t('Document ID'),
  t('.'),
  t('Subject'),
  t('Date added'),
  t('Date updated'),
  t('Document Download link'),
  t('Display Name'),
  t('All'),
  t('Page'),
);
