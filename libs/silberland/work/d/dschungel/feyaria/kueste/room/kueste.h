// /d/dschungel/feyaria/kueste/room/kueste.h
// Allgemeine Details fuer den Kuestenweg
// 30-11-96  Feyaria@SilberLand ( Dank an Cheasy@AnderLand )
// KUESTE 12 Details, 2 Sound, 3 Smells
// WETTER 10 Details
// PFLANZEN 7 Details
// PALMEN 2 Details
// KOKOS  3 Details
// KAJUBO 2 Details
// Funktionen: BADEN, GRABEN, LIEGEN, KLETTERN, SUCHEN, PFLUECKEN

#define RANDOM_KAJUBO 10
#define RANDOM_KOKOS 10

#define VARIABLEN							\
int kokospalme, kokosnuss;						\
int kajubo, kajuboknospen, kajubo_gefunden;


#define KUESTE								\
AddDetail( ({"kueste", "kuestenweg", "weg"}),				\
  "Der Kuestenweg fuehrt entlang der Kueste von "+CAP(DIR1)+" nach "+	\
  CAP(DIR2)+" und wird von einer Reihe von Palmen gesaeumt.");		\
									\
AddDetail( ({"boden", "sandboden"}),					\
  "Der Boden besteht aus festgetretenem Sand.");			\
									\
AddDetail( ({"meer", "wellen", "brandung"}),				\
  "Weit draussen brechen sich die grossen Wellen an einem Riff. "	\
  "Darum gibt es hier an der Kueste nur noch kleine Wellen, die "	\
  "rauschend den schneeweissen Sandstrand hinauf rollen und wieder "	\
  "zurueck ins Meer fliessen. Am Tidensaum findet sich neben "		\
  "abgestorbenen Algen viele Muschelschalen.");				\
									\
AddDetail( ({"wasser", "salzwasser", "meerwasser"}),			\
  "Es ist eindeutig Salzwasser, dass in diesem Meer ans Ufer " 		\
  "schwappt.");								\
  									\
AddDetail( ({"ufer", "strand", "sandstrand"}),				\
  "Weisser Sandstrand, soweit das Auge reicht, bildet hier das Ufer "	\
  "des Meers. Ein Rand aus halbvermoderten Algen zeigt, wie hoch die "	\
  "hoechsten Wellen den Strand hinaufrollen.");				\
									\
AddDetail( ({"algen", "tidensaum", "rand"}),				\
  "Ein Rand aus halbvermoderten Algen zeigt, wie hoch die "		\
  "hoechsten Wellen den Strand hinaufrollen.");				\
  									\
AddDetail( ({"muschel", "muscheln", "schalen", "muschelschalen",	\
             "muschelschale", "formen", "form", "farbe", "farben"}),	\
  "Du siehst verschiedene Muschelschalen in allen vorstellbaren "	\
  "Formen und Farben.");						\
									\
AddDetail( ({"salz"}),							\
  "Das Salz ist im Meerwasser geloest. Sehen kann man es nicht.");	\
									\
AddDetail( ({"sand"}),							\
  "Der Sand ist weiss und ganz fein.");					\
									\
AddDetail( ({"riff", "korallenriff"}),					\
  "Das Riff ist irgendwo da draussen im Meer. Vielleicht kannst Du "	\
  "ja ins Meer hinausschwimmen und hinuntertauchen, um die "		\
  "phantastischen Geschichten zu ueberpruefen, die Du ueber das "	\
  "Korallenriff gehoert hast.");					\
									\
AddDetail( ({"korallen", "fische", "fisch"}),				\
  "Zahlreiche exotische Fische sollen sich zwischen den Korallen "	\
  "tummeln.");								\
									\
AddDetail( ({"geschichten"}),						\
  "Du wirst Dich doch noch an die Geschichten erinnern, die ueber "	\
  "das Korallenriff erzaehlt werden?");					\
									\
AddSound( ({DEFAULT_SOUND}),						\
  "Du hoerst das Rauschen der Brandung.");				\
									\
AddSmell( ({DEFAULT_SMELL}),						\
  "Es riecht nach Meer.");						\
									\
AddSmell( ({"meer"}),							\
  "Das Meer riecht nach Salz, Seetang und Fisch.");			\
									\
AddSmell( ({"salz", "seetang", "tang", "fisch"}),			\
  "Danach riecht das Meer.");						\
									\
AddSound( ({"wellen", "welle", "rauschen", "brandung", "meer"}),	\
  "Du hoerst das Rauschen der Wellen.");


