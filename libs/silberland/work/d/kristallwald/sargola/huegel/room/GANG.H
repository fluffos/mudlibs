/*
***********************************************************************
**
** h-file fuer die unterirdischen Gaenge
**
** date: 09-05-97
***********************************************************************
**
** STANDARD
** SS		->	sounds, smells
** INNIT		->	Du rennst in eine Unebenheit der Decke
** HAND		->	Man loesst einen Erdrutsch aus ;)
** SCHLINGE	->	kampf mit schlingpflanze		(func)
*/


#define STANDARD							\
AddDetail("boden",							\
	"Der Boden ist aus festgetrampelter Erde und recht uneben. "	\
	"Hin und wieder wachsen Wurzeln und andere schlingartige "	\
	"Pflanzen aus ihm. Es sieht so aus, als ob schon viele "	\
	"Fuesse ueber ihn gelaufen waeren.");				\
									\
AddDetail( ({"erdreich","erde"}),					\
	"Die Erde ist dunkelbraun, kuehl und am Boden von vielen "	\
	"Fuessen zusammengedrueckt. An den Waenden broeckelt sie "	\
	"leicht ab, wenn Du mit der Hand ueber sie faehrst. Die "	\
	"Decke wirkt auch nicht unbedingt so, als ob Du hier unbe"	\
	"dingt sicher waerst.");					\
									\
AddDetail( ({"fuss","fuesse"}),						\
	"Du kannst nur mehr die Abdruecke erkennen.");			\
									\
AddDetail( ({"abdruecke","abdruck"}),					\
	"Viele Spuren, die kreuz und quer laufen, haben sich am "	\
	"Boden verewigt. Du kannst Spuren von schweren Schuhen, "	\
	"leichten Sandalen und auch Abdruecke von Fuessen "		\
	"erkennen.");							\
									\
AddDetail( ({"spuren"}),						\
	"Eine grosse Anzahl von Spuren verlaeuft am Boden.");		\
									\
AddDetail("anzahl",							\
	"Einfach viele...");						\
									\
AddDetail("schuhe",							\
	"Der Traeger, der die Abdruecke mit den Schuhen hinterliess, "	\
	"muss ein ziemlich ausgewachsener Bursche sein. Sonst wuerden "	\
	"die Abdruecke nicht so tief sein...");				\
									\
AddDetail("sandalen",							\
	"Die Abdruecke der Sandalen sind nicht so tief und auch "	\
	"ein gutes Stueck kleiner.");					\
									\
AddDetail("fuessen",							\
	"So seltsam es auch anmutet, Du siehst sogar Spuren von "	\
	"nackten Fuessen. Und das merkwuerdigste ist, dass bei "	\
	"einigen Spuren die Abdruecke der Zehen nicht vollstaendig "	\
	"sind...");							\
									\
AddDetail("zehen",							\
	"Einige der Abdruecke haben nur 4 oder gar 3 Zehen! Was das "	\
	"wohl bedeuten mag...");					\
									\
AddDetail(({"wurzel","wurzeln"}),					\
	"An einigen Stellen an Waenden, Decke und Boden dringen "	\
	"Wurzeln durch das Erdreich. Sie sind weisslich und wenn "	\
	"Du sie angreifst, fuehlen sie sich weich an. Sogar finger"	\
	"dicke Wurzeln haengen von der Decke.");			\
									\
AddDetail("pflanzen",							\
	"Die Pflanzen sind Dir nicht ganz geheuer. Einige Schlingen "	\
	"scheinen sich zu bewegen...");					\
									\
AddSpecialDetail("schlingen","schlingen");				\
									\
AddSpecialDetail("hand","hand");					\
									\
AddDetail("decke",							\
	"Die Decke ist ungleich und broeckelt von Zeit zu Zeit ab. "	\
	"Von ihr haengen weissliche Wurzeln und schlagen Dir ins "	\
	"Gesicht. Du kannst gerademal durchgehen, ohne Dich buecken "	\
	"zu muessen.");							\
									\
AddDetail( ({"wand","waende"}),						\
	"Die Waende laufen nach oben hin leicht zusammen und sind, "	\
	"wie die Decke, ungenau gearbeitet. Pflanzen und Wurzeln "	\
	"haengen von den Waenden herunter.");				\
									\
AddDetail("luftzug",							\
	"Du denkst . o 0 ( Wie kann hier unten einen Luftzug geben?).");	

									
#define INNIT								\
init()									\
{									\
	if(random(25))							\
	{  tell_object(TP, "Durch Deine Unachtsamkeit schlaegst Du "	\
	   	"Dir den Kopf an der Decke an.\n");			\
	   TP->reduce_hit_points(4);					\
	}								\
	if(random(30))							\
	{  tell_object(TP, "Du bleibst mit dem Kopf in einer Wurzel"	\
		"schlinge haengen.\n");					\
	   TP->reduce_hit_points(8);					\
	}								\
	::init();							\
}

									


