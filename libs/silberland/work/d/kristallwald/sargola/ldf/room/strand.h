/*
**********************************************************
** 
** STANDARD ...... boden, himmel usw
** COMMANDS ...... Kommandos in allen Raeumen
** TRINKEN  ...... meerwasser trinken
** BADEN    ...... im meerwasser baden
** FUEHLE   ...... hitze fuehlen
** KOERNER  ...... um den Sand zwischen den Zehen zu spueren ;)
** STRAUCH  ...... ein alter knorpeliger Strauch
**
**********************************************************
*/


#define STANDARD								\
AddDetail("boden", "Der Boden hier besteht komplett aus weissem Sand. An "	\
  "vielen Stellen siehst Du Fussabdruecke. Muscheln ueber Muscheln liegen "	\
  "vom gruenblauen Meerwasser angeschwemmt am Strand. Auch einige groessere "	\
  "Felsbrocken liege hie und da herum.");					\
AddDetail( ({"fels","felsbrocken"}),"Einige Felsbrocken liegen verstreut "	\
  "am Strand herum. Ein paar ragen ins Wasser und sind schon ziemlich "		\
  "umspuelt und abgerundet. Andere haben noch schroffe Kanten und sind "	\
  "ebenso wie der Sand von der Sonne erwaermt.");				\
AddDetail("kanten","Pass lieber auf, damit Du Dir nicht wehtust.");		\
AddDetail("strand", "Soweit Dein Auge reicht kannst Du nur weissen Sand "	\
  "entdecken. Die Brandung schlaegt sanft mit weisslichem Schaum ans Ufer.");	\
