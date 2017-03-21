<?php

echo rex_view::title('vNews - News AddOn für Redaxo 5');

$subpage = rex_be_controller::getCurrentPagePart(2);
include rex_be_controller::getCurrentPageObject()->getSubPath();
