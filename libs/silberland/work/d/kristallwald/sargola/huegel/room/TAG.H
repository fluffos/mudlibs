/*
***********************************************************************
**
** h-file fuer die Huegelgrber
** Raeume bei Tag
** 
** date: 22-09-97
***********************************************************************
**
** STANDARD		->	Raum-Details
** STANDARD1		->	same...
** SS			->	Sounds, smells
** GRAB_OBEN		->	Ein Huegelgrab
** GRAB_UNTEN		->	das Grab von der Talsenke aus
** OEFFNE		->	Graboeffnung am Tag 		(func)
** STEIN_OBEN		->	Steindetails
** STEIN_UNTEN		->	Stein vom Huegel aus
** SCHMUTZ		->	Schmutz rauskratzen 		(func)
** SCHLAFEN		->	Weg ins Dunkel...		(func)
** SCHAUE		->	blick durch ritze		(func)
**
** zu definieren: 	GRAVUR_TEXT
**
*/


#define STANDARD							\
AddDetail("boden",							\
	"Der Boden ist mit einer dichten, blassgruenen Wiese bedeckt. "	\
	"Hin und wieder bemerkst Du Blueten kleiner, unscheinbarer "	\
	"Blumen. Auch haessliche Straeucher wachsen hie und da.");	\
									\
AddDetail(({"graeser","wiese"}),					\
	"Die Wiese ist zwar dicht, aber die Farbe ist eigenartig "	\
	"blassgruen. Irgendwie scheint sie hier nicht richtig "		\
	"gedeihen zu koennen.");					\
									\
AddDetail("farbe",							\
	"Die Wiese und auch die Blumen kommen Dir seltsam blass "	\
	"vor.");							\
									\
AddDetail( ({"blume","blumen"}),					\
	"Du bemerkst einige Blumen, welche aber, wie die Wiese, "	\
	"eine seltsam blasse Farbe besitzen.");				\
									\
AddDetail( ({"bluete","blueten"}),					\
	"Normalerweise wuerde Dich der Anblick wohl erfreuen, aber "	\
	"irgendetwas stimmt hier nicht.");				\
									\
AddDetail("anblick",							\
	"Er ist schlicht gesagt, trostlos. Alles hier ist in unwirk"	\
	"lich blassen Farben. Kein kraeftiges Wiesengruen, keine "	\
	"tiefroten Blueten. Eine seltsame Gegend...");			\
									\
AddDetail("gegend",							\
	"Die Erde hier scheint fuer Pflanzen wohl nicht das richtige "	\
	"zu sein. Alle Pflanzen hier vegetieren am Existenzminimum.");	\
									\
AddDetail("erde",							\
	"Die Erde ist wohl kuehl und locker, doch scheint sie bar "	\
	"jeder Naehrstoffe zu sein.");					\
									\
AddDetail("naehrstoffe",						\
	"Selbst wenn es hier welche gaebe: Naehrstoffe kannst Du "	\
	"mit blossem Auge eher schwer erkennen.");			\
									\
AddDetail("pflanzen",							\
	"Ausser der Wiese, ein paar mickrigen Blumen und Straeuchern "	\
	"findest Du hier nichts.");					\
									\
AddDetail("existenzminimum",						\
	"Alles hier scheint knapp vor dem Tode zu stehen.");		\
									\
AddDetail(({"tode","tod"}),						\
	"Der Tod teilt Dir mit: Willst Du denn zu mir?");		
									
#define STANDARD1							\
AddDetail("straeucher",							\
	"Die Straeucher scheinen wie die Blumen nicht richtig "		\
	"wachsen zu koennen. Nur ein paar halb verkrueppelte "		\
	"Straeucher kaempfen hier ums Ueberleben.");			\
									\
AddDetail("ueberleben",							\
	"Das scheint bei dem Boden hier recht muehselig zu sein.");	\
									\
AddDetail("himmel",							\
	"Der Himmel liegt wolkenlos und blasslbau ueber Dir. Nur "	\
	"einige Schlieren ziehen sich ueber das Firmament. Sogar die "	\
	"Sonne scheint hier nicht so intensiev zu scheinen.");		\
									\
