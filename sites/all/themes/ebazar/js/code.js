
  jQuery(document).ready(function(){  
	
	jQuery("#accordion #collapseOne").collapse('hide');

	var count = jQuery('#block-views-shopping-cart-block-1 .line-item-quantity-raw').html();

	if(count > 0){

    	jQuery('#navbar .navbar-toggle').append('<div id="cart-count" class="badge" >' + count + '<div>');
    
    }
	
  });
