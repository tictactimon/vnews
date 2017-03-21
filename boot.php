<?php

rex_vnews::addTable( rex_vnews_news::getTable() );

if ( rex::isBackend() ) {
	rex_extension::register( 'PACKAGES_INCLUDED', function ( $params ) {

		$plugin = rex_plugin::get( 'yform', 'manager' );

		if ( $plugin ) {
			$pages = $plugin->getProperty( 'pages' );
			$ycom_tables = rex_vnews::getTables();

			if ( isset( $pages ) && is_array( $pages ) ) {
				foreach ( $pages as $page ) {
					if ( in_array( $page->getKey(), $ycom_tables ) ) {
						$page->setBlock( 'vnews' );
					}
				}
			}

		}

	} );
}

rex_vnews::addTable('vnews_category');
rex_yform_manager_dataset::setModelClass('vnews_category', rex_vnews_news::class);

rex_vnews::addTable('vnews_author');
rex_yform_manager_dataset::setModelClass('vnews_author', rex_vnews_news::class);