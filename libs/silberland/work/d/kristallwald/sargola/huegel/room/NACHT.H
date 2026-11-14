/*
***********************************************************************
**
** h-file fuer die Huegelgraeber
** Raeume bei Nacht :)
** 
** date: 22-09-97
***********************************************************************
**
** STANDARD	->	Raum-Details
** SS		->	Sounds, smells
** GRAB_OBEN	->	Ein Huegelgrab
** GRAB_UNTEN
** OEFFNE	->	Graboeffnung in der Nacht 	(func)
** STEIN_UNTEN	->	Steindetails
** STEIN_OBEN	->	Steindetails
** SCHMUTZ	->	Schmutz rauskratzen 		(func)
** SCHAUE	->	Blick durch Ritze		(func)
** SCHLAFEN	->	zurueck-schlafen		(func)
**
** zu definieren: 	GRAVUR_TEXT
**
*/


#define STANDARD							\
AddDetail("boden",							\
	"Der Boden ist mit einer dichten, blassgruenen Wiese bedeckt. "	\
	"Schemenhaft bemerkst Du Blueten kleiner, unscheinbarer "	\
	"Blumen. Die Straeucher erscheinen Dir nun wie bedrohliche, "	\
	"schwarze Flecken. Auch die sanft ansteigenden Haenge wirken "	\
	"erdrueckend.");						\
									\
AddDetail("flecken",							\
	"Du kannst schwer erkennen, was hinter den Flecken steckt. "	\
	"An der Form glaubst Du Straeucher erkennen zu koennen. Hat "	\
	"sich da nicht eine Schatten bewegt??");			\
									\
AddDetail("schatten",							\
	"Du bist Dir ganz sicher, dass sich einer der Schatten bewe"	\
	"gt hat...Also doch nicht nur harmlose Straeucher...Was "	\
	"wohl hinter der Silhouette steckt?");				\
									\
AddDetail("silhouette",							\
	"Als Du genauer hinsiehst, ist wieder alles mucksmaeuschen"	\
	"still. War das alles nur Einbildung oder ist ausser Dir "	\
	"noch jemand hier?");						\
									\
AddDetail("wiese",							\
	"Die Farbe der dicht wachsenden Wiese ist nicht mehr blass"	\
	"gruen, sondern fast schwarz. Wenn Du nicht wuesstest, dass "	\
	"hier Wiese waechst, haettest Du es nicht erkannt.");		\
									\
AddDetail("farbe",							\
	"Die bei Tag wohl blassgruene Wiese ist bei Nacht einfach "	\
	"schwarz.");							\
									\
AddDetail( ({"blume","blumen"}),					\
	"Die Blueten der Blumen scheinen kaum merklich und Du bist "	\
	"Dir oft nicht sicher, ob Du Dir die blassen, farblichen "	\
	"Flecken nicht nur einbildest.");				\
									\
AddDetail( ({"bluete","blueten"}),					\
	"Normalerweise wuerde Dich der Anblick wohl erfreuen, aber "	\
	"um diese Zeit tun sie das kaum.");				\
									\
AddDetail("anblick",							\
	"War der Anblick bei Tag schon irritierend, ist er bei Nacht "	\
	"noch um vieles bedrueckender.");				\
									\
AddDetail("tag",							\
	"Netter Versuch, aber es ist Nacht!  ;)");			\
									\
AddDetail("gegend",							\
	"Viel kannst Du bei der Sicht ja nicht entdecken. Du siehst "	\
	"ja nur einige Meter weit.");					\
									\
AddDetail("erde",							\
	"Die Erde ist kuehl, locker und vor allem schwarz.");		\
									\
AddDetail("straeucher",							\
	"Waren die Straeucher schon bei Tag unheimlich, so sind sie "	\
	"es bei Nacht durch ihre merkwuerdig verkrueppelte Form "	\
	"noch viel mehr. Fast meinst Du, die Schatten der Straeucher "	\
	"wuerden sich bewegen.");					\
									\
AddDetail("form",							\
	"In diese Licht sehen die Straeucher wie verkrueppelte Wesen "	\
	"aus, die alle in Deine Richtung blicken.");			\
									\
AddDetail( ({"wesen"}),							\
	"Du willst gar nicht ganauer wissen, was denn genau dahinter "	\
	"steckt.");							\
									\
