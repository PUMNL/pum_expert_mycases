<?php

$case_type_id = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'case_type'));
$travel_case_type_id = civicrm_api3('OptionValue', 'getvalue', array('return' => 'value', 'name' => 'TravelCase', 'option_group_id' => $case_type_id));

$ta_info = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'travel_data'));
$pickup = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'pickup'));

$dep_date = civicrm_api3('CustomField', 'getvalue', array('name' => 'requested_departure_date', 'return' => 'column_name', 'custom_group_id' => $ta_info['id']));
$return_date = civicrm_api3('CustomField', 'getvalue', array('name' => 'requested_return_date', 'return' => 'column_name', 'custom_group_id' => $ta_info['id']));
$destination = civicrm_api3('CustomField', 'getvalue', array('name' => 'destination', 'return' => 'column_name', 'custom_group_id' => $ta_info['id']));
$notes = civicrm_api3('CustomField', 'getvalue', array('name' => 'notes', 'return' => 'column_name', 'custom_group_id' => $ta_info['id']));

$pickup_name = civicrm_api3('CustomField', 'getvalue', array('name' => 'pickup_name', 'return' => 'column_name', 'custom_group_id' => $pickup['id']));
$pickup_telephone = civicrm_api3('CustomField', 'getvalue', array('name' => 'pickup_telephone', 'return' => 'column_name', 'custom_group_id' => $pickup['id']));
$accommodation_name = civicrm_api3('CustomField', 'getvalue', array('name' => 'accommodation_name', 'return' => 'column_name', 'custom_group_id' => $pickup['id']));
$accommodation_telephone = civicrm_api3('CustomField', 'getvalue', array('name' => 'accommodation_telephone', 'return' => 'column_name', 'custom_group_id' => $pickup['id']));
$pickup_notes = civicrm_api3('CustomField', 'getvalue', array('name' => 'pickup_notes', 'return' => 'column_name', 'custom_group_id' => $pickup['id']));

