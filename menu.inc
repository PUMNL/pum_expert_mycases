<?php

require_once 'contact_with_customer.inc';

function _pum_expert_mycases_menu() {
    $items = array();
    $items['expert/my-cases/new-contact-with-customer/%'] = array( //this creates a URL that will call this form at "examples/form-example"
        'title' => 'Contact with customer', //page title
        'description' => '',
        'page callback' => 'drupal_get_form', //this is the function that will be called when the page is accessed.  for a form, use drupal_get_form
        'page arguments' => array('pum_expert_mycases_contact_with_customer', 3), //put the name of the form here
        'access callback' => '_pum_expert_mycases_user_has_role',
        'access arguments' => array(array('Expert')), // arg 1 loads the user, arg 2 is the role name
    );
    return $items;
}

function _pum_expert_mycases_user_has_role($roles = array()) {
    global $user;
    foreach ($roles as $role) {
        if (in_array($role, $user->roles)) {
            return TRUE;
        }
    }
    return FALSE;
}