AddDetail("sonne",							\
	"Selbst die Strahlen der Sonne scheinen hier in diesem Tal "	\
	"nicht intensiv zu sein.");					\
									\
AddDetail("strahlen",							\
	"Sie wirken kraftlos und verbreiten auch keinerlei Waerme.");	\
									\
AddDetail("waerme",							\
	"Die blassen Strahlen waermen Dich kein bisschen.");		\
									\
AddDetail("schlieren",							\
	"Einige Schlieren reichen von Horizont zu Horizont und "	\
	"wirken wie duenne, weissliche Baender.");			\
									\
AddDetail("horizont",							\
	"Du kannst nicht weit sehen, da Du ja in einem Tal stehst.");	\
									\
AddDetail("tal",							\
	"Du befindest Dich in einem ausladenden Tal. Links und "	\
	"rechts von Dir beginnen mit Wiese bedeckte Haenge anzu"	\
	"steigen.");							\
									\
AddDetail( ({"hang","haenge"}),						\
	"Die Haenge beginnen sanft und steigen bis zur Kante "		\
	"immer steiler an. Ausser dem Weg kannst Du hier nirgends "	\
	"rausklettern.");						\
									\
AddDetail("kante",							\
	"Die Kante ist weit oberhalb und Du siehst keine Moeglich"	\
	"keit, sie naeher zu untersuchen. Du bist Dir nur sicher, "	\
	"dass sie mit Wiese bedeckt ist.");				\
									\
AddDetail("baender",							\
	"Die Schlieren wirken fast wie Baender, die den Himmel um"	\
	"fassen.");							\
									\
AddDetail( ({"fuchs","steppenfuchs"}),					\
	"Du kannst keinen Fuchs entdecken, solltest aber auf der "	\
	"Hut sein.");							\
									\
AddDetail(({"auge","gurgel"}),						\
	"Konzentrier Dich lieber auf die Umgebung - sonst bist Du "	\
	"wohl bald wieder mal bei Lars.");


#define SS								\
AddSmell(DEFAULT_SMELL,							\
	"Du riechst eigentlich nichts.");				\
									\
AddSmell( ({"blumen","blueten"}),					\
	"Sollten die Blueten nicht normalerweise einen angenehmen "	\
	"blumigen Duft verbreiten? Seltsam, aber Du kannst einfach "	\
	"nichts riechen.");						\
									\
AddSmell("duft",							\
	"Du kannst hier keinen Duft riechen.");				\
									\
AddSound(DEFAULT_SOUND,							\
	"Nach 3 Minuten eingehendem Lauschen gibts Du es auf - Du "	\
	"kannst einfach nichts hoeren. Kein Vogelgezwitscher, keine "	\
	"Graeser, die im Wind wiegen. Hier ist eine beklemmende "	\
	"Stille.");							\
									\
AddSound( ({"vogel","gezwitscher","vogelgezwitscher"}),			\
	"Du kannst keine Voegel hoeren. Je mehr Du Dich hier um"	\
	"siehst, desto unwohler fuehlst Du Dich hier.");		\
									\
AddSound( ({"gras","graeser"}),						\
	"Die Graeser sind voellig still.");				\
									\
AddSound("wind",							\
	"Hier in dem Tal weht kein Wind, nicht einmal ein leichtes "	\
	"Lueftchen.");							\
									\
AddSound("lueftchen",							\
	"Kein Lueftchen, rein gar nichts.");				\
									\
AddSound("stille",							\
	"Es ist hier absolut ruhig. Du wirst immer unruhiger und "	\
	"erwartest fast, dass Dir gleich ein riesiger Steppen"		\
	"fuchs an die Gurgel springt.");


#define GRAB_OBEN							\
AddDetail("huegel",							\
	"Du stehst auf einem grossen Huegel, welcher mit dichtem Gras "	\
	"bedeckt ist. Auf der Kuppe kannst Du einen steinernes "	\
	"Grab entdecken. Was das wohl sein mag?");			\
									\
