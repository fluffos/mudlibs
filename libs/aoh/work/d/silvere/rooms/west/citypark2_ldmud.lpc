// This road leads to the citypark
// created:       Sonic    [30-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
//                Auryn    [01-May-1999]  description, details


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Park Lane");
   Set(P_INT_WIZMSG,
" NORTH: Back to the mainroad.\n\
 SOUTH: The road continues to the citypark, another newbie area\n");

   Set(P_INT_LONG,
"You are still strolling along Park Lane, which runs parallel "
"to the city wall. The chipped cobblestones under your feet and the "
"peeling paint on the houses' fronts are obvious signs of the lacking "
"wealth of the local residents. @@TimeMsg@@ You can follow the street "
"north towards Westway, or go south to the city park.\n");

   AddDetail( ({"street","lane","park lane"}),
	      "The street is paved with dirty cobblestones, and the houses "
	      "around you have seen better days, too.\n");

   AddDetail( ({"wall","city wall"}),
	      "The city's defensive wall rises to the west of you.\n");

   AddVItem(
	    ([P_IDS:({"stones","cobblestones"}),
	    P_ADS:({"dirty","chipped","cracked"}),
	    P_LONG:
	    "The stones are cracked and caked with dirt.\n"
	    ]) );

   AddDetail("dirt","Nobody seems to sweep the street here.\n");

   AddVItem(
	    ([P_IDS:({"paint"}),
	    P_ADS:({"faded","peeling"}),
	    P_LONG:
	    "The paint that used to adorn the houses' fronts has faded "
	    "with time. It is peeling off in many places, revealing the"
	    "bare bricks beneath.\n"
	     ]) );
   AddVItem(
	    ([P_IDS:({"brick","bricks"}),
	    P_ADS:({"bare"}),
	    P_LONG:
	    "The houses are built from bricks which are visible in places "
	    "beneath the peeling paint.\n"
	    ]) );

   AddDetail( ({"houses","house","fronts"}),
	      "While the houses along this street don't look exactly "
	      "run-down, they have definitely seen better days. The paint "
	      "is peeling off in many places, and dirt accumulates in "
	      "almost every corner.\n");

   AddDetail("westway","You can't see it from here. It's far off to "
	     "the north.\n");

   AddDetail( ({"park","city park"}),
	      "You can see the entrance to the park south of you.\n");

   AddDetail("children","You see some children playing on the street.\n");

   AddDetail("women","Some women are standing in one of the doors, having "
	     "a chat.\n");


   Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG:"Around you, people are going after their daily "
"business. Children are playing, and some women are standing together in "
"one of the doors, chatting.",
      NIGHT_DEFAULT_MSG:"It is night, and there is nobody to be seen on "
"the street.",
      ND_SUNSET:"As the sun is setting, you see people returning to their "
"homes after the day's work.",
      ND_DAWN:
        "The street is still empty, although in the houses around you "
"people are beginning to stir.",
      ND_SUNRISE:
        "As the sun rises, people start emerging from the houses."
   ]) );


   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -180,40,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("north",SIL_WEST("citypark1"));
   AddExit("south",SIL_WEST("cityenter"));
}
