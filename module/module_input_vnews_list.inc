<?php
    $db_table_deux = "vnews_category";
    $db_table_tres = "vnews_author";
    $sql = rex_sql::factory();
    $sql->setDebug(false); //Ausgabe Query
    // Verbinden mit den 2 Datenbank
    $sql->setQuery("SELECT cat.*,aut.* FROM $db_table_deux cat, $db_table_tres aut");
    
$mform = new MForm();

$mform->addFieldset('Artikelliste');

$mform->addSelectField("10", array("8"=>'8er',"10"=>'10er'), array('label'=>'Spaltenbreite'));

$mform->addRadioField("11",array("oben"=>'Über dem Text',"links"=>'Links vom Text',"rechts"=>'Rechts vom Text'),array('label'=>'Platzierung des Bildes','class'=>"radio"));

$mform->addLinkField("1",array('label'=>'Detailansicht-Artikel'));

$mform->addTextField("2", array('label'=>'Anzahl Artikel'));

$mform->addCheckboxField("3",array("3"=>'Titel verlinken (Wenn dieses Feld nicht angekreuzt ist, wird ein "Weiter"-Button am Ende des Leads platziert)'),array('label'=>'Artikelausgabe definieren'));

$mform->addCheckboxField("4",array("4"=>'Autor anzeigen'));

$mform->addCheckboxField("5",array("5"=>'Kategorie anzeigen'));

/*if($sql->getRows()) {

echo '<select class="form-control" name="REX_INPUT_VALUE[12]">';
while($sql->hasNext()) {

$kategorie  = $sql->getValue('category_name');

        echo '<option value="'.$kategorie.'" ';
        if ( "REX_VALUE[12]"=="$kategorie" ) {
          echo 'selected="selected" ';
        }   
        echo '>'.$kategorie.'</option>';
        $sql->next();
    }
echo '</select>';
}*/

$mform->addCheckboxField("6",array("6"=>'Lead anzeigen'));

$mform->addCheckboxField("7",array("7"=>'Datum anzeigen'));

$mform->addCheckboxField("8",array("8"=>'Uhrzeit anzeigen (nur wenn Datum auch angezeigt wird)'));

$mform->addCheckboxField("9",array("9"=>'Bild anzeigen'));

echo $mform->show();

?>