#define WETTER								\
  AddDetail( ({"himmel"}),						\
    "Am Himmel ist nicht das kleinste Woelkchen zu sehen, daher "	\
    "glueht die Sonne auch so herunter. Nur am Horizont haengt eine "	\
    "kleine Wolkenbank.");						\
									\
  AddDetail( ({"wolke", "wolken", "woelkchen"}),			\
    "Bis auf die Wolkenbank am Horizont ist keine Wolke zu sehen.");	\
									\
  AddDetail( ({"horizont", "wolkenbank"}),				\
    "Am Horizont haengt eine Wolkenbank, aber ansonsten ist es "	\
    "wolkenlos.");							\
									\
  AddDetail( ({"sonne"}),						\
    "Die Sonne brennt erbarmungslos vom Himmel herunter. Das ist wohl "	\
    "auch der Grund, dass es hier so warm ist. Du kannst richtig die "	\
    "Strahlung auf Deiner Haut spueren.");				\
									\
  AddDetail( ({"strahlung"}),						\
    "Die Strahlung der Sonne ist sehr intensiv hier.");			\
									\
  AddDetail( ({"haut"}),						\
    "Deine Haut hat noch eine normale Farbe, aber wenn Du zu lange in "	\
    "der Sonne stehst, koenntest Du einen Sonnenbrand bekommen.");	\
									\
  AddDetail( ({"sonnenbrand"}),						\
    "Noch hast Du keinen, aber pass lieber auf!");			\
									\
  AddDetail( ({"wind"}),						\
    "Der frische Wind bringt etwas Kuehlung vom Meer her.");		\
									\
  AddDetail( ({"kuehlung"}),						\
    "Eine richtige Kuehlung bringt der Wind zwar nicht, aber ohne "	\
    "Wind waere die Hitze hier sicher unertraeglich.");			\
									\
  AddDetail( ({"hitze"}),						\
    "Ohne Wind waere die Hitze sicher unertraeglich.");			\
                                                                        \
  AddDetail( ({"schwitzen", "schweiss"}),                               \
    "Wegen der Hitze schwitzt du so stark, dass Du schon ganz voll "    \
    "Schweiss bist.");


#define PFLANZEN							\
  AddDetail( ({"dschungel", "wald"}),					\
    "Der Dschungel beginnt gleich wenige Meter neben dem Weg. Dort "	\
    "ist die Vegetation so dicht, dass man nur wenige Schritte weit "	\
    "in den dichten Urwald hinein sehen kann.");			\
									\
  AddDetail( ({"vegetation", "pflanzen"}),				\
    "Die Vegetation des Dschungels besteht aus den verschiedensten "	\
    "Pflanzen. Zwischen den hohen Baumriesen zwaengt sich dichtes "	\
    "Gestruepp und verschiedene Buesche und Straeucher.");		\
									\
  AddDetail( ({"baeume", "baum", "baumriesen"}),			\
    "Die Baeume sind wirklich riesengross.");				\
									\
  AddDetail( ({"riesen"}),						\
    "Sei froh, dass es nur Baumriesen sind und keine echten Riesen.");	\
									\
  AddDetail( ({"gestruepp", "buesche", "straeucher"}),			\
    "Zwischen den Baeumen versuchen sich verschiedene Buesche und "	\
    "Straeucher zu behaupten. Sie bilden ein richtiges Gestruepp.");	\
									\
  AddDetail( ({"busch", "strauch"}),					\
    "Es gibt hier so viele Buesche und Straeucher, dass Dir kein "	\
    "einzelner besonders auffaellt. Aber wenn Du einen bestimmten "	\
    "Busch finden willst, dann kannst Du ja danach suchen.");		\
									\
  AddDetail( ({"urwald"}),						\
    "Es ist wirklich ein richtiger Urwald hier, den sicher noch "	\
    "nicht viele Menschen betreten haben.");

#define PALMEN								\
  AddDetail( ({"palmen", "palme"}),					\
    "Hier an der Kueste steht eine lange Reihe von Palmen, die den "	\
    "Kuestenweg saeumt. Ein Stueck dahinter beginnt dann der dichte "	\
    "Urwald.");								\
									\
  AddDetail( ({"reihe", "palmenreihe"}),				\
    "Die Palmen bilden wirklich eine richtige Reihe. Hin und wieder "	\
    "befindet sich auch eine Kokospalme darunter.");

