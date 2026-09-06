/* A Storage Room for tools.
**
**  The room is meant as an easy dispenser for tools of common interest.
**  Please note that the tools must be trusted before use.
** 
**    v.1  18-Jun-92 [m]
**    v.2  07-Feb-95 [m] Small fixes.
**
**  [m] Mateese
*/

#include <properties.h>
#include <rooms.h>
#include <secure/wizlevels.h>

inherit "/std/room";

#define SAVEFILE "/d/archwiz/common/lpc/toolstorage"

#define PL this_player()
#define ME this_object()

#define VERSION "950207"

#define T_ID    0
#define T_PATH  1
#define T_DESC  2

mixed *shelves; 
/*  ({ ({ tool_shorts }), ({ tool_path }), ({ tool_description}) }) */

string _look_tools();

/*-------------------------------------------------------------------------
*/

create() {
  room::create();
  SetIntShort ("The tool storage");
  SetIntLong (
"This room has many shelves ('look' at them), filled with useful tools, "+
"free for you to 'take'. But note that some tools needs to be trusted to. "+
"The tools are generously 'deposit'ed here by their creators, and rarely "+
"'remove'd again (give '<cmd> ?' for further explanations on these).\n"+
"To the west is the LPC-Office.\n"
              );
  AddExit ("west", "/d/archwiz/common/lpc/office");
  AddDetail ( ({ "shelves", "tools" }), #'_look_tools);
  AddRoomCmd ("take"   , "ftake");
  AddRoomCmd ("deposit", "fdeposit");
  AddRoomCmd ("remove" , "fremove");
  /* SetIntLight(1); */
  Set(P_INDOORS, 1);
  shelves = ({ ({}), ({}), ({}) });
  restore_object(SAVEFILE);
}

/*-------------------------------------------------------------------------
** Look at the tools.
*/

string _look_tools() {
  string rc;
  int i, size;

  if (!(size = sizeof(shelves[T_ID])))
    return "Sorry, the shelves are all empty.\n";
  rc = "--- You see on the shelves: ---\n";
  for (i = 0; i < size; i++) {
    rc += shelves[T_ID][i]+", File: "+shelves[T_PATH][i]+"\n";
    rc += "   "+shelves[T_DESC][i]+"\n";
  }
  return rc;
}

/*-------------------------------------------------------------------------
** Take a tool.
*/

ftake (string arg) {
  int ix;
  object ob;

  if (!arg || (ix = member(shelves[T_ID], arg)) < 0) return 0;
  ob = clone_object(shelves[T_PATH][ix]);
  if (PL->command_me("clone "+shelves[T_PATH][ix])) {
    write ("You take "+ob->QueryShort()+" from one shelf.\n");
    say (PL->QueryShort()+" takes "+ob->QueryShort()+" from one shelf.\n");
  }
  else {
    write ("You try to get hold of "+ob->QueryShort()+" but you fail.\n");
   say (PL->QueryShort()+"tries to get hold of "+ob->QueryShort()+" fails.\n");
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Deposit a tool.
*/

fdeposit (string arg) {
  string tid, tpath, tdesc;

  if (!arg) return 0;
  if (arg == "?") {
    write (
"deposit <id> <path> <desc>\n"+
"  Deposit your tool on the shelves.\n"+
"  It is stored under the <id> with the (relative) filename <path>\n"+
"  and the one-line <desc>ription.\n"
          );
    return 1;
  }

  if (sscanf (arg, "%s %s %s", tid, tpath, tdesc) != 3) {
    notify_fail ("Not enough arguments.\n");
    return 0;
  }

  tpath = MASTER->full_path(tpath, PL->QueryRealName());
  if (!IS_LORD(PL) && MASTER->creator_file(tpath) != geteuid(PL)) {
    write ("You are not allowed to deposit some other's tool here.\n");
    write ("Ask the creator or an Lord or Arch to do that.\n");
    return 1;
  }

  shelves = insert_alist(tid, tpath, tdesc, shelves);
  save_object(SAVEFILE);

  write ("You put your tool on one of the shelves.\n");
  say (PL->QueryName()+" puts aa "+tid+" on one of the shelves.\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Remove a tool.
*/

fremove (string arg) {
  string tid, tpath, tdesc;
  int ix;

  if (!arg) return 0;
  if (arg == "?") {
    write (
"remove <id>\n"+
"  Remove your tool <id> from the shelves.\n"
          );
    return 1;
  }

  tid = arg;
  if ((ix = member(shelves[T_ID]), tid) < 0) {
    write ("There's no such tool.\n");
    return 1;
  }

  tpath = shelves[T_PATH][ix];
  tdesc = shelves[T_DESC][ix];

  if (!IS_LORD(PL) && "/secure/master"->creator_file(tpath) != geteuid(PL)) {
    write ("You are not allowed to remove some other's tool.\n");
    write ("Ask the creator or an Lord or Arch to do that.\n");
    return 1;
  }

  shelves[T_ID] -= ({ tid });
  shelves[T_PATH] -= ({ tpath });
  shelves[T_DESC] -= ({ tdesc });
  shelves = order_alist(shelves);

  save_object(SAVEFILE);

  write ("You remove your tool from the shelves.\n");
  say (PL->QueryName()+" removes a "+tid+" from the shelves.\n");
  return 1;
}

/*************************************************************************/

