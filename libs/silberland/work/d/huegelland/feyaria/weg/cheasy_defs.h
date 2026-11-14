/*
 * File:		cheasy_defs.h
 *
 * Contains:	common definitions for cheasy's rooms
 *
 *
 *      96-12-19	feyaria	angepasst an SilberLand, Du/Dir/Dich gross
 * History:
 *	96-03-26	cps	modified BS(s) to add \n after the string
 *	96-03-25	cps	moved all room-specific defines into separate
 *					files inside
 *	96-03-20	cps	added some of fyt's macro definitions
 *	96-03-20	cps	added room descriptions for some of my rooms
 *	96-03-19	cps	created this file
 */

#ifndef CHEASY_DEFS
#define CHEASY_DEFS 1

/* common abbreviations *
 ************************
 */

#include "./def.h"

#ifndef MSG
#define MSG(x,y)	write(BS(x));say(BS(CAP(TPN)+y))
#endif

#ifndef N_STADT
#define N_STADT "Derlim"
#endif

#ifndef N_BERG
#define N_BERG "Silberberg"
#endif

#ifndef N_SEE
#define N_SEE	"Silbersee"
#endif


/*
 * Some standard details to use for Cheasy's rooms *
 ***************************************************
 */

/*** Short descriptions ***/

#define P_INT_SHORT_SCHLUCHT	"In einer Schlucht"
#define P_INT_SHORT_SIMS	"Auf einem Sims"
#define P_INT_SHORT_KAMIN	"In einem Felskamin"
#define P_INT_SHORT_KPFAD	"Auf einem Kletterpfad"

/*** Some pieces to add to long descriptions ***/

#define B_MISSING							\
	"Nanu? Was soll denn diese Fast-Food-Tuete hier?\n"		\
	"Du solltest besser mal einen Bugreport abschicken.\n\n"

/*** Cheasys Standard Details --- just add to your rooms. ***/
#define B_FELSBODEN							\
  "Der Boden ist felsig. Hie und da liegt ein Steinchen."

#define B_WIESENBODEN							\
  "Du siehst Gras. Viele gruene Halme stehen da dicht gedraengt "	\
  "nebeneinander -- kein Wunder, ein einzelner Grashalm wuerde "	\
  "sich alleine zu Tode fuerchten."

#define B_SANDBODEN							\
  "Sand, Sand, Sand -- wie Sand am Meer liegt das  Zeugs hier rum.")

/** Boden **/
#define CD_FELSBODEN							\
AddDetail( ({"boden", "felse", "stein",	"steinchen" }),  B_FELSBODEN);

#define CD_WIESENBODEN							\
AddDetail( ({"boden", "gras", "halm","halme"}), B_WIESENBODEN);

#define CD_SANDBODEN							\
AddDetail( ({"boden", "sand", "zeugs"}), B_SANDBODEN);


/** Berg *****************************************************************/
#define CD_BERG_WEIT							\
AddDetail( ({"berg", "hang", "gebirge", N_BERG, "berge"}),				\
  "Der " N_BERG " erhebt sich majestaetisch in der Ferne. Ein paar "	\
  "Wolken verhuellen den Gipfel.");					\
AddDetail( ({"wolken", "gipfel"}),					\
  "Einige Wolken verhuellen den Gipfel...\n"				\
  "Was sich dahinter wohl verbirgt?\n");

#define CD_BERG_NAH							\
AddDetail( ({"berg", "hang", "gebirge", N_BERG}),				\
  "Der Hang ist sehr steil und von tiefen Falten durchfurcht. "		\
  "Ueber Dir verschwimmen die Konturen im den Wolken.");		\
AddDetail( ({"dunst", "nebel", "wolken"}),				\
  "Ueber Dir ist es so dunstig, dass Du keinerlei Details"		\
  " erkennen kannst.");							\
AddDetail( ({"detail", "details"}),					\
  "Wilst Du wirklich JEDES Detail untersuchen?\n");			\
