<?php
$view = new view();
$view->name = 'dsa_details_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_activity';
$view->human_name = 'DSA Details (expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Daily Subsistence Allowances';
$handler->display->display_options['css_class'] = 'pum-list-view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: CiviCRM DSA Compose: ID */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['relationships']['id']['field'] = 'id';
/* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_activity_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['record_type'] = '0';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Field: CiviCRM DSA Compose: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['exclude'] = TRUE;
/* Field: Go back link */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Go back link';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/expert/dsa" class="button">Go back</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: CiviCRM DSA Compose: Amount DSA */
$handler->display->display_options['fields']['amount_dsa']['id'] = 'amount_dsa';
$handler->display->display_options['fields']['amount_dsa']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_dsa']['field'] = 'amount_dsa';
$handler->display->display_options['fields']['amount_dsa']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_dsa']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_dsa']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Amount Briefing */
$handler->display->display_options['fields']['amount_briefing']['id'] = 'amount_briefing';
$handler->display->display_options['fields']['amount_briefing']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_briefing']['field'] = 'amount_briefing';
$handler->display->display_options['fields']['amount_briefing']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_briefing']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_briefing']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Amount Airport */
$handler->display->display_options['fields']['amount_airport']['id'] = 'amount_airport';
$handler->display->display_options['fields']['amount_airport']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_airport']['field'] = 'amount_airport';
$handler->display->display_options['fields']['amount_airport']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_airport']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_airport']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Amount Transfer */
$handler->display->display_options['fields']['amount_transfer']['id'] = 'amount_transfer';
$handler->display->display_options['fields']['amount_transfer']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_transfer']['field'] = 'amount_transfer';
$handler->display->display_options['fields']['amount_transfer']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_transfer']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_transfer']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Amount Hotel */
$handler->display->display_options['fields']['amount_hotel']['id'] = 'amount_hotel';
$handler->display->display_options['fields']['amount_hotel']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_hotel']['field'] = 'amount_hotel';
$handler->display->display_options['fields']['amount_hotel']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_hotel']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_hotel']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Amount Visa */
$handler->display->display_options['fields']['amount_visa']['id'] = 'amount_visa';
$handler->display->display_options['fields']['amount_visa']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_visa']['field'] = 'amount_visa';
$handler->display->display_options['fields']['amount_visa']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_visa']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_visa']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Amount Medical */
$handler->display->display_options['fields']['amount_medical']['id'] = 'amount_medical';
$handler->display->display_options['fields']['amount_medical']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_medical']['field'] = 'amount_medical';
$handler->display->display_options['fields']['amount_medical']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_medical']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_medical']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Amount Other */
$handler->display->display_options['fields']['amount_other']['id'] = 'amount_other';
$handler->display->display_options['fields']['amount_other']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_other']['field'] = 'amount_other';
$handler->display->display_options['fields']['amount_other']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_other']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_other']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Description Other */
$handler->display->display_options['fields']['description_other']['id'] = 'description_other';
$handler->display->display_options['fields']['description_other']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['description_other']['field'] = 'description_other';
$handler->display->display_options['fields']['description_other']['relationship'] = 'id';
$handler->display->display_options['fields']['description_other']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['description_other']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['description_other']['empty_zero'] = TRUE;
/* Field: CiviCRM DSA Compose: Amount Advance */
$handler->display->display_options['fields']['amount_advance']['id'] = 'amount_advance';
$handler->display->display_options['fields']['amount_advance']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['amount_advance']['field'] = 'amount_advance';
$handler->display->display_options['fields']['amount_advance']['relationship'] = 'id';
$handler->display->display_options['fields']['amount_advance']['exclude'] = TRUE;
$handler->display->display_options['fields']['amount_advance']['element_label_type'] = 'strong';
/* Field: CiviCRM DSA Compose: Total amount */
$handler->display->display_options['fields']['total_amount']['id'] = 'total_amount';
$handler->display->display_options['fields']['total_amount']['table'] = 'civicrm_dsa_compose';
$handler->display->display_options['fields']['total_amount']['field'] = 'total_amount';
$handler->display->display_options['fields']['total_amount']['relationship'] = 'id';
$handler->display->display_options['fields']['total_amount']['exclude'] = TRUE;
$handler->display->display_options['fields']['total_amount']['element_label_type'] = 'strong';
/* Field: Signed Amount DSA */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['ui_name'] = 'Signed Amount DSA';
$handler->display->display_options['fields']['php']['label'] = 'Amount DSA';
$handler->display->display_options['fields']['php']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_dsa;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_dsa;
} elseif ($result[\'values\'][0][\'name\'] == "Business DSA") {
echo $currency." ".$row->bdsa_amount;
} elseif ($result[\'values\'][0][\'name\'] == "Credit Business DSA") {
echo "- ".$currency." ".$row->bdsa_amount;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Signed Amount Briefing */
$handler->display->display_options['fields']['php_1']['id'] = 'php_1';
$handler->display->display_options['fields']['php_1']['table'] = 'views';
$handler->display->display_options['fields']['php_1']['field'] = 'php';
$handler->display->display_options['fields']['php_1']['ui_name'] = 'Signed Amount Briefing';
$handler->display->display_options['fields']['php_1']['label'] = 'Amount Briefing';
$handler->display->display_options['fields']['php_1']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_1']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_briefing;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_briefing;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
/* Field: Signed Amount Airport */
$handler->display->display_options['fields']['php_2']['id'] = 'php_2';
$handler->display->display_options['fields']['php_2']['table'] = 'views';
$handler->display->display_options['fields']['php_2']['field'] = 'php';
$handler->display->display_options['fields']['php_2']['ui_name'] = 'Signed Amount Airport';
$handler->display->display_options['fields']['php_2']['label'] = 'Amount Airport';
$handler->display->display_options['fields']['php_2']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_2']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_2']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_airport;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_airport;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
/* Field: Signed Amount Transfer */
$handler->display->display_options['fields']['php_3']['id'] = 'php_3';
$handler->display->display_options['fields']['php_3']['table'] = 'views';
$handler->display->display_options['fields']['php_3']['field'] = 'php';
$handler->display->display_options['fields']['php_3']['ui_name'] = 'Signed Amount Transfer';
$handler->display->display_options['fields']['php_3']['label'] = 'Amount Transfer';
$handler->display->display_options['fields']['php_3']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_3']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_3']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_transfer;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_transfer;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
/* Field: Signed Amount Hotel */
$handler->display->display_options['fields']['php_4']['id'] = 'php_4';
$handler->display->display_options['fields']['php_4']['table'] = 'views';
$handler->display->display_options['fields']['php_4']['field'] = 'php';
$handler->display->display_options['fields']['php_4']['ui_name'] = 'Signed Amount Hotel';
$handler->display->display_options['fields']['php_4']['label'] = 'Amount Hotel';
$handler->display->display_options['fields']['php_4']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_4']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_4']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_hotel;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_hotel;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
/* Field: Signed Amount Visa */
$handler->display->display_options['fields']['php_5']['id'] = 'php_5';
$handler->display->display_options['fields']['php_5']['table'] = 'views';
$handler->display->display_options['fields']['php_5']['field'] = 'php';
$handler->display->display_options['fields']['php_5']['ui_name'] = 'Signed Amount Visa';
$handler->display->display_options['fields']['php_5']['label'] = 'Amount Visa';
$handler->display->display_options['fields']['php_5']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_5']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_5']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_visa;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_visa;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
/* Field: Signed Amount Medical */
$handler->display->display_options['fields']['php_6']['id'] = 'php_6';
$handler->display->display_options['fields']['php_6']['table'] = 'views';
$handler->display->display_options['fields']['php_6']['field'] = 'php';
$handler->display->display_options['fields']['php_6']['ui_name'] = 'Signed Amount Medical';
$handler->display->display_options['fields']['php_6']['label'] = 'Amount Medical';
$handler->display->display_options['fields']['php_6']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_6']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_6']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_medical;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_medical;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
/* Field: Signed Amount Other */
$handler->display->display_options['fields']['php_7']['id'] = 'php_7';
$handler->display->display_options['fields']['php_7']['table'] = 'views';
$handler->display->display_options['fields']['php_7']['field'] = 'php';
$handler->display->display_options['fields']['php_7']['ui_name'] = 'Signed Amount Other';
$handler->display->display_options['fields']['php_7']['label'] = 'Amount Other';
$handler->display->display_options['fields']['php_7']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_7']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_7']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_other;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_other;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
/* Field: Signed Amount Advance */
$handler->display->display_options['fields']['php_8']['id'] = 'php_8';
$handler->display->display_options['fields']['php_8']['table'] = 'views';
$handler->display->display_options['fields']['php_8']['field'] = 'php';
$handler->display->display_options['fields']['php_8']['ui_name'] = 'Signed Amount Advance';
$handler->display->display_options['fields']['php_8']['label'] = 'Amount Advance';
$handler->display->display_options['fields']['php_8']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_8']['element_label_class'] = 'dsa-details-label';
$handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_8']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->amount_advance;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->amount_advance;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
/* Field: Signed Total Amount */
$handler->display->display_options['fields']['php_9']['id'] = 'php_9';
$handler->display->display_options['fields']['php_9']['table'] = 'views';
$handler->display->display_options['fields']['php_9']['field'] = 'php';
$handler->display->display_options['fields']['php_9']['ui_name'] = 'Signed Total Amount';
$handler->display->display_options['fields']['php_9']['label'] = 'Total Amount';
$handler->display->display_options['fields']['php_9']['element_type'] = 'span';
$handler->display->display_options['fields']['php_9']['element_class'] = 'dsa-details-label total';
$handler->display->display_options['fields']['php_9']['element_label_type'] = 'span';
$handler->display->display_options['fields']['php_9']['element_label_class'] = 'dsa-details-label total';
$handler->display->display_options['fields']['php_9']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_9']['php_output'] = '<?php
$params = array(
  \'version\' => 3,
  \'sequential\' => 1,
  \'value\' => $row->activity_type,
);
$result = civicrm_api(\'OptionValue\', \'get\', $params);

$currency  = "&euro;";

if($row->type == 1) {
echo $currency." ".$row->total_amount;
} elseif ($row->type == 3) {
echo "- ".$currency." ".$row->total_amount;
} else {
echo "?";
}
?>';
$handler->display->display_options['fields']['php_9']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_9']['php_click_sortable'] = '';
/* Contextual filter: CiviCRM Activities: Activity ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_activity';
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

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/dsa/details';
$translatables['dsa_details_expert_'] = array(
  t('Master'),
  t('Daily Subsistence Allowances'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('CiviCRM DSA Compose'),
  t('Activity Contact ID'),
  t('Drupal User'),
  t('Type'),
  t('<a href="/expert/dsa" class="button">Go back</a>'),
  t('Amount DSA'),
  t('Amount Briefing'),
  t('Amount Airport'),
  t('Amount Transfer'),
  t('Amount Hotel'),
  t('Amount Visa'),
  t('Amount Medical'),
  t('Amount Other'),
  t('Description Other'),
  t('Amount Advance'),
  t('Total amount'),
  t('Total Amount'),
  t('All'),
  t('Page'),
);
