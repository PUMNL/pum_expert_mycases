<?php

$postal_loc_type_id = civicrm_api3('LocationType', 'getvalue', array('return' => 'id', 'name' => 'Postaladdress'));

$customer_data_custom_group = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Customers_Data'));
$customer_data_table = $customer_data_custom_group['table_name'];
$customer_data_gid = $customer_data_custom_group['id'];


$view = new view();
$view->name = 'expert_customer_info';
$view->description = 'This view is used to show customer info in drupal. ';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'Customer info (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Customer';
$handler->display->display_options['css_class'] = 'pum-grid-view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'php';
$handler->display->display_options['access']['php_access'] = '$hasrole = FALSE;
$url = $_SERVER["REQUEST_URI"];
$url_path = parse_url($url, PHP_URL_PATH);
$customer_id = explode("/",$_GET[\'q\']);

civicrm_initialize();
$session = CRM_Core_Session::singleton();
$contact_id = $session->get(\'userID\');
$civi_config = CRM_Core_Config::singleton();
$civi_dsn = DB::parseDSN($civi_config->dsn);
$civicrm_db = $civi_dsn[\'database\'];

if (!empty($civicrm_db) && !empty($customer_id[2])) {
  $relationships = db_query("SELECT DISTINCT rel.contact_id_b AS \'contact_id\' FROM $civicrm_db.civicrm_relationship rel
WHERE rel.contact_id_a = :customer_id AND rel.is_active = :is_active",
array(\':customer_id\'=>check_plain($customer_id[2]), \':is_active\'=>1))->fetchAll();

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
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '1';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['table'] = 'views';
$handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['label'] = 'General info';
$handler->display->display_options['fields']['fieldset']['children'] = array(
  0 => 'id',
  1 => 'display_name',
  2 => 'email',
  3 => 'phone1',
  4 => 'phone2',
  5 => 'view_2',
  6 => 'fieldset_1',
  7 => 'fieldset_2',
);
$handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = '';
$handler->display->display_options['fields']['display_name']['element_type'] = 'h1';
$handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['location_type'] = '0';
$handler->display->display_options['fields']['email']['location_op'] = '0';
$handler->display->display_options['fields']['email']['is_primary'] = 0;
/* Field: CiviCRM Phone Details: Phone Number */
$handler->display->display_options['fields']['phone1']['id'] = 'phone1';
$handler->display->display_options['fields']['phone1']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone1']['field'] = 'phone';
$handler->display->display_options['fields']['phone1']['label'] = 'Phone 1';
$handler->display->display_options['fields']['phone1']['location_type'] = '0';
$handler->display->display_options['fields']['phone1']['location_op'] = '0';
$handler->display->display_options['fields']['phone1']['is_primary'] = 1;
$handler->display->display_options['fields']['phone1']['phone_type'] = '0';
/* Field: CiviCRM Phone Details: Phone Number */
$handler->display->display_options['fields']['phone2']['id'] = 'phone2';
$handler->display->display_options['fields']['phone2']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone2']['field'] = 'phone';
$handler->display->display_options['fields']['phone2']['label'] = 'Phone 2 (Mobile)';
$handler->display->display_options['fields']['phone2']['location_type'] = '0';
$handler->display->display_options['fields']['phone2']['location_op'] = '0';
$handler->display->display_options['fields']['phone2']['is_primary'] = 0;
$handler->display->display_options['fields']['phone2']['phone_type'] = '2';
/* Field: Global: View */
$handler->display->display_options['fields']['view_2']['id'] = 'view_2';
$handler->display->display_options['fields']['view_2']['table'] = 'views';
$handler->display->display_options['fields']['view_2']['field'] = 'view';
$handler->display->display_options['fields']['view_2']['label'] = '';
$handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_2']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['view_2']['view'] = 'customer_websites';
$handler->display->display_options['fields']['view_2']['arguments'] = '!1';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
$handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
$handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset_1']['label'] = 'Primary address';
$handler->display->display_options['fields']['fieldset_1']['children'] = array(
  0 => 'street_address',
  1 => 'city',
  2 => 'postal_code',
  3 => 'state_province',
  4 => 'country',
);
/* Field: CiviCRM Address: Full Street Address */
$handler->display->display_options['fields']['street_address']['id'] = 'street_address';
$handler->display->display_options['fields']['street_address']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['street_address']['field'] = 'street_address';
$handler->display->display_options['fields']['street_address']['label'] = '';
$handler->display->display_options['fields']['street_address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['street_address']['location_type'] = '0';
$handler->display->display_options['fields']['street_address']['location_op'] = '0';
$handler->display->display_options['fields']['street_address']['is_primary'] = 1;
$handler->display->display_options['fields']['street_address']['is_billing'] = 0;
/* Field: CiviCRM Address: City / Suburb */
$handler->display->display_options['fields']['city']['id'] = 'city';
$handler->display->display_options['fields']['city']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['city']['field'] = 'city';
$handler->display->display_options['fields']['city']['label'] = '';
$handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['city']['location_type'] = '0';
$handler->display->display_options['fields']['city']['location_op'] = '0';
$handler->display->display_options['fields']['city']['is_primary'] = 1;
$handler->display->display_options['fields']['city']['is_billing'] = 0;
/* Field: CiviCRM Address: ZIP / Postal Code */
$handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['label'] = '';
$handler->display->display_options['fields']['postal_code']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['postal_code']['location_type'] = '0';
$handler->display->display_options['fields']['postal_code']['location_op'] = '0';
$handler->display->display_options['fields']['postal_code']['is_primary'] = 1;
$handler->display->display_options['fields']['postal_code']['is_billing'] = 0;
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country']['id'] = 'country';
$handler->display->display_options['fields']['country']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country']['field'] = 'country';
$handler->display->display_options['fields']['country']['label'] = '';
$handler->display->display_options['fields']['country']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['country']['location_type'] = '0';
$handler->display->display_options['fields']['country']['location_op'] = '0';
$handler->display->display_options['fields']['country']['is_primary'] = 1;
$handler->display->display_options['fields']['country']['is_billing'] = 0;
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
$handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
$handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset_2']['label'] = 'Postal address';
$handler->display->display_options['fields']['fieldset_2']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['fieldset_2']['children'] = array(
  0 => 'street_address_1',
  1 => 'city_1',
  2 => 'postal_code_1',
  3 => 'state_province_1',
  4 => 'country_1',
);
/* Field: CiviCRM Address: Full Street Address */
$handler->display->display_options['fields']['street_address_1']['id'] = 'street_address_1';
$handler->display->display_options['fields']['street_address_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['street_address_1']['field'] = 'street_address';
$handler->display->display_options['fields']['street_address_1']['label'] = '';
$handler->display->display_options['fields']['street_address_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['street_address_1']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['street_address_1']['location_type'] = $postal_loc_type_id;
$handler->display->display_options['fields']['street_address_1']['location_op'] = '0';
$handler->display->display_options['fields']['street_address_1']['is_primary'] = 0;
$handler->display->display_options['fields']['street_address_1']['is_billing'] = 0;
/* Field: CiviCRM Address: City / Suburb */
$handler->display->display_options['fields']['city_1']['id'] = 'city_1';
$handler->display->display_options['fields']['city_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['city_1']['field'] = 'city';
$handler->display->display_options['fields']['city_1']['label'] = '';
$handler->display->display_options['fields']['city_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['city_1']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['city_1']['location_type'] = $postal_loc_type_id;
$handler->display->display_options['fields']['city_1']['location_op'] = '0';
$handler->display->display_options['fields']['city_1']['is_primary'] = 0;
$handler->display->display_options['fields']['city_1']['is_billing'] = 0;
/* Field: CiviCRM Address: ZIP / Postal Code */
$handler->display->display_options['fields']['postal_code_1']['id'] = 'postal_code_1';
$handler->display->display_options['fields']['postal_code_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['postal_code_1']['field'] = 'postal_code';
$handler->display->display_options['fields']['postal_code_1']['label'] = '';
$handler->display->display_options['fields']['postal_code_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['postal_code_1']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['postal_code_1']['location_type'] = $postal_loc_type_id;
$handler->display->display_options['fields']['postal_code_1']['location_op'] = '0';
$handler->display->display_options['fields']['postal_code_1']['is_primary'] = 0;
$handler->display->display_options['fields']['postal_code_1']['is_billing'] = 0;
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country_1']['id'] = 'country_1';
$handler->display->display_options['fields']['country_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country_1']['field'] = 'country';
$handler->display->display_options['fields']['country_1']['label'] = '';
$handler->display->display_options['fields']['country_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['country_1']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['country_1']['location_type'] = $postal_loc_type_id;
$handler->display->display_options['fields']['country_1']['location_op'] = '0';
$handler->display->display_options['fields']['country_1']['is_primary'] = 0;
$handler->display->display_options['fields']['country_1']['is_billing'] = 0;
$handler->display->display_options['fields']['country_1']['country_display'] = '2';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset_5']['id'] = 'fieldset_5';
$handler->display->display_options['fields']['fieldset_5']['table'] = 'views';
$handler->display->display_options['fields']['fieldset_5']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset_5']['label'] = 'Contact persons';
$handler->display->display_options['fields']['fieldset_5']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['fieldset_5']['children'] = array(
  0 => 'authrosied_contacts',
  1 => 'representatives',
);
$handler->display->display_options['fields']['fieldset_5']['fieldset']['collapsible'] = 1;
$handler->display->display_options['fields']['fieldset_5']['fieldset']['collapsed'] = 1;
/* Field: Global: View */
$handler->display->display_options['fields']['authrosied_contacts']['id'] = 'authrosied_contacts';
$handler->display->display_options['fields']['authrosied_contacts']['table'] = 'views';
$handler->display->display_options['fields']['authrosied_contacts']['field'] = 'view';
$handler->display->display_options['fields']['authrosied_contacts']['label'] = 'Authorised contacts';
$handler->display->display_options['fields']['authrosied_contacts']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['authrosied_contacts']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['authrosied_contacts']['view'] = 'authorised_contacts_for_customer';
$handler->display->display_options['fields']['authrosied_contacts']['arguments'] = '!1';
/* Field: Global: View */
$handler->display->display_options['fields']['representatives']['id'] = 'representatives';
$handler->display->display_options['fields']['representatives']['table'] = 'views';
$handler->display->display_options['fields']['representatives']['field'] = 'view';
$handler->display->display_options['fields']['representatives']['label'] = 'Representative';
$handler->display->display_options['fields']['representatives']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['representatives']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['representatives']['view'] = 'representatives_for_customer';
$handler->display->display_options['fields']['representatives']['arguments'] = '!1';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset_3']['id'] = 'fieldset_3';
$handler->display->display_options['fields']['fieldset_3']['table'] = 'views';
$handler->display->display_options['fields']['fieldset_3']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset_3']['label'] = 'Documents';
$handler->display->display_options['fields']['fieldset_3']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['fieldset_3']['children'] = array(
  0 => 'documents',
);
$handler->display->display_options['fields']['fieldset_3']['fieldset']['collapsible'] = 1;
$handler->display->display_options['fields']['fieldset_3']['fieldset']['collapsed'] = 1;
/* Field: Global: View */
$handler->display->display_options['fields']['documents']['id'] = 'documents';
$handler->display->display_options['fields']['documents']['table'] = 'views';
$handler->display->display_options['fields']['documents']['field'] = 'view';
$handler->display->display_options['fields']['documents']['label'] = 'Documents';
$handler->display->display_options['fields']['documents']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['documents']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['documents']['view'] = 'customer_documents_for_expert_';
$handler->display->display_options['fields']['documents']['arguments'] = '!1';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset_4']['id'] = 'fieldset_4';
$handler->display->display_options['fields']['fieldset_4']['table'] = 'views';
$handler->display->display_options['fields']['fieldset_4']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset_4']['label'] = 'Customer data';
$handler->display->display_options['fields']['fieldset_4']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['fieldset_4']['children'] = array(
  0 => 'customer_data',
  1 => 'yearly_information',
  2 => 'customer_data_additional',
);
$handler->display->display_options['fields']['fieldset_4']['fieldset']['collapsible'] = 1;
$handler->display->display_options['fields']['fieldset_4']['fieldset']['collapsed'] = 1;
/* Field: Global: View */
$handler->display->display_options['fields']['customer_data']['id'] = 'customer_data';
$handler->display->display_options['fields']['customer_data']['table'] = 'views';
$handler->display->display_options['fields']['customer_data']['field'] = 'view';
$handler->display->display_options['fields']['customer_data']['label'] = 'Customer data';
$handler->display->display_options['fields']['customer_data']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['customer_data']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['customer_data']['view'] = 'customer_data_for_expert_';
$handler->display->display_options['fields']['customer_data']['arguments'] = '!1';
/* Field: Global: View */
$handler->display->display_options['fields']['yearly_information']['id'] = 'yearly_information';
$handler->display->display_options['fields']['yearly_information']['table'] = 'views';
$handler->display->display_options['fields']['yearly_information']['field'] = 'view';
$handler->display->display_options['fields']['yearly_information']['label'] = 'Yearly information';
$handler->display->display_options['fields']['yearly_information']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['yearly_information']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['yearly_information']['view'] = 'yearly_information_for_expert_';
$handler->display->display_options['fields']['yearly_information']['arguments'] = '!1';
/* Field: Global: View */
$handler->display->display_options['fields']['customer_data_additional']['id'] = 'customer_data_additional';
$handler->display->display_options['fields']['customer_data_additional']['table'] = 'views';
$handler->display->display_options['fields']['customer_data_additional']['field'] = 'view';
$handler->display->display_options['fields']['customer_data_additional']['label'] = '';
$handler->display->display_options['fields']['customer_data_additional']['view'] = 'customer_data_additional_for_expert_';
$handler->display->display_options['fields']['customer_data_additional']['arguments'] = '!1';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset_6']['id'] = 'fieldset_6';
$handler->display->display_options['fields']['fieldset_6']['table'] = 'views';
$handler->display->display_options['fields']['fieldset_6']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset_6']['label'] = 'Projects';
$handler->display->display_options['fields']['fieldset_6']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['fieldset_6']['children'] = array(
  0 => 'projects',
);
$handler->display->display_options['fields']['fieldset_6']['fieldset']['collapsible'] = 1;
$handler->display->display_options['fields']['fieldset_6']['fieldset']['collapsed'] = 1;
/* Field: Global: View */
$handler->display->display_options['fields']['projects']['id'] = 'projects';
$handler->display->display_options['fields']['projects']['table'] = 'views';
$handler->display->display_options['fields']['projects']['field'] = 'view';
$handler->display->display_options['fields']['projects']['label'] = 'Projects';
$handler->display->display_options['fields']['projects']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['projects']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['projects']['view'] = 'customer_info_projects_for_expert_';
$handler->display->display_options['fields']['projects']['arguments'] = '!1';
/* Contextual filter: CiviCRM Contacts: Contact ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Contacts: Contact Sub Type */
$handler->display->display_options['filters']['contact_sub_type']['id'] = 'contact_sub_type';
$handler->display->display_options['filters']['contact_sub_type']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['contact_sub_type']['field'] = 'contact_sub_type';
$handler->display->display_options['filters']['contact_sub_type']['value'] = array(
  'Customer' => 'Customer',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/customer';
$translatables['expert_customer_info'] = array(
  t('Master'),
  t('Customer'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('General info'),
  t('.'),
  t('Email Address'),
  t('Phone 1'),
  t('Phone 2 (Mobile)'),
  t('Primary address'),
  t('Postal address'),
  t('Contact persons'),
  t('Authorised contacts'),
  t('Representative'),
  t('Documents'),
  t('Customer data'),
  t('Yearly information'),
  t('Projects'),
  t('All'),
  t('Page'),
);