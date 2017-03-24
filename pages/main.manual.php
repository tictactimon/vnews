<?php

$content = '';

$content .= '<section class="rex-page-section">
             <div class="panel panel-default">
    			<header class="panel-heading"><div class="panel-title">Tabellen</div></header>
         			<div class="panel-body">
					<p>Diese AddOn verfügt über folgende 3 Tabellen</p>
					<ul>
						<li>Artikel</li>
						<li>Kategorie</li>
						<li>Autor</li>
					</ul>
					<p>Die Felder in der Tabelle können beliebig gelöscht, ergänzt und verändert werden. Wichtig das diese Änderungen auch in den Modulen übernommen werden.</p>
				</div>
			</div>
   			</section>';


$content .= '<section class="rex-page-section">
             <div class="panel panel-default">
    			<header class="panel-heading">
					<div class="panel-title">vNews aufsetzen</div>
				</header>
         			<div class="panel-body">
					<p>Bevor vNews genutzt werden kann, müssen einige Vorkehrungen getroffen werden.</p>
						<dl>
							<dt>YRewrite aufsetzen</dt>
							<dd>YRewrite -> Domain aufsetzen, im URL darf nicht <code>www.domain.com/index.php?article_id=1</code> stehen sondern <code>www.domain.com/startseite</code> </dd>
							<p></p>
							<dt>Artikel für Modul "0743 - vNews Ausgabe Detailansicht" erstellen/auswählen</dt>
							<dd>Erstellung des Platzhalter-Artikel für das Modul und platzieren des Moduls. Es muss noch keine Einstellungen im Modul selber vorgenommen werden.</dd>
							<p></p>
							<dt>Url-Rewerite für Platzhalter-Artikel erstellen.</dt>
							<dd>Im <a href="index.php?page=url/generate">Url-AddOn</a> der von "vNews" erstellten Eintrag auswählen und im ersten Feld den Platzhalter-Artikel verlinken.</dd>
							<p></p>
							<dt>Artikel für Modul "0742 - vNews Ausgabe Artikelliste" erstellen/asuwählen</dt>
							<dd>Artikel auswählen und Modul platzieren. Bei Option "Detailansicht-Artikel" den Plathzahlter-Artikel des Moduls "0743 - vNews Ausgabe Detailansicht" auswählen. Weitere Einstellungen können Sie später vornehmen.</dd>
						</dl>
						<dl>
							
						</dl>
					</div>
				</div>
   			</section>';
$content .= '';
$content .= '';
$content .= '';

$fragment = new rex_fragment();
$fragment->setVar( 'title', Anleitung );
$fragment->setVar( 'body', $content, false );
echo $fragment->parse( 'core/page/section.php' );