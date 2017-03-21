<?php

$mform = new MForm();

$mform->addFieldset('Artikelliste Detailansicht');

$mform->addSelectField("1", array("8"=>'8er',"10"=>'10er'), array('label'=>'Spaltenbreite'));

$mform->addCheckboxField("3",array("3"=>'Lead anzeigen'));

$mform->addCheckboxField("4",array("4"=>'Autor anzeigen'));

$mform->addCheckboxField("5",array("5"=>'Kategorie anzeigen'));

$mform->addCheckboxField("6",array("6"=>'Galerie anzeigen'));

$mform->addCheckboxField("7",array("7"=>'Datum anzeigen'));

$mform->addCheckboxField("8",array("8"=>'Uhrzeit anzeigen (nur wenn Datum auch angezeigt wird)'));

$mform->addCheckboxField("9",array("9"=>'Bild anzeigen'));

$mform->addRadioField("11",array("oben"=>'Über Titel',"unten"=>'Unter Titel'),array('label'=>'Platzierung des Bildes','class'=>"radio"));

//mForm Element ausgeben
echo $mform->show();

?>