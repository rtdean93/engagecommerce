<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>

<?php
$term = taxonomy_term_load($output); // load term object
$term_uri = taxonomy_term_uri($term); // get array with path
$term_title = taxonomy_term_title($term);
$term_path = $term_uri['path'];
$alias = drupal_get_path_alias($term_path);

$clean = str_replace("product-family/", "bazar/item-category/", $alias);

if ($image_items = field_get_items('taxonomy_term', $term, 'field_image')) {
  $uri = $image_items[0]['uri'];
  $external_url = file_create_url($uri);
  $image = image_style_url("medium_retina", $uri);
  $s = file_exists($image) || image_style_create_derivative("medium_retina", $external_url, $image);
  $img = file_create_url($image);
}

$full = $GLOBALS['base_url'].'/'. $clean;
  
?> 

<a href="<?php print $full; ?>"><img src="<?php print $img; ?>"  /></a>