
/*

  Die Verwaltung der Potions.
  In Haenden von Zordan@SL

*/


#include "moredef.h"
#include "defines.h"

/*

  verschiedene Farben fuer verschiedene Flaeschchen:

  0 rot          - Kraft
  1 gruen        - Intelligenz
  2 blau         - Geschicklichkeit
  3 tuerkis      - Ausdauer
  4 schwarz      - Movingpoints
  5 braun        - Poison
  6 orange       - Alcohol
  7 gelb         - Heilung LE
  8 violett      - Frog
  9 weiss        - Blind
 10 durchsichtig - Heilung MP
 11 grau         - Deaf
 12 silbern      - SA_SPEED
 13 golden       - Food
 14 kupfern      - Heilung
 15 cyan         - Drink
 16 ockern       - Nightvision
 17 neonfarben   - no_aggressive
 18 beigen       - P_TMP_DEFEND_HOOK -> +-Damage
 19 rosan        - P_TMP_DEFEND_HOOK -> +-Heilung
 20 purpurn      - P_TMP_DIE_HOOK
 21 bunt         - zufaellig eines der anderen
 22 lilan        - Temperatur 

weitere Ideen: 

 azurblau, blutrot, giftgruen, silbergrau,
     
*/

// die Pfade muessen dem akt. angepasst werden !!!
#define TRANK       "/p/daemon/potiond/potion"
#define TRANKMASTER "/p/daemon/potiond/potionmaster"
#define TRANKATTR   "/p/daemon/potiond/potionobj"
#define TRANKLOG    "daemon/TRAENKE"

// die variablen muessen von der Balance angepasst werden !!!
#define MAXGLOBAL      200              // maximale GLOBALE anzahl potions
#define MAXSINGLE ({ 100,80,60,40,20 }) // maximale anzahl PRO groesse
#define CURSEDCHANCE    98              // in % wie der trank NICHT cursed
#define CLONECHANCE    200              // x:10000 ob gecloned wird (corpse)
#define CLONERASSEN ({ "Zwerg","Mensch","Elf","Hobbit","Dunkelelf","Oger", \
                       "Ork","Troll","Fee","Xandim","Froglok","Gnom", \
                       "Gaffo","Goblin","Hobgoblin"})

#define FARBEN ({ \
  "rot","gruen","blau","tuerkis","schwarz","braun","orang","gelb","violett", \
  "weiss","durchsichtig","grau","silbern","golden","kupfern","cyanfarben", \
  "ockern", "neonfarben","beig","rosan","purpurn","bunt","lilan" })

#define GROESSE ({ \
  "winzig","klein","normal","gross","riesig" })

#define PINFO ({ \
  "Rot steht im Magischen oft fuer das Riesige und Gigantische.", \
  "Gruen gilt als eine sehr weise Farbe.", \
  "Mit dem Blau des Himmels wurde schon so mancher in seinen Taten besser.", \
  "Tuerkis ist oftmals ein Hinweis auf eine lange Standhaftigkeit.", \
  "Ein schwarzer Adler kann oft weite Wege zuruecklegen.", \
  "Durch das Braune wurde schon so mancher entgiftet.", \
  "Das Orange beten die Zechpreller angeblich an.", \
  "Dem Gelben sagt man heilende Faehigkeiten nach.", \
  "Violett ist ein seltsames Gegenmittel gegen einen kleinen Zustand.", \
  "Mit dem Weiss kann man das Weisse wieder sehen.", \
  "Die Magie ernaehrt sich von unsichtbaren Dingen.", \
  "Grau steht oft fuer das gesprochene Wort.", \
  "Viele silberne Lebewesen sind die schnellsten im Silberland.", \
  "Mit dem Goldenen im Magen kann man mehr zu sich nehmen.", \
  "Die kupferne Magie steht fuer die vollkommene Heilung.", \
  "Schon so mancher ist in der Wueste mit dem Cyanen gestorben.", \
  "Wer Ockernes im Blute hat, steht oft nicht mehr im Dunkeln.", \
  "Das Neonfarbene steht oftmals fuer den Frieden.", \
  "Mit der beigenen Farbe im Verbund kann man oft mehr Schaden abwehren.", \
  "Der rosanen Farbe sagt man vampirartige Faehigkeiten nach.", \
  "Die purpurne Farbe hat schon so manchem einen Besuch bei Lars erspart.", \
  "Das Bunte ist eine Mischung aus allen Farben. Daher oft gefaehrlich.", \
  "Die Farbe Lila soll gut in der eisigen Kaelte und in der Wueste sein." })


