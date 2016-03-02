<?php

function pum_expert_mycases_contact_with_customer($form, &$form_state, $case_id) {

    $form['case_id']['#type'] = 'hidden';
    $form['case_id']['#name'] = 'case_id';
    $form['case_id']['#value'] = $case_id;

    $form['subject'] = array(
        '#type' => 'textfield',
        '#required' => true,
        '#title' => t('Subject'),
    );

    $form['details'] = array(
        '#type' => 'textarea',
        '#required' => true,
        '#title' => t('Details'),
    );

    $form['submit_button'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
    );

    $form_state['redirect'] = array(
        array('query' => drupal_get_destination()),
    );

    return $form;
}

function pum_expert_mycases_contact_with_customer_submit($form, &$form_state) {
    $config = pum_expert_mycases_config::singleton();
    $case_id = $form_state['values']['case_id'];

    $params['case_id'] = $case_id;
    $params['subject'] = $form_state['values']['subject'];
    $params['details'] = $form_state['values']['details'];
    $params['activity_type_id'] = $config->getContactWithCustomerActivityTypeId();
    civicrm_api3('Activity', 'create', $params);

    drupal_goto('expert/my-cases/contact-with-customer/'.$case_id);
}