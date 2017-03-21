<?php

rex_vnews::addTable( rex_vnews_news::getTable() );
rex_vnews::addTable( rex_vnews_news_author::getTable() );
rex_vnews::addTable( rex_vnews_news_category::getTable() );

if ( rex::isBackend() ) {
	rex_extension::register( 'PACKAGES_INCLUDED', function ( $params ) {

		$plugin = rex_plugin::get( 'yform', 'manager' );

		if ( $plugin ) {
			$pages = $plugin->getProperty( 'pages' );
			$vnews_tables = rex_vnews::getTables();

			if ( isset( $pages ) && is_array( $pages ) ) {
				foreach ( $pages as $page ) {
					if ( in_array( $page->getKey(), $vnews_tables ) ) {
						$page->setBlock( 'vnews' );
					}
				}
			}

		}

	} );
	
	rex_extension::register( 'PACKAGES_INCLUDED', function ( $params ) {

		$category_plugin = rex_plugin::get( 'yform', 'manager' );

		if ( $category_plugin ) {
			$category_pages = $category_plugin->getProperty( 'pages' );
			$vnews_category_tables = rex_vnews::getTables();

			if ( isset( $category_pages ) && is_array( $category_pages ) ) {
				foreach ( $category_pages as $category_page ) {
					if ( in_array( $category_page->getKey(), $vnews_category_tables ) ) {
						$category_page->setBlock( 'vnews' );
					}
				}
			}

		}

	} );
	
	rex_extension::register( 'PACKAGES_INCLUDED', function ( $params ) {

		$author_plugin = rex_plugin::get( 'yform', 'manager' );

		if ( $author_plugin ) {
			$author_pages = $author_plugin->getProperty( 'pages' );
			$vnews_author_tables = rex_vnews::getTables();

			if ( isset( $author_pages ) && is_array( $author_pages ) ) {
				foreach ( $author_pages as $author_page ) {
					if ( in_array( $author_page->getKey(), $vnews_author_tables ) ) {
						$author_page->setBlock( 'vnews' );
					}
				}
			}

		}

	} );
	
	
}

/*rex_vnews::addTable( 'vnews_category' );
rex_yform_manager_dataset::setModelClass( 'vnews_category', rex_vnews_news::class );

rex_vnews::addTable( 'vnews_author' );
rex_yform_manager_dataset::setModelClass( 'vnews_author', rex_vnews_news::class );*/