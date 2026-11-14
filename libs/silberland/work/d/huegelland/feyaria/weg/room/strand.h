/*
 * File:    /d/gebirge/feyaria/weg/room/strand.h
 *
 * Contains:  Common details for the strand area
 *
 * History:
 *  96-04-03  cps   created this file
 *  96-12-22  feyaria fuers SL
 */

#ifndef __STRAND__
#define __STRAND__ 19960403
/* use the date as version number, thus we may check for versions in the
 * files including this one
 */

#include "../directions.h"
 
#define P_INT_SHORT_STRAND						\
  SetProp(P_INT_SHORT, "Auf einem Sandstrand")

#define CD_STRAND							\
SetProp(P_LIGHT, 1); 							\
AddDetail( ({"boden"}),							\
  "Der Boden ist voller Sand.");					\
AddDetail( ({"sand"}),							\
  "Hier gibts soviel Sand wie Sand am Meer.\n\n"			\
  "Du denkst . o O ( Aber wir sind doch am Meer?)\n");			\
AddDetail( ({"wie sand am meer"}),					\
  "Soviel Sand gibt es hier.");						\
AddDetail( ({"himmel", "sonne"}),					\
  "Mitten am Himmel siehst Du die Sonne.");				\
AddDetail( ({"weg"}),							\
  "Der Weg fuehrt am Strand entlang.");					\
AddDetail( ({"bucht", "meeresbucht"}),					\
  "Du befindest Dich am Strand einer grossen Meeresbucht.");		\
AddDetail( ({"meer", "wellen", "brandung", "see", "kueste"}),		\
  "Rauschend rollen die Wellen den schneeweissen Strand hinauf und "	\
  "fliessen wieder zurueck ins Meer. Am Tidensaum findet sich neben "	\
  "abgestorbenen Algen allerlei Geruempel.");				\
  									\
AddDetail( ({"seetang", "tang"}),					\
  "Die grossen gruenen und braunen Stuecke des Seetangs liegen "	\
  "ueberall am Strand herum.");						\
									\
AddDetail( ({"tidensaum", "saum", "geruempel", "algen"}),		\
  "Da liegen aufgeweichte und ausgelaugte Holzstuecke und Bretter "	\
  "neben abgerissenen Korkschwimmern und halben Muschelschalen, "	\
  "alles verkrustet von halbverfaulten abgestorbenen Algen.");		\
  									\
AddDetail( ({"holz", "holzstueck", "holzstuecke", "brett", "bretter"}),	\
  "Die Bretter und Holzstuecke sind vom Salzwasser zerfressen und "	\
  "ausgelaugt. Du kannst damit bestimmt nichts mehr anfangen.");	\
  									\
AddDetail( ({"kork", "schwimmer", "korkschwimmer", "strandgut"}),	\
  "Selten findet sich auch einmal ein Korkschwimmer zwischen dem "	\
  "Strandgut. Enttaeuscht wendest Du Dich ab: auch die Schwimmer "	\
  "lagen schon zu lange im Salzwasser.");				\
  									\
AddDetail( ({"wasser", "salzwasser", "meerwasser"}),			\
  "Es ist eindeutig Salzwasser, das in diesem Meer ans Ufer " 		\
  "schwappt.");								\
  									\
AddDetail( ({"ufer", "strand", "rand", "sandstrand"}),			\
  "Weisser Sandstrand, soweit das Auge reicht, bildet hier das Ufer "	\
  "des Meers. Ein Rand aus halbvermoderten Algen zeigt, wie hoch die "	\
  "hoechsten Wellen den Strand hinaufrollen.");				\
  									\
AddDetail( ({"muschel", "muscheln", "schalen", "muschelschalen",	\
             "muschelschale", "formen", "form", "farbe", "farben"}),	\
  "Du siehst verschiedene Muschelschalen in allen vorstellbaren "	\
  "Formen und Farben.");						\
									\
AddDetail( ({"salz"}),							\
  "Das Salz ist im Meerwasser geloest. Sehen kann man es nicht.");	\
									\
AddSmell( ({DEFAULT_SMELL, "meer"}),							\
  "Das Meer riecht nach Salz, Seetang und Fisch.");			\
									\
AddSmell( ({"salz", "seetang", "tang", "fisch"}),	\
  "Danach riecht das Meer.");						\
									\
AddSound( ({DEFAULT_SOUND, "wellen", "welle", "rauschen", "brandung",   \
            "meer"}),	                                                \
  "Du hoerst das Rauschen der Wellen.");


#endif __STRAND__

