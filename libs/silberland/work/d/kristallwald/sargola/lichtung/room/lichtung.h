/*
** ladfjkldasjfldasjflkadslk
***********************************************************************
**
** h-file fuer die Lichtung westlich von Elessar
**
** date: 09-05-97
***********************************************************************
**
** STANDARD
** SS	->		sounds, smells
** GOBLIN_ATTACK	Angriff von Goblins ;)
** BLUMEN		Blumen-pfluecken
*/

#define STANDARD							\
AddDetail("lichtung",							\
	"Du stehst auf der Lichtung.\n");				\
AddDetail("boden",							\
	"Der Boden ist mit einer dichten, dunkelgruenen Wiese be"	\
	"deckt. Hin und wieder siehst Du einige Blumen bluehen. "	\
	"Einen Weg kannst Du hier nicht erkennen.");			\
AddDetail("wiese",							\
	"Die Wiese wuchert hier ueberall und bedeckt den Boden. Hier "	\
	"scheint ein guter Boden zu sein.");				\
AddDetail(({"blume","blumen"}),					        \
	"Hin und wieder wachsen in verschiedensten Farben "		\
	"bluehende Blumen.");						\
AddDetail("farben",							\
	"Du siehst weiss, rot und blau bluehende Blumen.");		\
AddDetail(({"gaensebluemchen","bluemchen","weiss","weisse Blumen"}),	\
	"Hmmm, Du bist ja kein Fachmann, aber Du vermutest mit an "	\
	"Sicherheit grenzender Wahrscheinlichkeit, dass es sich "	\
	"hierbei um Gaensebluemchen handeln muss!");			\
AddDetail("fachmann",							\
	"Ausser Dir ist ja keiner da, der ein Fachmann sein koenn"	\
	"te...");							\
AddDetail("sicherheit",							\
	"Na sowas kannst Du hier nun wirklich nicht sehen...");		\
AddDetail("wahrscheinlichkeit",						\
	"Die Wahrscheinlichkeit, dass Du die Blume auch erkennst, "	\
	"ist hier gemeint.");						\
AddDetail(({"mohnblume","mohnblumen","rot","rote blume","rote blumen"}),\
	"Also die roten Blumen muessen wohl Mohnblumen sein. "		\
	"Das kannst Du an dem dunklen Kreuz in der Mitte "		\
	"der Bluete sehen.");						\
AddDetail("kreuz",							\
	"Mohnblumen haben ein dunkles Kreuz in der Mitte der Bluete.");	\
AddDetail("bluete",							\
	"Du kannst ganz deutlich das fast schwarze Kreuz in der "	\
	"Mitte entdecken. Es ist an den Enden weiss und gezackt.");	\
AddDetail("mitte",							\
	"Die Mitte wird genau durch ein dunkles, fast schwarzes "	\
	"Kreuz gekennzeichnet.");					\
AddDetail(({"enden","ende"}),						\
	"Die Enden verlaufen in weissen ausgefransten Zacken.");	\
AddDetail("zacken",							\
	"Die Zacken sind am Ende voellig weiss. Sie geben der "		\
	"Mohnblume ein schoenes Aussehen.");				\
AddDetail(({"blau","blaue blumen","blaue blume","kornblume"}),		\
	"An den gezackten, blauen Bluetenblaettern erkennst Du, dass "	\
	"es eine Kornblume sein muss.");				\
AddDetail("weg",							\
	"Die Wiese ist so dicht hier, einen Weg kannst Du nicht "	\
	"sehen. Zwar trampelten offensichtlich schwere Wesen "		\
	"hier herum, aber die kannst Du gerade nicht sehen.");		\
AddDetail("wesen",							\
	"Du kannst keinen entdecken, solltest aber auf der Hut "	\
	"sein.");							\
AddDetail("himmel",							\
	"Der Himmel leuchtet tiefblau ueber Dir. Die Sonne strahlt "	\
	"und verbreitet eine sanfte Waerme. Du fuehlst Dich einfach "	\
	"wohl.");							\
AddDetail("waerme",							\
	"Du fuehlst sie deutlich auf Deiner Haut.");			\
AddDetail("sonne",							\
	"Du solltest nicht mit blossem Auge in die Sonne schauen!");	\
AddDetail("auge",							\
	"Das eigene Auge zu beobachten - das hat noch niemand "		\
	"geschafft.");							\
AddDetail(({"bluetenblaetter"}),					\
	"Die Blaetter von Kornblumen sind blau und am Rand gezackt.");	\
AddDetail("baum",							\
	"Du siehst im "+RICHTUNG+" einen riesigen, umgestuerzten "	\
	"Baum. Seine Wurzeln liegen im Freien.");			\
AddDetail(({"wurzeln","wurzel"}), 					\
	"Wenn Du mehr sehen willst, muss Du schon hingehen.");		\
AddDetail("baeume",							\
	"Silberne bis weissliche Baeume mit ebensolchen Blaettern "	\
	"wachsen hier ueberall.");					\
AddDetail(({"staemme","blaetter"}),					\
	"Die Blaetter sind, wie die Staemme, mit einer Schicht aus "	\
	"Kristall ueberzogen. Aber das wirst Du ja schon bemerkt "	\
	"haben.");							\
