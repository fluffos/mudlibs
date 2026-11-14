void wohn1_desc(){
  int i;
  SetProp (P_LIGHT, 1);
  SetProp (P_INDOORS, 1);
  SetProp (P_ENVIRONMENT, ([ENV_TEMPERATURE:20]));  
  SetProp(P_INT_SHORT, "In einem elfischen Wohnzelt");
  i=random(2);
  switch(i)
  {
  case 0:
  SetProp(P_INT_LONG, 
     "Mit Zweigen ist der Eingang dicht,\n"
     "Du spuerst es schmerzlich im Gesicht.\n"
     "Das Laub sieht aus wie frisch geschnitten,\n"
     "doch muss es alt sein, unbestritten.\n"
     "\n"
     "Das Innere ist sehr gemuetlich,\n"
     "bei naeherer Betrachtung fuegt sich,\n"
     "dass Bett, Tisch, Stuehle und Regal\n"
     "gemacht aus Zweigenmaterial!\n"
     "\n"); 

   break;
  
  case 1:
  SetProp(P_INT_LONG, 
     "Mit etwas Muehe, List und Tuecke\n"
     "schaffst du im Eingang eine Luecke.\n"
     "Die Zweige sind so fest und fein,\n"
     "doch scheinen gar nicht alt zu sein.\n"
     "\n"
     "Das ganze Zelt ist so gewebt,\n"
     "Regal und Stuehle, der Tisch lebt,\n"
     "das Bett aus feinem Astgeflecht,\n"
     "im Kuechenkasten wohnt ein Specht.\n"
     "\n"); 


   break;

 }
}

void wohn1_details(){
 
  AddDetail( ({"zeltlager", "lager"}),
     "In muehevoller Handarbeit\n"
     "ward dieses Lager einst bereit'.\n"
     "Von Elfenhand erbaut es stand,\n"
     "und unberuehrt von Menschenhand.\n"
     "\n"
     "*bei nicht elfen zusaetzlich:*\n"
     "Nach schier unendlich langer Zeit\n"
     "scheint hier Deine Anwesenheit\n"
     "fast ungehorsam der Natur,\n"
     "guter Freund - was suchst Du nur?\n"
     "\n"); 

  AddDetail( ({"vogel", "voegel"}),
     "Sie flattern hin und flattern her\n"
     "und zwitschern, ja sie freuen sich sehr.\n"
     "Sie singen voller Lebenslust,\n"
     "sind keiner Sorgen sich bewusst.\n"
     "\n"); 

  AddDetail( ({"zelte", "zelt"}),
     "Man muss dicht an den Zelten stehn\n"
     "um sie erst richtig zu besehn,\n"
     "aus Stoff und Aesten nur gewebt,\n"
     "doch sieht man, wie sichs gut drin lebt.\n"
     "\n"); 

  AddDetail( ({"blumen","blume"}),
     "Sie anzusehen in Farbenpracht\n"
     "erfreuet Herz und Sinne,\n"
     "obwohl dein Herz sonst nur bedacht\n"
     "auf Highscore und Gewinne.\n"
     "\n"); 
      
  AddDetail( ({"gras", "boden"}),
     "Das Gras scheint gaenzlich unberuehrt\n"
     "als ob es Tritte nie vespuert,\n"
     "doch Elfen haben eins gemein:\n"
     "Sie sinken in das Gras nicht ein.\n"
     "\n"); 

  AddDetail( ({"zweig", "zweige"}),
     "Die Blaetter sacht beiseit geschoben\n"
     "siehst du die Aeste dicht verwoben,\n"
     "aus denen alles hier gemacht,\n"
     "selbst Waende und des Zeltes Dach.\n"
     "\n"); 

  AddDetail( "blatt",
     "Die Blaetter hier sind interessant,\n"
     "das hast du nie zuvor gekannt,\n"
     "dies alte Blattwerk hat noch Saft,\n"
     "woher stammt all die Lebenskraft?\n"
     "\n"); 

  AddDetail( "lebenskraft",
     "Die Lebenskraft von der Natur\n"
     "scheint manchen Menschen unnuetz nur,\n"
     "doch ohne stet' Metarmorphos\n"
     "ist auf der Erde gar nichts los.\n"
     "\n");

  AddDetail( "blaetter",
     "Fuer wohnlichere Ausgestaltung\n"
     "und zur Gemuetlichkeitsentfaltung\n"
     "dient weiches Blaetterwerk allumher\n"
     "es macht sich doch gemuetlich sehr!\n"
     "\n"
     "Sogar von Blaettern sind verdeckt\n"
     "die Waende, wie man hier entdeckt.\n"
     "Auch ist das Dach vor Regen fest,\n"
     "damit der Elf nicht ganz durchnaesst.\n"
     "\n"); 

  AddDetail( "dach",
     "Du hast noch nie ein Dach gesehen??\n"
     "Dann lass jetzt den Computer stehen\n"
     "und mach mal kurz das Fenster auf,\n"
     "sonst hoert dein Hirn zu denken auf.\n"
     "\n");

  AddDetail( ({"tisch", "stuhl", "stuehle", "regal", "sessel", "bett", "einrichtung", "moebelstuecke"}),
     "Das ganze Zelt ist nur aus Holz,\n"
     "aus frischen gruenen Zweigen.\n"
     "Es ist der Elfen ganzer Stolz,\n"
     "laedt fast dich ein, zu bleiben.\n"
     "\n"); 

  AddSound(DEFAULT_SOUND,
     "Still stehst du da und lauschst dem Wald,\n"
     "den Voeglein klein, den Baeumen alt,\n"
     "der Ruhe und dem sanften Rauschen,\n"
     "gar stundenlang koenntest Du lauschen.\n"
     "\n"); 

  AddSmell(DEFAULT_SMELL,
     "Erfuellt ist rings die Waldesluft\n"
     "von gar betoerend schwerem Duft\n"
     "der Blumen all, der Zweige Laub,\n"
     "dem Gras, und feinem Blaetterstaub.\n"
     "\n"); 

}

