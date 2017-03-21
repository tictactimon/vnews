DROP TABLE IF EXISTS `vnews_article`;
DROP TABLE IF EXISTS `vnews_category`;
DROP TABLE IF EXISTS `vnews_author`;
DELETE FROM `%TABLE_PREFIX%yform_table` WHERE table_name = 'vnews_author';
DELETE FROM `%TABLE_PREFIX%yform_table` WHERE table_name = 'vnews_category';
DELETE FROM `%TABLE_PREFIX%yform_table` WHERE table_name = 'vnews_article';
DELETE FROM `%TABLE_PREFIX%yform_field` WHERE table_name = 'vnews_category';
DELETE FROM `%TABLE_PREFIX%yform_field` WHERE table_name = 'vnews_article';
DELETE FROM `%TABLE_PREFIX%yform_field` WHERE table_name = 'vnews_author';