AddDetail("kristall",							\
	"Hmm... vieles ist hier aus Kristall...");			\
AddDetail("schicht",							\
	"Die Schicht scheint aus Kristall zu bestehen und ueberzieht "	\
	"hier alles. Es ist maerchenhaft schoen.");			\
AddDetail(({"kristallwald","wald"}),					\
	"Von hier aus siehst Du nur die kristall-artigen, "		\
	"weisslichen Baeume.");						\
AddDetail("nektar",							\
	"Den Nektar holen sich die Bienen aus den Blueten der Blumen " 	\
	"- muss man Dir wirklich alles erklaeren?");
									

#define SS								\
AddSound(DEFAULT_SOUND,							\
	"Du hoerst Voegel singen, Bienen und andere Insekten "		\
	"brummen durch die Gegend und das Gras wiegt sich sanft "	\
	"im Wind.");							\
									\
AddSound(({"zwitschern","voegel","vogel"}),				\
	"Du kannst nirgends Voegel sehen, aber das Zwitschern dringt "	\
	"deutlich an Dein Ohr.");					\
									\
AddSound(({"biene","bienen","summen","insekten"}),			\
	"Auf der ganzen Lichtung schwirren die Bienen und Hummeln "	\
	"herum, welche eifrig Nektar sammeln.");			\
									\
AddSound("insekten",							\
	"Du hoerst ein entferntes Schwirren von Fluegeln. Du hoffst, "	\
	"dass sie auch weit weg bleiben....");				\
									\
AddSound(({"graeser","gras"}),						\
	"Es raschelt leise im sanften Wind.");				\
									\
AddSound("wind",							\
	"Der Wind faehrt leise durch die Graeser.");			\
									\
AddSmell(DEFAULT_SMELL,							\
	"Du riechst die Blumen, den Wald rundherum und die frische "	\
	"Luft, die der sanfte Wind zu Dir traegt.");			\
									\
AddSmell("blumen",							\
	"Du atmest den Duft der Blumen ein und fuehlst, wie die "	\
	"Kraft des Fruehlings durch Dich dringt.");			\
									\
AddSmell(({"fruehling","duft"}),					\
	"Der frische, belebende Duft des Fruehlings durchdringt "	\
	"dich.");							\
									\
AddSmell(({"luft","wald"}),						\
	"Aus der Richtung des Waldes kommt feuchte und kuehle "		\
	"Luft.");							\
									\
AddSmell(({"lichtung","wind"}),						\
	"Der Wind weht sanft ueber die Lichtung.");			


#define BLUMEN								\
nosave int pfluecken(string str) \
{ \
  object blume; \
 \
  notify_fail(BS("Was moechtest Du pfluecken?")); \
  if(!str) return 0; \
   \
  if(str=="blume") \
    return write(BS("Welche Blume willst Du denn pfluecken?")), 1; \
  \
  switch(str) \
    { \
    case "mohnblumen": \
    case "mohnblume": \
      if(mohnblumenanzahl) \
	{ \
	  blume=clone_object(OBJ "mohnblume"); \
	   \
	  if(blume->move(TP, M_GET)==ME_TOO_HEAVY) \
	    { \
	      blume->remove(1); \
 \
	      write(BS("Die Mohnblume wuerde Dir zu schwer werden.")); \
 \
	      return 1; \
	    }				                         \
	  write(BS("Du pflueckst eine wunderschoene, rote Mohnblume.")), 1; \
	   \
	  mohnblumenanzahl--; \
	   \
	  return 1; \
	} \
 \
      return write(BS("Es sind nur mehr wenig Exemplare hier. Du " \
		      "beschliesst, sie doch stehen zu lassen.")), 1; \
 \
    case "kornblumen": \
    case "kornblume": \
      if(kornblumenanzahl) \
	{ \
	  blume=clone_object(OBJ "kornblume"); \
	   \
	  if(blume->move(TP, M_GET)==ME_TOO_HEAVY) \
	    { \
	      blume->remove(1); \
	       \
	      write(BS("Die Kornblume wuerde Dir zu schwer werden.")); \
	       \
	      return 1; \
	    } \
	  write(BS("Du pflueckst Dir eine der groessten Kornblumen.")), 1; \
	   \
	  kornblumenanzahl--; \
	   \
	  return 1; \
	} \
       \
      return write(BS("Lass doch die paar Blumen, damit auch andere " \
		      "Wanderer sich daran erfreuen koennen.")), 1; \
       \
    case "gaensebluemchen":					 \
      if(gaensebluemchenanzahl) \
	{ \
	  blume=clone_object(OBJ "gaensebluemchen"); \
	   \
	  if(blume->move(TP, M_GET)==ME_TOO_HEAVY) \
	    { \
	      blume->remove(1); \
	       \
	      write(BS("Das Gaensebluemchen wuerde Dir zu schwer werden.")); \
	       \
	      return 1; \
	    }				                         \
	  write(BS("Du rupfst ein kleines Gaensebluemchen aus.")), 1; \
	   \
	  gaensebluemchenanzahl--; \
	   \
	  return 1; \
	} \
       \
      return write(BS("Du willst die Schoenheit der Natur nicht schaenden " \
		      "und laesst das Bluemchen stehen.")), 1; \
    } \
 \
  return 0; \
} 
