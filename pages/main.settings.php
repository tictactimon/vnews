<?php

$vnews_module_list = '0742 - vNews Ausgabe Artikelliste';
$vnews_module_detail = '0743 - vNews Ausgabe Detailansicht';
$vnews_module_list_short = 'vnews_list';
$vnews_module_detail_short = 'vnews_detail';

$content = '';

$content .= '<h1 class="wow animate fadeInLeft"><i class="fa fa-bullhorn" aria-hidden="true"></i> vNews</h1>';
$content .= '<hr class="divider">';

$content .= '<p>Als erstes, danke für die Installation dieses AddOns.</p>';
$content .= '<p>Eine ausführliche Erklärung wie dieses AddOn verwendet werden kann findest du <a href="index.php?page=vnews/main/manual">hier</a></p>';
$content .= '<hr class="divider">';
$content .= '<p><strong>Module installieren</strong></p>';
$content .= '<p>Installiere Bitte zuerst das Modul "'.$vnews_module_list.'". Das Modul "'.$vnews_module_detail .'" kann nur verwendet werden wenn dass andere Modul installierst ist.</p>';

if (rex_request('install',"integer") == 1) {
       
		$input = rex_file::get(rex_path::addon('vnews','module/module_input_'.$vnews_module_list_short.'.inc'));
        $output = rex_file::get(rex_path::addon('vnews','module/module_output_'.$vnews_module_list_short.'.inc'));

		$vinstall = rex_sql::factory();
		$vinstall->setTable('rex_module');
		$vinstall->setValue('input', $input);
        $vinstall->setValue('output', $output);

		$vinstall->setValue('name', $vnews_module_list);
		$vinstall->insert();
		echo rex_view::success('vNews Modul wurde angelegt unter "' .$vnews_module_list . '"');
	
}

if (rex_request('install',"integer") == 2) {
		
		$input = rex_file::get(rex_path::addon('vnews','module/module_input_'.$vnews_module_detail_short.'.inc'));
        $output = rex_file::get(rex_path::addon('vnews','module/module_output_'.$vnews_module_detail_short.'.inc'));

		$vinstall = rex_sql::factory();
		$vinstall->setTable('rex_module');
		$vinstall->setValue('input', $input);
        $vinstall->setValue('output', $output);

		$vinstall->setValue('name', $vnews_module_detail);
		$vinstall->insert();
		echo rex_view::success('vNews Modul wurde angelegt unter "' .$vnews_module_detail . '"');
	
}

$content .= '<p><a class="btn btn-primary rex-button" href="index.php?page=vnews/main/settings&amp;install=1">Modul "'.$vnews_module_list.'" installieren</a></p>';
$content .= '<p><a class="btn btn-primary rex-button" href="index.php?page=vnews/main/settings&amp;install=2">Modul "'.$vnews_module_detail.'" installieren</a></p>';


$fragment = new rex_fragment();
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');

