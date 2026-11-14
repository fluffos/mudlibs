#define STANDARD							\
AddDetail("boden","Der Boden ist hier aus Felsgestein und einigen "	\
  "Felsbrocken, die heruntergebroeckelt sind.");			\
AddDetail(({"brocken","felsbrocken"}),"Die Felsbrocken sind eigent"	\
  "liche eher kleine Steinchen im Vergleich zu dem massiven Berg.");	\
AddDetail("steinchen","Du kickst gelangweilt eines durch die Luft.");	\
AddDetail("luft","Pffft... macht das Steinchen.");			\
AddDetail("pffft","Komisch, gell?");					\
AddDetail(({"gestein","felsgestein"}),"Das Gestein gehoert schon zu "	\
  "dem Berg im Norden dazu, der sich vor Dir fast senkrecht erhebt. "	\
  "Es ist, wie so vieles hier, schwarz ... zumindest das, was du vom "	\
  "Berg siehst.");							\
AddDetail("berg","Ein maechtiger Berg erhebt sich genau vor Dir im "	\
  "Norden und Du kommst Dir ploetzlich ganz klein und mickrig vor. "	\
  "Nicht einmal ansatzweise kannst Du die Spitze sehen. Du siehst "	\
  "aber keinen Weg an dem Berg vorbei. Hach waere es jetzt schoen, "	\
  "Berge versetzen zu koennen.");					\
AddDetail("spitze","Sie ist viel zu weit weg.");			\
AddDetail("himmel","Der Himmel liegt friedlich und blauschwarz ueber "	\
  "Dir. Komischerweise kannst du keine Sterne erblicken, obwohl es nicht "	\
  "neblig ist.");							\
AddDetail("sterne","Normalerweise muesstest Du doch welche sehen "	\
  "koennen ... Das muss wieder die Macht von Ritter Kato sein.");	\
AddDetail("macht","Die sieht man an den fehlenden Sternen.");		\
AddDetail(({"ritter","kato"}),"Den sieht man nur durch sein durch "	\
  "und durch boeses Wirken.");						\
AddDetail("wirken","Sag bloss, Dir ist nichts aufgefallen...");		\
AddDetail("weg","Weder vorbei noch ueber den Berg findest Du einen "	\
  "Weg. Er ist einfach zu steil.");					\
AddDetail("baeume","Die siehst Du im Sueden.");


#define VERSETZE							\
int versetze(string str)						\
{									\
  notify_fail("Was moechtst Du versetzen?\n");				\
  if(!str || str!="berg") return 0;					\
  									\
  if(str=="berg")							\
  {									\
    tell_object(TP, BS("Du gehst hoechstmotiviert zur Felswand und "	\
      "beginnst allen Ernstes mit dem Versuch, den Berg zu versetz"	\
      "en! Das ganze endet damit, dass der Berg bleibt, wo er ist "	\
      "und Du mit peinlich hochrotem Kopf dastehst!"));			\
    tell_room(TO, BS(TPN+"geht hoechstmotiviert zur Felswand und be"	\
      "ginnt allen Ernstes mit dem Versuch, den Berg zu versetz"	\
      "en! Das ganze endet damit, dass der Berg bleibt, wo er ist "	\
      "und "+TPN+" mit peinloch hochrotem Kopf dasteht!"),({TP}));		\
    return 1;								\
  }									\
  return 0;								\
}
