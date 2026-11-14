/*
***********************************************************************
**
** h-file fuer den abschuessigen Gang
**
** date: 06-07-97
***********************************************************************
**
** 
** 
*/


#define STANDARD							\
AddDetail("boden",							\
	"Der Boden ist kuehl, mit feinem Staub bedeckt und es "		\
	"knirscht, wenn Du gehst. Er ist von einer Art Randstein "	\
	"gesaeumt. Erstaunlicherweise ist der Boden ganz eben.");	\
									\
AddDetail("randstein",							\
	"Er laeuft links und rechts am Boden entlang und ist circa "	\
	"20 Zentimeter hoch und schmal. Darauf kann man auf keinen "	\
	"Fall gehen. Wozu der wohl dient? Auch die Kanten des Rand"	\
	"steines sind exact verarbeitet worden. Bei genauem Hinsehen "	\
	"entdeckst Du Schleifspuren.");					\
									\
AddDetail("kanten",							\
	"Die Kanten sind gleichmaessig abgerundet.");			\
									\
AddDetail( ({"spuren","schleifspuren"}),				\
	"Unter dem Staub erkennst Du Schleifspuren, also sein "		\
	"hier ein schwerer Gegenstand geschliffen worden. Die Kerben "	\
	"sind teilweise ziemlich tief.");				\
									\
AddDetail(({"furchen","kerben"}),					\
	"Du entdeckst tiefe Kerben und Furchen, die sicherlich "	\
	"von dem Stein stammen, der auf Dich zurumpelt.");		\
									\
AddDetail("gegenstand",							\
	"Das kann wohl nur der Steinblock sein, der bestaendig den "	\
	"Gang entlang in Deine Richtung rutscht...");			\
									\
AddDetail("richtung",							\
	"Die Richtung entspricht der des Ganges.");			\
									\
AddDetail( ({"block","steinblock"}),					\
	"Er rutscht durch das leichte Abfallen des Ganges bestaendig "		\
	"in Deine Richtung. Du solltest Dir schnell was ueberlegen...");	\
									\
AddDetail("abfallen",							\
	"Der Gang faellt leicht nach unten ab.");			\
									\
AddDetail(({"sand","staub"}),						\
	"Der Staub, man koennte fast schon Sand dazu sagen, ist sehr "	\
	"grob und bedeckt den ganzen Boden.");				\
									\
AddDetail(({"wand","waende"}),						\
	"Die Waende sind, wie der Block selbst, aus grauem Stein und "	\
	"fuehlen sich auch kuehl an. Sie sind aus einem Stueck ge"	\
	"fertigt.");							\
									\
AddDetail("stein",							\
	"Der Quader sieh von innen genauso aus wie von aussen. Grauer "		\
	"Stein mit einem weisslichen Schimmer.");			\
									\
AddDetail("quader",							\
	"In den kannst Du nicht wieder zurueck.");			\
									\
AddDetail("stueck",							\
	"Das hier muss alles ein riesiger Block aus Stein gewesen "	\
	"sein - oder, man kann die einzelnen Steine einfach nicht "	\
	"erkennen.");							\
									\
AddDetail("schimmer",							\
	"Der Stein scheint ebenfalls kristallin zu sein.");		\
									\
AddDetail("decke",							\
	"Die Decke ist knapp ueber Deinem Kopf und bietet keine "	\
	"Besonderheiten.");						\
									\
AddDetail("besonderheiten",						\
	"Selbst wenn Du wollen wuerdest, Du koenntest Die Decke "	\
	"nicht untersuchen - es ist einfach zu dunkel.");		\
									\
AddSound(DEFAULT_SOUND,							\
	"Du das Knirschen und Grammeln des Blockes.");			\
									\
AddSmell(DEFAULT_SMELL,							\
	"Es mieft hier drin unglaublich...Dir wird mulmig.");		\
									\
AddSmell("luft",							\
	"Die kuehle Luft steht schon sicher seit vielen Jahren..."	\
	"Obwohl ... irgendwie kommt es Dir vor, als sei sie hier "	\
	"kaelter aus in dem grossen Quader.");				\
									\
AddSound("ton",								\
	"Hin und wieder glaubst Du ein leises Lueftchen zu hoeren. Ob "	\
	"es hier doch irgendwo ins Freie geht?");			\
									\
AddSound("lueftchen",							\
	"Du kannst es nicht genau lokalisieren. Aber es kommt Dir vor, "	\
	"als sei es hier etwas kuehler als im Quader.");		\
									\
AddSound( ({"knirschen","grammeln"}),					\
	"Das Knirschen und Grammeln kommt immer naeher...");		\
									\
AddSound( ({"block","steinblock"}),					\
	"Er verursacht durch sein Rutschen ein Knirschen, das Dir "	\
	"durch Mark und Bein faehrt.");


