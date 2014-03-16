<?php
/**
 * @file
 * services.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function services_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Services';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Services';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4 col-sm-4';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: FontAwesome String */
  $handler->display->display_options['fields']['field_fontawesome_string']['id'] = 'field_fontawesome_string';
  $handler->display->display_options['fields']['field_fontawesome_string']['table'] = 'field_data_field_fontawesome_string';
  $handler->display->display_options['fields']['field_fontawesome_string']['field'] = 'field_fontawesome_string';
  $handler->display->display_options['fields']['field_fontawesome_string']['label'] = '';
  $handler->display->display_options['fields']['field_fontawesome_string']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Read More Link */
  $handler->display->display_options['fields']['field_read_more_link']['id'] = 'field_read_more_link';
  $handler->display->display_options['fields']['field_read_more_link']['table'] = 'field_data_field_read_more_link';
  $handler->display->display_options['fields']['field_read_more_link']['field'] = 'field_read_more_link';
  $handler->display->display_options['fields']['field_read_more_link']['label'] = '';
  $handler->display->display_options['fields']['field_read_more_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_read_more_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_read_more_link']['type'] = 'text_plain';
  /* Field: Content: Read More Text */
  $handler->display->display_options['fields']['field_read_more_text']['id'] = 'field_read_more_text';
  $handler->display->display_options['fields']['field_read_more_text']['table'] = 'field_data_field_read_more_text';
  $handler->display->display_options['fields']['field_read_more_text']['field'] = 'field_read_more_text';
  $handler->display->display_options['fields']['field_read_more_text']['label'] = '';
  $handler->display->display_options['fields']['field_read_more_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_read_more_text']['alter']['path'] = '[field_read_more_link]';
  $handler->display->display_options['fields']['field_read_more_text']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_read_more_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_read_more_text']['type'] = 'text_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'services' => 'services',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'EBazar - Services Block (6 in 3 Columns)';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['block_description'] = 'EBazar - Services Block (3 in 3 Columns)';
  $export['Services'] = $view;

  return $export;
}