//AddDetail("sand","Der Sand ist so weiss, dass man fast die Augen ein wenig "	\
//  "schliessen muss, damit man noch etwas sehen kann. Er besteht aus feinen "	\
//  "Koernern, die durch die Sonne erwaermt sind.");				\
AddDetail("sand",#'sand_check);							\
AddDetail( ({"strahlen","sonne"}),"Ihre Strahlen erwaermen den Strand und "	\
  "laden so zum Baden ein.");							\
AddDetail("baden", "*Grummel* Baden ist kein Hauptwort.");			\
AddDetail("hauptwort","Hmmmm.... und wie siehst mit Apoiuztrewxcvb aus?");	\
AddDetail("Apoiuztrewxcvb","Okok, Du bekommst den Forscherpunkt.");		\
AddDetail("forscherpunkt","AEEETSCH!!! Doch nicht! *grins*");			\
AddDetail("aeeetsch","Jetzt wirds aber fad ...");				\
AddDetail( ({"abdruecke","fussabdruecke"}), "Es sind viele, also laufen "	\
  "und spielen hier wohl oft andere Leute.");					\
AddDetail("leute","Die kannst Du gerade nicht sehen.");				\
AddDetail("muscheln", "Es gibt hier soviele Muscheln, du kannst sie gar nicht"	\
  "zaehlen. Obwohl sie schoen geformt sind, kannst Du trotzdem nichts damit "	\
  "anfangen.");									\
AddDetail("straeucher","Hie und da siehst Du alte, von der Hitze fast kahle "	\
  "Straeucher wachsen. Duerre Zweige zeugen von der grossen Hitze, die "	\
  "hier um die Mittagszeit herrschen muss.");					\
AddDetail("zweige","Die Zweige haben kaum Blaetter und wirken knorrig.");	\
AddDetail("hitze","Die kann man nicht sehen, nur fuehlen.");			\
AddDetail("mittagszeit","Die Hitze brennt runter, dass Du glaubst \"Des gibts "	\
  "jo ned!\" ... und gleich drauf: \"Gibts des?\".");				\
AddDetail("des","Auf Hochdeutsch heisst \"des\" \"das\".");			\
AddDetail("nass","Du meinst wohl das Wasser, oder?");				\
AddDetail( ({"wasser","meerwasser"}), "Das Wasser ist unglaublich rein und "	\
  "hat eine gruenblaue Farbe. Leise schlagen die Wellen ans sandige Ufer und "	\
  "Du fuehlst Dich wohl hier.");						\
AddDetail("farbe", "Die ist gruenblau.");					\
AddDetail("ufer","Du stehst am Ufer des Meeres.");				\
AddDetail("koerner",#'koerner);							\
//AddDetail("koerner","Der Sand ist sehr feinkoernig, das macht es noch an"	\
//  "genehmer, hier barfuss herumzuspazieren.");				\
AddDetail("auge", "Du blickst Dir lange in die Augen und bist zutiefst "	\
  "beruehrt.");									\
AddDetail("meer","Du blickst Dich um und fuehlst Dich im Vergleich zum "	\
  "riesigen Meer ganz klein.");							\
AddDetail("himmel","Der Himmel ist, ebenso wie das Meer ,strahlend blau. "	\
  "Aber er ist heller und von einigen weissen Schaefchenwolken bedeckt.");	\
AddDetail( ({"wolken","schaefchenwolken"}), "Die Wolken heissen nicht um"	\
  "sonst Schaefchenwolken. Einige haben wahrlich die Form eines Schafes.");	\
AddDetail("schaf","Im ersten Augenblick dachtest Du, da waere doch tatsaech"	\
  "lich ein Schaf am Himmel!");							\
AddDetail("form","Tja, es ist halt die Form eines Schafes.");			\
AddDetail("augenblick", "Mist, schon ist er wieder vorbei!");			\
AddSound(DEFAULT_SOUND, "Das leise Rauschen des Meeres dringt an Dein Ohr.");	\
AddSound(({"brandung","meer"}) ,"Leise schlaegt die Brandung an den "		\
  "Strand.");									\
AddSound("rauschen","RAUUUUUUSCHHHHHHH....");					\
AddSound("schaf","WOOOW! Es bloeckt ja! *staun*  :)");				\
AddSound("muscheln","Du hoerst das Meer rauschen.");				\
AddSmell(DEFAULT_SMELL,"Du riechst den herben Geruch des Meeres.");		\
AddSmell("meer","Ganz intensiv riechst Du den salzigen Geruch des Wassers.");	\
AddSmell("wasser","Die Luft ist mit salzigem Duft angereichert, der wohl "	\
  "vom Meer stammt.");								
  
#define STRAUCH									\
AddDetail(({"aussehen","strauch"}),						\
  "Ein kleiner Strauch mit knorpeligen Aesten. Er reicht "			\
  "Dir in etwa zu den Knien und hat kleine, dunkelgruene und ovale "		\
  "Blaetter.");									\
AddDetail("aeste","Die Aeste sind an den Astgabelungen dicker als sonst "	\
  "und das bewirkt das knorpelige Aussehen des Strauches. An ihnen haengen "	\
  "eine Menge Blaetter.");							\
AddDetail("knie","Die gehoeren aber nicht zum Strauch.");			\
AddDetail("blaetter","Sie sind dunkelgruen und oval.");

#define COMMANDS								\
AddCmd(({"schwimm","schwimme","bade"}),"baden");				\
AddCmd(({"trink","trinke"}),"trink");						\
AddCmd(({"fuehlen","fuehle","fuehl"}),"fuehlen");

#define BADEN									\
int baden(string str)								\
{										\
  notify_fail("Was moechtest Du worin tun?\n");					\
  if(!str) return 0;								\
  if(str!="in wasser"||str!="in meer")						\
    return 0;									\
  										\
  write("Du reisst erfreut Deine Sachen vom Leib und stuerzt Dich ins "		\
  "herrliche kuehle Nass.");							\
  say(TPN+" reisst sich alle Kleider vom Leib und stuerzt sich ins kuehle "	\
  "Nass.");									\
  return 1;									\
}


#define TRINKEN									\
int trinken(string str)								\
{										\
  notify_fail("Was moechtest Du trinken?\n");					\
  if(!str) return 0;								\
  if(str!="wasser"||str!="meerwasser")						\
    return 0;									\
  										\
  write("Waeh! Rein ist das Wasser ja, aber so salzig....");			\
  say(TPN+" trinkt vom Wasser und verzieht angewidert das Gesicht.");		\
  return 1;									\
}



#define FUEHLEN									\
int fuehlen(string str)								\
{										\
  object * r;									\
  int i, erlaubt;								\
  string typ;									\
  erlaubt = 1;									\
										\
  notify_fail("Was moechtest Du fuehlen?\n");					\
  if(!str) return 0;								\
  if(str=="hitze")								\
  {										\
    write("Wirklich ziemlich heiss hier ...\nDer Schweiss rinnt Dir den "	\
      "Ruecken runter.");							\
    say(TPN+" ist sichtlich von der unglaublichen Hitze gekennzeichnet.");	\
      return 1;									\
  }										\
  if(str=="kanten"||str=="kante")						\
  {										\
     write("Autsch! Jetzt hast Du Dir doch tatsaechlich die Zehe aufge"		\
       "schnitten.");								\
     say(TPN+" hat sich in "+(TP->QueryProp(P_GENDER)==MALE)? "seiner":"ihrer") \
     	+" Tollpatschigkeit die Zehe aufgeschnitten.");				\
     TP->reduce_hit_points(4);							\
     return 1;									\
   }										\
   if(str=="sand zwischen den zehen"||str=="sand zwischen zehn")		\
   {										\
	if(TO != find_object("/d/kristallwald/sargola/ldf/room/strand3"))	\
   	{									\
	     tell_object(TP, "Der Sand ist sehr feinkoernig, das macht es "	\
	       "noch an genehmer, hier barfuss herumzuspazieren.");		\
	     return 1;								\
	}									\
   r = TP->QueryProp(P_ARMOURS);						\
   if(sizeof(r)>0)								\
   {  										\
      for(i = sizeof(r)-1; i>=0;i--)						\
      {	typ = r[i]->QueryProp(P_ARMOUR_TYPE);					\
   	if(typ == AT_BOOT)							\
   		erlaubt = 0;							\
      }										\
   }										\
   if(!erlaubt)									\
   {										\
     tell_object(TP, "Du hast ja noch Schuhe an!");				\
     return 1;									\
   }										\
   tell_object(TP, "Du geniesst es, den warmen Sand an den Fussohlen "		\
     "zu spueren und fuehlst den Sand zwischen den Zehen.");			\
   return 1;									\
}
     