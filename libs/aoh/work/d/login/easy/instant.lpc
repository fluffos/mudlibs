// The Instant Character Creation Option


#include <regions.h>
#include <rooms.h>
#include <properties.h>
#include <moving.h>
#include <stdrooms.h>

#define KNIFE "/d/silvere/obj/weapons/simple_knife"
#define BAG "/obj/bag"


inherit "/std/room";

void do_race_select()
{
   string *races;
   string myRace;

   races = ({string *})RACEMASTER->AllRaceNames()||({});

   myRace = random_select(races);
   races -= ({ "visitor" });

   this_player()->Set(P_RACE, myRace);
   this_player()->SetGhost(0);
   RACEMASTER->InitRace(this_player(), myRace);
   RACEMASTER->EquipPlayer(this_player());

   if(ME_OK != ({int})this_player()->move(STARTROOM, M_GO) )
      this_player()->move("/std/void", M_GO);

}

varargs string MakeExitString(int brief, string *dirs, string kind)
{
  return "";
}

varargs void create()
{
   ::create();
   SetIntShort("The Insta-Creation Room. Just add water.");
   SetIntLong(
     "\nAs you step into the room, an unseen hand quickly draws a grey "
     "burlap sack over your head... you feel rough hands prodding and "
     "poking at you... spinning you around...dizziness...then oddly enough "
     "you get the sensation of salty breezes and squawking gulls "
     " just as the bag is yanked from your head.\n\n");

   SetIndoors(1);
   SetIntLight(50);
   Set(P_REGION, REGION_DREAM);
   Set(P_TEMPERATURE, 20);
}

void init()
{
   ::init();
   call_out("do_race_select", 2);

}
