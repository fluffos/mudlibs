/*
 * File:    /d/gebirge/feyaria/weg/room/huegel2.h
 *
 * Contains:  Common details for the lower hill area
 *
 * History:
 *  96-04-02  cps   created this file
 */

#ifndef __HUEGEL2__
#define __HUEGEL2__ 19960402
/* use the date as version number, thus we may check for versions in the
 * files including this one
 */

#include "../directions.h"
 
#define P_INT_SHORT_HUEGEL						\
  SetProp(P_INT_SHORT, "In einer Huegellandschaft")

#define CD_HUEGEL							\
  SetProp(P_LIGHT, 1);							\
  AddDetail( ({"sonne", "himmel"}),					\
    "Vom Himmel lacht die Sonne herunter.");				\
  AddDetail( ({"huegellandschaft", "landschaft"}),			\
    QueryProp(P_INT_LONG) );						\
  AddDetail( ({"boden", "grund", "huegelboden"}),			\
      "Der Huegelboden ist fruchtbar und saftiggruen. Die Wiese wird"	\
      " als Weide genutzt, tatsaechlich kannst Du in der Ferne einen"	\
      " Hirtenjungen mit seiner Kuhherde entdecken.");			\
  AddDetail( ({"weg", "pfad", "huegelweg", "huegelpfad"}),		\
      "Der Weg hier wird offensichtlich von irgendjemand gepflegt: Du"	\
      " kannst fachmaennisch ausgebesserte Schlagloecher entdecken, und"\
      " Du findest nur wenige Pferdeaepfel und Kuhfladen. Hin und"	\
      " wieder sieht man auch sauber gestapelte Pflastersteine am"	\
      " Wegrand liegen, ganz als waere ein weiterer Ausbau dieses Pfads"\
      " in naechster Zeit geplant.");					\
  AddDetail( ({"kuhherde", "herde", "hirte", "junge", "hirtenjunge", \
               "ferne"}),	\
      "Da steht doch tatsaechlich ein Hirtenjunge und huetet eine"	\
      " Herde Kuehe, die friedlich auf der Wiese grasen.");		\
  AddDetail( ({"schlagloch", "schlagloecher"}),				\
      "Die hier wurden vor kurzem fachmaennisch repariert.");		\
  AddDetail( ({"stein", "steine", "pflaster", "pflastersteine",		\
               "wegrand", "rand", "haufen"}),					\
      "Am Wegrand liegen hin und wieder sauber gestapelte Haufen von"	\
      " Pflastersteinen, die hier wohl kuerzlich erst abgeladen"	\
      " wurden.");							\
  AddDetail( ({"dunst"}),						\
      "Vom letzten Regen ist die Wiese noch feucht, es steigt ein"	\
      " leichter Dunst von ihr auf, der die Fernsicht verschleiert.");	\
  AddDetail( ({"weide", "wiese", "gras", "viehfutter"}),		\
      "Das Gras waechst saftiggruen auf der Wiese, kraftstrotzend und"	\
      " vorzueglich als Viehfutter geeignet. Ab und zu wird das Gruen"	\
      " der Wiese vom Braun eines Kuhfladens unterbrochen.");		\
  AddDetail( ({"gruen", "braun"}),					\
      "Das Gruen ist das saftige Gras. Das Braun ist wohl etwas"	\
      " Anderes.");

#define CD_HUEGEL2							\
  AddDetail( ({"kuhfladen", "fladen", "pferdeapfel", "apfel", "kot",	\
               "kothaufen", "pferdeaepfel"}),				\
      "Mit Kennermiene greifst Du in den Haufen und pruefst Geruch,"	\
      " Farbe, Oberflaeche, Konsistenz und Geschmack (wuerg). Nach"	\
      " eingehender Pruefung meinst Du, es sind ganz gewoehnliche"	\
      " Kothaufen, die seit mindestens drei Tagen hier herumfaulen"	\
      " (Igitt).");							\
  AddDetail("geruch",							\
      "Stinkt wie drei Tage oder aelter.... *gruebel*");		\
  AddDetail("farbe",							\
      "Braun. Mit leichten halbverdauten gelblichen Einschluessen,"	\
      " vermutlich Hafer oder Heu.");					\
  AddDetail( ({"einschluss", "einschluesse", "hafer", "heu"}),		\
    "Die Einschluesse stammen wohl von Hafer oder Heu.");		\
  AddDetail("oberflaeche",						\
      "Weich-klebrig.");						\
  AddDetail("konsistenz",						\
      "Weich-broeckelig, nicht besonders viskos, dafuer umso "		\
      "mehr igitt.");							\
  AddDetail( ({"geschmack", "schweinepriester"}),			\
      "Baeh, Du Schweinepriester! *wuerg*");				\
  AddDetail( ({"scheisse", "scheiss", "kacke"}),			\
      "Aber wer wird denn? Nicht vulgaer werden, bitte.");		\
  AddSmell( ({DEFAULT_SMELL, "geruch", "duft", "luft", "landluft"}),	\
    "Es riecht nach Landluft... aber woher kommt dieser wuerzige "	\
    "Duft?");								\
  AddSmell( ({"kuhfladen", "fladen", "pferdeapfel", "apfel", "kot",	\
    "haufen", "kothaufen", "pferdeaepfel"}),				\
      "Uuuuuaaaaahhhhh.... konzentriert ist der Duft hier aber"		\
      " ungeniessbar!");						\

#endif __HUEGEL__
