#include <properties.h>
#include <rooms.h>

inherit "/std/room";

void create() {
  (::create());
  SetIntShort("Hallway of the Magic Dungeons");
  SetIntLong(
"You are in the Hallway of the Magic Dungeons.\n"
"To the north you can enter the example and testing dungeons for tasks "
"related to teleports.\n"
"In this room are all example items and tools that are related to magic.\n");
  AddExit("north","./teleport/t1");
  AddExit("up","./office/office"); 
  SetIntLight(20);
  AddItem("../tools/teleport_tool", REFRESH_REMOVE);
}

