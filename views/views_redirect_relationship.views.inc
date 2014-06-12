<?php
/**
 * @file
 * Views relationship integration.
 */

/**
 * Implements hook_views_data_alter().
 *
 * Adds a two-way relationship between nodes/content and redirects
 */
function views_redirect_relationship_views_data_alter(&$data) {
  $data['redirect']['nid'] = array(
    'title' => t('Content NID'),
    'help' => t('Relate all nodes which form internal endpoints for redirects.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'group' => t('Content'),
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'relationship field' => 'nid',
      'label' => 'nodes',
    ),
  );

  $data['node']['redirect_node_nid'] = array(
    'title' => t('Redirects'),
    'help' => t('Relate all redirects pointing to the individual node'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'group' => t('Redirect'),
      'handler' => 'views_handler_relationship',
      'base' => 'redirect',
      'base field' => 'nid',
      'relationship field' => 'nid',
      'label' => 'redirects',
    ),
  );
}
