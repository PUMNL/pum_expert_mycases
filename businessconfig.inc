<?php

class pum_expert_mycases_businessconfig {

  protected static $singleton;

  public $custom_groups = array();

  public $programme_activity_type_id;

  public $programme_activity_type_name;

  public $submitted_status;

  public $in_progress_status;

  public $mainActivityInfoCustomGroup;

  public $mainActivityStartDateCustomField;

  public $mainActivityStartDateCustomFieldName;

  public $mainActivityEndDateCustomField;

  public $mainActivityEndDateCustomFieldName;

  public $business_case_type;

  protected function __construct() {
    civicrm_initialize();
    $this->custom_groups['Business_Programme'] = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Business_Programme'));
    $this->custom_groups['Business_Programme']['fields']['Naam_bedrijf'] = civicrm_api3('CustomField', 'getsingle', array(
      'name' => 'Naam_bedrijf',
      'custom_group_id' => $this->custom_groups['Business_Programme']['id']
    ));
    $this->custom_groups['Business_Programme']['fields']['Location'] = civicrm_api3('CustomField', 'getsingle', array(
      'name' => 'Location',
      'custom_group_id' => $this->custom_groups['Business_Programme']['id']
    ));
    $this->custom_groups['Business_Programme']['fields']['Aim_of_Visit'] = civicrm_api3('CustomField', 'getsingle', array(
      'name' => 'Short_description_Aim_of_Visit',
      'custom_group_id' => $this->custom_groups['Business_Programme']['id']
    ));
    $this->custom_groups['Business_Programme']['fields']['Visit_from'] = civicrm_api3('CustomField', 'getsingle', array('name' => 'Visit_from', 'custom_group_id' => $this->custom_groups['Business_Programme']['id']));
    $this->custom_groups['Business_Programme']['fields']['Visit_to'] = civicrm_api3('CustomField', 'getsingle', array('name' => 'Visit_ot', 'custom_group_id' => $this->custom_groups['Business_Programme']['id']));
    $this->custom_groups['Business_Programme']['fields']['Thank_you_Note'] = civicrm_api3('CustomField', 'getsingle', array('name' => 'Thank_you_Note', 'custom_group_id' => $this->custom_groups['Business_Programme']['id']));
    $this->custom_groups['Business_Programme']['fields']['Business_Visit_Cancelled'] = civicrm_api3('CustomField', 'getsingle', array('name' => 'Business_Visit_Cancelled', 'custom_group_id' => $this->custom_groups['Business_Programme']['id']));


    $this->programme_activity_type_name = 'Business Programme';
    $activity_type_option_group = civicrm_api3('OptionGroup', 'getvalue', array(
      'return' => 'id',
      'name' => 'activity_type'
    ));
    $this->programme_activity_type_id = civicrm_api3('OptionValue', 'getvalue', array(
      'return' => 'value',
      'name' => $this->programme_activity_type_name,
      'option_group_id' => $activity_type_option_group
    ));

    $this->mainActivityInfoCustomGroup = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'main_activity_info'));
    $this->mainActivityStartDateCustomField = civicrm_api3('CustomField', 'getsingle', array(
      'name' => 'main_activity_start_date',
      'custom_group_id' => $this->mainActivityInfoCustomGroup['id']
    ));
    $this->mainActivityStartDateCustomFieldName = $this->mainActivityStartDateCustomField['column_name'];
    $this->mainActivityEndDateCustomField = civicrm_api3('CustomField', 'getsingle', array(
      'name' => 'main_activity_end_date',
      'custom_group_id' => $this->mainActivityInfoCustomGroup['id']
    ));
    $this->mainActivityEndDateCustomFieldName = $this->mainActivityEndDateCustomField['column_name'];

    $activity_status_option_group = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'activity_status'));
    $this->submitted_status = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Submitted', 'option_group_id' => $activity_status_option_group));
    $this->in_progress_status = civicrm_api3('OptionValue', 'getsingle', array('name' => 'In Progress', 'option_group_id' => $activity_status_option_group));

    $case_type_id = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'case_type'));
    $this->business_case_type = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Business', 'option_group_id' => $case_type_id, 'return' => 'value'));
  }

  /**
   *
   * @return pum_expert_mycases_businessconfig
   */
  public static function singleton() {
    if (!self::$singleton) {
      self::$singleton = new pum_expert_mycases_businessconfig();
    }
    return self::$singleton;
  }

}