AddDetail(({"vollmond","mond"}),					\
	"Du bist froh, den Mond ueber Dir am Firmament haengen zu "	\
	"sehen. Auch wenn es nicht viel ist, er spendet Dir immer"	\
	"hin ein wenig Licht.");					\
									\
AddDetail( ({"himmel","firmament"}),					\
	"Auf dunkelblau-schwarzerm Hintergrund erkennst Du kraeftig "	\
	"leuchtend den Nordstern. Erst nach laengerem Absuchen des "	\
	"Himmels bemerkst Du einige weitere kleine Sterne.");		\
									\
AddDetail("hintergrund",						\
	"Du glaubst noch einen Schimmer von dunklem Blau zu "		\
	"erkennen.");							
									

#define STANDARD1							\
AddDetail("schimmer",							\
	"Besonders am westlichen Horizont, wo schon vor einger Zeit "	\
	"die Sonne untergegangen sein muss, kannst Du den blaeu"	\
	"lichen Ton bemerken.");					\
									\
AddDetail("horizont",							\
	"Du kannst lediglich vermuten, wo er sich befindet.");		\
									\
AddDetail("zeit",							\
	"Tja, wie lange Du geschlafen hast, kannst Du nicht sagen. "	\
	"Aber es war auf jeden Fall zu lange...");			\
									\
AddDetail("ton",							\
	"Ein Schimmer von Dunkelblau im sonst schwarzen Firmament.");	\
									\
AddDetail("nordstern",							\
	"Immerhin kannst Du am intensiven Strahlen erkennen, dass "	\
	"dies wohl der Nordstern sein muesste. Sonst haettest Du wohl "	\
	"die Orientierung verloren.");					\
									\
AddDetail("strahlen",							\
	"Immerhin sind sie ein wenig kraeftiger als die der anderen "	\
	"Sterne.");							\
									\
AddDetail("orientierung",						\
	"Also wenn man \"Orientierung\" soo leicht finden koennte...");	\
									\
AddDetail("sterne",							\
	"Hie und da findest Du kleine Sterne am Himmel. Du musst "	\
	"jedoch schon sehr genau schauen, um zu entdecken, dass "	\
	"es eine auffaelligere Sternenkonstellation gibt.");		\
									\
AddDetail( ({"konstellation","sternenkonstellation"}),			\
	"Du weisst nicht, wie die Konstellation heisst.");		\
									\
AddDetail("absuchen",							\
	"Das faellt Dir bei diesen Lichtverhaeltnissen recht schwer.");	\
									\
AddDetail("lichtverhaeltnisse",						\
	"Sollte es Dir bisher noch nicht aufgefallen sein: Es ist "	\
	"dunkel hier! ;)" );						\
									\
AddDetail( ({"mondlicht","licht"}),					\
	"Viel ist es zwar nicht, aber Du kannst deutlich den weissen "	\
	"Stein im Zentrum des Tales sehen. Sonst hat der Mond, ob"	\
	"wohl er fast voll ist, kaum Leuchtkraft.");			\
									\
AddDetail("leuchtkraft",						\
	"Naja, der Mond reflektiert das Licht ja nur...*gruebel*");	\
									\
AddDetail( ({"hang","haenge"}),						\
	"Die Haenge beginnen sanft und steigen bis zur Kante "		\
	"immer steiler an. Der Grat hebt sich durch das Mondlicht "	\
	"vom Himmel sichtbar ab.");					\
									\
AddDetail( ({"linie","grat"}),						\
	"Du kannst nur eine schwarze Linie sehen, die wohl der Grat "	\
	"sein muss.");							\
									\
AddDetail("kante",							\
	"Die Kante ist weit oberhalb und Du siehst keine Moeglich"	\
	"keit, sie naeher zu untersuchen. Du bist Dir nur sicher, "	\
	"dass sie mit Wiese bedeckt ist.");
									







#define SS								\
AddSmell(DEFAULT_SMELL,							\
	"Nur die kuehle Nachtluft umschmeichelt Deine Nase.");		\
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
	"Dir ist vorher schon aufgefallen, dass es hier nicht so "	\
	"ruhig ist, wie Du es Dir erwartet hast. Besonders diese "	\
	"fast schon regelmaessigen Geraeusche schuechtern Dich ein.");	\
									\
