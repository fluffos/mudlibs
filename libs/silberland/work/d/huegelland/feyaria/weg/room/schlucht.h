/*
 * File:    /d/gebirge/feyaria/weg/room/schluchtpfad.h
 *
 * Contains:  Common details for the cliffpath area 
 *
 * History:
 *  96-03-26  cps   moved cliffpath-specific defines into this file
 *  96-12-20 feyaria fuers SL
 */

#ifndef __SCHLUCHTPFAD__
#define __SCHLUCHTPFAD__ 19960327
/* use the date as version number, thus we may check for versions in the files
 * including this one
 */

#include "../directions.h"

#define WARNSCHILD_TEXT \
"+-------------------------------------------+ \n" \
"|                                           | \n" \
"|           LAWINEN-ABGANGSGEBIET           | \n" \
"|                                           | \n" \
"|          VORSICHT, LEBENSGEFAHR!          | \n" \
"|                                           | \n" \
"|   Der Schluchtpfad ist lebensgefaehrlich. | \n" \
"| Laute Geraeusche, Rufe, und unvorsichtige | \n" \
"|   Bewegungen koennen Lawinen ausloesen,   | \n" \
"|   die schwerste Verletzungen oder sogar   | \n" \
"|     den Tod zur Folge haben koennen.      | \n" \
"|                                           | \n" \
"|       BETRETEN AUF EIGENE GEFAHR!         | \n" \
"|                                           | \n" \
"|     Bitte beachten Sie die Broschuere     | \n" \
"|  'Verhaltensmassnahmen im Lawinengebiet'  | \n" \
"|                                           | \n" \
"|   Die SilberLand Feld-, Wald- und Wiesen- | \n" \
"|                   Wegeverwaltungsbehoerde.| \n" \
"+-------------------------------------------+ \n"

#define P_INT_SHORT_SCHLUCHTPFAD \
  SetProp(P_INT_SHORT, "Ein Gebirgspfad")


#define CD_SCHLUCHTPFAD 						\
AddDetail( ({"serpentinen", "kurven", "spitzkehren", "kehre", 		\
             "spitzkehre"}), 						\
    "Mit grosser Kunst haben die Strassenbauer hier jedes Plaetzchen in" \
    " der fast senkrechten Felswand genutzt, um einen Wendeplatz zu" 	\
    " bauen.");								\
AddDetail( ({"wand", "fels", "felswand"}), 				\
    "Der Fels ist hier sehr bruechig und verwittert. Laute Geraeusche," \
    " unvorsichtige Bewegungen oder sogar ein heftiger Windstoss" 	\
    " koennten jederzeit eine Geroellawine ausloesen.");		\
AddDetail("gipfel", 							\
    "Du stehst viel zu nah an der Felswand, deshalb kannst Du den Gipfel" \
    " nicht erkennen.");						\
AddDetail( ({"kunst", "strassenbauer", "platz", "plaetzchen", 		\
    "wendeplatz"}),							\
    "Du bewunderst die Kunst der Strassenbauer, die geschickt jede"	\
    " Moeglichkeit nutzten, den Pfad sicher an der Felswand zu"		\
    " verankern.");							\
AddDetail( ({"geraeusche", "bewegungen", "wind", "windstoss"}),		\
    "Dustyseidank ist sowas zur Zeit nicht zu beobachten.");		\
AddDetail( ({"lawine", "geroell", "geroellawine", "geroelllawine",	\
             "baeume", "muren", "mure", "bergwacht"}),			\
    "Auch hier ging erst kuerzlich eine Mure nieder. Sie hat einige" 	\
    " Baeume plattgewalzt und den Weg fuer eine Weile unpassierbar gemacht," \
    " aber inzwischen hat die Bergwacht den Pfad freigeraeumt.");	 \
AddDetail( ({"boden", "weg", "pfad", "gebirgspfad", "landweg"}),			\
    "Der Weg ist hier aus dem blanken Fels herausgeschlagen worden. Du" \
    " fragst Dich, wer sich solche Muehe machte, nur um einen Landweg nach " \
    N_STADT " zu bauen...");						\
AddDetail( ({lower_case(N_STADT)}),\
    "Der Weg fuehrt nach " N_STADT ".");\
AddDetail( ({"himmel", "sonne"}), 					\
 ([0: "Die Sonne brennt angenehm warm auf Deine Haut. Trotzdem ist "    \
      "es hier oben unangenehm kuehl.",                                 \
  "hobbit": "Die Sonne brennt angenehm warm auf Deinen Pelz. Trotzdem " \
            "ist es hier oben unangenehm kuehl."]));			\
AddDetail( ({"abgrund", "tiefe"}), 					\
    "Neben Dir ist ein tiefer Abgrund, dessen Tiefe Du lieber nicht" 	\
    " ergruendest.");							\
AddDetail( ({"berg", "berge"}),                                         \
    "Rundherum gibt es viele Berge.");                                  \
AddDetail( ({"pfad", "schluchtpfad", "schlucht"}),			\
    "Der Schluchtpfad fuehrt durch eine enge Schlucht.");
    
#endif
