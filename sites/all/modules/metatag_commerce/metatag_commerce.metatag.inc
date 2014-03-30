<?php

/**
 * @file
 * Product meta tags for Open Graph and Twitter Card protocards.
 * 
 * Provides product-related meta tag options for Metatag: Open Graph and 
 * Metatag: Twitter Cards modules.
 */

/**
 * Implements hook_metatag_config_default().
 */
function metatag_commerce_metatag_config_default() {
  $configs = array();

  if (module_exists('commerce_product')) {
    $config = new stdClass();
    $config->instance = 'commerce_product';
    $config->api_version = 1;
    $config->disabled = FALSE;
    $config->config = array();
    $configs[$config->instance] = $config;
  }

  return $configs;
}

/**
 * Implements hook_metatag_config_default_alter().
 */
function metatag_commerce_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
 
        case 'commerce_product':
          if (module_exists('metatag_opengraph')) {
            $config->config += array(
              'og:type' => array('value' => 'product'),
              'product:price:amount' => array('value' => '[commerce-product:commerce-price:amount_decimal]'),
              'product:price:currency' => array('value' => '[commerce-product:commerce-price:currency_code]'),
              'product:retailer_part_no' => array('value' => '[commerce-product:sku]'),
            );
          }
          if (module_exists('metatag_twitter_cards')) {
            $config->config += array(
              'twitter:card' => array('value' => 'product'),
              'twitter:data1' => array('value' => '[commerce-product:commerce-price:amount_decimal]'),
              'twitter:label1' => array('value' => '[commerce-product:commerce-price:currency_code]'),
            );
          }
          break;

    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function metatag_commerce_metatag_info() {

  /** Add Open Graph Product Tags **/
  if (module_exists('metatag_opengraph')) {
    $info['groups']['metatag-commerce-og'] = array(
      'label' => t('Commerce Open Graph'),
      'form' => array(
        '#weight' => 51,
      )
    );
    $info['tags']['product:price:amount'] = array(
      'label' => t('Price'),
      'description' => 'Product price (without currency sign, for example "6.50")',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:price:currency'] = array(
      'label' => t('Currency'),
      'description' => 'Currency code string as defined in http://www.xe.com/iso4217.php (for example "USD")',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:availability'] = array(
      'label' => t('Availability'),
      'description' => 'Case insensitive string, possible values: "instock", "pending", "oos" per https://developers.facebook.com/docs/reference/opengraph/object-type/product.',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:brand'] = array(
      'label' => t('Brand'),
      'description' => '',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:upc'] = array(
      'label' => t('UPC'),
      'description' => '',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:ean'] = array(
      'label' => t('EAN'),
      'description' => '',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:isbn'] = array(
      'label' => t('ISBN'),
      'description' => '',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:plural_title'] = array(
      'label' => t('Plural Title'),
      'description' => 'A title to be used to describe multiple items of this product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:retailer'] = array(
      'label' => t('Retailer ID'),
      'description' => 'A Facebook ID (or reference to the profile) of the retailer of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:retailer_title'] = array(
      'label' => t('Retailer Name'),
      'description' => 'The name of the retailer of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:retailer_part_no'] = array(
      'label' => t('Retailer SKU/Product Number'),
      'description' => 'A retailer part number for the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:mfr_part_no'] = array(
      'label' => t('Manufacturer SKU/Part Number'),
      'description' => 'A manufacturer part number for the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:size'] = array(
      'label' => t('Size'),
      'description' => 'A size describing the product (such as S, M, L)',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:product_link'] = array(
      'label' => t('Product Link'),
      'description' => 'A link to find out more about the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:category'] = array(
      'label' => t('Category'),
      'description' => 'A category for the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:color'] = array(
      'label' => t('Color'),
      'description' => 'A color describing the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:material'] = array(
      'label' => t('Material'),
      'description' => 'A description of the material used to make the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:pattern'] = array(
      'label' => t('Pattern'),
      'description' => 'A description of the pattern used on the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:shipping_cost:amount'] = array(
      'label' => t('Shipping Cost Amount'),
      'description' => 'The shipping cost of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:shipping_cost:currency'] = array(
      'label' => t('Shipping Cost Currency'),
      'description' => 'The shipping cost currency of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:weight:value'] = array(
      'label' => t('Product Weight'),
      'description' => 'The weight of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:weight:units'] = array(
      'label' => t('Product Weight Units'),
      'description' => 'The unit of weight of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:shipping_weight:value'] = array(
      'label' => t('Shipping Weight'),
      'description' => 'The shipping weight of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:shipping_weight:units'] = array(
      'label' => t('Shipping Weight Units'),
      'description' => 'The unit of shipping weight of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:expiration_time'] = array(
      'label' => t('Expiration'),
      'description' => 'A time representing when the product expired (or will expire)',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
    $info['tags']['product:condition'] = array(
      'label' => t('Condition'),
      'description' => 'The condition of the product',
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-og',
      'element' => array(
        '#theme' => 'metatag_opengraph',
      ),
    );
  }
  
  /** Add Twitter Card Product Tags **/
  if (module_exists('metatag_twitter_cards')) {
    $info['groups']['metatag-commerce-twitter'] = array(
      'label' => t('Commerce Twitter Card'),
      'form' => array(
        '#weight' => 61,
      )
    );
    $info['tags']['twitter:card']['form']['#options']['product'] = t('Product');
      
    $info['tags']['twitter:data1'] = array(
      'label' => t('Data 1'),
      'description' => t('Top customizable data field, can be a relatively short string (ie "$3.99")'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-twitter',
      'element' => array(
        '#theme' => 'metatag_twitter_cards',
      ),
    );
    $info['tags']['twitter:label1'] = array(
      'label' => t('Label 1'),
      'description' => t('Customizable label or units for the information in twitter:data1 (best practice: use all caps)'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-twitter',
      'element' => array(
        '#theme' => 'metatag_twitter_cards',
      ),
    );
    $info['tags']['twitter:data2'] = array(
      'label' => t('Data 2'),
      'description' => t('Bottom customizable data field, can be a relatively short string (ie "Seattle, WA")'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-twitter',
      'element' => array(
        '#theme' => 'metatag_twitter_cards',
      ),
    );
    $info['tags']['twitter:label2'] = array(
      'label' => t('Label 2'),
      'description' => t('Customizable label or units for the information in twitter:data2 (best practice: use all caps)'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'metatag-commerce-twitter',
      'element' => array(
        '#theme' => 'metatag_twitter_cards',
      ),
    );
  }
  
  return $info;
}