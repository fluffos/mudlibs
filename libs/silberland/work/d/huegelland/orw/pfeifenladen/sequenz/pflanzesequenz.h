//  Projekt   : Barry's Pfeifenladen
//  Objekt    : Sequenz beim Rauchen der Nakrafulpflanze
//  Erstellt  : 03.06.2001 (Orw)
//  Geaendert : -

#define FIGUREN ({"eines Stegs","einer Burg","eines Walfaengers", \
                  "eines Schlosses","eines Wachturms","eines Wasserfalls", \
                  "eines Turms","eines Bergs","einer riesigen Spinne", \
		  "eines Torbogens","eines Kraters","einer Eiche", \
		  "eines Throns","eines Pilzes","eines riesigen Vogels", \
		  "eines Altars","einer Blutulme","einer kleinen Piazza", \
		  "einer Huette","einer Kaverne","eines Kerzenhalters", \
		  "einer Oase","eines riesigen Wurms","einer Kneipe" })

#define ORT     ({"/d/wueste/protheg/kraterrand/room/steg", \
                  "/gilden/paladine/room/burg_c2", \
                  "/d/wasser/feyaria/schiffe/walfaenger", \
                  "/d/ebene/ronja/feenquest/room/kerker", \
                  "/d/polar/thor/xandim/room/wachturm3", \
                  "/d/dschungel/dante/weg/room/weg10", \
                  "/d/ebene/lamuerte/turm/rooms/platte", \
                  "/d/gebirge/angrox/room/ebene1/bergwerk_r14", \
		  "/d/unterwelt/zordan/dhrkion/room/wall-e1", \
		  "/d/ebene/lamuerte/burg/weg/16x6y", \
		  "/d/unterwelt/basics/central/room/01-01+11", \
		  "/d/kristallwald/sargola/wald/room/4_0602", \
		  "/d/gebirge/speedy/trollager/room/boss", \
		  "/d/gebirge/orw/quest/room/hain4", \
		  "/d/gebirge/eros/room/berg_d18", \
		  "/d/dschungel/feyaria/tijara/room/kult", \
		  "/d/dschungel/feyaria/dorf/room/baum-0b0", \
		  "/d/ebene/Midas/room/kanal/piazza_c6", \
		  "/d/unterwelt/amazora/dimension/room/huette", \
                  "/d/gebirge/angrox/4elem/room/hoehle/hoehle_j7", \
		  "/d/gebirge/orw/grotte/room/grotte8", \
		  "/d/wueste/arthoas/erg/room/aragh/raum43", \
		  "/d/gebirge/monimor/room/see", \
		  "/d/unterwelt/zordan/dhrkion/room/kneipe" })

int zufall;


int pflanzerauchen1(object raucher)
{
  if(raucher)
  {
    write(BS("Du wunderst Dich ueber den komischen Geschmack der Nakrafulpflanze. "
          "Irgendwie nicht schlecht, aber irgendwie auch ganz anders als alles "
          "das Du bisher geraucht hast.\n\n"));
    say  (BS(raucher->name()+" schliesst "+raucher->QueryPossPronoun(FEMALE,WEN)+
              " Augen und entspannt sich total.\n"));
    call_out("pflanzerauchen2", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen2(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    write(BS("Vergnuegt springst Du herum und machst "+RINGERL[formringerl]+". "
          "Du fuehlst Dich total frei, denkst an die Weiten der Wueste.\n\n"));
    say  (BS(raucher->name()+" blaest vergnuegt "+RINGERL[formringerl]+".\n"));
    call_out("pflanzerauchen3", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen3(object raucher)
{
  if(raucher)
  {
    zufall=random(24);
    write(BS("Bilder dringen in Deinen Kopf ein, Bilder "+FIGUREN[zufall]+". "
          "Du gruebelst ob sie Dir bekannt vorkommen, ob Du dort "
          "schon mal warst.\n\n"));
    say  (BS(raucher->name()+" scheint in Gedanken versunken.\n"));
    call_out("pflanzerauchen4", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen4(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    write(BS("Du nimmst einen tiefen Zug aus der Pfeife und machst "
          +RINGERL[formringerl]+". Die Bilder verpuffen wieder.\n\n"));
    say  (BS(raucher->name()+" raucht laessig eine Nakrafulpflanze und "
              "blaest "+RINGERL[formringerl]+".\n"));
    call_out("pflanzerauchen5", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen5(object raucher)
{
  if(raucher)
  {
    write(BS("Deine Augen werden muede, Dein Atem wird immer regelmaessiger und "
          "die Welt um Dich herum scheint zu verschwimmen.\n\n"));
    say  (BS(raucher->name()+" bewegt sich immer langsamer.\n"));
    call_out("pflanzerauchen6", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen6(object raucher)
{
  if(raucher)
  {
    zufall=random(24);
    write(BS("Wieder finden Bilder Zugang zu Deinen Gedanken. "
          "Sie nehmen die Form "+FIGUREN[zufall]+" an.\n\n"));
    say  (BS(raucher->name()+" sieht benommen aus.\n"));
    call_out("pflanzerauchen7", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen7(object raucher)
{
  if(raucher)
  {
    write(BS("Du konzentrierst Dich auf die Bilder. Sie draengen in Deinen Kopf, "
          "lassen Dir keine Ruhe. Du versuchst danach zu greifen...\n\n"));
    say  (BS(raucher->name()+" taumelt herum.\n"));
    call_out("pflanzerauchen8", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen8(object raucher)
{
  if(raucher)
  {
    write(BS("Erschrocken stellst Du fest, dass sich Dein Koerper langsam "
          "aufloest. Du erinnerst Dich an die Nakrafulpflanze und kommst "
          "Dir ploetzlich ziemlich bloed vor... wieso musst Du auch jeden "
          "Mist den Du findest in der Pfeife rauchen...\n\n"));
    say  (BS(raucher->name()+" scheint sich langsam aufzuloesen.\n"));
    call_out("pflanzerauchen9", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen9(object raucher)
{
  if(raucher)
  {
    write(BS("Die Bilder werden immer staerker, Dein Koerper loest sich nun ganz "
          "auf... In Deinem Kopf schwirren tausend Muecken...\n\n"));
    say  (BS(raucher->name()+" verkrampft sich und loest sich weiter auf.\n"));
    call_out("pflanzerauchen10", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen10(object raucher)
{
  if(raucher)
  {
    write(BS("Ploetzlich findest Du dich an dem Ort wieder, den Du in Deinen "
          "Visionen gesehen hast...\n"));
    raucher->move(ORT[zufall], M_GO, 
             "vor Deinen Augen",
             "verschwindet",
             "erscheint mit einem lauten Knall");
    call_out("pflanzerauchen11", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int pflanzerauchen11(object raucher)
{
  if(raucher)
  {
    write(BS("Total benommen nimmst Du noch einen letzten Zug aus Deiner "
          "Pfeife und steckst sie dann weg.\n\n"));
    say  (BS(raucher->name()+" nimmt noch einen letzten Zug aus der Pfeife und steckt "
          "sie dann weg.\n"));
    SetProp(P_SHORT, pfeifenname);
    SetProp(P_NODROP, 0);
    SetProp(P_NEVERDROP, 0);
    pfeifegestopft_kraut=0;
    pfeifeangezuendet=0;
    return 1;
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}
