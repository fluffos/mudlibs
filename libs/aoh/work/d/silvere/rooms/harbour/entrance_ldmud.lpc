// This is the gate from the harbour to the city of Silvere
// created:          Sonic  [26-May-1997]
// last changed:     Sonic  [29-Jun-1997]
//                   Taurec [08-Mar-1998]  added prevent_leave

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit HARBOUR_BASEROOM;

// NPC's that may not leave the harbour are entered in *restricted
// enter (hopefully) unique id here
string *restricted = ({"seastorm","fisherman","dockworker"});

int prevent_leave(mixed dest, int method, mixed extra){
  string *id_arr;
  ::prevent_leave(dest,method,extra);
  id_arr=({string *})PO->QueryIds();
  if ((id_arr) && (extra=="east") && sizeof(id_arr & restricted))
    return ME_NO_LEAVE;
  return 0;
}

int enter_city()
{
   /* Add some guards to the city here. Maybe also a nice
    * description of how you enter the city or sneak behind
    * the guards through the gate or something else...
    */
   TP->move(SIL_WEST("harbourgate"),M_GO,"east");
   return 1;
}

int enter_office()
{

   /* check, if the daystate is something from ND_SUNRISE to
    * ND_SUNSET. The office is opened during that period.
    */
   switch(({int})TO->Query(P_DAY_STATE))
   {
      case ND_SUNRISE..ND_SUNSET:
      {
         TP->move(SIL_HARBOUR("harbourmaster"),M_GO,"north");
         break;
      }
      default:
         write(
            "The office is closed at the moment. Maybe it is a "
            "good idea to come back during day...\n");
         break;
   }
   return 1;
}

string CheckIvy()
{
   switch(({int})NIGHTDAY->QuerySeason())
   {
      case WINTER: return
         "The ivy is brown and without leaves. It doesn't look "
         "interesting.\n";
         break;
      case SPRING: return
         "The ivy is hanging down from the citywall of Silvere. "
         "A few green leaves are showing up, but most of it is "
         "dry and brown. But time will fix that in a short time. "
         "Mother nature is very good at that.\n";
         break;
      case SUMMER: return
         "The ivy is hanging down from the citywall. It is full "
         "of red leaves and looks pretty interesting. It seems "
         "to be strong enough to climb up on it, too.\n";
         break;
      case AUTUMN: return
         "The ivy is hanging down from the citywall, but most of it's "
         "leaves are gone now. It's probably too cold for it during "
         "night. It looks brown and dry, except for a few dry leaves "
         "hanging nearly dead from it.\n";
         break;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"City Gate");
   Set(P_INT_LONG,
      "@@SeasonMsg@@"
      "The road leads from the harbour into the city of Silvere. At "
      "the walls of the city are two buildings. The building to the "
      "north is the office of the harbourmaster and to the south is "
      "the Seaman's Rest. @@TimeMsg@@\n");

   Set(P_SEASON_MSG,
   ([ WINTER: "It is winter at the moment and it's rather cold now. ",
      SPRING: "A fresh breeze brings the smell of a new year and "
              "lots of cold air from the ocean. ",
      SUMMER: "It's summer at the moment and the walls of Silvere "
              "are full of ivy, which grows down from the top. It "
              "looks pretty nice. ",
      AUTUMN: "A cold wind comes from the ocean and makes you "
              "shiver for a moment. It seems the end of the year "
              "is near. ",
   ]) );

   Set(P_INT_WIZMSG,
      " %^BOLD%^*** Sorry, no details yet. ***%^RESET%^\n"
      " North: The office of the harbourmaster.\n"
      " South: The harbour inn.\n"
      " West:  To the harbour quays.\n"
      " East:  The gate of the city.\n");

   Set(P_TIME_MSG,
   ([ DAY_DEFAULT_MSG:"The gates of the city are opened wide.",
      NIGHT_DEFAULT_MSG:"The office of the harbourmaster is closed.",
      ND_SUNRISE:"The office is opened.",
      ND_SUNSET:"The office is closed.",
   ]) );

   /*
    * Add details here *giggle*
    */
   AddVItem(
   ([ P_IDS: ({"ivy"}),
      P_ADS: ({"poison"}),
      P_LONG: SF(CheckIvy),
   ]) );

   Set(P_INT_MAP,"harbour");
   Set(P_COORDINATES, ({ ({ -200,10,0 }), C_SILVERE }) );
   Set(P_REGION, REGION_CITY | REGION_HARBOUR);
   Set(P_NOWAY_MSG,"You run in a wall.\n");
   AddExit("north",  SF(enter_office));
   AddExit("south",SIL_HARBOUR("harbour_inn"));
   AddExit("west", SIL_HARBOUR("street1"));
   AddExit("east",   SF(enter_city));
}
