/*
 * File:    /d/gebirge/feyaria/weg/room/bergpfad.h
 *
 * Contains:  Common details for the cliffpath area 
 *
 * History:
 *  96-04-02  cps   created this file
 *  96-12-20  feyaria fuers SL
 */

#ifndef __BERGPFAD__
#define __BERGPFAD__ 19960402
/* use the date as version number, thus we may check for versions in the
 * files including this one
 */

#include "../directions.h"

/***** Defined Details *****************************************************
"boden", "weg", "pfad", "grund"
"lust"
"kuhfladen", "fladen", "pferdeapfel", "apfel", "kot", "haufen", "kothaufen"
"geruch"
"farbe"
"oberflaeche"
"konsistenz"
"geschmack"
"scheisse", "scheiss", "kacke"
 ***** end of Defined Details **********************************************/
 
 
#define P_INT_SHORT_BERGPFAD						\
  SetProp(P_INT_SHORT, "Auf einem Bergpfad")

#define CD_BERGPFAD							\
  SetProp(P_LIGHT, 1);							\
  AddDetail( ({"boden", "weg", "pfad", "grund"}),			\
      "Der Weg fuehrt ueber angenehm weichen Boden, der Deine Schritte"\
      " so weich abfedert, dass das wandern eine wahre Lust ist."	\
      " Darunter scheint allerdings sehr harter Grund zu sein, denn"	\
      " obwohl der Grund nach dem letzten Regen noch aufgeweicht ist,"	\
      " haben sich die Karrenspuren kaum in den Boden eingegraben.");	\
  AddDetail("lust",							\
      "Lust -- schoen und gut. Aber wenn Du weiter so unsinnige"	\
      " Details untersuchst, kann Dir der Spass daran sehr schnell"	\
      " vergehen.");							\
  AddDetail( ({"wald", "baum", "baeume"}),				\
      "Der Wald ist noch nass vom letzten Schauer, von den Baeumen"	\
      " fallen die letzten Tropfen auf den Boden.");			\
  AddDetail( ({"schauer", "tropfen", "wasser"}),			\
      "Von den Baeumen tropft noch ein wenig Wasser auf den Boden.");	\
  AddDetail( ({"kuhfladen", "fladen", "pferdeapfel", "apfel", "kot",	\
      "haufen", "kothaufen"}),						\
      "Mit Kennermiene greifst Du in den Haufen und pruefst Geruch,"	\
      " Farbe, Oberflaeche, Konsistenz und Geschmack (wuerg). Nach"	\
      " eingehender Pruefung meinst Du, es sind ganz gewoehnliche"	\
      " Kothaufen, die seit mindestens drei Tagen hier herumfaulen"	\
      " (Igitt).");							\
  AddDetail("geruch",							\
      "Stinkt wie drei Tage oder aelter.... *gruebel*");		\
  AddDetail("farbe",							\
      "Braun. Mit leichten halbverdauten gelblichen Einschluessen,"	\
      " vermutlich Hafer oder Heu.\n");					\
  AddDetail("oberflaeche",						\
      "Weich-klebrig.");						\
  AddDetail("konsistenz",						\
      "Weich-broeckelig, nicht besonders viskos, dafuer umso mehr"	\
      " igitt.");							\
  AddDetail("geschmack",						\
    "Baeh, Du Schweinepriester! *wuerg*");				\
  AddDetail("schweinepriester",						\
      "Jawohl, Du bist gemeint!");					\
  AddDetail( ({"scheisse", "scheiss", "kacke", "shit", "merde"}),	\
      "Aber wer wird denn? Nicht vulgaer werden, bitte.");		\

#endif __BERGPFAD__
