/*
 * part of the townwall
 *
 * last changes:
 * [m] 8 feb 98 - first version
 */

// TODO: wipe the board, clean the board, write on the board
// allow changing the messages of the board

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <nightday.h>
#include <sykorath.h>

inherit TOWNWALL;

string boardmsg;

//*******************
// property handling:
//*******************
string QueryBoard() { return boardmsg; }
string SetBoard(string msg) { return boardmsg=msg; }

//****************
// read the board:
//****************
string readboard() {
  return boardmsg+"\n";
}

//*******
// create
//*******
create() {
  ::create();
  boardmsg="No active duty";
  SetIntShort("Inside the townwall");
  SetIntLong(
    "You are inside the townwall. On the south wall hangs a big "
    "blackboard.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({540,680,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"wall"}),
    P_ADS:  ({"south","southern"}),
    P_LONG: "The wall consist of a heavy stone. A big blackboard hangs on "
            "the southern wall.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"board","blackboard"}),
    P_ADS:  ({"black","big"}),
    P_LONG: "It is a big blackboard. It looks like the board, where the "
            "guards of this town note their duties. Some words are written "
            "on it.\n",
    P_READ_MSG: #'readboard ]) );

  /* exits */
  AddExit("east","./town58x68");
  AddExit("northwest","./town52x66");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
    "Wizards can set the board here by using:\n"
    "xcall $h->SetBoard(\"message text\")\n"
  );
}

