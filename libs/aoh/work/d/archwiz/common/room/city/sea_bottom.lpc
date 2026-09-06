/* the shell is an item for the collector quest please don't change
   its path or the path of this file without notifying the questdepartment
   AND Cadra */
#include "path.h"
#include <moving.h>

inherit"std/room";

object octopus,chest,shell;

void create() {
        ::create();
        SetIntShort("Sea bottom");
        SetIntLong(
"You are at the bottom of the sea. You can go back up, if you want to.\n");
        AddExit("up", "./sea");
	HideExit("up",1);
  octopus=clone_object("/std/npc");
  octopus->SetLevel(9);
  octopus->SetStr(20); // otherwise he might not carry the chest ...
  octopus->SetName("octopus");
  octopus->SetIds( ({"octopus"}) );
  octopus->SetShort("an octopus");
  octopus->SetLong(
"A very big octopus with long tentacles, reaching for you.\n");
  octopus->SetRace("octopus");
  octopus->SetMaxWeight(200000);
  octopus->InitChats(7, 
      ({"The octopus says: Mumble\n",
        "The octopus says: I will convert you to a pulp!\n" }) );
  octopus->SetAlign(-20);  // neutral
  octopus->SetHands( ({ ({ "huge tentacle",0,15}), ({"small tentacles",0,12}) }) );
  octopus->move(this_object(),M_SILENT);
  chest = clone_object("/obj/chest");
  chest->SetShort("an old heavy chest");
  chest->SetLong(
"This chest looks very old and wet. It is crusted with shells and\n\
there is only rust left of its locks.\n");
  chest->AddId("chest");
  chest->SetAds( ({"heavy","old","crusted"}) );
  chest->SetWeight(30000);
  chest->SetMaxWeight(40000);
  chest->move(octopus,M_SILENT);
  shell = clone_object(OBJ("shell"));
  shell->move(chest,M_NOCHECK);
}

reset() {
  if (!this_object()) {return;}
  if (!octopus) {
  octopus=clone_object("/std/npc");
  octopus->SetLevel(9);
  octopus->SetStr(20); // otherwise he might not carry the chest
  octopus->SetName("octopus");
  octopus->SetIds( ({"octopus"}) );
  octopus->SetShort("an octopus");
  octopus->SetMaxWeight(200000);
  octopus->SetLong(
"A very big octopus with long tentacles, reaching for you.\n");
  octopus->SetRace("octopus");
  octopus->InitChats(7, 
      ({"The octopus says: Mumble\n",
        "The octopus says: I will convert you to a pulp!\n" }) );
  octopus->SetAlign(-20);  // neutral
  octopus->SetHands( ({ ({ "huge tentacle",0,15}), ({"small tentacles",0,12}) }) );
  octopus->move(this_object(),M_NOCHECK);
}

  if (!chest) {
  chest = clone_object("/obj/chest");
  chest->SetShort("an old heavy chest");
  chest->SetLong(
"This chest looks very old and wet. It is crusted with shells and "
"there is only rust left of its locks.\n");
  chest->AddId("chest");
  chest->SetAds( ({"heavy","old","crusted"}) );
  chest->SetWeight(30000);
  chest->SetMaxWeight(40000);
  chest->move(octopus,M_SILENT);
}

  if (present(chest,this_object())) {
  chest->move(octopus,M_SILENT);
 }

  if (!shell) {
  shell = clone_object(OBJ("shell"));
  shell->move(chest,M_SILENT);
}
}
