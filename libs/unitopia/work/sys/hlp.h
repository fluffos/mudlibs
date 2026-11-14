// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/hlp.h
// Description:	Makro zum Test auf bestimmte Gabe eines HLP
// Author:	Garthan (vor 09.08.1996)
//
// $Log: hlp.h,v $
// Revision 1.6  2002/12/01 03:32:38  gnomi
// Neues Define GABE2 wie GABE nur ohne Meldung.
//
// Revision 1.5  2002/02/03 21:40:08  gnomi
// Typo.
//
// Revision 1.4  2002/02/01 21:02:14  gnomi
// Typo.
//
// Revision 1.3  2002/02/01 07:56:21  gnomi
// Doku von Pulami etwas geaendert eingebaut.
// HLP_ALIGN ausgebaut, da es sinnlos geworden und nicht mehr verwendet wird.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef HLP_H
#define HLP_H 1

#ifndef GABE
#  ifndef hlpp
#     include <level.h>
#  endif
#  define GABE(player,g)                  \
       ((hlpp(player) || wizp(player)) &&  \
       present("hlp#tool",(player)) &&      \
       present("hlp#tool",(player))->gabe(g))
#  define GABE2(player,g)                  \
       ((hlpp(player) || wizp(player)) &&  \
       present("hlp#tool",(player)) &&      \
       present("hlp#tool",(player))->gabe(g,1))
#endif

/*
FUNKTION: GABE
DEKLARATION: int GABE(object spieler, string gabe)
BESCHREIBUNG:
Liefert 1, wenn der Spieler die Gabe besitzt, sonst 0.
gabe ist dabei das zweibuchstabige Kuerzel fuer eine Gabe in Kleinbuchstaben.
Moerder, welche diese Gabe urspruenglich hatten, aber aufgrund des (M)'s
sie nicht mehr besitzen, erhalten eine entsprechende Meldung. Ebenfalls
wird eine Meldung ausgegeben, wenn man die Gabe zwar grundsaetzlich besitzt,
aber aus irgendwelchen Umstaenden sie derzeit nicht verfuegbar ist.
VERWEISE: hlpp, GABE2
GRUPPEN: level
*/

/*
FUNKTION: GABE2
DEKLARATION: int GABE2(object spieler, string gabe)
BESCHREIBUNG:
Liefert 1, wenn der Spieler die Gabe besitzt, sonst 0.
gabe ist dabei das zweibuchstabige Kuerzel fuer eine Gabe in Kleinbuchstaben.
Es wird keinerlei Meldung an den Spieler ausgegeben.
VERWEISE: hlpp, GABE
GRUPPEN: level
*/

#endif // HLP_H
