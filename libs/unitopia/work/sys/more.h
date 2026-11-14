// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/more.h
// Description: Defines fuer player::more()
// Author:	Freaky
//
// $Log: more.h,v $
// Revision 1.6  2003/11/14 04:17:34  gnomi
// Defines zur ANgabe der Meldungstypen eingefuehrt.
// More-Flag M_SECURE eingefuehrt.
//
// Revision 1.5  2001/04/27 02:31:10  gnomi
// Weitere Flags M_SCROLL, M_NO_FIRST_SCREEN.
//
// Revision 1.4  2001/04/07 00:53:37  gnomi
// INPUT etwas dokumentiert.
//
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef MORE_H
#define MORE_H 1

// Diese Defines werden von der Funktion more_action, die im aufrufenden 
// Objekt definiert werden sollte, erwartet. Sie bestimmen die weitere
// Reaktion des more()
#define CONTINUE 0		// Die naechsten n Zeilen werden ausgegeben
#define END_MORE 1		// Der more() wird beendet.
#define NOTHING	 2		// status wird erneut ausgegeben, sonst nix
#define INPUT	 3		// Es findet gerade ein Input_to statt.
				// (das sollte nur intern verwendet werden!)

// Diese Defines werden als flags dem more() als 4. Argument erwartet. Mehrere
// davon werden mit '|' kombiniert.
#define M_LINE_NUMBERS	0x01	// Zeilennummern voranstellen
#define M_DO_NOT_END	0x02	// Nach Augabe der letzten Zeile more() nicht
				// verlassen
#define M_FRAME		0x04	// Jeder ausgegebenen Seite Linien voran- und
				// nachstellen
#define M_HEADER_LINE	0x08	// Die Ausgabe wird durch eine Linie am Anfang
				// und am Ende abgegrenzt
#define M_AUTO_END	0x10	// more() verlassen, wenn letzte Zeile 
				// ausgegeben
#define M_THIS_OBJECT	0x20	// Fuer den Fall, dass man in ob den more
				// aufrufen will, aber this_player()!=ob ist
				// Wird nicht mehr benoetigt.
#define M_CHARMODE	0x40	// Experimentell, nicht verwenden
#define M_FORCE         0x80    // Auch dann anzeigen, wenn es leer ist.
				// (Evntl. wegen Frame usw.)         
#define M_SCROLL        0x100   // Durchscrollen
#define M_NO_FIRST_SCREEN 0x200 // Am Anfang nur den Prompt ausgeben
#define M_SECURE	0x400	// Nicht anzeigen, wenn man beobachtet wird.

				// Noch 3 Bits (0x800 bis 0x2000) sind frei

#define M_TYPE(x)	((x)<<20)	// 10 Bits, 2 Reserve
#define M_ACTION(x)	((x)<<14)	// 5 Bits, 1 Reserve

#define M_GET_TYPE(x)	(((x)>>20)&0x3ff)
#define M_GET_ACTION(x)	(((x)>>14)&0x1f)

// Fehlerbehandlung
#define M_ERR(x)	((x)[2..])	// String der Fehlermeldung
#define M_ERR_NUM(x)	(to_int(x))	// Fehlernummer

// Defines der Fehlernummern
#define M_ERR_FAIL			1
#define M_ERR_NO_FILE_OR_ARRAY_GIVEN	2
#define M_ERR_FILE_UNREADABLE		3
#define M_ERR_NO_SUCH_FILE		4
#define M_ERR_NULL_FILE			5
#define M_ERR_NULL_ARRAY		6
#define M_ERR_FILE_TOO_LONG		7
#define M_ERR_INSECURE			8

#endif // MORE_H
