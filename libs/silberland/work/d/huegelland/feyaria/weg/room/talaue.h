 /*
 * File:    /d/gebirge/feyaria/weg/room/talaue.h
 *
 * Contains:  Common details for the cliffpath area 
 *
 * History:
 *  96-03-27  cps   moved cliffpath-specific defines into this file
 *  96-12-20  feyaria fuers SL 
 */

#ifndef __TALAUE__
#define __TALAUE__ 19960327
/* use the date as version number, thus we may check for versions in the files
 * including this one
 */

#include "../directions.h"

#define P_INT_SHORT_AU 							\
  SetProp(P_INT_SHORT, "In einer Talaue")

#define CD_AUE 								\
AddDetail( ({"weg", "pfad"}), 						\
    "Der Weg windet sich durch den saftigen Wiesengrund. Hin und wieder" \
    " siehst Du einen Kuhfladen und ein paar Pferdeaepfel zwischen den"	\
    " Karrenspuren liegen.");						\
AddDetail( ({"wiese", "wiesen", "wiesengrund", "grund"}), 		\
    "Die Wiese ist saftig gruen und sieht sehr schmackhaft aus --" 	\
    " zumindest fuer Kuehe. Du kannst aber kein einziges Milchvieh hier" \
    " entdecken und wunderst Dich warum.");				\
AddDetail( ({"boden"}), 						\
    "Der Boden sieht feucht und nahrhaft aus; eine saftiggruene Wiese" 	\
    " waechst hier.");							\
AddDetail( ({"kuh", "kuehe", "vieh", "milchvieh"}), 			\
    "Seltsamerweise findet sich auf dieser Wiese kein Milchvieh. Die" 	\
    " Kuhfladen auf dem Weg scheinen nur von den Ochsen der" 		\
    " Haendlerkarren zu stammen.");					\
AddDetail( ({"kuhfladen", "pferdeaepfel", "aepfel", "kot", "dung", 	\
             "dunghaufen", "mist", "pferdeapfel", "apfel"}), 		\
    "Nur auf dem Weg findest Du mehr oder weniger alte Dunghaufen." 	\
    " Unverstaendlicherweise liegt auf der Wiese kein einziger.");	\
AddDetail( ({"spuren", "karrenspuren", "radgeleise", "spur", "karrenspur"}), \
    "Die Karrenspuren folgen peinlich genau dem Weg. Zwischen den" 	\
    " parallel laufenden Radgeleisen liegt hin und wieder ein Kuhfladen" \
    " oder ein Pferdeapfel.");						 \

#define CD_AUE2 							\
AddDetail( ({"scheiss", "scheisse", "kack", "kacke"}), 			\
    "Na wer wird denn gleich obszoen werden hier... tststs. Probier" 	\
    " lieber mal Dung, Mist, oder Kot.");				\
AddDetail( ({"busch", "buesche", "gewaechs", "gewaechse"}), 		\
    "Komisch... die Buesche wachsen nur entlang des Wegs, auf der Wiese" \
    " sieht man ueberhaupt keine. Nur am gegenueberliegenden Berghang" 	\
    " scheinen wieder hoehere Gewaechse zu gedeihen.");			\
AddDetail( ({"berg", "hang", "berghang"}), 				\
    "Im " + capitalize(ED5) + " siehst Du einen hohen Berg, dessen" 	\
    " Gipfel von einem hohen Pass gespalten ist. Im " + capitalize(ED1) \
    + " liegt eine Steilwand, an der sich ein Pfad in atemberaubenden" 	\
    " Serpentinen emporwindet.");					\
AddDetail( ({"gipfel", "wand", "steilwand", "pass", "serpentinen"}), 	\
    "Du solltest naeher rangehen, um genaueres erkennen zu koennen."); 	\
AddDetail( ({"tal", "talau", "talaue", "aue"}), 			\
    "In geradezu uebernatuerlich saftigem Gruen glaenzt die Wiese in der" \
    " Talaue unter dem blauen Himmel.");			 	\
AddDetail( ({"gruen", "wiese"}), 					\
    "Die Wiese ist einfach nur gruen. Kein Bluemchen unterbricht das Wogen" \
    " des Grases, kein Strauch waechst in den wogenden Halmen.");	\
AddDetail( ({"strauch"}),                                               \
    "Es waechst hier wirklich kein Strauch.");                          \
AddDetail( ({"wogen"}),                                                 \
    "Kein Bluemchen unterbricht das Wogen des Grases, kein Strauch "    \
    "waechst in den wogenden Halmen.");                                 \
AddDetail( ({"gras", "grashalme", "grashalm", "halme", "halm"}),	\
    "Dieses Gras hier scheint Dir nicht normal: kein Bluemchen blueht" 	\
    " zwischen den Grashalmen, kein Kuhfladen ist auf der Wiese zu sehen.");\
AddDetail( ({"blume", "blumen", "bluemchen"}), 				\
    "ARRRRGGGLLLLLLL... ich sagte doch gerade \"KEIN Bluemchen...\" Auch" \
    " KEINE Blume. Und wenn wir schon dabei sind: Buesche wachsen nur" 	\
    " entlang des Weges."); 						\
AddDetail( ({"huegel", "anhoehe"}), 					\
    "Gegen den hohen Pass im " + capitalize(ED4) + " ist die Anhoehe im " +	\
    capitalize(ED1) + " nur ein Huegel. Das hindert den Huegel aber"	\
    "nicht daran, in einer atemberaubenden, mehrere hundert Schritt "	\
    "hohen Steilwand jaeh ins Tal zu stuerzen.");			\
AddDetail( ({"pass", "berg", "gipfel"}), 				\
    "Im " + capitalize(ED4) + " erhebt sich ein gewaltiger Berg, zwischen" \
    " dessen beiden kahlen Gipfeln ein Pass liegt, durch den der Weg" 	\
    " fuehrt.");							\

#endif