AddDetail("kuppe",							\
	"Die Kuppe ist leicht abgeflacht und bietet genau fuer ein "	\
	"steinernes Grab platz.");					\
									\
AddDetail("grab",							\
	"Der Kasten hat in etwa die Form eines menschlichen "		\
	"Koerpers. Die Steinplatten wirken stabil und sehr schwer. "	\
	"Bei genauerer Betrachtung faellt Dir eine Ritze auf.");	\
									\
AddDetail(({"spalt","spalte","ritze"}),					\
	"Der Deckel passt nicht exakt auf den Rumpf. Aber Du haeltst "	\
	"es nicht fuer eine gute Idee, das Grab zu oeffnen.");		\
									\
AddDetail("rumpf",							\
	"Der Rumpf besteht aus massiven, schweren Platten aus "		\
	"schwarzem Granit. Sie wurden nur grob behauen, deswegen "	\
	"kannst Du auch einen Spalt zwischen Deckel und Rumpf "		\
	"entdecken.");							\
									\
AddDetail("deckel",							\
	"Der Deckel ist aeusserst massiv, wie Du am dunklen Klang "	\
	"erkennen kannst, wenn Du dagegen klopfst. Er besteht aus "	\
	"fast schwarzem Granit. Auf ihm kannst Du eine Gravur ent"	\
	"decken.");							\
									\
AddDetail("klang",							\
	"Lausch doch mal...");						\
									\
AddDetail("granit",							\
	"Das ganze Grab ist aus schwarzem Granit, das durch die "	\
	"Witterung schon an den Ecken ziemlich mitgenommen wurde.");	
									
#define GRAB_OBEN1							\
AddDetail("witterung",							\
	"Sie hat deutliche Spuren auf dem Grab hinterlassen. Die "	\
	"Ecken sind abgestumpft und manchmal sogar abgesplittert.");	\
									\
AddDetail ( ({"ecke","ecken"}),						\
	"Die Ecken sind eigentlich schon fast rund und hin und "	\
	"wieder ist ein Stueck abgesplittert. Da hat wohl ein "		\
	"Abenteurer wutentbrannt mit dem Schwert zugeschlagen."),	\
									\
AddDetail("schwert",							\
	"Das kannst Du hier zwar nicht sehen, aber Du kannst noch "	\
	"deutlich die Spuren der Schneide erkennen.");			\
									\
AddDetail( ({"schlag","spuren"}),					\
	"Spuren eines sinnlosen Schlages einer Schwertschneide.");	\
									\
AddDetail("gravur",							\
	"Du kannst sie lesen.");					\
									\
AddReadDetail("gravur",							\
	GRAVUR_TEXT );							\
									\
AddSmell("grab",							\
	"Du glaubst, aus der Ritze einen leichten Luftstrom zu "	\
	"bemerken.");							\
									\
AddSmell( ({"luft","ritze"}),						\
	"Aus der Ritze dringt kalte, abgestandene und muffige "		\
	"Luft.");							\
									\
AddSmell( ({"strom","luftstrom"}),					\
	"Ein leichter, kaum bemerkbarer Luftstrom dringt aus dem "	\
	"Grab.");							\
									\
AddSound("grab",							\
	"Du hoerst ein leises \"chhhchhh\", das zwischen dem Grab "	\
	"und dem Deckel erklingt.");					\
									\
AddSound("chhhchhh",							\
	"Tja, mehr als ein \"chhhchhh\" des Windes kannst Du "	\
	"trotzdem nicht erlauschen.");					\
									\
AddSound("wind",							\
	"Er stroemt durch die Ritzen und verursacht ein \"chhhchhh\". "	\
	"Oder irrst Du Dich da etwa?\n");


#define GRAB_UNTEN							\
AddDetail(({"grashuegel","huegel"}),					\
	"Du siehst etwas weiter entfernt 4 langsam ansteigende Gras"	\
	"huegel auf deren Kuppen dunkle Kaesten stehen. Die Huegel sind "	\
	"einige Meter hoch, reichen aber nicht aus dem Tal hinaus.");	\
									\
