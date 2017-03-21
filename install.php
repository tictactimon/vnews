<?php

$content = rex_file::get(rex_path::addon('vnews','install/vtablesets/vnews_default_tableset.json'));
rex_yform_manager_table_api::importTablesets($content);
