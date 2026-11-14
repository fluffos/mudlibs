/*
 * File:    /d/gebirge/feyaria/weg/room/wald.h
 *
 * Contains:  common definitions for cheasy's rooms
 *
 * History:
 *  96-03-25  cps   moved wood-specific defines into this file
 *  96-12-20  feyaria  fuers SL
 */

#ifndef __WALD__
#define __WALD__ 19960325


/* use the date as version number, thus we may check for versions in the files
 * including this one
 */

#define P_INT_SHORT_WALDWEG 						\
  SetProp(P_INT_SHORT, "Auf einem Waldweg")

#define CD_WALDBODEN 							\
  AddDetail( ({"boden", "laub", "nadeln", "nadel", "waldboden"}), 		\
    "Der Boden ist mit Laub und Nadeln bedeckt.\n");

#define CD_WALD 							\
  AddDetail( ({"wald", "baum", "baeume"}), 				\
    "Der Wald besteht aus vielen Baeumen, die mehr oder weniger nahe" 	\
    " beieinander stehen.");						\
  AddDetail( ({"rinde", "zweige", "aeste", "blatt", "blaetter", "stamm",\
               "staemme", "wurzeln", "wurzel", "zweig", "ast", "holz" }),\
    "Wurzeln, Stamm, Holz, Rinde, Zweige, Aeste und Blaetter; die Baeume "\
    "hier haben alles, was einen richtigen Baum ausmacht.");

#define CD_NADELWALD 							\
  AddDetail( ({"wald", "baum", "baeume", "tannen", "fichten", "kiefern",\
        "nadelbaum", "nadelbaeume", "nadelwald" ,"tanne", "fichte", "kiefer"}),		\
    "Du siehst hier nur noch Nadelbaeume, unter anderem Tannen, Fichten" \
    " und Kiefern, die mehr oder weniger dicht beieinander stehen.");	\
  AddDetail( ({"rinde", "zweige", "aeste", "wurzel", "wurzeln",		\
               "stamm", "staemme", "zweig", "ast"}), 			\
    "Wurzeln, Stamm, Rinde, Zweige, Aeste und Nadeln; die Nadelbaeume "	\
    "hier haben alles, was einen richtigen Nadelbaum ausmacht.");


/** Waldweg **********************************************************/

#define CD_WALDWEG 							\
  SetProp(P_LIGHT, 1); 							\
  AddDetail( ({"weg", "waldweg"}), 					\
    "Du stehst auf einem Waldweg. Der Boden ist von tiefen Karrenspuren" \
    " durchpfluegt. Hier scheinen oefter mal Haendler mit ihren schweren" \
    " Lastkarren vorbeizukommen."); 					\
  AddDetail( ({"spuren", "karrenspuren", "spur", "karrenspur"}), 				\
    "Die Lastkarren der Haendler haben zwei tiefe Spuren in den" 	\
    " Waldboden gepraegt."); 						\
  AddDetail("haendler", 						\
    "Im Moment ist gerade keiner zu sehen.");	 			\
  AddDetail( ({"karren", "lastkarren", "haendlerkarren"}),		\
   "Du schaust angestrengt den Weg hinauf und hinunter, kannst" 	\
   " aber gerade keinen Karren entdecken."); 				\
  AddDetail( ({"himmel", "sonne", "wolke", "wolken", "wind"}), 		\
   "Blauer Himmel, gelbe Sonne, ein paar Wolken, leichter Wind: also" 	\
   " nichts Besonderes."); 						\

#define CD_WALDPFAD 							\
  AddDetail( ({"weg", "waldweg"}), 					\
    "Den Waldweg hast Du laengst verlassen. Du stehst nur mehr auf "	\
    "einem schmalen Waldpfad."); 					\
  AddDetail( ({"pfad", "waldpfad"}),	 				\
    "Der Waldpfad ist gerade mal so breit, dass Du hier gehen kannst. "	\
    "Die breiten Lastkarren koennten hier niemals fahren.");		\
  AddDetail( ({"himmel", "sonne", "wolke", "wolken"}), 			\
    "Der Himmel ist durch die dichten Baeume verdeckt. Aber die Sonne "	\
    "steht wohl immer noch dort oben am Himmel, auch wenn Du sie nicht "\
    "direkt sehen kannst.");						\
  AddDetail( ({"karren", "lastkarren"}), 				\
    "Einen Lastkarren wirst Du hier nie sehen, weil der Pfad viel zu "	\
    "schmal ist.");							\
  AddDetail( ({"unterholz", "holz", "verlassen"}),			\
    "Das Unterholz neben dem Pfad ist so dicht, dass ein Verlassen "	\
    "des Pfades unmoeglich ist.");					\
  AddSound( DEFAULT_SOUND,						\
    "Hier ist es angenehm ruhig.");					\
  AddSmell( ({DEFAULT_SMELL, "duft", "waldduft"}),			\
    "Du laesst den beruhigenden Waldduft in Deine Lungen einstroemen.");
    
#endif