AddDetail( ({"kuppe", "kuppen"}),					\
	"Du kannst von hier unten die Kuppen nicht untersuchen.");	\
									\
AddDetail( ({"kasten","kaesten"}),					\
	"Du kannst auf jedem der 4 Huegel einen dunklen Kasten "	\
	"sehen, der mitten auf der Kuppe steht. Genaueres kannst Du "	\
	"von hier nicht erkennen.");					
									

#define OEFFNE								\
int oeffne(string str)							\
{									\
	int zaehler;							\
	notify_fail("Was moechtest Du oeffnen?\n");			\
	if(!str) return 0;						\
									\
	if(str=="grab"||str=="deckel")					\
	{								\
/*		if(enemy_anz > 0)						\
		{								\
		   tell_object(TP, BS("Durch Dein Herumprobieren hast du wohl "	\
			"jemanden aufgeschreckt...\n"));			\
		   zaehler = random(5);						\
										\
		   switch(zaehler)						\
		   {								\
			case 1:							\
			{  (clone_object(NPC+"schimmler"))->move(environment(TP), M_GO);break;	}	\
			case 2:										\
			{  (clone_object(NPC+"skelett"))->move(environment(TP),M_GO);break;	}	\
			case 3:										\
			{  (clone_object(NPC+"unhold"))->move(environment(TP),M_GO);break;	}	\
			case 4:										\
			{  (clone_object(NPC+"unhold"))->move(environment(TP),M_GO);			\
			   (clone_object(NPC+"skelett"))->move(environment(TP),M_GO);break; 	}	\
			case 5:										\
			{  (clone_object(NPC+"skelett"))->move(environment(TP),M_GO);			\
			   (clone_object(NPC+"skelett"))->move(environment(TP),M_GO);break;	}	\
		   }								\
		   enemy_anz -= 1;						\
		   return 1;							\
		}*/								\
		tell_object(TP, BS("Du bemuehst Dich vergeblich, den Deckel "	\
		+"zu oeffnen. Er sitzt trotz der Ritze ausserge"	\
		+"woehnlich fest.\n"));						\
		return 1;							\
	}									\
	return 0;								\
}


#define STEIN_UNTEN							\
AddDetail( ({"stein","hinkelstein", "fels"}),				\
	"Genau im Zentrum des Tales steht aufrecht ein riesiger Fels "	\
	"in Form eines Hinkelsteines. Er ist gut und gern 10 Meter "	\
	"hoch und ragt wie ein mahnender Finger gen Himmel. Der "	\
	"Stein ist strahlend weiss mit einer glatten Oberflaeche.");	\
									\
AddDetail("zentrum",							\
	"Im Zentrum der Talsenke steht der Hinkelstein.");		\
									\
AddDetail("finger",							\
	"Er scheint Dich irgendwie zur Vorsicht mahnen zu wollen.");	\
									\
AddDetail("oberflaeche",						\
	"Obwohl der Fels nicht gleichmaessig rund geformt ist, seine "	\
	"Oberflaeche ist es jedenfalls. Bis auf ein paar kleine "	\
	"Rillen.");							\
									\
AddDetail("rillen",							\
	"Du kannst feine Rillen entdecken, in denen sich Schmutz ge"	\
	"sammelt hat.");						\
									\
AddDetail("schmutz",							\
	"Absolut normaler Schmutz.");				



#define STEIN_OBEN							\
AddDetail( ({"stein","hinkelstein", "fels"}),				\
	"Genau im Zentrum des Tales steht aufrecht ein riesiger Fels "	\
	"in Form eines Hinkelsteines. Er ist gut und gern 10 Meter "	\
	"hoch und ragt wie ein mahnender Finger gen Himmel. Der "	\
	"Stein ist strahlend weiss mit einer glatten Oberflaeche.");	\
									\
AddDetail("zentrum",							\
	"Im Zentrum der Talsenke steht der Hinkelstein.");		\
									\
AddDetail("finger",							\
	"Er scheint Dich irgendwie zur Vorsicht mahnen zu wollen.");	\
									\
AddDetail("oberflaeche",						\
	"Um das zu untersuchen, solltest Du wohl naeher an den Stein "	\
	"herangehen.");							\