AddSound( ({"laute","geraeusche"}),					\
	"Du hoerst immer wieder leises Stoehnen und bestaendiges "	\
	"Schleifen.");							\
									\
AddSound( ({"stoehnen"}),						\
	"Es ist nur ganz leise und Du kannst auch nicht die Rich"	\
	"tung peilen, aber es ist definitiv da. Nur welches Wesen "	\
	"gibt derartige Laute von sich?");				\
									\
AddSound( ({"kreatur","wesen"}),					\
	"Es ist ein langgezogenes, tiefes Stoehnen, als ob die "	\
	"Kreatur gepeinigt wird.");					\
									\
AddSound("schleifen",							\
	"Das schleifende Geraeusch kommt aus verschiedenen Richtungen "	\
	"und scheint sich auch zu bewegen. Du merkst, wie Dein Puls "	\
	"schneller zu schlagen beginnt.");				\
									\
AddSound("puls",							\
	"Bummm.......Bummm......Bummm......");				\
									






#define GRAB_UNTEN							\
AddDetail("huegel",							\
	"Um Dich herum befinden sich vier Huegel, die in der Dunkel"	\
	"heit aber nur als bedrohliche duestere Schatten erscheinen. "	\
	"Auf ihnen kannst kannst Du eckige, dunkle Gebilde erahnen.");	\
									\
AddDetail("gebilde",							\
	"Ob das Graeber sind, auf den Huegeln dort?");			\
									\
AddDetail( ({"grab", "graeber"}),					\
	"Du hast das Gefuehl, Du solltest die Graeber lieber in Ruhe "	\
	"lassen.");							\
									

#define GRAB_OBEN							\
AddDetail("grab",							\
	"In das Grab passt ein ausgewachsener Mensch bequem hinein. "	\
	"Die Steinplatten wirken stabil und schwer. Erst nach einiger "	\
	"Zeit faellt Dir eine Ritze am Grab auf.\n");			\
									\
AddDetail("huegel",							\
	"Von dem grasbewachsenen Huegel kannst Du ins Tal hinunter "	\
	"blicken, wo der Hinkelstein im Zentrum steht.");		\
									\
AddDetail("ritze",							\
	"Der Deckel passt nicht exact auf das Grab. Aber Du haeltst "	\
	"es nicht fuer eine gute Idee, das Grab zu oeffnen.");		\
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
	"Witterung schon an den Ecken ziemlich mitgenommen wurde.");	\
									\
AddDetail("witterung",							\
	"Sie hat deutliche Spuren auf dem Grab hinterlassen. Die "	\
	"Ecken sind abgestumpft und manchmal sogar abgesplittert.");	\
									\
AddDetail ( ({"ecke","ecken"}),						\
	"Die Ecken sind eigentlich schon fast rund und hin und "	\
	"wieder ist ein Stueck abgesplittert. Da hat wohl ein "		\
	"Abenteurer wutentbrannt mit dem Schwert zugeschlagen.");	\
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
	"Du hoerst ein leises \"chhhhchhhhh\", das zwischen dem Grab "	\
	"und dem Deckel erklingt.");					\
									\
AddSound("chhhhchhhh",							\
	"Tja, mehr als ein \"chhhhchhhh\" des Windes kannst Du "		\
	"trotzdem nicht erlauschen.");					\
									\
AddSound("wind",							\
	"Er stroemt durch die Ritzen und verursacht ein \"chhhchhh\". "	\
	"Oder irrst Du Dich da etwa?\n");


#define OEFFNE							\
int oeffne(string str)							\
{									\
	int zaehler;							\
	notify_fail("Was moechtest Du oeffnen?\n");			\
	if(!str) return 0;						\
	if(random(3)==1 && enemy_anz)							\
	{								\
	   tell_object(TP, "Durch Dein Herumprobieren hast du wohl "	\
		"jemanden aufgeschreckt...\n");				\
	   zaehler = random(5);						\
									\
	   switch(zaehler)						\
	   {								\
		case 1:							\
		{  (clone_object(NPC+"schimmle"))->move(TO, M_GO);break;	}	\
		case 2:									\
		{  (clone_object(NPC+"skelett"))->move(TO, M_GO); break;	}	\
		case 3:									\
		{  (clone_object(NPC+"unhold"))->move(TO, M_GO);break;		}	\
		case 4:									\
		{  (clone_object(NPC+"unhold"))->move(TO, M_GO);			\
		   (clone_object(NPC+"skelett"))->move(TO, M_GO);break;		}	\
		case 5:									\
		{  (clone_object(NPC+"skelett"))->move(TO, M_GO);			\
		   (clone_object(NPC+"skelett"))->move(TO, M_GO);break;		}	\
	   }								\
	   enemy_anz -= 1;						\
	   return 1;							\
	}								\
	else								\
	{								\
		tell_object(TP, BS("Du bemuehst Dich redlich, aber Du "	\
			"bewegst den Deckel keinen Millimeter."));	\
		return 1;						\
	}								\
	return 0;							\
}


