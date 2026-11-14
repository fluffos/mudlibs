/*
 * File:    /d/gebirge/feyaria/weg/room/huegel.h
 *
 * Contains:  Common details for the highland area 
 *
 * History:
 *  96-05-10  cps   added lots of details
 *  96-03-25  cps   moved wood-specific defines into this file
 *  96-12-20 feyaria fuers SL
 */

#ifndef __HUEGEL__
#define __HUEGEL__ 19960325
/* use the date as version number, thus we may check for versions in the
 * files including this one
 */

#include "../directions.h"
 
#define P_INT_SHORT_HUEGEL 						\
  SetProp(P_INT_SHORT, "Auf einem Huegel")

#define CD_HUEGEL 							\
  SetProp(P_LIGHT, 1); 							\
  AddDetail( ({"boden", "weg", "pfad", "grund"}), 			\
      "Hier oben auf dem Huegel ist der Boden karg. Du kannst kaum "	\
      "noch die Karrenspuren ausmachen, die vorhin im weichen "		\
      "Waldboden den Verlauf des Pfades so klar in den Grund "		\
      "gezeichnet hatten. Hie und da liegt ein Kuhfladen, aber auch "	\
      "Pferdeaepfel kannst Du ausmachen."); 				\
  AddDetail( ({"kuhfladen", "fladen", "pferdeapfel", "apfel", "kot", 	\
      "haufen", "kothaufen", "pferdeaepfel", "aepfel"}), 		\
      "Mit Kennermiene greifst Du in den Haufen und pruefst Geruch, Farbe," \
      " Oberflaeche, Konsistenz und Geschmack (wuerg). Nach eingehender" \
      " Pruefung meinst Du, es sind ganz gewoehnliche Kothaufen, die seit" \
      " mindestens drei Tagen hier herumfaulen (Igitt)."); 		\
  AddDetail("geruch", 							\
    "Stinkt wie drei Tage oder aelter.... *gruebel*"); 			\
  AddSmell( ({DEFAULT_SMELL, "geruch","kuhfladen", "fladen", 		\
            "pferdeapfel", "apfel", "kot", "haufen", "kothaufen",	\
            "pferdeaepfel", "aepfel" }),				\
    "Hier riecht es stark nach Kuhfladen. Igitt :(");			\
  AddDetail("farbe", 							\
      "Braun. Mit leichten halbverdauten gelblichen Einschluessen," 	\
      " vermutlich Hafer oder Heu.");	 				\
  AddDetail("oberflaeche", 						\
    "Weich-klebrig."); 							\
  AddDetail( ({"einschluss", "einschluesse", "hafer", "heu"}),		\
    "Die Einschluesse stammen wohl von Hafer oder Heu.");		\
  AddDetail("konsistenz", 						\
      "Weich-broeckelig, nicht besonders viskos, dafuer umso " 		\
      "mehr igitt."); 							\
  AddDetail( ({"geschmack", "schweinepriester"}),			\
      "Baeh, Du Schweinepriester! *wuerg*"); 				\
  AddDetail( ({"scheisse", "scheiss", "kacke"}), 			\
      "Aber wer wird denn? Nicht vulgaer werden, bitte."); 		\
  AddDetail( ({"waldboden", "wald"}), 					\
      "Hier ist kein Wald und darum auch kein Waldboden!");

#define CD_HUEGEL2 							\
  AddDetail( ({"gott", "goetter", "woody", "dusty"}),					\
      "Unsere Goetter heissen hier Dusty und Woody."); 	\
  AddDetail( ({"huegel", "aussicht", "umgebung"}), 			\
      "Der Huegel ist nicht besonders hoch, aber er erhebt sich doch" 	\
      " deutlich ueber die Umgebung. Die Aussicht ist atemberaubend." 	\
      " Abgesehen von einigen Krueppelkiefern und Ginsterbueschen waechst" \
      " hier nur Gras, das allerdings sehr abgefressen aussieht. Oben" 	\
      " scheint der Huegel erstaunlicherweise sehr flach zu sein, aber" \
      " genau kannst Du das von hier aus nicht erkennen."); 		\
  AddDetail( ({"krueppelkiefern", "kiefern", "kiefer"}), 		\
      "Selbst die Krueppelkiefern sehen angefressen aus. Kein Wunder, auf" \
      " dieser Hochflaeche muss jedes Tier fressen, was es zu knabbern" \
      " kriegt."); 							\
  AddDetail( ({"ginster", "ginsterbusch", "ginsterbuesche", "busch", 	\
               "buesche", "strauch", "straeucher"}), 			\
      "Der Ginster ist wohl nochmal davongekommen -- kein Wunder, es gibt" \
      " kaum ein Tier, das die harten Blaetterchen dieser Buesche fressen" \
      " mag. Die knallgelben Blueten dieser Straeucher sind meilenweit zu" \
      " sehen."); 							\
  AddDetail( ({"blatt", "blaetter", "blaetterchen", "bluete", "blueten"}), \
      "Die Blaetter des Ginsters sind so hart und fast genauso schmal wie" \
      " die Nadeln der Krueppelkiefern, die Blueten sind leuchtend gelb."); \
  AddSmell( ({"blueten", "bluete"}),					\
    "Die Blueten duften herrlich.");					\
  AddDetail( ({"tier", "tiere", "viech", "viecher"}), 			\
      "Abgesehen von den ueblichen Insekten und Kaefern siehst Du im " \
      + capitalize(ED3) + " eine Schafherde weiden, die von einem Schaefer" \
      " und mehreren Schaeferhunden bewacht wird."); 			\
  AddDetail( ({"insekt", "insekten", "kaefer"}), 			\
      "Nichts besonders zu sehen, die ueblichen Viecher halt."); 	\
  AddDetail( ({"spuren", "karrenspuren", "boden", "steinboden",		\
               "ochsenhufe", "karrenraeder", "spur", "karrenspur"  }),		 	\
      "Du kannst auf dem kargen, steinigen Boden kaum etwas erkennen. Nur" \
      " hie und da vermutest Du, dass die wenigen Grasbueschel von" 	\
      " Ochsenhufen oder Karrenraedern plattgedrueckt wurden.");

