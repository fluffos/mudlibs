// Deck of the harbour-ferry
// Created by:    Taurec [20-JAN-1998]

#include <silvere.h>
#include <properties.h>
#include <regions.h>
#include <macros.h>
#include <rooms.h>

inherit BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Onboard the harbourferry");

   Set(P_INT_LONG,
    "You are on board the little harbourferry of Silvere. Sails flutter in "
    "the breeze, wooden planks gnarl and seagulls circle around the ferry "
    "while it makes a little tour through the bay of Silvere.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_OCEAN|REGION_HARBOUR);
}
