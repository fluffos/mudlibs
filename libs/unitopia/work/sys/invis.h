// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/invis.h
// Description:	Argumente fuer set_invis
//
// $Log: invis.h,v $
// Revision 1.5  2001/06/02 03:18:18  gnomi
// Typ-Casting im IS_HIDDEN/IS_INVIS.
//
// Revision 1.4  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef INVIS_H
#define INVIS_H 1

/*
 * Intern verwendete Defines.
 */
#define V_ATOM_NOLIST		0x01
#define V_ATOM_HIDDEN		0x02
#define V_ATOM_INVIS		0x04
#define V_ATOM_NOSHIMMER	0x08

#define IS_INVIS(ob) (({int})(ob)->query_invis() & V_ATOM_INVIS)
#define IS_HIDDEN(ob) (({int})(ob)->query_invis() & V_ATOM_HIDDEN)

#define V_ATOM_MASK (V_ATOM_NOLIST|V_ATOM_HIDDEN|V_ATOM_INVIS|V_ATOM_NOSHIMMER)

/*
 * Nur die nachfolgenden Defines hier sind fuer Programmierer interessant !
 */

/*
 * Stinknormale Objekte.
 */
#define V_VIS		0

/*
 * Objekte, die nicht in der Inhaltsliste auftauchen sollen.
 *
 * Bsp:	/obj/tuer.c
 */
#define V_NOLIST V_ATOM_NOLIST

/*
 * Objekte, bei denen, wenn man sie anschaut, fuer andere die Meldung
 * kommen soll: "...schaut ETWAS an."
 *
 * Bsp: - Speisen in /room/gasthof/kueche.c
 *      - set_hidden_until_next_move()  in /i/move.c
 */
#define V_HIDDEN (V_ATOM_NOLIST|V_ATOM_HIDDEN)

/* 
 * Objekte, die man nicht richtig sieht, aber bei denen man erkennt
 * dass 'etwas' da ist (oder kommt oder geht). 'Ein Luftflimmern'.
 * Man weiss also nicht was es ist, bemerkt aber die Praesenz.
 * 
 * Bsp: 'Unsichtbare' Engel.
 */
#define V_SHIMMER (V_ATOM_NOLIST|V_ATOM_HIDDEN|V_ATOM_INVIS)


/*
 * Echte Unsichtbarkeit.
 * Niemand sieht etwas, niemand bekommt eine Meldung.
 *
 * Bsp: Unsichtbare Goetter.
 */
#define V_INVIS (V_ATOM_NOLIST|V_ATOM_HIDDEN|V_ATOM_INVIS|V_ATOM_NOSHIMMER)

#endif // INVIS_H
