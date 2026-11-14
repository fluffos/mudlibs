/*
 * File:    /d/gebirge/feyaria/weg/room/pass.h
 *
 * Contains:  common definitions for cheasy's rooms
 *
 * History:
 *  96-04-02  cps   rewritten completely
 *  96-04-01  cps   created this file
 *  96-12-20 feyaria fuers SL
 */

#ifndef __PASS__
#define __PASS__ 19960401
/* use the date as version number, thus we may check for versions in the 
 * files including this one
 */

#define P_INT_SHORT_PASS						\
  SetProp(P_INT_SHORT, "Auf einem Pass")

#define CD_PASS								\
  SetProp(P_LIGHT, 1);							\
  AddSound( ({DEFAULT_SOUND, "wind"}),					\
    "Auf dem Pass pfeift der Wind.");					\
  AddSmell( ({DEFAULT_SMELL, "luft", "bergluft"}),			\
    "Die Bergluft riecht ausgezeichnet.");				\
  AddDetail( ({"pass", "passhoehe"}),					\
      "Fast eben fuehrt der Weg hier ueber einen Pass, zwischen"	\
      " Felsbloecken und Geroell hindurch. Du kannst kaum noch"		\
      " Krueppelkiefern entdecken, nur noch wenige Graeser bewachsen"	\
      " das Geroell.");							\
  AddDetail( ({"graeser", "gras", "halm", "halme", "grashalm", 		\
               "grashalme"}),						\
    "Nur wenige Grashalme bewachsen das Geroell.");			\
  AddDetail( ({"boden", "stein", "steine", "felsen", "geroell",		\
      "geroellboden", "bloecke", "block", "felsblock", "felsbloecke",	\
      "brocken", "felsbrocken", "geroellhang"}),			\
      "Der Boden ist felsig und mit kleinen Steinen und Felsbrocken"	\
      " bedeckt.");							\
  AddDetail( ({"weg", "pfad"}),						\
      "Der Pfad fuehrt ueber Geroellboden zwischen zwei hohen Gipfeln"	\
      " im " + CAP(ED2) + " und " + CAP(ED6) + " ueber einen kahlen," 	\
      " windgebeutelten Pass. Im " + CAP(ED4) + " siehst Du in weiter"	\
      " Ferne das Meer tief unter Dir blau leuchten, nach " + CAP(ED8)+	\
      " fuehrt der Weg steil bergab in ein Tal, das im Sommerdunst"	\
      " verschwimmt.");							\
  AddDetail( ({"gipfel"}),						\
      "Du stehst zwischen zwei Gipfeln, die beide unbezwingbar"		\
      " scheinen.");							\
  AddDetail( ({"berg", "berge", "gebirge", "ueberraschung"}),		\
      "Welche Ueberraschung! Hier im Gebirge gibt es Berge!");		\
  AddDetail( ({"ferne", "meer", "tal"}),				\
      "Das ist viel zu weit weg, so dass Details im Dunst"		\
      " verschwimmen.");						\
  AddDetail( ({"dunst", "sommerdunst"}),				\
      "Es hat wohl in letzter Zeit ein wenig geregnet, so dass die"	\
      " Landschaft in der Ferne im Dunst verschwimmt.");		\
  AddDetail( ({"landschaft"}),						\
      "Es ist ziemlich dunstig, so dass Du von hier oben nichts"	\
      " Genaueres erkennen kannst.");					\
  AddDetail( ({"silberland", "land"}),                                  \
      "Du befindest Dich im SilberLand.");                              \
  AddDetail( ({"wolken", "nebel"}),					\
      "Die Wolken bestehen offensichtlich aus Nebel. Seltsam, von"	\
      " weiter unten sehen Sie aus, als waeren Sie aus Watte gemacht.");\
  AddDetail( "wind",							\
      "Der Wind blaest hier staendig.");				\
  AddDetail( ({"kiefer", "kiefern", "krueppelkiefer",			\
    "krueppelkiefern"}),						\
      "Nur ganz selten kannst Du eine Krueppelkiefer sehen: der Wind"	\
      " hier oben ist meist zu stark, und die Winter sind hart.");	\
  AddDetail( ({"himmel", "sonne", "wolke", "wolken"}),			\
      "Die Sonne scheint aus dem blauen Himmel, ueber den nur hin und"	\
      " wieder eine Wolke zieht. Trotzdem ist es unangenehm kalt hier.");

#endif