#define SCHMUTZ_NOE								\
int schmutz(string str)							\
{									\
	notify_fail("Was moechtest Du denn kratzen?\n");		\
	if(!str || str == "schmutz") return 0;				\
									\
	if(str=="schmutz aus rille"||str=="dreck aus rille")		\
	{								\
		tell_object(TP, BS("Du kratzt mit deinen Fingernaegeln "	\
			"den Dreck aus den Rillen. Aber ausser dreckigen "	\
			"Fingern bringt Dir das nichts.\n"));	\
	   return 1;							\
	}								\
	return 0;							\
}



#define SCHMUTZ_YUP								\
int schmutz(string str)							\
{									\
	notify_fail("Was moechtest Du denn kratzen?\n");		\
	if(!str || str == "schmutz") return 0;				\
									\
	if(str=="schmutz aus rille"||str=="dreck aus rille")					\
	{								\
		tell_object(TP, BS("Du kratzt mit deinen Fingernaegeln "	\
			+"den Dreck aus den Rillen. Du bist nun "	\
			+"stolzer Besitzer eines kleinen Haeufchens "	\
			+"Dreck.\n"));					\
		(clone_object(OBJ+"dreck"))->move(TP);			\
	   return 1;							\
	}								\
	return 0;							\
}

#define SCHLAFEN							\
int schlafen(string str)						\
{									\
	notify_fail("Wie bitte?\n");					\
	if(!str)							\
		return 0;						\
	if(str!="ein")							\
		return 0;						\
									\
	if(file_name(TO) != "/d/kristallwald/sargola/huegel/room/0303t" )	\
	{								\
	   tell_object(TP, "Du legst Dich mit dem Ruecken an den "	\
		+"grossen kuehlen Stein. Du bleibst allerdings nicht "	\
		+"lange sitzen, weil es einfach ungemuetlich ist.\n");	\
	   return 1;							\
	}								\
	else								\
	{								\
	   tell_object(TP, "Du legst Dich mit dem Ruecken an den "	\
		+"kuehlen Stein. Es ist so bequem hier, dass Dir nach "	\
		+"einiger Zeit die Augen zufallen...\n\n\n");		\
	   if(find_call_out("sequenz")==-1)				\
		call_out("sequenz",0);					\
	   return 1;							\
	}								\
}									\
									\
sequenz()								\
{									\
	clone_object(OBJ+"sleep")->move(TP);				\
	tell_object(TP, "Du beginnst zu traeumen...\n\n\n");		\
		call_out("sequenz1", 3);				\
}									\
sequenz1()								\
{									\
	tell_object(TP, BS("Du bist in einer dunklen, unheimlichen "	\
		"Umgebung, hoerst dumpfe, klopfende Geraeusche.\n"));	\
	tell_object(TP, "\n\n\n");					\
	call_out("sequenz2", 4);					\
}									\
sequenz2()								\
{									\
	tell_object(TP, "Du siehst wirre Szenen von Untoten und "	\
		"Graebern.\nDeine Knochen beginnen zu zittern...\n\n\n");	\
	call_out("sequenz3", 4);					\
}									\
sequenz3()								\
{	object ob;							\
	ob = present("\nsleep", TP);					\
	if (objectp(ob)) ob->remove();					\
	tell_object(TP, "Du bemerkst mit Schrecken, dass es kein "	\
		"Traum ist!!\n\n\n");					\
	TP->move(ROOM+"0303n", M_GO);					\
}	



#define SCHAUE								\
int schaue(string str)							\
{									\
	notify_fail("Wodurch willst du schauen?\n");			\
	if(!str && str!="durch ritze")					\
		return 0;						\
									\
	tell_object(TP,"Du kannst im Dunkeln nichts Eindeutiges "	\
		"erkenne, aber Du bist Dir sicher, dass sich im "	\
		"Grab etwas bewegt. Ueberhaupt wirkt es so, als "	\
		"ob es dort ganz und gar nicht eng und erdig "		\
		"sei..\n");						\
	return 1;							\
}