#define POS ({ \
  "... Du fuehlst Dich gross und stark wie ein Riese.", \
  "... Du glaubst jetzt alle Weisheiten erkennen zu koennen.", \
  "... Du fuehlst Dich erfahren genug mit jeder erdenklichen Waffe umzugehen.",\
  "... Du wuerdest es jetzt viel laenger in einem Kampf aushalten.", \
  "... Du fuehlst Dich frei und beweglicher als jemals zuvor.", \
  "... Du fuehlst Dich innerlich von etwas Schlimmen geheilt.", \
  "... Du koenntest jetzt jeden Zechpreller unter den Tisch saufen.", \
  "... Du spuerst wie Deine Wunden schneller heilen.", \
  "... Du spuerst ein Kribbeln in Deinem ganzen Koerper.", \
  "... Du kannst durch Deine Augen jetzt wieder mehr sehen.", \
  "... Du spuerst Deine magische Faehigkeit frisch gestaerkt.", \
  "... Du spuerst wie Deine Ohren klarer hoeren koennen.", \
  "... Du fuehlst Dich flink wie nie zuvor.", \
  "... Du hast auf einmal einen Baerenhunger.", \
  "... Du fuehlst Dich frisch und gestaerkt.", \
  "... Du kannst auf einmal Saufen wie ein Kamel.", \
  "... Du kannst mit Deinen Augen jede Dunkelheit durchdringen.", \
  "... Du empfindest Deine Umwelt als sehr friedfertig.", \
  "... Du glaubst das einiges an Schaden jetzt einfach so abprallen wird.", \
  "... Du nimmst Deinen Gegnern bei Treffern einen gewissen Teil fuer Dich.", \
  "... Du bist fuer kurze Zeit mit einer gewissen Wahrscheinlichkeit unsterblich.", \
  "... Du weisst gar nicht so genau was passiert ist.", \
  "... Du spuerst wie Deine Haut jedem Wetter besser gewappnet ist." })

#define NEG ({ \
  "... Du bist auf einmal so schwach wie ein kleines Kind.", \
  "... Du kannst Dich kaum noch auf das Lesen konzentrieren.", \
  "... Du bist kaum noch in der Lage ein Messer zu benutzen.", \
  "... Du fluechtest in naechster Zeit schneller aus dem Kampf.", \
  "... Du fuehlst Dich auf einmal so erschoepft.", \
  "... Du zuckst zusammen und fuehlst Dich auf einmal so schlecht.", \
  "... Du bist so voll wie ein guter Zechpreller.", \
  "... Du siehst wie Eiter in Deinen Wunden entsteht.", \
  "... Du wirst auf einmal ganz klein und gruen.", \
  "... Du kannst das Flaeschchen auf einmal nicht mehr erkennen.", \
  "... Du spuerst wie Deine magischen Faehigkeiten kurz aussetzen.", \
  "... Du kannst auf einmal Deinen eigenen Atem nicht mehr hoeren.", \
  "... Du bist auf einmal so lahm und zaeh.", \
  "... Du bist total und vollkommen satt.", \
  "... Du brichst unter einer schweren Last zusammen.", \
  "... Du bekommst keinen Schluck Wasser mehr runter.", \
  "... Du bist auf einmal geblendet.", \
  "... Du empfindest Deine Umwelt auf einmal als sehr aggressiv.", \
  "... Du glaubst das Du im Moment bei jedem Treffer mehr Schaden nimmst.", \
  "... Du wirst Deinen Gegner bei jedem Schlag einen Teil schenken.", \
  "... Du spuerst einen grausamen Schmerz und stirbst.", \
  "... Du weisst gar nicht so genau was passiert ist.", \
  "... Du spuerst wie Deine Haut gegen jedes Wetter schlechter gewappnet ist." })


