// The entrance to the city park.
// created:       Sonic    [30-May-1997]
// last changed:  Sonic    [01-Jul-1997] Added region/coordinates
//                Auryn    [03-May-1999] description, details


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

int leave_city(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"city")!=-1)
   {
      write("You leave the city and enter the park.\n");
      TP->move(SIL_PARK("parkenter"),M_GO,"south");
      return 1;
   }
   return 0;
}

int enter_park(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"park")!=-1)
   {
      write("You enter the citypark.\n");
      TP->move(SIL_PARK("parkenter"),M_GO,"south");
      return 1;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Citypark entrance");
   Set(P_INT_WIZMSG,
" NORTH: Back to the mainroad.\n\
 SOUTH: (or ENTER PARK | LEAVE CITY): enter the newbiepark.\n");

   Set(P_INT_LONG,
"Park Lane ends here in front of a large gate which leads into the city "
"park. The high wall surrounding Silvere runs parallel to the street. The "
"houses here are rather small and plain and show signs of neglect. You "
"can go south to enter the park, or follow Park Lane north farther into "
"the city.\n" );

   AddDetail( ({"street","lane","park lane"}),
	      "The street is paved with cobblestones and quite dirty. It "
	      "is bordered by the city wall on the western and some houses "
	      "on the eastern side. It leads north into the city and south "
	      "through a large gate into the park.\n");

   AddDetail( ({"stones","cobblestones","pavement"}),
	      "Cobblestones were used to pave the street once. By now they "
	      "are cracked and covered with dirt.\n");

AddDetail("dirt","There is a lot of dirt here. The people who live here "
	     "are too busy trying to survive to bother with trivialities "
	     "like sweeping the street.\n");

   AddDetail(({"crack","cracks"}),"The pavement is in bad disrepair.\n");

   AddVItem(
	    ([ P_IDS: ({"wall","city wall"}),
	    P_ADS: ({"high"}),
	    P_LONG:
	    "The city wall runs parallel to the street here, forming its "
	    "western border. It is very high, and unlike the street and "
	    "houses here it looks very massive and appears to be in good "
	    "repair. Guards are patrolling on top of it.\n"
	     ]) );

   AddDetail("guards","They are patrolling on the city wall.\n");

   AddVItem(
	    ([P_IDS: ({"houses","buildings","house"}),
	    P_ADS: ({"small","plain","neglected","drab"}),
	    P_LONG:
	    "The buildings are obviously the living quarters of the poorer "
	    "part of Silvere's populace. While not exactly a slum, this area "
	    "seems to be inhabited by people who are too busy earning enough "
	    "money to survive, without having anything left to spend on "
	    "niceties like fresh paint.\n"
	     ]) );

   AddDetail( ({"signs","signs of neglect"}),
	      "Paint is peeling from the walls, the occasional broken "
	      "window here and there hasn't been replaced... while none "
	      "of the houses actually seems to be on the verge of "
	      "collapsing, there is definitely room for improvements.\n");

   AddDetail( ({"window","windows"}),
	      "Some of the windows are broken. They haven't been replaced, "
	      "as glass is quite expensive, but covered with cloth "
	      "instead.\n");

   AddDetail("cloth","Here and there, a window is broken and has been "
	     "covered with cloth. The owners probably couldn't afford "
	     "to have the glass replaced.\n");


AddDetail( ({"glass","panes"}),
	      "The panes of one or two windows are broken.\n");

   AddVItem(
	    ([P_IDS: ({"gate","archway"}),
	    P_ADS: ({"large"}),
	    P_LONG:
	    "The gate leading into the city park was built from large "
	    "blocks of reddish sandstone and decorated with reliefs. Its "
       "massive double doors are usually open, allowing free passage "
	    "into and out of the park. The archway is really quite "
	    "beautiful and looks a bit out of place among the drab houses.\n"
	     ]) );

   AddDetail( ({"relief","reliefs"}),
	      "The archway has been decorated with very lifelike reliefs "
	      "depicting flowers and birds. Their beauty forms a stark "
	      "contrast to this somewhat run-down neighbourhood.\n");

   AddVItem(
	    ([ P_IDS:({"door","doors"}),
	    P_ADS: ({"massive","wooden","double","large"}),
	    P_LONG:
	    "The large double doors look very massive. However, they appear "
	    "not to have been closed for years - the hinges are quite rusty, "
	    "and you doubt that the gate could be closed in a hurry, should "
	    "this become necessary.\n"
	     ]) );

   AddDetail("hinges","The gate's hinges are rusty, as if the doors hadn't "
	     "been moved in years.\n");

   AddDetail("flowers","The only flowers you can see here are the reliefs "
	     "on the archway. However, not two of them look the same, and "
	     "each is shown in great detail.\n");

   AddDetail("birds","While you can hear birds' voices from the park, the "
	     "only birds you can actually see are the ones depicted on the "
	     "archway. Every single one is different from the others, and "
	     "they have been chiseled from the stone so carefully that you "
	     "can make out every single feather - which quite surprising, "
	     "as the gate seems to be quite old and sandstone isn't "
	     "exactly known for its enduring qualities.\n");

   AddDetail( ({"feather","feathers","plumage"}),
	      "The reliefs are so lifelike that you can make out every "
	      "single feather of the birds' plumage.\n");

   AddVItem(
	    ([ P_IDS: ({"sandstone","blocks","stone"}),
	    P_ADS: ({"reddish","large"}),
	    P_LONG:
	    "The archway was built from sandstone and has been lovingly "
	    "decorated.\n"
	     ]) );



   AddRoomCmd("enter",#'enter_park /*'*/);
   AddRoomCmd("leave",#'leave_city /*'*/);

   Set(P_INT_NOISE,"You hear birds singing in the park.\n");
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -180,50,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");

   AddExit("north",SIL_WEST("citypark2"));
   AddExit("south",SIL_PARK("parkenter"));
}
