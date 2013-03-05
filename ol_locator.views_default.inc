<?php
/**
 * @file
 * ol_locator.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ol_locator_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ol_locator_proximity_search';
  $view->description = 'Displays geocoded locations on a dynamic map for users to do proximity searches.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OpenLayers Locator proximity search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Common good organizations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Find a location near you. You can search using your <strong>City, Province/State</strong> or your <strong>Postal/Zip code.</strong>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '
';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_ol_locator_address']['id'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['table'] = 'field_data_field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['field'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['label'] = '';
  $handler->display->display_options['fields']['field_ol_locator_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_ol_locator_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_ol_locator_geofield']['id'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '2';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
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
    'gwo_business' => 'gwo_business',
    'gwo_institution' => 'gwo_institution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Number of employees  (field_number_of_employees_) */
  $handler->display->display_options['filters']['field_number_of_employees__value']['id'] = 'field_number_of_employees__value';
  $handler->display->display_options['filters']['field_number_of_employees__value']['table'] = 'field_data_field_number_of_employees_';
  $handler->display->display_options['filters']['field_number_of_employees__value']['field'] = 'field_number_of_employees__value';
  $handler->display->display_options['filters']['field_number_of_employees__value']['operator'] = '>';
  $handler->display->display_options['filters']['field_number_of_employees__value']['group'] = 1;
  $handler->display->display_options['filters']['field_number_of_employees__value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_of_employees__value']['expose']['operator_id'] = 'field_number_of_employees__value_op';
  $handler->display->display_options['filters']['field_number_of_employees__value']['expose']['label'] = 'Minimum number of employees';
  $handler->display->display_options['filters']['field_number_of_employees__value']['expose']['operator'] = 'field_number_of_employees__value_op';
  $handler->display->display_options['filters']['field_number_of_employees__value']['expose']['identifier'] = 'field_number_of_employees__value';
  $handler->display->display_options['filters']['field_number_of_employees__value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_number_of_employees__value']['group_info']['label'] = 'Number of employees  (field_number_of_employees_)';
  $handler->display->display_options['filters']['field_number_of_employees__value']['group_info']['identifier'] = 'field_number_of_employees__value';
  $handler->display->display_options['filters']['field_number_of_employees__value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_number_of_employees__value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Address (field_address:postal_code) */
  $handler->display->display_options['filters']['field_address_postal_code']['id'] = 'field_address_postal_code';
  $handler->display->display_options['filters']['field_address_postal_code']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_postal_code']['field'] = 'field_address_postal_code';
  $handler->display->display_options['filters']['field_address_postal_code']['group'] = 1;
  $handler->display->display_options['filters']['field_address_postal_code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_postal_code']['expose']['operator_id'] = 'field_address_postal_code_op';
  $handler->display->display_options['filters']['field_address_postal_code']['expose']['label'] = 'Postal code';
  $handler->display->display_options['filters']['field_address_postal_code']['expose']['operator'] = 'field_address_postal_code_op';
  $handler->display->display_options['filters']['field_address_postal_code']['expose']['identifier'] = 'field_address_postal_code';
  $handler->display->display_options['filters']['field_address_postal_code']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Business sector';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'sector';

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_ol_locator_geofield',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => '',
    'description_field' => '#row',
    'view_mode' => 'full',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_ol_locator_address']['id'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['table'] = 'field_data_field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['field'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['label'] = '';
  $handler->display->display_options['fields']['field_ol_locator_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_ol_locator_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_ol_locator_geofield']['id'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '350',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'ol_locator_proximity_search_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'locator';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Organizations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-network';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_ol_locator_address']['id'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['table'] = 'field_data_field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['field'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_ol_locator_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_ol_locator_geofield']['id'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '2';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'block_1' => 'block_1',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;
  $handler->display->display_options['render_pager'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'ol_locator_proximity_search_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['ol_locator_proximity_search'] = array(
    t('Master'),
    t('Common good organizations'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Find a location near you. You can search using your <strong>City, Province/State</strong> or your <strong>Postal/Zip code.</strong>'),
    t('
'),
    t('Geofield'),
    t('Distance'),
    t('.'),
    t(','),
    t('Name'),
    t('Type'),
    t('Minimum number of employees'),
    t('Number of employees  (field_number_of_employees_)'),
    t('Postal code'),
    t('Business sector'),
    t('OpenLayers Data Overlay'),
    t('Page'),
    t('Attachment'),
    t('Title'),
    t('Address'),
    t('Block'),
  );
  $export['ol_locator_proximity_search'] = $view;

  return $export;
}
