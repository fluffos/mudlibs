/*
** STANDARD1, STANDARD2 - Standard-details
** AESTE_RAUF - Hier kann man nach oben klettern
** AESTE_NICHT_RAUF - hier gehts nicht nach oben
** COMMANDS - Kommandos fuer das klettern
** RAUF - Func fuers klettern
**    bei RAUF muss die Konstante DESTINATION definiert werden :)
*/


#define STANDARD1							\
AddDetail(({"eichen","baeume"}),					\
	BS("Um Dich herum stehen Eichen, die mit einer kristallinen "	\
	"Schicht ueberzogen sind. Blaetter, Aeste und die Staemme - "	\
	"alles ist weisslich gefaerbt."));				\
									\
AddDetail("schicht",							\
	BS("Die Schicht scheint aus Kristall zu bestehen und ueber"	\
	"zieht die gesamte Gegend. Durch sie glitzert der Wald "	\
	"maerchenhaft schoen."));					\
									\
AddDetail("kristall",							\
	BS("Hmm - hier ist so ziemlich alles mit Kristall ueber"	\
	"zogen."));							\
									\
AddSound(DEFAULT_SOUND,							\
	BS("Du hoerst das Klingen der Blaetter im Wind."));		\
									\
AddSound (({"blaetter", "blatt","klingen", "wind"}),			\
	BS("Die Blaetter schwingen sanft mit dem Wind und verursachen "	\
	"dadurch ein leises Klingen."));				\
									\
AddSmell (DEFAULT_SMELL,						\
	BS("Du ziehst die frische Waldluft tief durch die Nase!"));	\
									\
AddSmell( ({"luft","waldluft"}),					\
	BS("Ahhh! Du fuehlst Dich gleich viel wohler."));		\
									\
AddDetail( "boden",							\
	BS("Der Boden ist mit Graesern ueberzogen, die leise "		\
	"knirschen, wenn Du auf sie trittst. Weiters entdeckst Du "	\
	"Blaetter, Zweige und kristallines Gestein."));			\
									\
AddDetail("gestein",							\
	BS("Viele mehr oder weniger grosse, glaeserne Steine liegen "	\
	"auf dem Weg verstreut herum."));				\
									\
AddDetail( ({"stein","steine", "brocken"}),				\
	BS("Von Kieselsteinen bis faustgrossen Brocken findest Du "	\
	"hier alles."));						\
									\
AddDetail("kieselsteine",						\
	BS("Sie glitzern ein wenig und wirken dadurch wertvoll. Du "	\
	"laesst sie aber trotzdem liegen."));				\
									\
AddDetail( "himmel",							\
	BS("Hie und da scheint das Blau des Himmels "			\
	"durch. Meist jedoch wird es von den Aesten verdeckt. Durch "	\
	"Loecher zwischen den Aesten faellt das Licht wie Saeulen auf " \
        "den Boden."));							\
									\
AddDetail("lichtung", 							\
	BS("Geh doch hin, wenn Du darueber was wissen willst!"));	\
									\
AddDetail( "blau",							\
	BS("Es ist aber nicht immer blau - durch die Wolken scheint es "\
	"manchmal eher weiss durch."));					\
									\
AddDetail( ({"wolke","wolken"}),					\
	BS("Genaueres kannst Du von hier nicht ersehen."));		\
									\
AddDetail( ({"loch","loecher"}), 					\
	BS("Obwohl der Wald hier sehr dicht ist, gibt es doch kleine "	\
	"Durchlaesse."));						\
									\
AddDetail( ({"durchlass","durchlaesse"}),				\
	BS("Hier dringt das Licht bis auf den Boden durch."));		\
									\
AddDetail( ({"wege","weg"}), 						\
	BS("Von einem Weg kann man eigentlich nicht sprechen. "		\
	"In alle Himmelsrichtungen fuehren hier die Wege."));		\
									\
AddDetail( ({"saeule","saeulen"}),					\
	 BS("Weisse Lichtkegel, die sehr unterschiedliche Durchmesser "	\
	 "haben."));							\
	 								\
AddDetail( ({"kegel","lichtkegel", "licht"}),				\
	BS("Es wirkt schoen hier, in dieser mystisch erleuchteten "	\
	"Gegend."));							\
									\
