<?php
    $spalte = 'REX_VALUE[10]'; //Abfrage der Breite
    switch ($spalte)
    {
    case '10':
    $spalte = '10';
    $spaltesm = '12';
    $offset = 'col-md-offset-1 col-sm-offset-0';
    break;
    case '8':
    $spalte = '8';
    $spaltesm = '12';
    $offset = 'col-md-offset-2 col-sm-offset-0';
    break;    
    }

    print '<div class="'.$offset.' col-md-'.$spalte.' col-sm-'.$spaltesm.' col-xs-12">';
    print '<div class="row">';

//Abfragen der VALUES aus dem Modulinput, wenn die VALUES leer sind bleiben die Variabeln leer.
    $detail_id = "REX_LINK[1]"; 

    if("REX_VALUE[2]"){
        $limit = "LIMIT REX_VALUE[2]";  
    }
    if("REX_VALUE[8]"){
        $ham = 'h.i';
        $uhr = ' Uhr';
    }

    $db_table = "vnews_article";
    $db_table_deux = "vnews_category";
    $db_table_tres = "vnews_author";
    $sql = rex_sql::factory();
    $sql->setDebug(false); //Ausgabe Query
    // Verbinden mit den 3 Datenbanken/Tabellen. Die Artikel werden zudem mit dem passenden Autor und der Kategorie verknüpft
    $sql->setQuery("SELECT art.*, cat.*, aut.* FROM $db_table art, $db_table_deux cat, $db_table_tres aut WHERE art.article_author = aut.id AND art.article_category = cat.id AND art.article_status = 'online' $limit");

     if($sql->getRows()) {
          while($sql->hasNext()) {
 
    //Variabeln für die einzelnen Felder 
    $art_id = $sql->getValue('art.id');
    $titel = $sql->getValue('article_title');
    $author = $sql->getValue('author_name');
    $category = $sql->getValue('category_name');
    $lead = $sql->getValue('article_lead');     
    $datum =  $sql->getValue('article_date');
    $date = date("d.m.Y $ham", strtotime($datum));
    $pic = $sql->getValue('article_pic');
    $status = $sql->getValue('article_status');
              
    $detail_url = rex_getUrl($detail_id, '', ['id' => $art_id]);
    
    $out = ''; //Sammelt alle Werte und gibt diese am Schluss als ganzes aus.
   
    //Abfrage des Link-Elements, muss nach dem zusammenbauen des Links stattfinden und vor der Ausgabe der <a> Elemente ausgeben wegen Variabel-Definition.           
      if("REX_VALUE[3]"){
        $linked_title_begin = '<a href="'.$detail_url.'">';
        $linked_title_end = '</a>';
    }
    else{
        $linked_button = '<a class="btn btn-info btn-sm" href="'.$detail_url.'">Weiter</a>';
    }          
              
    $spalte = 'REX_VALUE[11]';
    switch ($spalte)
    {
    case 'links':
        $out .= '<div class="card medium">';
        $out .= '<div class="col-md-12">';
        $out .=  '<p class="vnews_titel_liste liste_titel">'.$linked_title_begin.$titel.$linked_title_end.'</p>';
        if("REX_VALUE[4]"){
            $out .=  '<div class="vnews_aut card-content">'.$author.'</div>';
        }
        if("REX_VALUE[5]"){
            $out .=  '<div class="vnews_cat card-content">'.$category.'</div>';
        }
        if("REX_VALUE[7]"){          
            $out .=  '<div class="vnews_time card-content">'.$date.$uhr.'</div>';
        }
        $out .= '</div>';
        $out .= '<div class="col-md-4 col-sm-12">';
        if("REX_VALUE[9]"){ 
			if(rex::isBackend()) {
				$out .=  '<img class="img-responsive" src="index.php?rex_media_type=rex_mediabutton_preview&rex_media_file='.$pic.'">';
			}else{
            	$out .=  '<img class="img-responsive" src="/media/'.$pic.'">';
			}
        }
        $out .= '</div>';
        $out .= '<div class="vnews_lead card-content col-md-8 col-sm-12">';
        if("REX_VALUE[6]"){
            $out .= $lead;
        }
        
        $out .= $linked_button;

        $out .= '</div>';
        $out .= '</div>';


    break;  
    case 'oben':
    $out .= '<div class="col-md-12 col-sm-12">';    
    $out .=  '<p class="vnews_titel_liste liste_titel">'.$linked_title_begin.$titel.$linked_title_end.'</p>';
    if("REX_VALUE[4]"){
        $out .=  '<div class="vnews_aut card-content">'.$author.'</div>';
    }
    if("REX_VALUE[5]"){
        $out .=  '<div class="vnews_cat card-content">'.$category.'</div>';
    }
    if("REX_VALUE[7]"){          
        $out .=  '<div class="vnews_time card-content">'.$date.$uhr.'</div>';
    }
    if("REX_VALUE[9]"){
		if(rex::isBackend()) {
				$out .=  '<img class="img-responsive" src="index.php?rex_media_type=rex_mediabutton_preview&rex_media_file='.$pic.'">';
			}else{
        $out .=  '<img class="img-responsive" src="/media/'.$pic.'">';
		}
    }
    if("REX_VALUE[6]"){
		$out .= '<div class="vnews_lead card-content col-md-8 col-sm-12">';
        $out .=  $lead;
		$out .= '</div>';
    }          
    
    $out .= $linked_button;  
    $out .= '</div>';
    
 
        
    break;  
    case 'rechts':
    
        $out .= '<div class="card medium">';
        $out .= '<div class="col-md-12">';
        $out .=  '<p class="vnews_titel_liste liste_titel">'.$linked_title_begin.$titel.$linked_title_end.'</p>';
        if("REX_VALUE[4]"){
            $out .=  '<div class="vnews_aut card-content">'.$author.'</div>';
        }
        if("REX_VALUE[5]"){
            $out .=  '<div class="vnews_cat card-content">'.$category.'</div>';
        }
        if("REX_VALUE[7]"){          
            $out .=  '<div class="vnews_time card-content">'.$date.$uhr.'</div>';
        }
        $out .= '</div>';
        $out .= '<div class="col-sm-4 col-sm-push-8">';
        if("REX_VALUE[9]"){
			if(rex::isBackend()) {
				$out .=  '<img class="img-responsive" src="index.php?rex_media_type=rex_mediabutton_preview&rex_media_file='.$pic.'">';
			}else{
            $out .=  '<img class="img-responsive" src="/media/'.$pic.'">';
			}
        }
        $out .= '</div>';
        $out .= '<div class="vnews_lead card-content col-sm-8 col-sm-pull-4">';
        if("REX_VALUE[6]"){
            $out .= $lead;
            $out .= $linked_button;
        }
 
        $out .= '</div>';
        $out .= '</div>';

     
       
        
        
    break;  
    }
              
    print $out;
              
    $sql->next();
         }
     }
    
    print '</div>';
    print '</div>';
?>