#define KOKOS								\
  kokospalme = 1 ;							\
  kokosnuss =1+random(3);						\
  AddDetail( ({"kokospalme", "kokospalmen"}),				\
    "Du stehst hier vor einer Kokospalme. Weit oben unter den "		\
    "Palmwedeln haengen einige Kokosnuesse.");				\
									\
  AddDetail( ({"palmwedel", "wedel"}),					\
    "Die Spitze der Kokospalme besteht aus Palmwedeln. Darunter "	\
    "haengen einige Kokosnuesse.");					\
									\
  AddDetail( ({"kokosnuss", "nuss", "kokosnuesse", "nuesse"}),		\
    "Wie Du so die Kokosnuesse da oben haengen siehst, bekommst Du "	\
    "richtig Lust, hinaufzuklettern und eine Kokosnuss zu essen.");

#define NOKOKOS								\
  kokospalme=0;								\
  kokosnuss=0;								\
  RemoveDetail( ({"kokospalme", "kokospalmen"}) );			\
  RemoveDetail( ({"palmwedel", "wedel"}) );				\
  RemoveDetail( ({"kokosnuss", "nuss", "kokosnuesse", "nuesse"}) );

#define KAJUBO								\
  AddDetail( ({"kajubostrauch", "kajubo"}),				\
    "Tatsaechlich hast Du einen Kajubostrauch gefunden. Mit Glueck "	\
    "kannst Du auch ein paar Kajuboknospen pfluecken.");		\
									\
  AddDetail( ({"knospen", "kajuboknospen", "knospe", "kajuboknospe"}),	\
    "Der Strauch besitzt doch tatsaechlich einige Knospen, die man "	\
    "ganz einfach pfluecken kann.");

#define NOKAJUBO							\
  kajubo=0;								\
  kajuboknospen = 0;							\
  kajubo_gefunden=0;							\
  RemoveDetail( ({"kajubostrauch", "kajubo"}) );			\
  RemoveDetail( ({"knospen", "kajuboknospen"}) );


#define COMMANDS							\
  AddCmd( ({"schwimme", "schwimm", "bade"}), "baden");			\
  AddCmd( ({"lieg", "liege"}), "liegen");				\
  AddCmd( ({"grabe", "grab", "buddel", "buddle", "buddl"}), "graben");	\
  AddCmd( ({"kletter", "klettere"}), "klettern");			\
  AddCmd( ({"suche", "such"}), "suchen");				\
  AddCmd( ({"pflueck", "pfluecke"}), "pfluecken");



#define BADEN								\
int baden(string str)							\
{									\
  notify_fail("Wo willst Du baden?\n");					\
  if(!str) return 0;							\
  if( member( ({"meer", "in meer","im meer", "wasser", "in wasser",	\
                "im wasser"}), str)!=-1 )				\
  {									\
    write("Das ist hier kein richtiger Badeplatz.\n");			\
    return 1;								\
  }									\
  return 0;								\
}

#define BADEN_BUCHT							\
int baden(string str)							\
{									\
  notify_fail("Wo willst Du baden?\n");					\
  if(!str) return 0;							\
  if( member( ({"meer", "wasser", "im wasser", "im meer", "in meer",	\
                "in wasser", "bucht", "in bucht"}), str)!=-1 )		\
  {									\
    write("Du watest durch das Wasser in die Bucht hinaus.\n");		\
    TP->move( ROOM "bucht", M_GO, "ins Wasser und schwimmt hinaus",	\
            "watet", "schwimmt herein");				\
    return 1;								\
  }									\
  return 0;								\
}

#define LIEGEN								\
int liegen(string str)							\
{									\
  notify_fail("Hier ist der Strand nicht dazu geeignet, sich "		\
              "hinzulegen.\n");						\
  return 0;								\
}

#define GRABEN								\
int graben(string str)							\
{									\
  switch( random(5) )							\
  {									\
    case 0: write("Du buddelst im Sand herum und fuehlst Dich wie in "	\
         	  "Deiner Kindheit.\n");				\
            break;							\
    case 1: write("Du buddelst sinnlos im Sand herum.\n");		\
            break;							\
    case 2: write("Du buddelst im Sand herum und findest nur Sand.\n");	\
            break;							\
    case 3: write("Du baust eine schoene Sandburg.\n");			\
            break;							\
    case 4: write("Du buddelst im Sand herum, aber findest nichts.\n");	\
            break;							\
  }									\
  say( CAP(TPN) + " buddelt im Sand herum.\n");				\
  return 1;								\
}

