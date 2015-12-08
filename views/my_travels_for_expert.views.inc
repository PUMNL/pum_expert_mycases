<?php

$case_type_id = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'case_type'));
$travel_case_type_id = civicrm_api3('OptionValue', 'getvalue', array('return' => 'value', 'name' => 'TravelCase', 'option_group_id' => $case_type_id));

$td_info = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'travel_data'));
$inboundArrivalTime = civicrm_api3('CustomField', 'getvalue', array('name' => 'arrival_time', 'return' => 'column_name', 'custom_group_id' => $td_info['id']));
$outboundDepartureTime = civicrm_api3('CustomField', 'getvalue', array('name' => 'return_departure_time', 'return' => 'column_name', 'custom_group_id' => $td_info['id']));
$destination = civicrm_api3('CustomField', 'getvalue', array('name' => 'destination', 'return' => 'column_name', 'custom_group_id' => $td_info['id']));
$flight_nr = civicrm_api3('CustomField', 'getvalue', array('name' => 'flight_number', 'return' => 'column_name', 'custom_group_id' => $td_info['id']));
$return_travel_from = civicrm_api3('CustomField', 'getvalue', array('name' => 'return_from', 'return' => 'column_name', 'custom_group_id' => $td_info['id']));
$return_flight_number = civicrm_api3('CustomField', 'getvalue', array('name' => 'return_flight_number', 'return' => 'column_name', 'custom_group_id' => $td_info['id']));
$notes = civicrm_api3('CustomField', 'getvalue', array('name' => 'notes', 'return' => 'column_name', 'custom_group_id' => $td_info['id']));

