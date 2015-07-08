<?php

$intake =civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Intake'));
$intake_gid = $intake['id'];
$intake_table = $intake['table_name'];

$assesment_rep =civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Assessment_Project_Request_by_Rep'));
$gid = $assesment_rep['id'];
$table = $assesment_rep['table_name'];

$view = new view();
$view->name = 'assesment_rep_for_expert_';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_case_project';
$view->human_name = 'Assesment Rep (for expert)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Representative Assement';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_expert_mycases_get_role_ids(array('Expert'));
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: CiviCRM Case Project: Case ID */
$handler->display->display_options['relationships']['case_id']['id'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['table'] = 'civicrm_case_project';
$handler->display->display_options['relationships']['case_id']['field'] = 'case_id';
$handler->display->display_options['relationships']['case_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Project: Project ID */
$handler->display->display_options['relationships']['project_id']['id'] = 'project_id';
$handler->display->display_options['relationships']['project_id']['table'] = 'civicrm_case_project';
$handler->display->display_options['relationships']['project_id']['field'] = 'project_id';
$handler->display->display_options['relationships']['project_id']['required'] = TRUE;
/* Relationship: CiviCRM Case Activity: Case Activity's Activity ID */
$handler->display->display_options['relationships']['activity_id']['id'] = 'activity_id';
$handler->display->display_options['relationships']['activity_id']['table'] = 'civicrm_case_activity';
$handler->display->display_options['relationships']['activity_id']['field'] = 'activity_id';
$handler->display->display_options['relationships']['activity_id']['relationship'] = 'case_id';
$handler->display->display_options['relationships']['activity_id']['required'] = TRUE;
/* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_activity_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['relationship'] = 'activity_id';
$handler->display->display_options['relationships']['contact_id']['label'] = 'Reported by';
$handler->display->display_options['relationships']['contact_id']['record_type'] = '2';
/* Field: CiviCRM Custom: Intake: Assessment Rep */
$handler->display->display_options['fields']['assessment_rep_138']['id'] = 'assessment_rep_138';
$handler->display->display_options['fields']['assessment_rep_138']['table'] = $intake_table;
$handler->display->display_options['fields']['assessment_rep_138']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'Assessment_Rep', 'custom_group_id' => $intake_gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['assessment_rep_138']['relationship'] = 'case_id';
$handler->display->display_options['fields']['assessment_rep_138']['label'] = '';
$handler->display->display_options['fields']['assessment_rep_138']['element_type'] = 'h4';
$handler->display->display_options['fields']['assessment_rep_138']['element_label_colon'] = FALSE;
/* Field: CiviCRM Activities: Activity Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['status']['label'] = '';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['display_name']['label'] = '';
$handler->display->display_options['fields']['display_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['activity_date_time']['label'] = '';
$handler->display->display_options['fields']['activity_date_time']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['activity_date_time']['alter']['text'] = '[activity_date_time] ([status]) by [display_name]';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'em';
$handler->display->display_options['fields']['activity_date_time']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['activity_date_time']['date_format'] = 'custom';
$handler->display->display_options['fields']['activity_date_time']['custom_date_format'] = 'd F Y';
$handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Intake: Comment Rep */
$handler->display->display_options['fields']['comment_rep_139']['id'] = 'comment_rep_139';
$handler->display->display_options['fields']['comment_rep_139']['table'] = $intake_table;
$handler->display->display_options['fields']['comment_rep_139']['field'] =  civicrm_api3('CustomField', 'getvalue', array('name' => 'Comment_Rep', 'custom_group_id' => $intake_gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['comment_rep_139']['relationship'] = 'case_id';
$handler->display->display_options['fields']['comment_rep_139']['label'] = 'Comment';
$handler->display->display_options['fields']['comment_rep_139']['element_label_type'] = 'h4';
/* Field: CiviCRM Custom: Assessment Project Request by Rep: Does the company support child labour or forced labour, or does it operate in either of the following sectors? */
$handler->display->display_options['fields']['does_the_company_support_child_l_45']['id'] = 'does_the_company_support_child_l_45';
$handler->display->display_options['fields']['does_the_company_support_child_l_45']['table'] = $table;
$handler->display->display_options['fields']['does_the_company_support_child_l_45']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'Does_the_company_support_child_labour_or_forced_labour_or_does_i', 'custom_group_id' => $gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['does_the_company_support_child_l_45']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['does_the_company_support_child_l_45']['element_label_type'] = 'h4';
/* Field: CiviCRM Custom: Assessment Project Request by Rep: If yes, please select: */
$handler->display->display_options['fields']['if_yes_please_select__46']['id'] = 'if_yes_please_select__46';
$handler->display->display_options['fields']['if_yes_please_select__46']['table'] = $table;
$handler->display->display_options['fields']['if_yes_please_select__46']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'If_yes_please_select_', 'custom_group_id' => $gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['if_yes_please_select__46']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['if_yes_please_select__46']['label'] = 'If yes, please select';
$handler->display->display_options['fields']['if_yes_please_select__46']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Assessment Project Request by Rep: If yes, please explain */
$handler->display->display_options['fields']['if_yes_please_explain_47']['id'] = 'if_yes_please_explain_47';
$handler->display->display_options['fields']['if_yes_please_explain_47']['table'] = $table;
$handler->display->display_options['fields']['if_yes_please_explain_47']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'If_yes_please_explain', 'custom_group_id' => $gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['if_yes_please_explain_47']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['if_yes_please_explain_47']['element_label_type'] = 'strong';
/* Field: CiviCRM Custom: Assessment Project Request by Rep: Please provide any additional information you have about the company and/or the project request details (problem definition)* */
$handler->display->display_options['fields']['please_provide_any_additional_in_48']['id'] = 'please_provide_any_additional_in_48';
$handler->display->display_options['fields']['please_provide_any_additional_in_48']['table'] = $table;
$handler->display->display_options['fields']['please_provide_any_additional_in_48']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'Please_provide_any_additional_information_you_have_about_the_com', 'custom_group_id' => $gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['please_provide_any_additional_in_48']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['please_provide_any_additional_in_48']['element_label_type'] = 'h4';
/* Field: CiviCRM Custom: Assessment Project Request by Rep: Motivate advice */
$handler->display->display_options['fields']['motivate_advice_49']['id'] = 'motivate_advice_49';
$handler->display->display_options['fields']['motivate_advice_49']['table'] = $table;
$handler->display->display_options['fields']['motivate_advice_49']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'Motivate_advice', 'custom_group_id' => $gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['motivate_advice_49']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['motivate_advice_49']['element_label_type'] = 'h4';
/* Field: CiviCRM Custom: Assessment Project Request by Rep: Attachments/translation */
$handler->display->display_options['fields']['attachments_translation_50']['id'] = 'attachments_translation_50';
$handler->display->display_options['fields']['attachments_translation_50']['table'] = $table;
$handler->display->display_options['fields']['attachments_translation_50']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'Attachments_translation', 'custom_group_id' => $gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['attachments_translation_50']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['attachments_translation_50']['element_label_type'] = 'h4';
/* Field: CiviCRM Custom: Assessment Project Request by Rep: Informed client about rejection */
$handler->display->display_options['fields']['informed_client_about_rejection_51']['id'] = 'informed_client_about_rejection_51';
$handler->display->display_options['fields']['informed_client_about_rejection_51']['table'] = $table;
$handler->display->display_options['fields']['informed_client_about_rejection_51']['field'] = civicrm_api3('CustomField', 'getvalue', array('name' => 'Informed_client_about_rejection', 'custom_group_id' => $gid, 'return' => 'column_name'));
$handler->display->display_options['fields']['informed_client_about_rejection_51']['relationship'] = 'activity_id';
$handler->display->display_options['fields']['informed_client_about_rejection_51']['element_label_type'] = 'h4';
/* Sort criterion: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['sorts']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['sorts']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['relationship'] = 'activity_id';
$handler->display->display_options['sorts']['activity_date_time']['order'] = 'DESC';
/* Contextual filter: CiviCRM Project: Project ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_project';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['relationship'] = 'project_id';
$handler->display->display_options['arguments']['id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Activities: Activity Type */
$handler->display->display_options['filters']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['relationship'] = 'activity_id';
$handler->display->display_options['filters']['activity_type']['value'] = array(
73 => '73',
);
/* Filter criterion: CiviCRM Activities: Current Revision */
$handler->display->display_options['filters']['is_current_revision']['id'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['is_current_revision']['field'] = 'is_current_revision';
$handler->display->display_options['filters']['is_current_revision']['relationship'] = 'activity_id';
$handler->display->display_options['filters']['is_current_revision']['value'] = '1';
/* Filter criterion: CiviCRM Activities: Is Deleted */
$handler->display->display_options['filters']['is_deleted']['id'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['is_deleted']['field'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['relationship'] = 'activity_id';
$handler->display->display_options['filters']['is_deleted']['value'] = '0';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/project-rep-assesment';
$translatables['assesment_rep_for_expert_'] = array(
t('Master'),
t('Representative Assement'),
t('more'),
t('Apply'),
t('Reset'),
t('Sort by'),
t('Asc'),
t('Desc'),
t('CiviCRM Case'),
t('CiviCRM Project'),
t('CiviCRM Activity, with custom fields'),
t('Is active'),
t('Page'),
);
