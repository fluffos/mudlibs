// part of the Madmonks Guild
// made MagicTCS - 8 may 97
// it is the room for trainign your skills!

#include <properties.h>
#include <rooms.h>
#include <guild.h>
#include <skills.h>
#include <config.h>

#ifdef ONESTEPBEYOND
#include <secure/wizlevels.h>
#else
#include <wizlevels.h>
#endif

#include <moving.h>
#include "/p/guilds/madmonks/madmonks.h"

inherit BASISROOM;

//************
// train skill
//************
int cmd_train(string str) {
  int ret;
/*
  object gobj;
  ret=cmd_advance(str);
  if (str=="level" && ret==1) {
    gobj=deep_present("mm_tattoo",this_player());
    if (gobj) gobj->SetFlyingHands();
  }
  return 1;
*/
  return 0;
}

//*************
// cost command
//*************
// better place them into a npc
int cmd_cost(string str) {
  return 0;
}

public void create()
{
  ::create();
  SetIntShort("Trainer's room");
  SetIntLong(
    "You are standing in the room of Magictcs - our skilltrainer.\n"
    "An old papyrus is hanging on a wall.\n"
    "To the west is the room of the Lords.\n");

  AddDetail("west",
    "To the west is the room of the Lords - the room of the HLPs.\n");
  AddDetail(({"room of the lords","room of lords"}),
    "It is to the west.\n");

  /* details */
  AddDetail(({"wall","one wall"}),
    "It is made of brown paper. An old papyrus is hanging on it.\n");
  AddDetail("walls",
    "All walls are made of the same old brown paper. One wall is a little\n"
    "bit more interesting.\n");
  AddDetail(({"paper","brown paper","old paper","old brown paper"}),
    "All walls consist of this paper (as each house in japan).\n");
  AddDetail(({"papyrus","old papyrus","very old papyrus"}),
    "An very old papyrus - but it is still readable.\n");
  AddReadMsg(({"papyrus","old papyrus","very old papyrus"}),
    "You can train your skills here.\n");

  SetIndoors(1);

  AddExit("west",MONKROOM("hlproom"));
  AddExit("south",MONKROOM("statstrain"));
  AddExit("north",MONKROOM("library"));
//  AddItem(MONSTER("joern/oldelf"), REFRESH_HOME);
  AddRoomCmd("train","cmd_train");
  AddRoomCmd("cost","cmd_cost");
}

//**************************
// entering and leaving room
//**************************
// forbid entering for non Madmonks
allow_enter(int method, mixed extra) {
  if (!interactive(PO)) return ME_OK;   // all non player (npc,items,...)
  if (IS_IMMORTAL(PO)) return ME_OK;     // wizzes allowed
  if (PO->QueryGuild()==GC_MADMONKS)
    return ME_OK;                       // madmonks allowed
  return ME_NO_ENTER;                   // forbid all others
}