$view = new view();
$view->name = 'expert_my_travels';
$view->description = '';
$view->tag = 'Travel case';
$view->base_table = 'civicrm_case';
$view->human_name = 'My travels (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My travels';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'display_name' => 'display_name',
  'destination' => 'destination',
  'requested_departure_date' => 'requested_departure_date',
  'requested_return_date' => 'requested_return_date',
);
$handler->display->display_options['style_options']['default'] = 'requested_departure_date';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'display_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'destination' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'requested_departure_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'requested_return_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: CiviCRM Parent case: Parent case */
$handler->display->display_options['relationships']['case_id']['id'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['table'] = 'civicrm_value_travel_parent';
$handler->display->display_options['relationships']['case_id']['field'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['label'] = 'Parent case';
$handler->display->display_options['relationships']['case_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Contact: Case Contact's Contact ID */
$handler->display->display_options['relationships']['client_id']['id'] = 'client_id';
$handler->display->display_options['relationships']['client_id']['table'] = 'civicrm_case_contact';
$handler->display->display_options['relationships']['client_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['client_id']['relationship'] = 'case_id';
$handler->display->display_options['relationships']['client_id']['label'] = 'Parent client';
$handler->display->display_options['relationships']['client_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Contact: Case Contact's Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_case_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['label'] = 'Traveler';
$handler->display->display_options['relationships']['contact_id']['required'] = TRUE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Field: CiviCRM Cases: Case ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Cases: Case ID */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['case_id']['field'] = 'id';
$handler->display->display_options['fields']['case_id']['relationship'] = 'case_id';
$handler->display->display_options['fields']['case_id']['label'] = '';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['case_id']['separator'] = '';
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
$handler->display->display_options['fields']['client_id']['id'] = 'client_id';
$handler->display->display_options['fields']['client_id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['client_id']['field'] = 'id';
$handler->display->display_options['fields']['client_id']['relationship'] = 'client_id';
$handler->display->display_options['fields']['client_id']['label'] = '';
$handler->display->display_options['fields']['client_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['client_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['client_id']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'client_id';
$handler->display->display_options['fields']['display_name']['label'] = 'Client';
$handler->display->display_options['fields']['display_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['display_name']['alter']['path'] = 'expert/customer/[client_id]';
$handler->display->display_options['fields']['display_name']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Cases: Case Type */
$handler->display->display_options['fields']['case_type']['id'] = 'case_type';
$handler->display->display_options['fields']['case_type']['table'] = 'civicrm_case';
$handler->display->display_options['fields']['case_type']['field'] = 'case_type';
$handler->display->display_options['fields']['case_type']['relationship'] = 'case_id';
$handler->display->display_options['fields']['case_type']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['case_type']['alter']['path'] = 'expert/my-cases/activities/[case_id]';
$handler->display->display_options['fields']['case_type']['alter']['absolute'] = TRUE;
/* Field: CiviCRM Custom: Info for travel agency: Destination */
$handler->display->display_options['fields']['destination']['id'] = 'destination';
$handler->display->display_options['fields']['destination']['table'] = $td_info['table_name'];
$handler->display->display_options['fields']['destination']['field'] = $destination;
$handler->display->display_options['fields']['destination']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Info for travel agency: Requested departure date */
$handler->display->display_options['fields']['requested_departure_date']['id'] = 'requested_departure_date';
$handler->display->display_options['fields']['requested_departure_date']['table'] = $td_info['table_name'];
$handler->display->display_options['fields']['requested_departure_date']['field'] = $inboundArrivalTime;
$handler->display->display_options['fields']['requested_departure_date']['label'] = 'Arrival date/time';
$handler->display->display_options['fields']['requested_departure_date']['date_format'] = 'short';
/* Field: CiviCRM Custom: Travel Data: Flight number */
$handler->display->display_options['fields']['flight_number']['id'] = 'flight_number';
$handler->display->display_options['fields']['flight_number']['table'] = $td_info['table_name'];
$handler->display->display_options['fields']['flight_number']['field'] = $flight_nr;
$handler->display->display_options['fields']['flight_number']['relationship'] = 'case_id';
$handler->display->display_options['fields']['flight_number']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Travel Data: Return from */
$handler->display->display_options['fields']['return_travel_from']['id'] = 'return_travel_from';
$handler->display->display_options['fields']['return_travel_from']['table'] = $td_info['table_name'];
$handler->display->display_options['fields']['return_travel_from']['field'] = $return_travel_from;
$handler->display->display_options['fields']['return_travel_from']['relationship'] = 'case_id';
$handler->display->display_options['fields']['return_travel_from']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Info for travel agency: Requested return date */
$handler->display->display_options['fields']['requested_return_date']['id'] = 'requested_return_date';
$handler->display->display_options['fields']['requested_return_date']['table'] = $td_info['table_name'];
$handler->display->display_options['fields']['requested_return_date']['field'] = $outboundDepartureTime;
$handler->display->display_options['fields']['requested_return_date']['label'] = 'Return date/time';
$handler->display->display_options['fields']['requested_return_date']['date_format'] = 'short';
/* Field: CiviCRM Custom: Travel Data: Flight number */
$handler->display->display_options['fields']['return_flight_number']['id'] = 'return_flight_number';
$handler->display->display_options['fields']['return_flight_number']['table'] = $td_info['table_name'];
$handler->display->display_options['fields']['return_flight_number']['field'] = $return_flight_number;
$handler->display->display_options['fields']['return_flight_number']['relationship'] = 'case_id';
$handler->display->display_options['fields']['return_flight_number']['alter']['strip_tags'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'Pickup info';
$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['path'] = 'expert/my-travels/pickup/[id]';
$handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
$handler->display->display_options['path'] = 'expert/my-travels';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'My Travels';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'menu-my-projects';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['travel_requests_for_bcd_'] = array(
  t('Master'),
  t('Travel requests'),
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
  t('Client'),
  t('Destination'),
  t('Departure date'),
  t('Return date'),
  t('First Name(s)'),
  t('Last Name(s)'),
  t('Partner Last Name'),
  t('Passport Number'),
  t('Passport Expiry Date'),
  t('Diet preference'),
  t('Seat'),
  t('Remarks for travel agency'),
  t('Page'),
);
