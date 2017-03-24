<?php
    $ausrichtung = 'REX_VALUE[11]';

    if("REX_VALUE[8]"){
        $ham = 'h.i';
        $uhr = ' Uhr';
    }

    if(rex::isBackend()) {
        $newsy = 2; //Im Backend kann keine ID aus dem Link gelesen werden, deshalb die fixe Zahl des Testartikels
    }else{
        $newsy = UrlGenerator::getId(); //
    }

    $db_table = "vnews_article";
    $db_table_deux = "vnews_category";
    $db_table_tres = "vnews_author";
    $sql = rex_sql::factory();
    $sql->setDebug(false); //Ausgabe Query
    // Verbinden mit den 3 Datenbanken/Tabellen. Die Artikel werden zudem mit dem passenden Autor und der Kategorie verknüpft
    $sql->setQuery("SELECT art.*, cat.*, aut.* FROM $db_table art, $db_table_deux cat, $db_table_tres aut WHERE art.article_author = aut.id AND art.article_category = cat.id AND art.id = $newsy");
    
    $titel = $sql->getValue('article_title');
    $lead = $sql->getValue('article_lead');
    $text = $sql->getValue('article_text');
    $author = $sql->getValue('author_name');
    $category = $sql->getValue('category_name');
    $lead = $sql->getValue('article_lead');     
    $datum =  $sql->getValue('article_date');
    $date = date("d.m.Y $ham", strtotime($datum));
    $pic = $sql->getValue('article_pic');
    $status = $sql->getValue('article_status');
    
    $out = ''; //Sammelt alle Werte und gibt diese am Schluss als ganzes aus.
    
    $spalte = 'REX_VALUE[1]';
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

    switch ($ausrichtung)
    {
    case 'oben':
        if("REX_VALUE[9]"){           
            print '<div class="row"><div class="col-md-12"><img class="img-responsive vnews_detail_pic" src="/media/'.$pic.'"></div></div>';
        }    
    break;
    }
    
    print '<div class="vnews_article article '.$offset.' col-md-'.$spalte.' col-sm-'.$spaltesm.' col-xs-12">';
    
    print '<h1 class="vnews_detail_titel">'.$titel.'</h1>';
    
    if("REX_VALUE[3]"){
        print '<div class="vnews_detail_lead">'.$lead.'</div>';
    }


   switch ($ausrichtung)
    {
    case 'unten':
    if("REX_VALUE[9]"){           
        print '<div class="row"><div class="col-md-12"><img class="img-responsive vnews_detail_pic" src="/media/'.$pic.'"></div></div>';
    }    
    break;
    }
    
    if("REX_VALUE[4]"){
    print '<p class="vnews_detail_author">'.$author.'</p>';
    }

    if("REX_VALUE[5]"){
    print '<p class="vnews_detail_category">'.$category.'</p>';
    }
    
    if("REX_VALUE[7]"){
        print '<p class="vnews_detail_time">'.$date.$uhr.'<p>';
    }
    
    print '<div class="vnews_detail_text">'.$text.'</div>';
      
    print $out;
      
    if("REX_VALUE[6]"){ 
        if(rex::isBackend()) {//Unitegallery funktioniert nicht in Backend, daher wird thumbnail-ansicht der Bilder gezeigt.
                  print '<div class="col-md-12 col-xs-12">';    
    if ($sql->getValue('article_slider') != ''){
        $bilderliste = explode(',', $sql->getValue('article_slider')); 
        
        print '<div id="REX_SLICE_ID">';
            
        foreach ($bilderliste as $file) {
        $media = rex_media::get($file);
        if ($media) {
            
            print '<div class="col-md-4 thumbnail"><img class="img-responsive" src="/media/'.$file.'""></div>';
         
        } /*/if*/
    } /*/foreach*/
    print'</div>';
        } /*/if*/
    print'</div>';
          } else {
    print '<div class="col-md-12 col-xs-12">';    
    if ($sql->getValue('article_slider') != ''){
        $bilderliste = explode(',', $sql->getValue('article_slider')); 
        
        print '<div id="galleryREX_SLICE_ID" style="display:none;">';
            
        foreach ($bilderliste as $file) {
        $media = rex_media::get($file);
        if ($media) {
            
print '<img class="img-responsive" alt="'.$titel.'" data-image="index.php?rex_media_type=vnewsdata&amp;rex_media_file='.$file.'" src="index.php?rex_media_type=vnewssrc&amp;rex_media_file='.$file.'" data-description="'.$titel.'"> ';
         
        } /*/if*/
    } /*/foreach*/
    print'</div>';
        } /*/if*/
    print'</div>';
    print '<!--Unite Gallery JS-->
<script type="text/javascript"> 
jQuery("#galleryREX_SLICE_ID").unitegallery({
    gallery_theme: "tilesgrid",
    tile_enable_shadow:false,
    tile_enable_border:true,
    tile_border_width:1,
    tile_border_color:"#CCC",
    tile_border_radius:4,
    gallery_width:"100%",
    gallery_min_width: 100,
    theme_gallery_padding: 0,
    grid_padding:0,
});
</script>';
        }/*If Backend Abfrage */
    }/*if REX_VALUE*/
  
    print '<a class="btn btn-info btn-sm vnews_back" onclick="goBack()">Zurück</a>';
    print '</div>';
?>

<script>
function goBack() {
    window.history.back();
}
</script>
