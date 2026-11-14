void wohn0_desc(){
  int i;  
  SetProp (P_LIGHT, 1);
  SetProp (P_INDOORS, 0);
  SetProp (P_ENVIRONMENT, ([ENV_TEMPERATURE:20]));
  SetProp(P_INT_SHORT, "Irgendwo im Zeltlager");
  i=random(3);
  switch(i)
  {
  case 0:
  SetProp(P_INT_LONG, 
     "Scheint dein Auge Dich zu narren?\n"
     "Nur von emsig Elfenscharen\n"
     "gut verborgen mit Geschick\n"
     "birgt das Dorf sich jedem Blick!\n"
     "\n"
     "Gruen in gruen die Zelte rings,\n"
     "von den Aesten zwitschernd singt's,\n"
     "schwer ist etwas zu entdecken,\n"
     "man sieht ringsherum nur Hecken.\n"
     "\n"); 

   break;
  
  case 1:
  SetProp(P_INT_LONG, 
     "Tief inmitten dichter Baeume\n"
     "ist der Platz der Elfentraeume\n"
     "Rast und Ruh der Waldeswesen\n"
     "kann bei Tolkien man auch lesen.\n"
     "\n"
     "Dichte Zweige dunkler Hecken\n"
     "lassen gut das Dorf verstecken,\n"
     "was man meist nur dann erkennt,\n"
     "wenn man selbst schon Elf sich nennt.\n"
     "\n"); 

   break;

  case 2:
  SetProp(P_INT_LONG, 
     "Zelte braun und Zelte gruen,\n"
     "gut getarnt sie dicht hier stehen.\n"
     "Doch die Elfen lieben Ruh,\n"
     "selten sieht man ihnen zu.\n"
     "\n"
     "Deshalb sind sie gut getarnt,\n"
     "und vor Gaesten vorgewarnt.\n"
     "Sie sind leicht zu uebersehen,\n"
     "und man wird voruebergehen.\n"
     "\n"); 

   break;
 }
}

void wohn0_details(){
 
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
     "doch sieht man, wie sich's gut drin lebt.\n"
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

  AddDetail( ({"buesche", "busch", "hecke", "hecken"}),
     "Ein Flechtwerk dichter Hecken\n"
     "umgibt an allen Ecken\n"
     "die Zelte fest und fein,\n"
     "so sieht man nicht hinein.\n"
     "\n"); 

  AddDetail( ({"baum", "baeume", "wald"}),
     "In schier unendlichen Hoehen\n"
     "kann man die Wipfel der Baeume sehen,\n"
     "deren Schatten das Dorf der Elfen birgt\n"
     "und als Tarnung wahre Wunder wirkt.\n"
     "\n"); 

  AddDetail( ({"spitzen", "baumspitzen", "wipfel", "baumwipfel", "voegel"}),
     "Hoch auf den Baumspitzen\n"
     "wo nur die Voeglein sitzen\n"
     "scheint hell die Sonne\n"
     "zu der Voeglein Wonne.\n"
     "\n"); 

  AddSound(DEFAULT_SOUND, 
     "Still stehst Du da und lauschst dem Wald,\n"
     "den Voeglein klein, den Baeumen alt,\n"
     "der Ruhe und dem sanften Rauschen,\n"
     "gar stundenlang koenntest Du lauschen.\n"
     "\n"); 

  AddSmell(DEFAULT_SMELL,
     "Erfuellt ist rings die Waldesluft\n" 
     "von gar betoerend schwerem Duft\n"
     "der Blumen all, der Zweige Laub,\n"
     "dem Gras, und feinem Bluetenstaub.\n"
     "\n"); 

}