#define SS								\
AddSound(DEFAULT_SOUND,							\
	"Du kannst viele verschiedene und erschreckende Geraeusche "	\
	"hoeren.\n");							\
									\
AddSound(({"gaenge","geraeusche"}),					\
	"In den Gaengen pflanzen sich Schleifgeraeusche, ein Rauschen "	\
	"des Windes, hin und wieder ein Knacksen und auch "		\
	"Laute von laufenden Kreaturen fort.\n");			\
									\
AddSound(({"schleifen","schleifgeraeusche"}),						\
	"Alle 2 bis 3 Sekunden hoerst Du ein Schleifen. Du kannst "	\
	"es aber nicht genau lokalisieren.\n");				\
									\
AddSound("rauschen",							\
	"Das Rauschen kommt vom offenen Grab. Obwohl oben kein "	\
	"starker Wind wehte, kannst Du einen Luftzug spueren.");	\
									\
AddSound("wind",							\
	"Der Wind verursacht das Rauschen, welches sich in den "	\
	"Gaengen hier gut fortpflanzt.\n");				\
									\
AddSound("knacksen",							\
	"Hmm....was das sein soll, kannst Du Dir beim besten Willen "	\
	"nicht vorstellen.\n");						\
									\
AddSound("laute",							\
	"Du kannst keine bestimmten Woerter oder Saetze erkennen, "	\
	"aber Du bist Dir sicher, dass das eine Art Kommunikation "	\
	"sein soll...\n");						\
									\
AddSound( ({"woerter","saetze"}),					\
	"Du verstehst nichts von dem.");				\
									\
AddSound("kommunikation",						\
	"Es ist mehr wie ein Fluestern.");				\
									\
AddSound("fluestern",							\
	"Welche Wesen auch immer, sie halten gerade Absprache.");	\
									\
AddSound("absprache",							\
	"Du bemuehst Dich, etwas zu verstehen, aber nur Fragmente "	\
	"kannst Du sicher identifizieren.");				\
									\
AddSound("fragmente",							\
	"Sie sagen: \"Toetet sie!\"!\nDu erbleichst.\n");		\
									\
AddSmell(DEFAULT_SMELL,							\
	"Du riechst kalte, abgestandene Luft. Von dem offenen Grab "	\
	"dringt frische Luft von der Oberflaeche zu Dir. Sehr alt "	\
	"duerften die Gaenge hier nicht sein, da alles noch nach "	\
	"frischer Erde riecht.");					\
									\
AddSmell("luft",							\
	"Die Luft riecht einerseits miefig, aber auch frisch.");	\
									\
AddSmell("grab",							\
	"Nachdem in dem Grab ja nicht, wie erwartet, Knochenreste "	\
	"oder aehnliches liegt, riecht es hier nicht nach Grab.");	\
									\
AddSmell("knochenreste",						\
	"Vielleicht gibt es die anders wo...");				\
									\
AddSmell( ({"erde","gaenge"}),						\
	"Die Gaenge scheinen erst vor kurzer Zeit gegraben worden "	\
	"sein, da Du noch frische Erde riechen kannst.");		\
									\
AddSmell("wurzeln",							\
	"Die Wurzeln riechen wie normale Wurzeln eben so riechen.");




#define HAND								\
int hand(string str)							\
{									\
	notify_fail("Worueber moechtest Du fahren?\n");			\
	if(!str && str!="mit hand ueber erde")				\
		return 0;						\
									\
	if(random(5)==1)						\
	{								\
	   tell_object(TP, "Du faehrst mit der Hand und ploetzlich "	\
		"loesst sich eine riesige Schicht von Erde aus der "	\
		"Wand und faellt auf Dich!!");				\
	   TP->do_damage(35);						\
	   return 1;							\
	}								\
	   tell_object(TP, "Du faehrst mit der Hand ueber die Erde "	\
		"und weckst dadurch zwei Regenwuermer auf!");		\
	   (clone_object(NPC+"rwurm"))->move(TO, M_GO);			\
	   (clone_object(NPC+"rwurm"))->move(TO, M_GO);			\
	   return 1;							\
}									\


#define SCHLINGE							\
int schlinge()								\
{									\
	if(schlinge)							\
	{								\
	   tell_object(TP, "Als Du die Schlingpflanze naeher unter"	\
		"suchst, merkst Du, dass sie ganz lebendig ist!\n");	\
	   clone_object(OBJ+"schlinge")->move(TO, M_GO);		\
	   schlinge = 0;						\
	   return 1;							\
	}								\
	else								\
	{								\
	   tell_object(TP, "Die Schlingpflanzen haengen von der "	\
		"Decke und sind nach wohl kaum von groesserem "		\
		"Interesse.\n");					\
	}								\
	return 1;							\
}
	   