nosave string *PLONG=({
  "Zwischen Deinen Besitztuemern findest Du dieses kleine rote Flaeschchen. "
  "Deine Angst kann Deine Neugier, herauszufinden was diese rote Fluessigkeit "
  "bewirkt, kaum stoppen. Etwas magisches strahlt das Flaeschchen einfach "
  "aus.",
  "Eine magisch gruene Fluessigkeit befindet sich in diesem kleinen "
  "Flaeschchen. Sie ist ein wenig dickfluessig.",
  "Die blaue Fluessigkeit ist an manchen Stellen sogar noch durchsichtig. "
  "Das kleine Flaeschchen ist mit einem kleinen Korken verschlossen. Trinken "
  "wuerdest Du es nur zu gerne.",
  "Tuerkiser als der wertvollste Topaz leuchtet diese Fluessigkeit in Deinen "
  "Augen. Eine wahrlich gigantische Macht scheint von ihr auszugehen. Nur " 
  "kann das auch eine wahrlich gute Taeuschung sein.", 
  "Pechschwarz gefuellt ist das Flaeschchen aus Glas. Eine Ausgeburt der " 
  "Hoelle koennte nicht dunkler sein. Aber auch das Boese kann eine " 
  "positive Auswirkung haben. Ob Du Dich trauen solltest die Fluessigkeit " 
  "zu trinken?", 
  "Braun wie die Erde in Midas ist das Wasser in dem Flaeschchen. So als " 
  "ob jemand einfach ein wenig Erde mit Wasser gemischt haette. Nur die " 
  "seltsame magische Ausstrahlung macht Dich ein wenig nervoes.", 
  "Ein wirklich sattes und kuenstliches Orange strahlt Dich aus dem " 
  "Flaeschchen an. Kleine feste Bestandteile schwimmen darin herum und " 
  "glitzern Dich an.", 
  "Pigelb wuerdest Du als erstes denken. Oerkz. Ob man dieses Flaeschchen " 
  "wirklich trinken sollte? Eigentlich ekelst Du Dich ja davor. Waere da " 
  "nicht dieser magische Schimmer ...", 
  "Eine wahrlich duenne und violette Fluessigkeit schwimmt in dem Flaeschchen "
  "und verbreitet beim dran Schnuppern einen suesslichen Geruch. Ins Licht " 
  "gehalten aendert sich der Kontrast sogar ein wenig.", 
  "Weiss wie der direkte Strahl der Sonne erscheint die Fluessigkeit in " 
  "diesem Flaeschchen. Ein seltsames Gefuehl umgibt Dich, als Du laenger " 
  "in das Flaeschchen schaust.", 
  "Durchsichtig, nicht sichtbar. Wuerde das Flaeschchen nicht beim Schuetteln "
  "ein wenig plaetschern, dann wuerde man meinen dieses Flaeschchen waere " 
  "schlicht und weg einfach leer. Auch riechen tut es einfach nach gar " 
  "nichts.", 
  "Grau wie eine Stadt, die am Meer im Nebel verschwunden liegt, schuechtert " 
  "Dich dieses Flaeschchen ein wenig ein. Ein grosses Geheimnis scheint auf " 
  "ihm zu liegen, denn schon viele Sagen berichten von grauen Flaeschchen.", 
  "Silberne Faeden durchziehen diese Fluessigkeit und erscheinen in Deinen " 
  "Augen als funkelnde Stellen. Aufmerksam beobachtest Du das Funkeln und " 
  "kannst Dich kaum auf etwas anderes konzentrieren.", 
  "Gold und Silber lieb ich sehr .. aber diese Fluessigkeit ist von reinster " 
  "Goldfarbe. Wertvoll wuerde man dieses Flaeschchen sicher bezeichnen. " 
  "Aber ob man wirklich Gold trinken sollte?", 
  "Ein kupferner Drache ist wahrlich boese. Sicher kann so ein Flaeschchen " 
  "nicht so derart boese sein. Aber auf der Hut sollte man schon sein. So " 
  "mancher Abenteurer hat die Einnahme schon bereut. Aber andere wiederum " 
  "genossen.", 
  "Cyan ist eine sehr seltsame Farbe. Viele wissen mit ihr nichts anzufangen " 
  "und meiden sie deshalb. Das man durch sie aber oft auch auf der sicheren " 
  "Seite ist, ignorieren die Meisten einfach ohne nachzuforschen.", 
  "Dunkel duester schwappt die ockerne Farbe in dem kleinen Flaeschchen hin " 
  "und her. Ihr Aussehen erinnert Dich irgendwie an Deine Kindheit wo Du " 
  "manchmal in der Nacht draussen gespielt hast.", 
  "Hell leuchtend strahlt Dir das neonfarbene Flaeschchen entgegen. Es wirkt "
  "wirklich sehr beruhigend auf Dich und Deine Umwelt. Viele Sagen handeln " 
  "von diesem Flaeschchen und Du bist echt neugierig was beim Trinken " 
  "passieren wird.", 
  "Truebe und beige ist der Inhalt dieses Flaeschchens. Es sieht eigentlich " 
  "ueberhaupt nicht magisch aus. Aber es versprueht eine wirklich starke " 
  "magische Praesenz. Es blubbert nicht und macht auch sonst gar keine " 
  "Geraeusche.", 
  "Rosa wie der Popo eines jungen Menschenkindes strahl das Flaeschchen eine " 
  "gewisse Jugenhaftigkeit aus. Aber oftmals ist es in der Magie so, dass " 
  "sich Teile davon gut verstecken oder gar ihr boeses gut tarnen. Du " 
  "solltest damit schon vorsichtig umgehen.",
  "Leuchtend purpurn erscheint das Flaeschchen. Unscheinbar und lautlos birgt "
  "dieses Flaeschchen wahrscheinlich eine ungeheure Macht. Ob Du dieser Macht "
  "schon gewachsen bist, magst Du derzeit nicht selber beantworten.",
  "Das bunte Flaeschchen ist ein Ding der wahrscheinlichsten "
  "Unwahrscheinlichkeit. Nur die tapfersten Recken wuerden je dieses hohe "
  "Risiko eingehen und es trinken. Geschichten behaupten, man soll lieber die "
  "Finger davon lassen.",
  "Die lila Fluessigkeit in dem Flaeschchen schwappt sanft hin und her. "
  "Eine gewaltige Kraft scheint in dem Inneren zu brodeln und macht Dich "
  "wirklich sehr neugierig. Sollte allerdings das Gegenteil von Deinen "
  "Erwartungen eintreffen, so wird Dein Leben sicher schwerer." });
