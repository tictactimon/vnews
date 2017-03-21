INSERT INTO vnews_author (author_name)
VALUES ('Kein Autor'); 

INSERT INTO vnews_category (category_name)
VALUES ('Keine Kategorie'); 

INSERT INTO rex_redactor2_profiles (name, description, urltype, minheight, maxheight, characterlimit, toolbarfixed, shortcuts, redactor_plugins)
VALUES ('vlead','Redactor Profil für vNews Lead','relative','0','150','150','1','1',''); 

INSERT INTO rex_url_generate (`table`, table_parameters) 
VALUES ('1_xxx_vnews_article','{"1_xxx_vnews_article_field_1":"article_title","1_xxx_vnews_article_field_2":"","1_xxx_vnews_article_field_3":"","1_xxx_vnews_article_id":"id","1_xxx_vnews_article_restriction_field":"","1_xxx_vnews_article_restriction_operator":"=","1_xxx_vnews_article_restriction_value":"","1_xxx_vnews_article_url_param_key":"","1_xxx_vnews_article_seo_title":"article_title","1_xxx_vnews_article_seo_description":"article_lead","1_xxx_vnews_article_sitemap_add":"1","1_xxx_vnews_article_sitemap_frequency":"always","1_xxx_vnews_article_sitemap_priority":"1.0","1_xxx_vnews_article_sitemap_lastmod":"article_title","1_xxx_vnews_article_path_names":"","1_xxx_vnews_article_path_categories":"0","1_xxx_vnews_article_relation_field":""}'); 