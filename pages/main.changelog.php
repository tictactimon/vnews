<?php

$content = rex_file::get(rex_path::addon('vnews','CHANGELOG.md'));

$fragment = new rex_fragment();
$fragment->setVar('title', 'Changelog','');
$fragment->setVar('body', rex_vnews::parseText($content), false);
echo $fragment->parse('core/page/section.php');




