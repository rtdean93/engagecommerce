<?php
/**
 * @file
 * payment_methods.features.inc
 */

/**
 * Implements hook_views_api().
 */
function payment_methods_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function payment_methods_node_info() {
  $items = array(
    'payment_method' => array(
      'name' => t('Payment Method'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
