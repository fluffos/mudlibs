/* 
***********************************************
** see.h                                      *
**                                            *
** date: 23-03-97 by Sargola@Silberland       *
** Email: a9504778@unet.univie.ac.at          * 
*********************************************** 
** 
**       
** STANDARD 
** GEBIRGE_NAH 
** GEBIRGE_FERN 
** SCHWIMMEN  
*/ 
 
#define STANDARD1							\
AddDetail("boden",							\
	BS("Eine Art Wiese, die aber immer mehr in felsigen "		\
	"Untergrund uebergeht. In Richtung Wald nehmen wieder Blumen "	\
	"und Farne Ueberhand. Weiters siehst du die Promenade um den "	\
	"See."));							\
									\
AddDetail("hoehe",							\
	BS("Das Gebirge ist sicher so an die... Naja, so genau "	\
	"kannst Du das nicht sagen."));					\
									\
AddDetail("ruhe",							\
	BS("Die kann man nicht untersuchen, nur spueren."));		\
									\
AddDetail(({"promenade"}),						\
	BS("Sie ist deutlich in der Wiese zu sehen. Du bist offenbar "	\
	"nicht der Erste, der hier geht. Sie fuehrt von "		\
	+CAP(DIR_VON)+" nach "+CAP(DIR_BIS)+"."));			\
									\
AddDetail("himmel",							\
	BS("Der Himmel liegt tiefblau ueber Dir. Du legst Dich in "	\
	"die Wiese und versinkst in den unendlichen Tiefen."));		\
									\
AddDetail(({"tiefen","tiefe"}),					\
	BS("Am liebsten wuerdest Du noch viele Stunden hier liegen "	\
	"und Wolken deuten."));						\
									\
AddDetail("wolken",							\
	BS("Herrliche Schaefchen-Wolken praegen das Firmament."));	\
									\
AddDetail("schaefchenwolken",						\
	BS("Das sind die, welche wie Daunenkissen aussehen gutes "	\
	"Wetter vorhersagen, oder...?"));				\
									\
AddDetail("wetter",							\
	BS("Es ist einfach herrlich!"));				\
									\
AddDetail("firmament",							\
	BS("Es wird nur im Westen vom Gebirge und sonst vom Wald " 	\
	"begrenzt."));							\
									\
AddDetail(({"kristallwald","wald"}),					\
	BS("Von hier aus siehst Du nur die kristallartigen, "		\
	"weisslichen Baeume."));					\
									\
AddDetail(({ "blumen", "blume" }),					\
	BS("Alle moeglichen Sorten von Blumen mit roten, gelben und "	\
	"orangen Blueten findest Du hier ebenso wie Farne."));		\
									\
AddDetail(({"flora","sorten"}),						\
	BS("Wenn Du Dich nur in der Flora besser auskennen "		\
	"wuerdest..."));						\
									\
AddDetail(({"welle","wellen"}),					\
	BS("Die Wellen schlagen sanft am Ufer auf."));			\
									\
AddDetail("wiese",							\
	BS("Ideal um einmal mit einer Person, die Du sehr magst, "	\
	"hierherzukommen...."));					\
									\
AddDetail("person",							\
	BS("Wer das ist, das musst schon Du wissen..."));		\
									\
AddDetail("oberflaeche",						\
	BS("Sie ist leicht von den Wellen gekraeuselt."));		\
									\
AddDetail(({"rhondonit","see"}),					\
	BS("Vor Dir breitet sich der See aus. Leichte Wellen bringen "	\
	"die Oberflaeche zum Funkeln."));				\
									\
AddDetail("funkeln",							\
	BS("Die leichten Wellen brechen das Licht und erzeugen damit "	\
	"ein mystisches Funkeln."));					\
									\
AddDetail("licht",							\
	BS("Du beobachtest eine Weile das beeindruckende Funkeln."));	\
									\
AddDetail(({"genaues","mitte"}),					\
	BS("Du kannst nichts Genaues ueber die Mitte des Sees "		\
	"sagen..."));							\
									\
AddDetail("ufer",							\
	BS("Es geht leicht abwaerts ins Wasser.")); 			\
									\
AddDetail("wasser",							\
	BS("Das Wasser scheint zwar nicht kristallin wie alles "	\
	"andere hier zu sein, ist aber auf eigenartige Weise "		\
	"blaeulich-silbrig gefaerbt. Ob Du darin baden kannst?")); 	\
									\