AddDetail("himmelsrichtungen",						\
	BS("Wenn Du Dich genau umsiehst, kannst Du sie sogar selbst "	\
	"herausfinden!"));						\
									\
AddDetail( "gegend",							\
	BS( "Na der Kristallwald!"));					\
									\
AddDetail( "durchmesser",						\
	BS( "Manchmal erleuchten die Kegel den halben Weg, "		\
	"manchmal sind sie so duenn wie ein glaeserner Dolch, der "	\
	"sich in den Boden rammt."));					\
									\
AddDetail( ({"dolch","dolche"}),					\
	BS( "Es sieht aus, als wuerden sie direkt vom Himmel hier in "	\
	"den Boden schiessen..."));					\
									\
AddDetail( ({"strauch","straeucher"}),					\
	BS( "Die stehen hier ueberall herum und versperren Dir den "	\
	"Weg."));							
	

#define STANDARD2							\
AddDetail( ({"gras","graeser"}),					\
	BS( "Es knirscht bei jedem Deiner Schritte."));			\
									\
AddDetail( ({"blatt","blaetter"}),					\
	BS( "Abgefallene Blaetter, weiter nichts."));			\
									\
AddDetail( ({"zweige","zweig"}),					\
	BS( "Kleinere Zweige liegen auch vereinzelt herum."));		\
									\
AddDetail( ({"stamm","staemme"}),					\
	BS( "Du siehst den Wald vor lauter Staemmen nicht mehr - "	\
	"oder irgendwie so heisst das doch..."));			\
									\
AddDetail( "hoehe",							\
	BS( "Die Staemme sind gut und gern zehn Meter hoch."));		\
									\
AddDetail( ({"wald","kristallwald"}),					\
	BS("Der ist gross - was willst Du denn genau untersuchen?"));	


#define AESTE_RAUF							\
AddDetail( ({"ast","aeste"}),						\
	BS("Sie wachsen nahe des Bodens aus dem Stamm. Vielleicht "	\
	"kannst Du ja irgendwie raufklettern..."));			\
AddDetail( ({"stamm","staemme"}),					\
	BS("Es sind die typischen, weisslichen Staemme, die die ganze "	\
	"Gegend hier charakterisieren."));				\
AddDetail("gegend",							\
	BS("Wo Du auch hinsiehst, nur Wald und Straeucher..."));	

#define AESTE_NICHT_RAUF						\
AddDetail( ({"ast","aeste"}),						\
	BS("Sie wachsen zu weit vom Boden entfernt aus dem Stamm. Du "	\
	"kommst hier sicher nicht auf den Baum."));			\
AddDetail( ({"stamm","staemme"}),					\
	BS("Du siehst die typisch weissen Staemme, welche die ganze "	\
	"Gegend hier praegen."));					\
AddDetail("gegend",							\
	BS("Alles hier um Dich herum ist aus weissem Kristall."));	\
									\
AddDetail(({"kristallschicht","schicht","kristall"}),			\
	BS("Die Baeume und Straeucher sind mit einer Kristallschicht "	\
	"ueberzogen. Deshalb ist hier alles so weiss."));		

#define COMMANDS							\
AddCmd(({ "spring","springe" }), "springe" );				\
AddCmd(({ "greife","greif" }), "greife" );				\
AddCmd(({ "knuepf", "knuepfe"}), "knuepfe");				\
AddCmd(({"bind","binde"}),"knuepfe");					\
AddCmd(CMD_KLETTERN,"kletter");



#define RAUF								\
nosave int greife (string str)						\
{									\
   notify_fail(BS("Wonach willst Du denn greifen?"));			\
   if(!str) return 0;							\
									\
   if(str=="nach ast"||str=="ast")					\
   {									\
      write(BS("Der Ast ist zu weit weg, um ihn anzugreifen!"));	\
									\
      say(BS(TPN+" kommt nicht an den Ast ran."));			\
									\
      return 1;								\
   }									\
   return 0;								\
}									\
									\
