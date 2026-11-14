// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/install.h
// Description: Fuer Objekte, die garantiert nie bewegt werden sollen,
//              nachdem sie ein Environment bekommen haben.
// Modified by:	Garthan (10.01.94) set_no_move ueberarbeitet
//		Freaky  (21.01.98) nur noch query_no_move()
//
// $Log: install.h,v $
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

/*
 *	void move(mixed ziel)
 *		Das Ziel kann sowohl ein Objekt, als auch ein File-Name sein.
 *		das Objekt bzw der File wird eventuell von Platte geladen.
 *
 *	--> entweder /i/move ODER /i/install , niemals beides.
 */

// Wenn query_no_move() 1 zurueckgibt, kann man das Objekt nur aus NULL
// heraus bewegen.
nomask int query_no_move() { return 1; }

