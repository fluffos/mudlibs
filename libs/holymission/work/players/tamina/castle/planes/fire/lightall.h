#include "/players/tamina/defs.h"

light_all()
{
  object everything;
  int i;

  if (!present("can_light", TP))   return;

  write("Some of the items you are carrying catch fire from the heat!\n");
  say("Some of "+TPN+"'s possesions catch fire from the heat.\n");

  everything = all_inventory(this_player());
    for (i=0; i < sizeof(everything); i++)
    if (everything[i]->id("can_light"))
      everything[i]->out(1);
}
