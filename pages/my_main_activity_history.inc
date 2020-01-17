<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

function pum_expert_mycases_my_main_activity_history() {
  $page = array();
  $history = array();

  civicrm_initialize();
  $session = CRM_Core_Session::singleton();
  $expert_id = $session->get('userID');

  $caseStatusOptionGroupId = civicrm_api3('OptionGroup', 'getvalue', array('name' => 'case_status', 'return' => 'id'));
  $completedCaseStatus = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Completed', 'return' => 'value', 'option_group_id' => $caseStatusOptionGroupId));

  $workAddressType = civicrm_api3('LocationType', 'getvalue', array('name' => 'Work', 'return' => 'id'));

  $caseTypeOptionGroupId = civicrm_api3('OptionGroup', 'getvalue', array('name' => 'case_type', 'return' => 'id'));
  $adviceCaseType = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Advice', 'option_group_id' => $caseTypeOptionGroupId));
  $seminarCaseType = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Seminar', 'option_group_id' => $caseTypeOptionGroupId));
  $businessCaseType = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Business', 'option_group_id' => $caseTypeOptionGroupId));
  $remoteCoachingCaseType = civicrm_api3('OptionValue', 'getsingle', array('name' => 'RemoteCoaching', 'option_group_id' => $caseTypeOptionGroupId));
  $mainActivities[$adviceCaseType['value']] = $adviceCaseType['label'];
  $mainActivities[$seminarCaseType['value']] = $seminarCaseType['label'];
  $mainActivities[$businessCaseType['value']] = $businessCaseType['label'];
  $mainActivities[$remoteCoachingCaseType['value']] = $remoteCoachingCaseType['label'];

  $expertRelationshipTypeId = civicrm_api3('RelationshipType', 'getvalue', array('name_a_b' => 'Expert', 'return' => 'id'));

  $mainActivityInfoCustomGroup = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'main_activity_info'));
  $mainActivityStartDateCustomField = civicrm_api3('CustomField', 'getsingle', array('name' => 'main_activity_start_date', 'custom_group_id' => $mainActivityInfoCustomGroup['id']));
  $mainActivityStartDateCustomFieldName = $mainActivityStartDateCustomField['column_name'];
  $mainActivityEndDateCustomField = civicrm_api3('CustomField', 'getsingle', array('name' => 'main_activity_end_date', 'custom_group_id' => $mainActivityInfoCustomGroup['id']));
  $mainActivityEndDateCustomFieldName = $mainActivityEndDateCustomField['column_name'];

  $prinsHistoryCustomGroup = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'prins_history'));
  $prinsHistoryFieldName = civicrm_api3('CustomField', 'getvalue', array('return' => 'column_name', 'name' => 'prins_history', 'custom_group_id' => $prinsHistoryCustomGroup['id']));
  // Build history from completed main activity cases.

  $sql = "SELECT customer.id as customer_id,customer.display_name as customer, project.id as project_id, project.title as project, `case`.case_type_id as case_type_id,
  `ma_info`.`{$mainActivityStartDateCustomFieldName}` AS start_date, `ma_info`.`{$mainActivityEndDateCustomFieldName}` AS end_date,
  country.name AS country,
  GROUP_CONCAT(segment.label SEPARATOR ', ') AS sector
  FROM civicrm_case `case`
  INNER JOIN civicrm_relationship expert_relation ON `case`.id = expert_relation.case_id
  INNER JOIN civicrm_case_contact client ON client.case_id = `case`.id
  INNER JOIN civicrm_contact customer ON client.contact_id = customer.id
  INNER JOIN civicrm_case_project ON `case`.id =  civicrm_case_project.case_id
  INNER JOIN civicrm_project project ON project.id = civicrm_case_project.project_id
  LEFT JOIN `{$mainActivityInfoCustomGroup['table_name']}` `ma_info` ON ma_info.entity_id = `case`.id
  LEFT JOIN civicrm_address address ON customer.id = address.contact_id
  LEFT JOIN civicrm_country country on address.country_id = country.id
  LEFT JOIN civicrm_contact_segment ON civicrm_contact_segment.contact_id = customer.id
  LEFT JOIN civicrm_segment segment ON civicrm_contact_segment.segment_id = segment.id
  WHERE (`case`.case_type_id LIKE  %1 OR `case`.case_type_id LIKE %2 OR `case`.case_type_id LIKE %3 OR `case`.case_type_id LIKE %4)
  AND expert_relation.relationship_type_id = %5 AND expert_relation.contact_id_b = %6
  AND `case`.status_id = %7
  AND address.location_type_id = %8
  AND civicrm_contact_segment.is_active = 1 AND civicrm_contact_segment.role_value = 'Customer'
  GROUP BY customer.id
  ";
  $sqlParams = array();
  $sqlParams[1] = array('%'.CRM_Core_DAO::VALUE_SEPARATOR.$adviceCaseType['value'].CRM_Core_DAO::VALUE_SEPARATOR.'%', 'String');
  $sqlParams[2] = array('%'.CRM_Core_DAO::VALUE_SEPARATOR.$seminarCaseType['value'].CRM_Core_DAO::VALUE_SEPARATOR.'%', 'String');
  $sqlParams[3] = array('%'.CRM_Core_DAO::VALUE_SEPARATOR.$businessCaseType['value'].CRM_Core_DAO::VALUE_SEPARATOR.'%', 'String');
  $sqlParams[4] = array('%'.CRM_Core_DAO::VALUE_SEPARATOR.$remoteCoachingCaseType['value'].CRM_Core_DAO::VALUE_SEPARATOR.'%', 'String');
  $sqlParams[5] = array($expertRelationshipTypeId, 'Integer');
  $sqlParams[6] = array($expert_id, 'Integer');
  $sqlParams[7] = array($completedCaseStatus, 'Integer');
  $sqlParams[8] = array($workAddressType, 'Integer');

  $dao = CRM_Core_DAO::executeQuery($sql,$sqlParams);
  $i = 0;
  while ($dao->fetch()) {
    $i++;
    $key = str_pad($i, 12, '0', STR_PAD_LEFT);
    $case_type_id = str_replace(CRM_Core_DAO::VALUE_SEPARATOR, "", $dao->case_type_id);
    $case_type = isset($mainActivities[$case_type_id]) ? $mainActivities[$case_type_id] : '';
    $start_date = '';
    $end_date = '';
    $country = '';
    $sector = '';

    if (!empty($dao->start_date)) {
      $start_date = new DateTime($dao->start_date);
      $key = $start_date->format('Ymd').str_pad($i,4, '0', STR_PAD_LEFT);
      $start_date = $start_date->format('d-m-Y');
    }
    if (!empty($dao->end_date)) {
      $end_date = new DateTime($dao->end_date);
      $end_date = $end_date->format('d-m-Y');
    }
    if (!empty($dao->country)) {
      $country = $dao->country;
    }
    if (!empty($dao->sector)) {
      $sector = $dao->sector;
    }

    $item = array(
      'customer' => $dao->customer,//'<a href="/expert/customer/'.$dao->customer_id.'">'.$dao->customer.'</a>',
      'project' => $dao->project,//'<a href="/expert/project/'.$dao->project_id.'">'.$dao->project.'</a>',
      'country' => $country,
      'sector' => $sector,
      'main_activity' => $case_type,
      'start_date' => $start_date,
      'end_date' => $end_date,
    );

    $history[$key] = $item;
  }

  // Retrieve the prins history
  $sql = "SELECT `{$prinsHistoryFieldName}` AS prins_history FROM `{$prinsHistoryCustomGroup['table_name']}` WHERE entity_id = %1";
  $sqlParams = array();
  $sqlParams[1] = array($expert_id, 'Integer');
  $dao = CRM_Core_DAO::executeQuery($sql, $sqlParams);
  while ($dao->fetch()) {
    $i++;
    $key = str_pad($i, 12, '0', STR_PAD_LEFT);
    $prinsHistory = explode("\n", $dao->prins_history);
    $item = array(
      'customer' => '',
      'project' => '',
      'country' => '',
      'sector' => '',
      'main_activity' => '',
      'start_date' => '',
      'end_date' => '',
    );

    foreach($prinsHistory as $line) {
      list($label, $value) = explode(": ", $line);
      switch ($label) {
        case 'Company name':
          $item['customer'] = trim($value);
          break;
        case 'Project number':
          $item['project'] = trim($value);
          break;
        case 'Country':
          $item['country'] = trim($value);
          break;
        case 'Sector':
          $item['sector'] = trim($value);
          break;
        case 'Start date':
          $start_date = new DateTime(trim($value));
          $item['start_date'] = $start_date->format('d-m-Y');
          $key = $start_date->format('Ymd').str_pad($i,4, '0', STR_PAD_LEFT);
          break;
        case 'End date':
          $end_date = new DateTime(trim($value));
          $item['end_date'] = $end_date->format('d-m-Y');
          break;
      }
    }

    $history[$key] = $item;
  }

  krsort($history);

  $page['history']['#theme'] = 'table';
  $page['history']['#header'] = array('Customer', 'Project', 'Country', 'Sector', 'Main Activity', 'Start date', 'End date');
  $page['history']['#rows'] = $history;
  $page['history']['#attributes'] = array('width' => '100%');

  return $page;
}