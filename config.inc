<?php

class pum_expert_mycases_config {

    protected static $singleton;

    protected $contact_with_customer;

    protected function __construct() {
        civicrm_initialize();

        $activity_type_option_group = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'activity_type'));
        $this->contact_with_customer = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Contact with Customer', 'option_group_id' => $activity_type_option_group));
    }

    public function getContactWithCustomerActivityTypeId() {
        return $this->contact_with_customer['value'];
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