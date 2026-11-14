/*
******************************
** STANDARD
** SPALTEGREIFEN
** SCHRECKEN
** SMELLS
** SOUNDS
******************************
*/



#define STANDARD							\
AddDetail("boden","Der Boden besteht aus schwarzen, glatten Felsen, "	\
  "zwischen denen kleine Zwischenraeume klaffen.");			\
AddDetail("felsen","Die Felsen sind ausgesprochen hart und schwarz "	\
  "wie alles andere hier auch. Sie sind ungenau gefertigt, sodass "	\
  "zwischen ihnen kleine Zwischenraeume klaffen.");			\
AddDetail("zwischenraeume","Du meinst die Spalten?");			\
AddDetail("spalten","Zwischen den Felsen findest Du ueberall kleine "	\
  "Spalten, in denen sich sicher nur Dreck befindet.");			\
AddDetail("dreck","Den kannst Du nicht sehen, weil es in den Spalten "	\
  "so unglaublich dunkel ist.");					\
AddDetail("decke","Die Decke ist ziemlich hoch ueber Dir und wurde "	\
  "von einem verspielten Baumeister konstruiert. Ueberall siehst Du "	\
  "Pfeiler und Spitzboegen.");				\
AddDetail("baumeister","Den siehst Du hier nicht, nur sein "		\
  "Schaffen.");								\
AddDetail("schaffen","Das aeussert sich in den Pfeilern und "	\
  "Spitzboegen.");							\
AddDetail("pfeiler","In regelmaessigen Abstaenden ragen Pfeiler an "	\
  "den Waenden nach oben. Der Durchmesser ist einen Meter und mehr. "	\
  "Oben mueden sie dann in grazilere Spitzboegen.");			\
AddDetail("meter","Du weisst doch, wieviel das ist!");			\
AddDetail("abstaende","Die Pfeiler sind regelmaessig in etwa einen "	\
  "Meter voneinander entfernt.");					\
AddDetail("durchmesser","So cirka ein Meter und das doppelte vom "	\
  "Radius.");								\
AddDetail("radius","Am besten, Du misst das genau nach.");		\
AddDetail(({"boegen","spitzboegen"}), "Sie laufen quer ueber die "	\
  "Decke und kreuzen sich in der Mitte. Vielleicht sind es dann "	\
  "auch Kreuzboegen??");						\
AddDetail(({"mitte", "zentrum"}),"Die Mitte befindet sich meistens "	\
  "im Zentrum.");							\
AddDetail("kreuzboegen","Die Boegen kreuzen sich in der Mitte. Dort "	\
  "entdeckst Du nun auch ein seltsames Ornament.");			\
AddDetail("ornament","Es stellt vermutlich ein Wappen dar.");		\
AddDetail("wappen","Das Wappen von Ritter Kato. \nKalte Schauer des "	\
  "Schreckens laufen ueber Deinen Ruecken.");				\