AddDetail(({"blueten","farne"}),					\
	BS("Tja, welche das genau sind, weisst Du auch nach "		\
	"intensivem Studium nicht.")); 					 									 
									 
#define STANDARD2							\
AddSound(({"see", DEFAULT_SOUND}),					\
	BS("Nur das leise Gurgeln der Wellen ist zu hoeren."));		\
									\
AddSound(({"wellen","gurgeln"}) ,					\
	BS("Sanft schlagen die Wellen an das Ufer.")); 			\
									\
AddSmell(DEFAULT_SMELL,							\
	BS("Du riechst die feuchte, erfrischende Luft des Sees ver"	\
	"mischt mit dem Duft der Blumen."));				\
									\
AddSmell("luft",							\
	BS("Genau kannst Du nicht definieren, wonach es hier riecht, "	\
	"aber es ist angenehm."));					\
									\
AddSmell(({"bluetenstaub","blumen","duft"}),				\
	BS("Du schnupperst an den Blumen und ziehst dabei den Blueten"	\
	"staub tief in die Nase.... HAAAAATSCHII!"));			\
									\
AddDetail("baeume",							\
	BS("Silberne bis weissliche Baeume mit ebensolchen Blaettern "	\
	"wachsen hier ueberall."));					\
									\
AddDetail(({"staemme","blaetter"}),					\
	BS("Die Blaetter sind, wie die Staemme, aus Kristall."));	\
									\
AddDetail("kristall",							\
	BS("Hmm... vieles ist hier aus Kristall...")); 
 
 
 
									 
#define GEBIRGE_NAH							\
AddDetail(({"baum"}),							\
	BS("Er liegt weit im Norden und trotzdem kannst Du ihn "	\
	"sehen.")); 							\
									\
AddDetail(({"berge","gebirge","almandin-gebirge","almandin"}),		\
	BS("Maechtig und beeindruckend hoch ragt das Gebirge neben "	\
	"Dir in den Himmel. Weit oben siehst du karstartige Gipfel, "	\
	"vom Nebel halb verdeckt. Wieviele Abenteurer sind schon "	\
	"losgezogen um die Berge zu erkunden und sind nie wieder "	\
	"zurueckgekehrt..."));						\
									\
AddDetail(({"teile","teil","gipfel"}),					\
	BS("Sie sind verdeckt vom sie umgebenden Nebel. Sicherlich "	\
	"liegt dort oben tiefer Schnee."));				\
									\
AddDetail(({"nebelschwaden","schwaden","nebel"}),			\
	BS("Dichte Nebelschwaden verdecken die Sicht auf die oberen "	\
	"Teile des Gebirges."));					\
									\
AddDetail("sicht",							\
	BS("Die ist verdeckt."));					\
									\
AddDetail("schnee",							\
	BS("Der Schnee ueberzieht die hoechsten Gipfel, reicht "	\
	"aber nicht sehr weit ins Tal herunter."));			\
									\
AddDetail("tal",							\
	BS("Der See hier befindet sich im Tal."));			\
									\
AddDetail("boden",							\
	BS("Der Boden ist mit einer Art Wiese bedeckt. In Richtung "	\
	"Wald nehmen wieder Blumen und Farne ueberhand. Zum Ufer hin "	\
	"geht die Wiese in Steine ueber. Weiters siehst du die "	\
	"Promenade um See."));  
 
#define GEBIRGE_FERN							\
AddDetail(({"berge","gebirge","almandin-gebirge","almandin"}),		\
	BS("Obwohl es weit im Westen liegt, ist es beeindruckend "	\
	"hoch. Du glaubst einige Gipfel zu sehen, die aber "		\
	"vom Nebel halb verdeckt sind."));				\
									\
AddDetail(({"nebelschwaden","schwaden","nebel"}),			\
	BS("Dichte Nebelschwaden verdecken die Sicht auf die oberen "	\
	"Teile des Gebirges."));					\
									\
AddDetail("sicht",							\
	BS("Die ist verdeckt."));					\
									\
AddDetail(({"spitzen","gipfel"}),					\
	BS("Mehr als die Spitzen siehst Du von hier aus nicht."));	\
									\
