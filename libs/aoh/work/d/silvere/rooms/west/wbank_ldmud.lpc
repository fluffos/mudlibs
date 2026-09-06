// This is the bank of silvere
// created:          Sonic [01-Aug-1997]
// last changed:     Tune  [26-Apr-1999]

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <macros.h>
#include <money.h>

inherit BASEROOM;

int leave_bank(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"building")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"bank")!=-1)
   {
      write("You leave the bank of Silvere.\n");
      TP->move(SIL_WEST("wpostroad2"),M_GO,"west");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"The bank of Silvere");
   Set(P_INT_LONG,
     "The fine decor and polished wooden panelling definitely exudes "
     "a sense of wealth and refined taste. The merchants "
     "and wealthy born of Silvere have entrusted their funds to the "
     "Counting House of Aberfynne for centuries, having the utmost "
     "faith in their financial abilities. \n"
     "\n"
     "A small but discreet sign directs potential clients to the "
     "New Accounts window, located in the ante-room to the east. "
     "(A not so small and far less discreet guard directs "
     "potential troublemakers and the more unsavory "
     "breeds ((being mostly orcs and trolls)) to the "
     "nearest exit.) Existing customers should proceed directly to "
     "the transactions window."
     "\n");

   SetIntNoise("Subdued murmuring from the junior clerks at the back of the "
      "bank are all that disturb the general hush.\n");

   Set(P_INT_WIZMSG,
" West: (or Leave Bank) back to the road.\n");

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -130,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall. That hurt.\n");

   AddExit("west",SIL_WEST("wpostroad2"));

   AddItem("/d/silvere/obj/bank/teller", REFRESH_REMOVE);
}

