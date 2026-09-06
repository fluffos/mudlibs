/* This is firewood.
** It is a simple thing with some added commands to prepare a fire
** and finally light it.
**
** created: Sonic       [01-May-1999]
** changed:
*/

#include <properties.h>
#include <regions.h>
#include <config.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit "/std/thing";

#define FIREPLACE "/d/silvere/obj/fireplace"

int cmd_build(string str)
{
   notify_fail("Build what?\n", NOTIFY_ILL_ARG);
   if(!str || !TP) return 0;
   if(strstr(LOW(str),"fire")!=-1)
   {
      object place;
      int region, weight;

      region = ({int})environment(TP)->Query(P_REGION);
      if(region&REGION_CITY)
      {
         notify_fail(
            "You can't create a fire here. Go to a pub or an inn, if "
            "you need to rest.\n",
            NOTIFY_NOT_VALID);
         return 0;
      }
      if(region&REGION_RIVER ||
         region&REGION_OCEAN ||
         region&REGION_LAKE ||
         region&REGION_SWAMP)
      {
         notify_fail(
            "That's not possible, the ground is too wet.\n",
            NOTIFY_NOT_VALID);
         return 0;
      }
      if(present("fireplace",environment(TP)))
      {
         notify_fail("There is already a fireplace here.\n",
            NOTIFY_NOT_VALID);
         return 0;
      }
      if(({int})TP->Query(P_INVIS)==0)
         tell_room(environment(TP),
            CAP(NAME(TP))+" searches the ground for a good place "
            "to build a fire. Then "+HESHE(TP)+" cleans a spot "
            "on the ground from litter and puts some of the "
            "firewood into it.\n", ({TP}) );
      write(
         "You search the ground for a good place to build your "
         "fire. Then you clean a spot on the ground from litter "
         "and other stuff lying around and put some of the wood "
         "into it.\n");
      place = clone_object(FIREPLACE);
      place->move(environment(TP), M_SILENT);
      weight = Query(P_WEIGHT);
      if(weight==1000)
      {
         write("You put the last piece of firewood on the fireplace.\n");
         remove();
         return 1;
      }
      Set(P_WEIGHT, weight-1000);
      return 1;
   }
   return 0;
}

int cmd_add(string str)
{
   notify_fail("Add what?\n", NOTIFY_ILL_ARG);
   if(!str || !TP) return 0;
   if(strstr(LOW(str), "wood")!=-1)
   {
      object fp;

      fp = present("fireplace",environment(TP));
      if(fp)
      {
         int weight;

         if(!({int})fp->QueryBurning())
         {
            notify_fail("The fire is not burning.\n",
               NOTIFY_NOT_VALID);
            return 0;
         }
         fp->AddFuel(1000);
         tell_object(TP,"You add some wood to the fire.\n");
         if(!({int})TP->Query(P_INVIS))
            tell_room(environment(TP),
               CAP(NAME(TP))+" adds some wood to the fire.\n",
               ({ TP}) );
         weight = QueryWeight();
         if(weight == 1000)
         {
            tell_object(TP, "This was the last piece of wood.\n");
            remove();
            return 1;
         }
         Set(P_WEIGHT, weight-1000);
         return 1;
      }
   }
   return 0;
}

void init()
{
   (::init());
   add_action("cmd_build", "build");
   add_action("cmd_add",   "add");
}

void create()
{
   (::create());
   seteuid(getuid(TO));
   Set(P_PROPERTIES,
   ([
      P_IDS:   ({"wood","firewood"}),
      P_ADS:   ({"stack","heap"}),
      P_SHORT: "a stack of firewood",
      P_LONG:
         "This is a small stack of firewood. It can be used to "
         "build a small fire.\n",
      P_WEIGHT:10000,
      P_NOSELL:"The shopkeeper refuses to buy this.\n",
      P_HELP_MSG:
         "The firewood can be used to build a small campfire. "
         "Use the following commands for that:\n"
         "\nbuild fire\n"
         "\tclean the ground, build a fireplace and stack the wood\n"
         "\tinto it.\n"
         "add wood [to fireplace]\n"
         "\tadd some wood to the fireplace.\n",
   ]) );
}