AddDetail("boden",							\
	BS("Der Boden ist mit einer Art Wiese bedeckt. Im Norden "	\
	"nehmen wieder Blumen "						\
	"und Farne ueberhand. Zum Ufer hin geht die Wiese in Steine "	\
	"ueber. Weiters siehst du die Promenade um See."));  
 
 
//******************************************************* 
//Schwimmen gehen - mit variablem Text im .c file 
//******************************************************* 
#define SCHWIMMEN							\
nosave int springe(string str)						\
{ \
  object ob;									\
   notify_fail(BS("Wohin willst Du denn springen?"));			\
   if(!str) return 0;							\
\
   if(str=="ins wasser"||str=="see"||str=="in den see"||str=="in see")  \
   { 									\
      if(ob = present("\nzedernquestobject",TP)) return quest_schwimmen(str, ob);	\
         write(BS(SCHWIMMEN_TEXT_ICH));				\
         say(TP->Name(WER,2)+SCHWIMMEN_TEXT_ANDERE); 	\
      return 1; 							\
   } 									\
   return 0; 								\
} 									\
      									\
nosave int baden_gehen(string str) 						\
{ \
   object ob;								\
\
   notify_fail("Wo willst Du denn schwimmen gehen?\n"); 		\
   if(!str) return 0;									\
   if(str =="im see" || str =="im wasser" || str=="in wasser" || str =="in see") 	\
   { 									\
      if(ob = present("\nzedernquestobject",TP)) return quest_schwimmen(str, ob);	\
      write(BS(SCHWIMMEN_TEXT_ICH)); 					\
      say(TP->name(WER,2)+SCHWIMMEN_TEXT_ANDERE); 		\
      return 1; 							\
   } 									\
   return 0; 								\
} 									\
 									\
nosave int quest_schwimmen(string str, object ob) 				\
{	int zaehler; 							\
					 				\
	notify_fail(BS("Worin willst Du baden?")); 			\
	if(!str) return 0; 						\
\
	zaehler = ob->frage_zaehler();					\
\
	if(zaehler < 3) 						\
	  return write(BS("Du hast besseres vor, als hier zu baden.")), 1; \
\
	if(ENV(TP)->QueryProp(P_INT_SHORT) !="Am See von Rhondonit") 	\
	  return write(BS("Du kannst hier nicht baden.")), 1; 		\
 									\
	if(zaehler==3) 						\
	{ 								\
	   if(!present("\nscript_schwimmen",TP)) 			\
	     CLONE("/d/kristallwald/sargola/lichtung/obj/scr_schw.lpc", TP); \
 									\
	   if((find_call_out("schwimmen1")==-1) && 		\
	     (find_call_out("schwimmen2")==-1) && 		\
	     (find_call_out("schwimmen3")==-1)) 			\
	      call_out("schwimmen1",0); 			\
	   return 1; 						\
	} 								\
	 								\
	if(zaehler==4) 						\
	  return write(BS("Du warst schon baden. Einmal reicht, findest " \
			  "Du.")), 1; 	\
   return 0; 								\
} 									\
									\
void schwimmen1() 								\
{ 									\
	write(								\
"\n\nDu legst alle Deine Sachen ab und gehst langsam in den See. Du spuerst das\n" 		\
+"kuehle Wasser, wie es Deine Beine und schliesslich Deinen ganzen Koerper umgibt.\n\n"); 	\
	call_out("schwimmen2",6); 					\
} 									\
 									\
void schwimmen2() 								\
{ 									\
	write(								\
"\n\nDu schwimmst raus auf den See. Du spuerst, wie alle Lasten und Alltagsprobleme\n" 		\
+"von Dir fallen. Du bist nur mehr ganz Du selbst. Alle deine kleinen Probleme,\n" 		\
+"Selbstzweifel verschwinden...\n"); 					\
	call_out("schwimmen3",6); 					\
} 									\
 									\
void schwimmen3() 								\
{ 									\
	object ob; 							\
	write(								\
"\n\nLangsam schwimmst Du zurueck ans Ufer, ziehst, noch immer tief in Dir selbst\n"		\
+"ruhend, Deine Sachen wieder an und bist nun bereit, um Xalgur gegenueberzu-\n" 		\
+"treten.\n"); 								\
	ob = present("\nscript_schwimmen",TP); 				\
	ob->remove(); 							\
	present("\nzedernquestobject",TP)->erhoehe_zaehler(4); 	\
}
