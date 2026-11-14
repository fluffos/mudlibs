/*
 * Filename:  hang.h
 *
 * Created by:      Cheasy (cps)
 *
 * Modified by:
 *
 * Change history:
 *   96-04-02 cps    created this file
 *   96-12-20 feyaria fuers SL
 */

#ifndef __HANG__
#define __HANG__


#include "../directions.h"
#include "../cheasy_defs.h"

#define P_INT_SHORT_HANG						\
  SetProp(P_INT_SHORT, "Auf einem Hang")

#define CD_HANG								\
  SetProp(P_LIGHT, 1);							\
  AddSound( ({DEFAULT_SOUND, "rollen", "geroell"}),			\
    "Du hoerst nur das Rollen des Geroells unter Deinen Schuhen.");	\
  AddSmell( ({DEFAULT_SMELL, "luft", "bergluft"}),			\
    "Die Bergluft riecht ausgezeichnet.");				\
  AddDetail( ({"hang", "geroellhang"}),					\
      "Ein steiler Geroellhang, auf dem Buschwerk und Gestruepp"	\
      " waechst. Du solltest besser auf dem Weg bleiben, denn der Boden"\
      " abseits des Wegs sieht gemeingefaehrlich aus.");		\
  AddDetail( ({"geroell", "geroellfeld", "brocken", "gipfel"}),		\
      "Das Geroell ist wohl beim Verwittern des Gipfels entstanden. Es"\
      " ist sehr scharfkantig und liegt wohl recht instabil abseits des"\
      " Wegs. Zwischen den einzelnen Brocken kann sich kaum ein Strauch"\
      " oder Busch halten.");						\
  AddDetail( ({"busch", "buesche", "buschwerk", "gestruepp",		\
		"strauch", "straeucher"}),				\
      "Die kuemmerlichen Buesche und Straeucher koennen sich kaum auf"	\
      " dem Geroellfeld halten.");					\
  AddDetail( ({"boden", "grund", "weg", "pfad", "geroellboden", "verlauf"}),\
      "Hier ist der Boden aus befestigtem Geroell; abseits des Wegs"	\
      " liegt das Rohmaterial dazu. Hier zeichnen sich fast keine"	\
      " Karrenspuren im felsigen Grund ab. Nur ein paar Pferdeaepfel"	\
      " und Kuhfladen zeigen den Verlauf des Wegs.");			\
  AddDetail( ({"Rohmaterial"}),						\
      "Geroell, was sonst?");						\
  AddDetail( ({"spuren", "karrenspuren" ,"spur", "karrenspur" }),				\
    "Wie? Spuren? Hier? Im Geroell? Ich glaub mein Schwein pfeift...");	\
  AddDetail( ({"schwein"}),						\
    "Floet... pfeif... piep...");					\
  AddSound( ({"schwein"}),						\
    "Floet... pfeif... piep...");					\
  AddDetail( ({"aepfel", "pferdeaepfel", "kuhfladen", "fladen", "kot"}),\
      "Feucht und kuehl. Bestimmt aelter als zwei, aber nicht aelter"	\
      " als drei Tage. Riecht naemlich kaum noch ;-)");			\
  AddSmell( ({"aepfel", "pferdeaepfel", "kuhfladen", "fladen", "kot",	\
              "kacke", "scheisse", "scheiss", "kack", "shit"}),		\
    "Das stinkt!");							\
  AddDetail( ({"kacke", "scheisse", "scheiss", "kack", "shit"}),	\
      "Aber, aber... nicht vulgaer werden.");				\
  AddDetail( ({"tag", "tage"}),						\
     "Hallo, Du Script!");						\
  AddDetail( ({"himmel", "wolke", "wolken", "sonne"}),			\
      "Die Sonne scheint aus dem blauen Himmel, nur ab und zu zieht"	\
      " eine Wolke vorbei.");

#endif __HANG__