AddDetail( ({"jedes", "wilst"}),					\
  BS("Also entweder Du bist ein Script, oder Du brauchst wirklich "	\
  "dringend einen von Cheasy's Zaubertraenken.")+"=;-)\n");		\
/***** ZAUBERTRANK HIERHER! *****/					\
AddDetail( "=;-)",							\
  "Cheasy ist zwar grad nicht da, er zwinkert Dir aber trotzdem zu.");	\
AddDetail( ({"weg", "pfad"}),						\
  "Der Weg schmiegt sich an den Berghang und folgt aber auch"		\
  " jeder Falte im Gelaende, was den Weg wesentlich laenger"		\
  " macht, als es von unten aussah.");
									
/** See **********************************************************/
#define CD_SEE_WEIT							\
AddDetail( ({"see", "wasser", N_SEE}),						\
  "Der " N_SEE " liegt traege glaenzend in einem weiten Tal.");		\
AddDetail( "tal" ,							\
  "In einem weiten Tal liegt der " N_SEE ". Du solltest schon"		\
  " etwas naeher rangehen, um ihn Dir genauer anzuschauen.");		\

#define CD_SEE_NAH							\
AddDetail( ({"see", "wasser", N_SEE}),						\
  "Vor Dir liegt der " N_SEE ". Traege plaetschert sein Wasser"		\
  " ans Ufer. Hie und da kannst Du weit draussen ein paar"		\
  " Wasservoegel erkennen. Am Ufer stehen Schilfbueschel und"		\
  " Roehricht.");							\
AddDetail( ({"ufer", "strand"}),					\
  "Am Ufer erkennst Du viele Schilfbueschel und ein wenig"		\
  " Roehricht.");							\
AddDetail( ({"schilf", "schilfbueschel"}),				\
  "Das Schilf steht zum grossen Teil an Land im feuchten Uferschlamm.");\
AddDetail( "roehricht",							\
  "Im Wasser erkennst Du einige wenige Roehrichthalme.");		\
AddDetail( ({"vogel", "voegel", "wasservoegel"}),			\
  "Du erkennst ein paar Enten und Haubentaucher weit draussen auf "	\
  "dem See.");								\
AddDetail( ({"matsch", "schlamm", "boden", "uferschlamm"}),		\
  "Hier nahe des Ufers ist der Boden sehr schlammig. Pass auf,"		\
  " dass Dir der Matsch nicht die Schuhe auszieht!");


#define CD_WARNSCHILD_TEXT						\
		"+-------------------------------------------+\n"	\
		"|                                           |\n"	\
		"|           LAWINEN-ABGANGSGEBIET           |\n"	\
		"|                                           |\n"	\
		"|          VORSICHT, LEBENSGEFAHR!          |\n"	\
		"|                                           |\n"	\
		"|   Der Schluchtpfad ist lebensgefaehrlich. |\n"	\
		"| Laute Geraeusche, Rufe, und unvorsichtige |\n"	\
		"|   Bewegungen koennen Lawinen ausloesen,   |\n"	\
		"|   die schwerste Verletzungen oder sogar   |\n"	\
		"|     den Tod zur Folge haben koennen.      |\n"	\
		"|                                           |\n"	\
		"|       BETRETEN AUF EINGENE GEFAHR!        |\n"	\
		"|                                           |\n"	\
		"|     Bitte beachten Sie die Broschuere     |\n"	\
		"|  \"Verhaltensmassnahmen im Lawinengebiet\"  |\n"	\
		"|                                           |\n"	\
		"|   Die SilberLand Feld-, Wald- und Wiesen- |\n"	\
		"|                   Wegeverwaltungsbehoerde.|\n"	\
		"+-------------------------------------------+\n"

#define CD_WARNSCHILD							\
	AddDetail( ({"schild", "warnschild", "lawinen-warnschild"}),	\
		CD_WARNSCHILD_TEXT);					\
	AddReadDetail( ({"schild", "warnschild", "lawinen-warnschild"}),\
		CD_WARNSCHILD_TEXT);



#endif
