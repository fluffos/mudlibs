// part of the Madmonks Guild
// made MagicTCS - 8 may 97
// it is the room for training your stats!

// TODO: adding guildexp and guildlevel

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
  string lower;
  if (!TP) return 0;
  if (!MAINGUILD->is_member(getuid(TP))) {
    notify_fail("You are not a member of this guild!\n");
    return 0;
  }
  if (!str) { notify_fail("Train what?\n"); return 0; }
  lower=lower_case(str);
  if (member(({"level","dex","con","str","int"}),lower) != -1) {
    write("Balgarion stomps in coming from an evil trip and says to you:\n"
          "You want to train your "+lower+" - ahh let me see.\n");
    ret=MAINGUILD->cmd_advance(str);
    if (ret==1) {
      write("Balgarion smiles and then he stomps out east.\n");
    } else {
      write("Oh sorry - check your costs first - you can't train your "+
            lower+" yet!\n");
    }
  }
  return 1;
}

//*************
// cost command
//*************
// better place them into a npc
int cmd_cost(string str) {
  if (!TP) return 0;
  if (str) { notify_fail("Use a simple 'cost' without any arguments.\n");
             return 0; }
  if (!MAINGUILD->is_member(getuid(TP))) {
    notify_fail("You are not a member of this guild!\n");
    return 0;
  }
  write("Balgarion stomps in coming from an evil trip and says to you:\n");
  MAINGUILD->PrintAdvanceCosts(TP);
  write("Then he stomps out east.\n");
  return 1;
}

public void create()
{
  ::create();
  SetIntShort("Trainer's room");
  SetIntLong(
    "You are standing in the room of our main-trainer. He is absent in the\n"
    "moment, but you can 'train' your level and your stats here.\n"
    "An old papyrus is hanging on a wall.\n");

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
    "You can train your level and your stats here.\n"
    "Use: 'cost' will print the costs needed for your next level...\n"
    "     'train level' for advancing your current level (if possible)\n"
    "     'train str'   for training your str\n"
    "     'train dex'   for training your dex\n"
    "     'train int'   for training your int\n"
    "     'train con'   for training your con\n" );

  SetIndoors(1);

  AddExit("east",MONKROOM("madmonks"));
  AddExit("west",MONKROOM("restroom"));
  AddExit("south",MONKROOM("restaurant"));
  AddExit("north",MONKROOM("skilltrain"));
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

