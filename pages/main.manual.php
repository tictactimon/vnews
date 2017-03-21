<?php

$content = '<h3>Tabellen pflegen</h3>';
$content = '<p>Für dieses AddOn verfügen Sie folgende drei Tabellen:</p>
<ul>
	<li>Artikel</li>
	<li>Kategorie</li>
	<li>Autor</li>
</ul>
<p></p>
<p></p>
<p></p>
<p></p>
<strong>Artikel</strong>
<p>In der Artikel-Tabelle sind alle News-Einträge gespeichert, Sie können neue Tabellen erstellen sowie Einträge verwalten und löschen.</p>
<p></p>
<strong>Kategorie</strong>
<p>Erstellen Sie neue Kategorien und Sortieren Sie ihre Neuigkeiten nach Kategorien. Sie können einen Eintrag in der Artikel-Tabelle einer Kategorie zuordnen</p>
<p></p>
<strong>Autor</strong>
<p>Erstellen Sie neue Autoren und ordnen Sie jedem Artikel einen Autor zu. Sie können jeden Eintrag in der Artikel-Tabelle einem Autor zuordnen</p>
<p></p>
<p></p>
<strong>vNews aufsetzen</strong>
<p>Als Sie vNews installierten, mussten gewisse AddOns vorinstalliert sein um dieses AddOn überhaupt nutzen zu können. Vergewissern Sie sich, dass alle benötigten AddOns immer noch installiert sind und auch einwandfrei funktionieren. Ebenso muss das AddOn "YRewrite" bereit aufgesetzt sein und einwandfrei funktionieren.</p>
<p>Legen Sie fest, in welchem Artikel Sie die Artikelliste und in welchemer Artikel Sie die Detailansicht platzieren wollen. Erstellen Sie wenn nötig diese Artikel und fügen die AddOns ein.</p>
<p></p>
<p>Im AddOn "Artikelliste" wählen Sie im Feld "Detailansicht-Artikel" den Artikel aus, in dem das Modul "Detailansicht" platziert wurde.</p>
<p>Wenn Sie den Artikel verlinkt haben, müssen Sie den gleichen Artikel nochmals im URL-AddOn. Wählen Sie dafür im URL-AddOn das bereits vom "vNews" erstelle Profil aus und wählen Sie im ersten Feld den gleichen Artikel aus wie im vorherigen Prozess. </p>
<p>Wurden all diese Einstellungen getätigt können Sie beginnen Artikel zu erstellen für das News AddOn.</p>
<p></p>
<p></p>
<p></p>';



$fragment = new rex_fragment();
$fragment->setVar('title', Anleitung);
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
