//
// ----------------------------------------------------------------------------
// Datei:        TEST.h
// Autor:        Rommy
// Datum:        02.08.2009
// ----------------------------------------------------------------------------
// Beschreibung: Defines fuers Beispielprojekt
// ----------------------------------------------------------------------------
// Aenderungen:
//
//

#ifndef TESTPROJEKT_H
#define TESTPROJEKT_H 1

// Pfade
#define TEST     "/doc/beispiele/beispielprojekt/"
#define TEST_I   TEST"i/"
#define TEST_N   TEST"npc/"
#define TEST_O   TEST"obj/"
#define TEST_R   TEST"room/"
#define TEST_A   TEST"armour/"
#define TEST_W   TEST"weapon/"
#define TEST_LOG TEST"log/"
//#define TEST_INFOLOG "testprojekt.log"

// Dinge und Namen


// Anschluesse
#define ANSCHLUSS "/players/rommy/workroom.lpc"

// needfull things
#define MOVE_OK  1
#define ERR(x)   write(x+"\n")
#define BS(x)    break_string(x,78)
#define BSN(x)   break_string(x,78,0,1) // "\n" werden beibehalten
#define DEBUG(x) if(find_player("rommy")) tell_object(find_player("rommy"),x)

#define bool int
#define FALSE 0
#define TRUE 1

#define ON  1
#define OFF 0

#ifndef CAP
#define CAP capitalize
#endif

#ifndef TO
#define TO this_object()
#endif

#ifndef TP
#define TP this_player()
#endif

#ifndef TPN
#define TPN TP->name()
#endif

#ifndef TI
#define TI this_interactive()
#endif

#ifndef PO
#define PO previous_object()
#endif

#ifndef ENV
#define ENV(x) environment(x)
#endif

#ifndef MENV
#define MENV environment(this_object())
#endif

#ifndef SUID
#define SUID seteuid(getuid(this_object()));
#endif

#endif // TESTPROJEKT_H
