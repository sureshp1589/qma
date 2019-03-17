<?php
/**
 * @file custom_booking.admin.inc
 * Custom Booking administration pages.
 */



/**
 * Implements hook_admin().
 *
 */
function custom_booking_admin_form() {
  $form = array();

  $form = system_settings_form($form);

  $form['api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Api Url'),
    '#default_value' => variable_get('api_url', ''),
    '#description' => t('Enter the APi Url. For example, https://facebook.com/acromediainc .'),
  );

  
  $form['api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Api Username'),
    '#default_value' => variable_get('api_username', ''),
    '#description' => t("Enter the Api Username."),
  );

  $form['api_password'] = array(
    '#type' => 'password',
    '#title' => t('Api Password'),
    '#default_value' => variable_get('api_password', ''),
    '#description' => t("Enter the Api Password."),
  );

  
  array_unshift($form['#submit'], 'custom_booking_admin_form_submit');

  return $form;
}

/**
 * Implements hook_admin()
 *
 * Attempts to fetch an application access token from facebook
 * based off of the app ID and app secret specified in the form
 */
function custom_booking_admin_form_submit($form, &$form_state) {

  $api_url = $form_state['values']['api_url'];
  $api_password = $form_state['values']['api_password'];
  $api_username = $form_state['values']['api_username'];
  variable_set('api_url', $api_url);
  variable_set('api_username', $api_username);
  variable_set('api_password', $api_password);
  
}


/**
 * Implements hook_validate()
 */
function custom_booking_admin_form_validate($form, &$form_state) {

  $api_url = $form_state['values']['api_url'];
  $api_password = $form_state['values']['api_password'];
  $api_username = $form_state['values']['api_username'];
  if (empty($api_url)) {
    form_set_error('api_url', t("Please enter Api Url"));
  } else if(empty($api_username)){
    form_set_error('api_username', t("Please enter Api Username"));
  } else if(empty($api_password)){
    form_set_error('api_password', t("Please enter Api Password"));
  } else {
    drupal_set_message('Successfully saved the details.', $type = 'status');
  }
}



