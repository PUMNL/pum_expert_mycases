<?php

class pum_expert_mycases_config {

    protected static $singleton;

    protected $contact_with_customer;

    protected $conditions = array();

    protected $doNotIncludeInCaseActivityList = array();

    protected $project_intake_case_type = array();

    protected $noActivityDetailsList = array();

    protected $repActivityList = array();

    protected function __construct() {
        civicrm_initialize();

        $case_type_option_group = 'case_type';
        $this->project_intake_case_type = civicrm_api3('OptionValue', 'getsingle', array('name' => 'Projectintake', 'option_group_name' => $case_type_option_group));

        $activity_type_option_group = 'activity_type';
        $activity_type_option_values = civicrm_api3('OptionValue', 'get', array('option_group_name' => $activity_type_option_group,'rowCount' => 0));

        foreach($activity_type_option_values['values'] as $key => $value){
          if($value['name'] === 'Contact with Customer') {
            $this->contact_with_customer = $value;
          }
          if($value['name'] === 'Conditions'){
            $this->conditions[] = $value;
          }
          if($value['name'] === 'Condition: Customer Contribution.'){
            $this->conditions[] = $value;
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'private_case_information'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Change Custom Data'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Representative payment'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Change Case Start Date'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Assign Case Role'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Remove Case Role'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Change Case Status'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Change Case Type'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Change Case Tags'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Contact about Expert'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }
          if($value['name'] === 'Contact with Colleague'){
            $this->doNotIncludeInCaseActivityList[] = $value;
          }


          if($value['name'] === 'Advice Debriefing CC'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Advice Debriefing Customer'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Advice Debriefing PrOf'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Advice Debriefing Representative'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Advice Debriefing SC'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Business Debriefing SC'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Business Debriefing CC'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Business Debriefing Customer'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Business Debriefing PrOf'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Remote Coaching Debriefing CC'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Remote Coaching Debriefing Customer'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Remote Coaching Debriefing PrOf'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Remote Coaching Debriefing PrOf'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Remote Coaching Debriefing SC'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Seminar Debriefing CC'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Seminar Debriefing Customer'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Seminar Debriefing PrOf'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Seminar Debriefing Representative'){
            $this->noActivityDetailsList[] = $value;
          }
          if($value['name'] === 'Seminar Debriefing SC'){
            $this->noActivityDetailsList[] = $value;
          }
        }

      $rep_activity_names = [
        'Assessment Project Request by Rep',
        'Condition',
        'Advice Debriefing Representative',
        'Representative payment',
        'Seminar Debriefing Representative',
        'Remote Coaching Debriefing Representative',
        'Condition: Customer Contribution',
        'Contact with Customer by Rep'
      ];

      $activities = civicrm_api3('OptionValue', 'get', [
        'sequential' => 1,
        'option_group_id' => "activity_type",
        'options' => ['limit' => 0]
      ])['values'];

      $this->repActivityList = [];
      foreach($activities as $activity){
        if(in_array($activity['label'],$rep_activity_names)){
          $this->repActivityList[$activity['value']] = $activity['value'];
        }
      }
    }

    public function getNoActivityDetailsList() {
    $return = array();
    foreach($this->noActivityDetailsList as $act) {
        $return[$act['value']] = $act['value'];
    }
    return $return;
    }

    public function getContactWithCustomerActivityTypeId() {
        return $this->contact_with_customer['value'];
    }

    public function getProjectInatkeCaseTypeId() {
        return $this->project_intake_case_type['value'];
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

        return $return;
    }

    /**
    * @return array
    */
    public function getRepActivityList() {
      return $this->repActivityList;
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