$view = new view();
$view->name = 'pickup_info_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_case';
$view->human_name = 'Pickup info (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Pickup info';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<a href="/expert/my-travels">Go back</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* Relationship: CiviCRM Parent case: Child case */
$handler->display->display_options['relationships']['entity_id']['id'] = 'entity_id';
$handler->display->display_options['relationships']['entity_id']['table'] = 'civicrm_value_travel_parent';
$handler->display->display_options['relationships']['entity_id']['field'] = 'entity_id';
$handler->display->display_options['relationships']['entity_id']['required'] = TRUE;
/* Relationship: CiviCRM Parent case: Parent case */
$handler->display->display_options['relationships']['case_id']['id'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['table'] = 'civicrm_value_travel_parent';
$handler->display->display_options['relationships']['case_id']['field'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['relationship'] = 'entity_id';
$handler->display->display_options['relationships']['case_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Contact: Case Contact's Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_case_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['label'] = 'Client';
$handler->display->display_options['relationships']['contact_id']['required'] = TRUE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Contact: Case Contact's Contact ID */
$handler->display->display_options['relationships']['contact_id_1']['id'] = 'contact_id_1';
$handler->display->display_options['relationships']['contact_id_1']['table'] = 'civicrm_case_contact';
$handler->display->display_options['relationships']['contact_id_1']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id_1']['relationship'] = 'case_id';
$handler->display->display_options['relationships']['contact_id_1']['label'] = 'Parent client';
$handler->display->display_options['relationships']['contact_id_1']['required'] = TRUE;
/* Field: CiviCRM Cases: Case ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Cases: Case ID */
$handler->display->display_options['fields']['parent_id']['id'] = 'parent_id';
$handler->display->display_options['fields']['parent_id']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['parent_id']['field'] = 'id';
$handler->display->display_options['fields']['parent_id']['relationship'] = 'case_id';
$handler->display->display_options['fields']['parent_id']['label'] = '';
$handler->display->display_options['fields']['parent_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['parent_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['parent_id']['separator'] = '';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['contact_id']['field'] = 'id';
$handler->display->display_options['fields']['contact_id']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['label'] = '';
$handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['contact_id']['separator'] = '';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id_1']['id'] = 'id_1';
$handler->display->display_options['fields']['id_1']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id_1']['field'] = 'id';
$handler->display->display_options['fields']['id_1']['relationship'] = 'contact_id_1';
$handler->display->display_options['fields']['id_1']['label'] = '';
$handler->display->display_options['fields']['id_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['id_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id_1']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id_1';
$handler->display->display_options['fields']['display_name']['label'] = 'Client';
$handler->display->display_options['fields']['display_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['display_name']['alter']['path'] = 'expert/customer[id_1]';
$handler->display->display_options['fields']['display_name']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
$handler->display->display_options['fields']['display_name']['element_type'] = 'span';
$handler->display->display_options['fields']['display_name']['element_label_type'] = 'strong';
/* Field: CiviCRM Cases: Case Type */
$handler->display->display_options['fields']['case_type']['id'] = 'case_type';
$handler->display->display_options['fields']['case_type']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['case_type']['field'] = 'case_type';
$handler->display->display_options['fields']['case_type']['relationship'] = 'case_id';
$handler->display->display_options['fields']['case_type']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['case_type']['alter']['path'] = 'expert/my-cases/activities/[parent_id]';
$handler->display->display_options['fields']['case_type']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['case_type']['element_type'] = 'span';
$handler->display->display_options['fields']['case_type']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Info for travel agency: Destination */
$handler->display->display_options['fields']['destination']['id'] = 'destination';
$handler->display->display_options['fields']['destination']['table'] = $ta_info['table_name'];
$handler->display->display_options['fields']['destination']['field'] = $destination;
$handler->display->display_options['fields']['destination']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['destination']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['destination']['element_type'] = 'span';
$handler->display->display_options['fields']['destination']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Info for travel agency: Requested departure date */
$handler->display->display_options['fields']['requested_departure_date']['id'] = 'requested_departure_date';
$handler->display->display_options['fields']['requested_departure_date']['table'] = $ta_info['table_name'];
$handler->display->display_options['fields']['requested_departure_date']['field'] = $dep_date;
$handler->display->display_options['fields']['requested_departure_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['requested_departure_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['requested_departure_date']['custom_date_format'] = 'j F Y';
$handler->display->display_options['fields']['requested_departure_date']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Info for travel agency: Requested return date */
$handler->display->display_options['fields']['requested_return_date']['id'] = 'requested_return_date';
$handler->display->display_options['fields']['requested_return_date']['table'] = $ta_info['table_name'];
$handler->display->display_options['fields']['requested_return_date']['field'] = $return_date;
$handler->display->display_options['fields']['requested_return_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['requested_return_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['requested_return_date']['custom_date_format'] = 'j F Y';
$handler->display->display_options['fields']['requested_return_date']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Pickup Data: Name of pickup person */
$handler->display->display_options['fields']['pickup_name']['id'] = 'pickup_name';
$handler->display->display_options['fields']['pickup_name']['table'] = $pickup['table_name'];
$handler->display->display_options['fields']['pickup_name']['field'] = $pickup_name;
$handler->display->display_options['fields']['pickup_name']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['pickup_name']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['pickup_name']['element_type'] = 'span';
$handler->display->display_options['fields']['pickup_name']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Pickup Data: Telephone number of pickup person */
$handler->display->display_options['fields']['pickup_telephone']['id'] = 'pickup_telephone';
$handler->display->display_options['fields']['pickup_telephone']['table'] = $pickup['table_name'];
$handler->display->display_options['fields']['pickup_telephone']['field'] = $pickup_telephone;
$handler->display->display_options['fields']['pickup_telephone']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['pickup_telephone']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['pickup_telephone']['element_type'] = 'span';
$handler->display->display_options['fields']['pickup_telephone']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Pickup Data: Name and address details of Hotel or Guesthouse */
$handler->display->display_options['fields']['accommodation_name']['id'] = 'accommodation_name';
$handler->display->display_options['fields']['accommodation_name']['table'] = $pickup['table_name'];
$handler->display->display_options['fields']['accommodation_name']['field'] = $accommodation_name;
$handler->display->display_options['fields']['accommodation_name']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['accommodation_name']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['accommodation_name']['element_type'] = 'span';
$handler->display->display_options['fields']['accommodation_name']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Pickup Data: Telephone number Hotel or Guesthouse */
$handler->display->display_options['fields']['accommodation_telephone']['id'] = 'accommodation_telephone';
$handler->display->display_options['fields']['accommodation_telephone']['table'] = $pickup['table_name'];
$handler->display->display_options['fields']['accommodation_telephone']['field'] = $accommodation_telephone;
$handler->display->display_options['fields']['accommodation_telephone']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['accommodation_telephone']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['accommodation_telephone']['element_type'] = 'span';
$handler->display->display_options['fields']['accommodation_telephone']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Pickup Data: Notes */
$handler->display->display_options['fields']['notes_1']['id'] = 'notes_1';
$handler->display->display_options['fields']['notes_1']['table'] = $ta_info['table_name'];
$handler->display->display_options['fields']['notes_1']['label'] = 'Travel remarks';
$handler->display->display_options['fields']['notes_1']['field'] = $notes;
$handler->display->display_options['fields']['notes_1']['alter']['nl2br'] = TRUE;
$handler->display->display_options['fields']['notes_1']['element_type'] = 'div';
$handler->display->display_options['fields']['notes_1']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Pickup Data: Notes */
$handler->display->display_options['fields']['notes']['id'] = 'notes';
$handler->display->display_options['fields']['notes']['table'] = $pickup['table_name'];
$handler->display->display_options['fields']['notes']['field'] = $pickup_notes;
$handler->display->display_options['fields']['notes']['label'] = 'Pickup remarks';
$handler->display->display_options['fields']['notes']['alter']['nl2br'] = TRUE;
$handler->display->display_options['fields']['notes']['element_type'] = 'div';
$handler->display->display_options['fields']['notes']['element_label_type'] = 'strong';
/* Contextual filter: CiviCRM Cases: Case ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_case';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';
/* Filter criterion: CiviCRM Cases: Case Type */
$handler->display->display_options['filters']['case_type']['id'] = 'case_type';
$handler->display->display_options['filters']['case_type']['table'] = 'civicrm_case';
$handler->display->display_options['filters']['case_type']['field'] = 'case_type';
$handler->display->display_options['filters']['case_type']['value'] = array(
  $travel_case_type_id => $travel_case_type_id,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/my-travels/pickup';
$translatables['pickup_info_for_expert_'] = array(
  t('Master'),
  t('Pickup info'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<a href="/expert/my-travels">Go back</a>'),
  t('.'),
  t('Destination'),
  t('Requested departure date'),
  t('Requested return date'),
  t('Name of pickup person'),
  t('Telephone number of pickup person'),
  t('Name and address details of Hotel or Guesthouse'),
  t('Telephone number Hotel or Guesthouse'),
  t('Notes'),
  t('All'),
  t('Page'),
);
