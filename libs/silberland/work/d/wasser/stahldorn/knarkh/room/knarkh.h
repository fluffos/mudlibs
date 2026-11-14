// knarkh.h
// Details zum Dorf Knarkh
// Stahldorn@Silberland 12.3.97

#define DORFDETAILS \
  AddDetail( ({ "boden", "weg", "pflaster" }), \
    "Der Boden ist steinig und wirkt ungepflegt. Aus den Rissen im Pflaster " \
    "wuchert bueschelweise das Unkraut."); \
  AddDetail( ({ "himmel", "sonne" }), \
    "Am Himmel scheint die Sonne."); \
  AddDetail( ({ "pflanzen", "unkraut", "bueschel" }), \
    "Lauter giftiges Unkraut."); \
  AddDetail( ({ "risse", "loecher", "loch", "riss" }), \
    "Der Boden ist ueberall aufgebrochen und loechrig. "); \
  AddDetail( ({ "steine", "belag" }), \
    "Irgendwelche Wurzeln haben den Boden gelockert und der Strassenbelag " \
    "ist in Form von Steinen ueberall verstreut."); \
  AddDetail( ({ "wurzeln", "wurzel" }), \
    "Sind wahrscheinlich an den Rissen im Belag schuld. " \
    "Aber komisch, dass keine der Wurzeln an die Oberflaeche getreten ist."); \
  AddDetail( ({ "knarkh", "dorf" }), \
    "Das boese Dorf, in dem Du dich befindest, heisst Knarkh. " \
    "Die Einwohner sehen zum Grossteil nicht besonders freundlich aus."); \
  AddDetail( ({ "einwohner", "gestalten" }), \
    "Die Einwohner von Knarkh sind alle entweder Orks, Oger, Trolle oder " \
    "Gaffos. Menschen, Elfen, Zwerge oder Hobbits sieht man nur selten."); \
  AddDetail( ({ "orks", "gaffos", "trolle", "typen", "oger" }), \
    "Boese und finstere Typen, die sicher keine Skrupel haben, zu toeten."); \
  AddDetail( ({ "menschen", "elfen", "zwerge", "hobbits" }), \
    "Sieht man selten, aber sie schauen auch nicht recht nett aus.");

#define DORFSMELLS \
  AddSmell( DEFAULT_SMELL, \
    "Es stinkt grauslich nach Verwesung und Faeulnis."); \
  AddSmell( ({"faeulnis", "verwesung", "gestank"}), \
    "Dir scheint, der TOD hat hier Einzug gehalten."); 

#define DORFSOUNDS   \
  AddSound( DEFAULT_SOUND, \
    "Von irgendwoher dringen Schreie an Dein Ohr."); \
  AddSound( ({"schreie", "schrei"}), \
    "Klingt fuerchterlich. Du willst lieber nicht wissen, wo das herkommt."); 

#define STANDARDLANG \
      "Du stehst im boesen Dorf Knarkh. Alles hier wirkt feindlich. " + \
      "Ueberall laufen dunkle Gestalten herum und schauen Dich gierig an. " 

#define STANDARDBOES  \
      "Da Du hier als "+ alignstring(TP) + \
      " bekannt bist, fuehlst Du Dich wie unter Freunden."

#define STANDARDGUT \
      "Da Du hier als "+ alignstring(TP) + \
      " bekannt bist, ist Dir auch ziemlich mulmig..."

#define STANDARDNEUTRAL \
      "Da Du hier als "+ alignstring(TP) + \
      " bekannt bist, hoffst Du, dass Dir nichts passiert."

#define STDFUNC \
string alignstring(object player) \
{ \
  return player->al_to_title(player->QueryProp(P_ALIGN)); \
} \
 \
string gut_boes() \
{ \
  if ( TP->QueryProp(P_ALIGN) > 40 ) \
    return "\n"+STANDARDGUT; \
  if (TP->QueryProp(P_ALIGN) < -39 ) \
    return "\n"+STANDARDBOES; \
    return "\n"+STANDARDNEUTRAL; \
}


#define PLAZALANG \
	"Du befindest Dich nun auf der Plaza von Knarkh. Dieser hochtrabende "\
	"Name wird aber der Realitaet kaum gerecht. Im Prinzip ist die "\
	"Plaza nicht mehr als eine haus- und huettenlose Flaeche, die von "\
	"Dreck und Unrat uebersaet ist. "

#define PLAZADETAILS \
  AddDetail("boden", "Der Boden ist voller Dreck."); \
  AddDetail( ({"dreck", "unrat"}), BS( \
   "Der Dreck hier ist uebelriechend und trotzdem sehr uninteressant.") ); \
  AddDetail( ({ "flaeche", "plaza", "platz" }), BS( \
   "Der Platz, auf dem Du stehst, wird 'Plaza' genannt.") ); \
  AddDetail( ({ "himmel" }), BS( \
   "Am Himmel ist kaum ein Woelkchen zu sehen. Eigentlich ein strahlend " \
   "schoener Tag, der gar nicht zu dieser grauslichen Umgebung passt.") ); \
  AddDetail( ({ "wolke", "wolken", "woelkchen" }), BS( \
   "Es ist kein Woelkchen zu sehen!") ); \
  AddDetail( ({ "sonne" }), BS( \
   "Die Sonne brennt vom Himmel. Es ist ziemlich schwuel hier.") );\
  AddDetail( ({ "knarkh", "dorf" }), \
   "Du stehst im Dorf Knarkh." );\
  AddDetail( ({ "name", "prinzip", "realitaet" }), \
   "Das Prinzip der Realitaet ist ihr Name. \n" \
   "(Danke an Justavius fuer diese sinnvollen Detailvorschlaege. :) )\n");\


