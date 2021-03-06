<?php
/**
 * @file
 * acme_episode.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function acme_episode_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'acme_episode_latest_episode';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ACME Episode latest episode';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest Episode';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_episode_media']['id'] = 'field_episode_media';
  $handler->display->display_options['fields']['field_episode_media']['table'] = 'field_data_field_episode_media';
  $handler->display->display_options['fields']['field_episode_media']['field'] = 'field_episode_media';
  $handler->display->display_options['fields']['field_episode_media']['label'] = '';
  $handler->display->display_options['fields']['field_episode_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_episode_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_episode_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_episode_media']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Sort criterion: Content: Date -  start date (field_episode_date) */
  $handler->display->display_options['sorts']['field_episode_date_value']['id'] = 'field_episode_date_value';
  $handler->display->display_options['sorts']['field_episode_date_value']['table'] = 'field_data_field_episode_date';
  $handler->display->display_options['sorts']['field_episode_date_value']['field'] = 'field_episode_date_value';
  $handler->display->display_options['sorts']['field_episode_date_value']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['gid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Interests (field_episode_interests) */
  $handler->display->display_options['arguments']['field_episode_interests_tid']['id'] = 'field_episode_interests_tid';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['table'] = 'field_data_field_episode_interests';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['field'] = 'field_episode_interests_tid';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['break_phrase'] = TRUE;
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
    'episode' => 'episode',
  );
  /* Filter criterion: Content: Date -  start date (field_episode_date) */
  $handler->display->display_options['filters']['field_episode_date_value']['id'] = 'field_episode_date_value';
  $handler->display->display_options['filters']['field_episode_date_value']['table'] = 'field_data_field_episode_date';
  $handler->display->display_options['filters']['field_episode_date_value']['field'] = 'field_episode_date_value';
  $handler->display->display_options['filters']['field_episode_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_episode_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_episode_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_episode_date_value']['year_range'] = '-0:+1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['acme_episode_latest_episode'] = $view;

  $view = new view();
  $view->name = 'acme_episode_on_tonight';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ACME Episode On Tonight';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'On Tonight';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_episode_media']['id'] = 'field_episode_media';
  $handler->display->display_options['fields']['field_episode_media']['table'] = 'field_data_field_episode_media';
  $handler->display->display_options['fields']['field_episode_media']['field'] = 'field_episode_media';
  $handler->display->display_options['fields']['field_episode_media']['label'] = '';
  $handler->display->display_options['fields']['field_episode_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_episode_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_episode_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_episode_media']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Interests (field_episode_interests) */
  $handler->display->display_options['arguments']['field_episode_interests_tid']['id'] = 'field_episode_interests_tid';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['table'] = 'field_data_field_episode_interests';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['field'] = 'field_episode_interests_tid';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_episode_interests_tid']['break_phrase'] = TRUE;
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
    'episode' => 'episode',
  );
  /* Filter criterion: Content: On Tonight (field_episode_on_tonight) */
  $handler->display->display_options['filters']['field_episode_on_tonight_value']['id'] = 'field_episode_on_tonight_value';
  $handler->display->display_options['filters']['field_episode_on_tonight_value']['table'] = 'field_data_field_episode_on_tonight';
  $handler->display->display_options['filters']['field_episode_on_tonight_value']['field'] = 'field_episode_on_tonight_value';
  $handler->display->display_options['filters']['field_episode_on_tonight_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_episode_on_tonight_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['acme_episode_on_tonight'] = $view;

  return $export;
}