AddDetail(({"schauer", "schrecken", "ruecken"}),#'schrecken);		\
AddDetail(({"ritter", "kato", "ritter kato"}), "Er kann nicht weit "	\
  "entfernt sein... wuuaah.");						\
AddDetail(({"wand", "waende"}),"Die Waende sind aus kalten, harten "	\
  "Felsen. Hin und wieder erleuchten Fackeln den Gang.");		\
AddDetail(({"fackel", "fackeln", "teerfackel", "teerfackeln"}), "Die "	\
  "Teerfackeln haengen in eisernen Haltern und erhellen den Gang "	\
  "notduerftig. Zwischen ihnen entdeckst Du auch einige Bilder.");	\
AddDetail("bilder", "Die Bilder wirken sehr duester, sie zeigen "	\
  "dunkle Gestalten.");							\
AddDetail("gestalten", "Diese Gestalten sind gar grausig anzusehen. "	\
  "Es kann sich nur um Ritter Kato und seine widerliche Ver"		\
  "wandschaft handeln.");						\
AddDetail(({"halter", "fackelhalter"}),"In den eisernen Fackelhalter "	\
  "stecken Teerfackeln, die den Gang ausleuchten.");			\
AddDetail("gang","Ein duesterer Gang der durch die Burg fuehrt. "	\
  "Pfeiler an den Waenden ragen nach oben, dazwischen leuchten "	\
  "Teerfackeln und erleuchten den Gang notduerftig.");			\
AddDetail("burg","Du bist in einem Gang in der Burg von Ritter "	\
  "Kato.");								


#define SMELLS								\
AddSmell(DEFAULT_SMELL, "Du riechst nur die abgestande Luft der "	\
  "Burg, die Teerfackeln und noch einen anderen Duft.");		\
AddSmell("luft","Hier ist definitiv schon laenger nicht mehr ge"	\
  "lueftet worden! Durch die muffige Luft musst Du fast husten.");	\
AddSmell("burg","Die Luft in der Burg steht seit Jahrhunderten.");	\
AddSmell("jahrhunderte","Jahrhunderte riechen im Allgemeinen sehr "	\
  "muffig.");								\
AddSmell(({"fackel","fackeln","teerfackel","teerfackeln"}), "Die "	\
  "Teerfackeln verstroemen einen beissenden Geruch aus Teer und "	\
  "Rauch.");								\
AddSmell("rauch","Er riecht bitter nach Teer.");			\
AddSmell("teer","Teer alleine riecht schon unangenehm, aber wenn "	\
  "er auch noch verbrannt wird .... waeh!");				\
AddSmell(({"gestank","geruch"}),"Ein Geruch aus Teer und Rauch.");	\
AddSmell("duft","Komisch, aber neben dem ganzen Gestank hier "		\
  "riechst Du doch tatsaechlich den Geruch von Speisen!");		\
AddSmell("speisen","Woher kommt das nur?");				\
AddSmell("kueche","Riechen kannst Du sie nicht - nur hoeren.");		


#define SOUNDS								\
AddSound(DEFAULT_SOUND, "In den Gaengen hallen die Schritte von "	\
  "Spaehern, die nach Dir suchen. Weiters hoerst Du das Klappern "	\
  "von Toepfen und ein Gackern.");					\
AddSound("gaenge","Du hoerst es hallen... hall....hall...");		\
AddSound("schritte","Die Schritte kommen aus allen Richtungen. Ueber"	\
  "all scheinen Spaeher zu sein, die nach Dir suchen.");		\
AddSound("spaeher","Die Spaeher laufen aufgebracht durch die Gaenge "	\
  "und wollen Dich toeten!");						\
AddSound("klappern","Es ist ein lautes Klappern von Toepfen.");		\
AddSound("toepfe","Irgendwo muss hier eine Kueche sein, in der "	\
  "lautstark gekocht wird.");						\
AddSound("kueche","Neben dem Klappern der Toepfe hoerst Du ein "	\
  "aufgeregtes Gackern.");						\
AddSound("gackern","Es klingt wie Huehner ... warum gackern die "	\
  "wohl so aufgeregt?");						\
AddSound("huehner","Die gackern wohl um ihr Leben...");			\
AddSound("leben","Noch klingen sie ganz lebendig...");			

#define SPALTEGREIFEN							\
int greif(string str)							\
{ notify_fail("Wo moechtest Du reingreifen?\n");			\
  if(!str || (str!="spalte" && str!="in spalte" && str!="in spalte rein")) return 0;	\
  tell_object(TP, "Du wuehlst mit deinem Zeigefinger mit grosser "	\
    "Hingabe im Dreck, findest aber nichts.");				\
  tell_room(TO, TPN+"wuehlt mit Hingabe im Dreck, findet nichts und "	\
    "grinst Dich bloed an.",({TP}));					\
  return 1;								\
} 

#define SCHRECKEN							\
int schrecken()								\
{ tell_room(TO, TPN+"laufen kalte Schauer des Schreckens ueber "	\
  "den Ruecken.",({TP}));						\
  domain_shout(TPN+"macht sich in der Ferne vor Angst fast in die "	\
    "Hose.");								\
  return BS("Dir laufen kalte Schauer des Schreckens ueber den "	\
    "Ruecken.");							\
}