#define CD_HUEGEL3 							\
  AddDetail( ({"gras", "bueschel", "grasbueschel"}), 			\
      "Es sind zwar nur wenige Grasbueschel im kargen Steinboden zu sehen," \
      " diese sehen aber nahrhaft und gesund aus. Hin und wieder erkennst" \
      " Du Karrenspuren im Gras."); 					\
  AddDetail( ({"aussicht", "landschaft"}), 				\
      "Diese Schoenheit hier oben ist atemberaubend. Du bist zwar weit weg" \
      " von allen Auslaeufern der Zivilisation, aber gerade das erscheint" \
      " Dir bemerkenswert. Weit im " + capitalize(ED1) + " siehst Du eine" \
      " Stadt, die friedlich in einem Talkessel liegt. Im " + capitalize(ED7) \
      + " erkennst Du eine friedliche Talaue, die voellig von der" 	\
      " Aussenwelt abgeschlossen ohne Weg und Steg in der Sonne bruetet. Im " \
      + capitalize(ED4) + " glaenzt ein Bergsee, in dem sich ein Berggipfel" \
      " spiegelt. Im " + capitalize(ED3) + " blickst Du auf einen" 	\
      " Bergriesen, der seinen Gipfel ueber den schneebedeckten Haengen" \
      " majestaetisch hinter einigen Wolken verbirgt."); 		\
  AddDetail("schoenheit", 						\
      "Man glaubt es kaum, aber sogar diese Schoenheit hier oben kann man" \
      " untersuchen."); 						\
  AddDetail( ({"auslaeufer", "zivilisation"}), 				\
      "Tststssss.... Zivilisation? Hier? Wovon traeumst Du Nachts?"); 	\
  AddDetail( ({"stadt", "talkessel"}), 					\
      "Da solltest Du ein bisschen naeher rangehen. Die Stadt ist" 	\
      " noch ziemlich weit entfernt.");					\
  AddDetail( ({"tal", "au", "aue", "talaue", "talau"}), 		\
      "Im " + capitalize(ED7) + " erkennst Du tief unter Dir eine "	\
      "friedliche Talaue fernab jeglicher Zivilisation. Es gibt hier "	\
      "aber keine Moeglichkeit, dorthin abzusteigen."); 		\
  AddDetail( ({"moeglichkeit"}),                                        \
      "Es ist wirklich nicht moeglich!");                               \
  AddDetail("aussenwelt", 						\
      "Du bist hier ziemlich weit weg davon."); 			\
  AddDetail( ({"weg und steg", "steg", "wortspiel"}),   		\
      "Oh-oh... das ist doch nur ein Wortspiel gewesen. ");     	\
  AddDetail( ({"sonne", "licht", "sonnenlicht"}), 			\
      "Tatsaechlich! Es gibt sogar hier eine Sonne, und sie heisst" 	\
      " auch genauso! Ob das Zufall ist?"); 				\
  AddDetail( ({"bergsee", "see"}), 					\
      "In der Ferne glaenzt der Bergsee traege im Sonnenlicht.");

#define CD_HUEGEL4 							\
  AddDetail( ({"berggipfel", "bergriese", "berg", "hang", "haenge"}), 	\
      "Weit im " + capitalize(ED3) + " ueberragt ein riesiger, einzeln" \
      " stehender Berg die Landschaft. Auf seinen Haengen schimmern" 	\
      " Schneefelder, sein Gipfel ist in Wolken gehuellt."); 		\
  AddDetail( ({"schnee", "schneefelder"}), 				\
      "Weiss glaenzen die Schneefelder in der Sonne, sodass sie weithin" \
      " sichtbar sind."); 						\
  AddDetail( ({"gipfel", "hochflaeche", "flaeche"}),			\
      "Etwas unterhalb des Gipfels breitet sich eine Hochflaeche im " 	\
      + capitalize(ED3) + " aus. Auf der Hochflaeche siehst Du einen "	\
      "Hirten mit seinen Schaeferhunden, die eine Schafherde bewachen.");\
  AddDetail( ({"hirte","hund","hunde","schaeferhunde","schaf","schafe",	\
           "herde", "schafherde", "hirten", "schafhirte", "schaefer"}), \
      "Ein Hirte treibt eine Schafherde ueber die Hochflaeche im " 	\
      + capitalize(ED3) + ", die die kargen Grasbueschel abweidet. Ein" \
      " paar Schaeferhunde passen auf die Herde auf."); 		\
  AddDetail( ({"wolke", "wolken", "schoenwetterwolken", "wetter", 	\
               "himmel", "sonne", "wattetupfen"}),			\
      "Einige Schoenwetterwolken haengen wie weisse Wattetupfen am Himmel," \
      " dazwischen brennt die Sonne auf Dich herab. Es ist ein richtig" \
      " angenehmes Wetter heute, um durch die Huegel zu spazieren."); 	\
  AddDetail( ({"nadeln"}), 						\
      "Die Nadeln der Krueppelkiefern bedecken den Boden.");


#endif
