/*
**************************************************
**
** Dunkler Wald
**
** (c) Sargola@Silberland, 21-08-98
**************************************************
*/



#define STANDARD							\
AddDetail("boden","Der Boden ist steinhart und klirrend kalt. Eigent"	\
  "lich ist es nur Erde, aber er ist trotzdem ungewoehnlich hart.");	\
AddDetail("erde","Sie ist nicht in Pfaden festgetrampelt, und doch "	\
  "ist sie steinhart. Und schwarz. Noch nie hast Du so eine schwarze "	\
  "Erde gesehen. Sie verschluckt alles Licht, das auf den Boden "	\
  "faellt.");								\
AddDetail("licht","Es scheint nur schwach der Schein des Mondes bis "	\
  "zu Dir herab. Irgendwie scheint Dir, als wuerde das Licht hier "	\
  "vom Boden und den Baeumen verschluckt werden. Ganz, als ob "		\
  "Ritter Kato kein Licht dulden wuerde.");				\
AddDetail(({"ritter","kato"}),"Noch kannst Du ihn nicht sehen.");	\
AddDetail(({"baum","baeume"}),"Du bist in einem befremdlich wirkenden Wald. "	\
  "Zwar stehen hier ueberall Baeume um Dich herum, aber sie sind "	\
  "abgestorben. Oder zumindest sind die Aeste und Wurzeln schwarz. "	\
  "Und das erschreckendste ist, dass sie alle keine Blaetter mehr "	\
  "haben...");								\
AddDetail("blaetter","Kein Baum hier hat noch Blaetter.");		\
AddDetail("wurzeln","Die Wurzeln reichen in den schwarzen Boden "	\
  "... Du kannst Dir nicht vorstellen, dass die dem Baum noch Naehr"	\
  "stoffe zufuehren koennen.");						\
AddDetail("naehrstoffe","Der Boden sieht nicht danach aus.");		\
AddDetail("aeste","Einige der Baeume sind beeindruckend gross und "	\
  "haben weitlaeufige Aeste. Aber alle sind fast schwarz und wirken "	\
  "wie ausgestorben. Als ob ihnen das Leben fehlen wuerde.");		\
AddDetail("leben","Alles scheint hier leblos zu sein. Als wuerde "	\
  "die boese Macht von Ritter Kato alles am Leben und Wachsen hind"	\
  "ern.");								\
AddDetail("macht","Sie manifestiert sich in den schwarzen Baeumen, "	\
  "den schwarzen Pflanzen, dem Boden ... ueberall einfach.");		\
AddDetail("pflanzen","Sogar kleine, junge Pflanzen wie Farne und "	\
  "Pilze sind schon schwaerzlich geworden.");				\
AddDetail("himmel","Du kannst den Himmel nicht sehen - ueber Dir "	\
  "ist es nur duester. Der Schein des Mondes ... oder ist es die "	\
  "Sonne? ... bringt nur sehr wenig diffuses Licht.");			\
AddDetail("schein","Du kannst nicht sagen, ob es sich um die Sonne "	\
  "oder den Mond handelt. Es ist weissliches, diffuses Licht.");	\
AddDetail(({"sonne","mond"}), "Ob es Sonne oder Mond ist, weisst "	\
  "Du nicht genau.");							\
AddDetail("licht","Verstraeut und an den Aesten unwirklich gebrochen "	\
  "taucht es die Gegend in eine unheimliche Stimmung.");		\
AddDetail("gegend","Im grossen kann man sie mit \"schwarz\" besch"	\
  "reiben.");								\
AddDetail("stimmung","Dir wird ganz unheimlich....");			\
AddDetail("farne","Kniehohe Gewaechse, die zumindest fuer Dich wie "	\
  "Farne aussehen. Seltsam sind nur die gelben Beeren darauf.");	\
AddDetail("beeren","Die gelben Beeren stechen durch ihre gelbe "	\
  "Farbe seltsamerweisse extrem heraus. Ob man die pfluecken kann?");	\
AddDetail("gewaechse","Vielleicht sind es ja Farne...");		\
AddDetail(({"pfad","pfade"}),"Es ist ein Pfad durch die Pflanzen "	\
  "klar erkennbar zu sehen ... so als ob hier oefter wer durch"		\
  "rennen wuerde...");							\
AddDetail("pilze","Die Pilze sind ebenso schwarz wie der Boden ..." 	\
  "aus irgendeinem Grund hast Du keine Lust, sie zu probieren.");	\
AddDetail("grund","Du meinst den Boden?");				\
AddDetail("farbe","Ein klassisches Gelb.");				\
AddDetail("wald","Alles um Dich herum koennte man im weitlaeufigsten "	\
  "Sinne als Wald bezeichnen.");					\
AddDetail("sinne","Schaerfe Deine Sinne fuer das, was da kommen mag!");	\
AddDetail("lust","Oder hast Du doch Lust?");				\
AddDetail("gelb","Die Farbe Gelb.");					\
AddDetail("magie","Die kann man ueberall wirken sehen.");

#define SOUND								\
AddSound(DEFAULT_SOUND, "Ein unheimliches und beklemmendes Fluestern "	\
  "rauscht durch die Baeume. Und noch ein seltsames Geraeusch faellt "	\
  "Dir auf.");						\
AddSound("fluestern","Es ist der Wind, der leise durch die Baeume "	\
  "heult.");								\
AddSound("wind","Man kann ihn nicht spueren, aber man hoert ihn ... "	\
  "wie er zwischen den Aesten hindurchsausen und fluestern.");		\
AddSound("geraeusch","Es ist ein leises Tippeln etwas weiter weg ... "	\
  "Du solltest vielleicht acht geben...");				\
AddSound("tippeln","Es klingt wie Fuesse die herumrennen...");		\
AddSound("fuesse","Pass auf, dass Du nicht ueberfallen wirst.");


#define SMELL								\
AddSmell(DEFAULT_SMELL, "Du riechst hier einfach nichts. Die Baeume "	\
  "und die Farne ... alles muesste doch nach irgendetwas riechen. "	\
  "Aber Du riechst nichts ... Ritter Katos Magie ist scheinbar "	\
  "ziemlich maechtig.");						\
AddSmell("magie","Magie direkt kann man nicht riechen - aber dass "	\
  "man nichts riecht, ist Magie!");					\
AddSmell(({"baeume","farne","pflanzen"}), "Die riechen nach nichts.");	\


#define SINNE								\
int schaerfe(string str)						\
{ notify_fail("Was moechtest Du schaerfen?\n"); if(!str) return 0;	\
  if(str=="sinne") tell_object(TP, BS("Du schaerfst Deine Sinne ein"	\
    "gehend."));	return 1;					\
  return 0; }								
  