#define STEIN_UNTEN							\
AddDetail( ({"stein","hinkelstein", "fels"}),				\
	"Genau im Zentrum des Tales steht aufrecht ein riesiger Fels "	\
	"in Form eines Hinkelsteines. Er ist gut und gern 10 Meter "	\
	"hoch und ragt wie ein mahnender Finger gen Himmel. Der "	\
	"weiss im Dunkeln schimmernde Stein besitzt eine glatte "	\
	"Oberflaeche.");						\
									\
AddDetail("dunkel",							\
	"Um Dich herum ist es dunkel...");				\
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
	"Den kannst Du so nicht erkennen.");				


#define STEIN_OBEN							\
AddDetail( ({"stein","hinkelstein", "fels"}),				\
	"Genau im Zentrum des Tales steht aufrecht ein riesiger Fels "	\
	"in Form eines Hinkelsteines. Er weiss im Dunkeln schimmernde "	\
	"STein ist gut und gern 10 Meter hoch und ragt wie ein "	\
	"mahnender Finger gen Himmel.");				\
									\
AddDetail("dunkel",							\
	"Um Dich herum ist es absolut finster...");			\
									\
AddDetail("zentrum",							\
	"Im Zentrum der Talsenke steht der Hinkelstein.");		\
									\
AddDetail("finger",							\
	"Er scheint Dich irgendwie zur Vorsicht mahnen zu wollen.");	
									



#define SCHMUTZ								\
int schmutz(string str)							\
{									\
	notify_fail("Was moechtest Du denn kratzen?\n");		\
	if(!str || str == "schmutz") return 0;				\
									\
	if(str=="schmutz aus rille")					\
	{								\
		tell_object(TP, "Du kratzt mit deinen Fingernaegeln "	\
			+"den Dreck aus den Rillen.Aber ausser dreck"	\
			+"igen Fingern bringt Dir das nichts.");	\
	   return 1;							\
	}								\
	return 0;							\
}


#define SCHAUE								\
int schaue(string str)							\
{									\
	notify_fail("Wodurch willst du schauen?\n");			\
	if(!str && str!="durch ritze")					\
		return 0;						\
									\
	tell_object(TP,"Du kannst im Dunkeln nichts Eindeutiges "	\
		"erkennen, aber Du bist Dir sicher, dass sich im "	\
		"Grab etwas bewegt. Ueberhaupt wirkt es so, als "	\
		"ob es dort ganz und gar nicht eng und erdig "		\
		"sei..\n");						\
	return 1;							\
}


#define SCHLAFEN							\
int schlafen(string str)						\
{	object *npcs;							\
	notify_fail("Wie bitte?\n");					\
	if(!str)							\
		return 0;						\
	if(str!="ein")							\
		return 0;						\
									\
	if(file_name(TO) != "/d/kristallwald/sargola/huegel/room/0303t" )	\
	{								\
	   tell_object(TP, "Du versuchst krampfhaft einzuschlafen, "	\
	   	"aber es will Dir nicht gelingen.\n");			\
	   return 1;							\
	}								\
	else								\
	{  								\
	   npcs = filter_array(TO);					\
	   npcs-=TP;							\
	   if(npcs)							\
	   {								\
	   	tell_object(TP, "Du kannst nicht einschlafen, wenn dauernd "	\
	   		"irgendwelche Kreaturen neben Dir stehen!");	\
	   	return 1;						\
	   }								\
	   else								\
	   {								\
	   	tell_object(TP, "Du legst Dich an den kalten Stein "	\
	   		"und gleitest in einen unruhigen Schlaf.");	\
	   	TP->move(ROOM+"0303t", M_GO);				\
	   	return 1;						\
	   }								\
	}								\
}									\
