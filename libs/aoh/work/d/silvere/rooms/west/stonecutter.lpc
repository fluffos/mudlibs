// A stonecutter's workshop
// created:      Xxxx       [24-Apr-99]

#include <silvere.h>
#include <properties.h>
#include <macros.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <nightday.h>

inherit BASEROOM;

varargs void create()
{
   ::create();

   Set(P_INDOORS, 1);

   SetIntShort("A stonecutter's workshop");

   SetIntLong(
     "Fine white dust clings to every flat surface. Numerous footsprints "
     "track in and out and across the floor in every direction. On the "
     "walls hang the implements of the stonecutter's trade: hammers, "
     "chisels, odd-looking tools with sharp edges and hooked points. "
     "@@TimeMsg@@\n");


   AddDetail( ({ "skylight", "skylights" }),
     "Smallish squares of glass set into the roof between the rafters allow "
     "a bit of light into the workshop during the day.\n");

   Set(P_TIME_MSG,
   ([
     DAY_DEFAULT_MSG:
       "Shafts of muted light speckled with dust motes pierce the dim "
       "interior with pools of brightness.",

     NIGHT_DEFAULT_MSG:
       "Pools of moonlight dot the dark and silent workshop."
    ]) );


   SetIntSmell("The chalky stone dust makes you sneeze.\n");
   AddExit("south", SIL_WEST("westroad3"));
}


