/* Fakeship for the southern Dock of Silvere Harbour */

// Created by Taurec, 10 Oct. 1997

#include <properties.h>
#include <moving.h>
#include <macros.h>
inherit "/std/thing";

void create()
{
  seteuid(getuid(this_object()));
  ::create();
  SetShort("an old elegant two-masted ship");
  SetLong("This is the \"Cydalus\", a small but proud ship that was in "
          "former days nothing more than a common fisherboat. But "
          "ol'Captain Kelawin did not want to stay fisherman for "
          "the rest of his life, and decided to seek adventures in "
          "traveling the oceans.\n");
  SetNoGet("No really! You somehow can't move the ship and just "
           "put it in your pockets. Strange, isn't it?\n");
  SetSmell("You try to get your nose closer to the ship and almost "
           "fall from the dock into the water.\n");
  SetNoise("The fluttering of sails in the wind, the creaking planks and "
           "the rattling of ropes at the mast create a funny symphony "
           "of noises.\n"); 
  SetValue(333);
  AddId("ship");
  AddAdjective(({"old","two-masted","elegant"}));
}

