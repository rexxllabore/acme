<?php
/**
 * @file
 * acme_global.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function acme_global_user_default_permissions() {
  $permissions = array();

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search',
  );

  return $permissions;
}