#define KLETTERN							\
int klettern (string str)						\
{									\
  object ob;								\
  notify_fail("Wohin willst Du klettern?\n");				\
  if(!str) return 0;							\
  if( member( ({"palme", "auf palme", "auf palme hinauf"}), str)!=-1 )	\
  {									\
    notify_fail("Diese Palme ist doch viel zu uninteressant.\n");	\
    return 0;								\
  }									\
  if( member( ({"palmen", "auf palmen"}), str)!=-1 )			\
  {									\
    notify_fail("Auf mehrere Palmen? Auf einmal?\n");			\
    return 0;								\
  }									\
  if( member( ({"kokospalme", "auf kokospalme", 			\
                "auf kokospalme hinauf"}), str)!=-1 )			\
  {									\
    if( kokospalme!=1 )							\
    {									\
      notify_fail("Hier ist doch gar keine Kokospalme.\n");		\
      return 0;								\
    }									\
    write("Du kletterst auf eine Kokospalme hinauf.\n");		\
    say( CAP(TPN)+ " klettert auf eine Kokospalme hinauf.\n");		\
    if( kokosnuss==0)							\
    {									\
      write("Leider ist keine Kokosnuss mehr da und so kletterst "	\
            "Du wieder nach unten.\n");					\
      return 2;								\
    }									\
    if( ob=TP->QueryProp(P_WEAPON) )					\
    {									\
      if( member( ob->QueryProp(P_DAM_TYPE), DT_SLASH)==-1 )		\
      {									\
        write( BS("Du versucht die Kokosnuss mit D"+ ob->name(WEM) +	\
              " zu oeffnen, aber es klappt irgendwie nicht. Daher "	\
              "kletterst Du frustriert wieder hinunter.") );		\
        return 2;							\
      }									\
      write( BS("Du oeffnest die Kokosnuss mit D"+ ob->name(WEM) +	\
                " und trinkst den erfrischenden Saft aus. Gestaerkt "	\
                "kletterst Du wieder hinunter.\n") );			\
      TP->heal_self( 10+random(20) );					\
      kokosnuss--;							\
      return 1;								\
    }									\
    write( "Du willst eine Kokosnuss mit blossen Haenden oeffnen?\n"	\
           "Schnell kletterst Du wieder hinunter, um eine Waffe zu "	\
           "suchen.\n");						\
    return 2;								\
  }									\
  return 0;								\
}


#define SUCHEN								\
int suchen(string str)							\
{									\
  notify_fail("Du suchst, aber findest nichts.\n");			\
  if(!str) return 0;							\
  if( member( ({"kajubo", "kajubostrauch"}), str)!=-1 )			\
  {									\
    if( kajubo==1)							\
    {									\
      write("Du findest tatsaechlich einen Kajubostrauch.\n");		\
      say( CAP(TPN)+ " sucht in den Straeuchern herum.\n");		\
      KAJUBO								\
      kajubo_gefunden=1;						\
      return 1;								\
    }									\
    notify_fail("Du suchst, aber findest nirgendwo einen "		\
                "Kajubostrauch.\n");					\
  }									\
  if( member(({"busch", "buesche", "strauch", "straeucher"}), str)!=-1)	\
    notify_fail("Willst Du nicht einen bestimmten Strauch suchen?\n");	\
  return 0;								\
}

#define PFLUECKEN							\
int pfluecken(string str)						\
{									\
  notify_fail("Was willst Du pfluecken?\n");				\
  if(!str) return 0;							\
  if( member( ({"kajubo", "knospen", "knospe", "kajuboknospe",		\
                "kajuboknospen"}), str)!=-1 )				\
  {									\
    if( kajubo_gefunden!=1 )						\
    {									\
      notify_fail("Wo siehst Du hier einen Kajubostrauch?\n");		\
      return 0;								\
    }									\
    if( !kajuboknospen )						\
    {									\
      write( BS("Leider findest Du keine Kajuboknospen und so "		\
                "verlierst Du auch das Interesse an dem Strauch.") );	\
      say( CAP(TPN) + " durchsucht erfolglos einen Strauch.\n");	\
      return 2;								\
    }									\
    write( "Du findest tatsaechlich eine Kajuboknospe und steckst "	\
           "sie ein.\n");						\
    say( CAP(TPN) + " durchsucht einen Strauch und steckt etwas "	\
         "ein.\n");							\
    CLONE(OBJ "kajubo", TP);						\
    kajuboknospen--;							\
    return 1;								\
  }									\
  return 0;								\
}

#define RESET								\
void reset()								\
{									\
  ::reset();								\
  if( kokospalme )							\
  {									\
    NOKOKOS								\
  }									\
  else if( !random(20) )						\
  {									\
    KOKOS								\
  }									\
  if( kajubo_gefunden )							\
  {									\
    NOKAJUBO								\
  }									\
  else if( !random(20) )						\
  {									\
    kajubo=1;								\
    kajuboknospen = random(3);						\
  }									\
}
    