nosave int springe(string str)						\
{									\
   notify_fail(BS("Wohin willst Du denn springen?"));			\
   if(!str) return 0;							\
									\
   if(str=="auf baum" || str=="baum") 				        \
   {   									\
      write(BS("Du kannst nicht auf den Baum springen! Du erreichst "	\
      "ja nicht mal den ersten Ast!"));					\
									\
      say(BS(TPN+" versucht ohne Erfolg auf den "			\
      "Baum zu springen."));						\
      									\
      return 1;								\
   }									\
									\
   if(str=="auf ast" || str=="ast")					\
   {									\
      write(BS("Du kannst nicht auf den Ast springen! Der ist doch "	\
      "zu hoch! Vielleicht kannst Du Dich ja irgendwie raufziehen"	\
      "..."));								\
									\
      say(BS(TPN+" versucht auf den Ast zu springen - wie lustig!"));	\
									\
      return 1;								\
   }									\
   									\
   if(str=="nach ast")						\
   {									\
      write(BS("Du kannst nicht bis zum Ast. Hmmm, was braucht man in " \
      "so einem Fall?"));   						\
   									\
      say(BS(TPN+" springt vergeblich in die Luft."));			\
									\
      return 1;								\
   }									\
									\
   return 0;								\
}									\
									\
nosave int knuepfe(string str)						\
{									\
  notify_fail("WAS willst Du denn WORAN knuepfen?\n");		\
  if(!str) return 0;						\
									\
  if(present("seil",TP))						\
    if(str =="seil an ast" || str =="seil auf ast")		\
      {								\
        write(BS("Du wirfst das Seil auf den Ast und "		\
         "verknotest es fest. Nun ist es ein leichtes fuer Dich, "	\
         "raufzuklettern. Das Seil nimmst Du sicherheitshalber mit - "	\
         "man weiss ja nie..."));					\
									\
         say(BS(TPN+" wirft das Seil "					\
         "um den Ast, verknotet es und klettert ohne Probleme rauf. "	\
         "Du siehst, wie "+TPN+" das Seil oben "			\
         "wieder loest."));						\
									\
         TP->move(ROOM+DESTINATION,M_GO|M_SILENT);			\
									\
         return 1;							\
       }								\
     else								\
       {								\
         write(BS("Woran willst Du das Seil knuepfen?"));		\
									\
         say(BS(TPN+" weiss nicht genau, woran man so ein Seil "	\
         "knuepft..."));						\
									\
         return 1;							\
       }								\
									\
  write(BS("Du hast ja nichts womit man raufklettern koennte."));	\
									\
  say(BS(TPN+" hat nichts womit man raufklettern koennte."));	\
									\
  return 1;							\
}									\
									\
nosave int kletter(string str)						\
{									\
  notify_fail("Wohin moechtest Du denn klettern?\n");		\
  if(!str) return 0;						\
									\
  if(str=="mit seil auf baum" || str=="mit seil auf ast" ||	\
     str=="auf baum mit seil" || str=="auf ast mit seil")        \
     if(present("seil",TP)) \
      {								\
       write(BS("Du wirfst das Seil auf den Ast und "	\
         "verknotest es fest. Nun ist es ein leichtes fuer Dich, "	\
         "raufzuklettern. Das Seil nimmst Du sicherheitshalber mit - "	\
         "man weiss ja nie..."));					\
									\
         say(BS(TPN+" wirft das Seil "					\
         "um den Ast, verknotet es und klettert ohne Probleme rauf. "	\
         "Du siehst, wie "+TPN+" das Seil oben "			\
         "wieder loest."));						\
									\
         TP->move(ROOM+DESTINATION,M_GO|M_SILENT);			\
									\
         return 1;							\
      }								\
     else \
       return write(BS("Mit welchem Seil?")), 1; \
 \
  if(str=="auf baum"||str=="baum" ||str=="auf ast"||str=="ast")	\
    {								\
      if(present("seil",TP))					\
	return write(BS("Hmm... warum verwendest Du nicht das Seil?")), 1;\
									\
      write(BS("Der unterste Ast ist zuweit weg, um ihn "	\
	       "direkt zu erreichen. Vielleicht gibt es ja irgend"	\
	       "welche Hilfsmittel..."));				\
      return 1;						\
    }								\
									\
  return 0;							\
}
