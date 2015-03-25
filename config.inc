<?php

class pum_expert_mycases_config {

    protected static $singleton;

    protected $contact_with_customer;

    protected $conditions = array();

    protected $doNotIncludeInCaseActivityList = array();

    protected function __construct() {
        civicrm_initialize();

        $activity_type_option_group = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'activity_type'));
        $this->contact_with_customer = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Contact with Customer', 'option_group_id' => $activity_type_option_group));

        $this->conditions[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Conditions', 'option_group_id' => $activity_type_option_group));
        $this->conditions[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Condition: Customer Contribution.', 'option_group_id' => $activity_type_option_group));

        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Condition: Customer Contribution.', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'private_case_information', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Change Custom Data', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Representative payment', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Change Case Start Date', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Assign Case Role', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Remove Case Role', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Change Case Status', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Change Case Type', 'option_group_id' => $activity_type_option_group));
        $this->doNotIncludeInCaseActivityList[] = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Change Case Tags', 'option_group_id' => $activity_type_option_group));
    }

    public function getContactWithCustomerActivityTypeId() {
        return $this->contact_with_customer['value'];
    }

    public function getConditions() {
        $return = array();
        foreach($this->conditions as $cond) {
            $return[$cond['value']] = $cond['value'];
        }
        return $return;
    }

    public function getDoNotIncludeCaseActivityInList() {
        $return = array();

        foreach($this->doNotIncludeInCaseActivityList as $act) {
            $return[$act['value']] = $act['value'];
        }
        foreach($this->conditions as $cond) {
            $return[$cond['value']] = $cond['value'];
        }
        $return[$this->getContactWithCustomerActivityTypeId()] = $this->getContactWithCustomerActivityTypeId();

        return $return;
    }

    /**
     * @return pum_expert_mycases_config
     */
    public static function singleton() {
        if (!self::$singleton) {
            self::$singleton = new pum_expert_mycases_config();
        }
        return self::$singleton;
    }

}