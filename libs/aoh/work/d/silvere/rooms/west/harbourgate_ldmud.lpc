// The gate of the city, leading in from the harbour to the west
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
//                Auryn    [11-May-1999]  description, details


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

int enter_harbour()
{

   write("You pass through the city gate and enter the harbour of Silvere.\n");
   say(CAP(({string})TP->QueryName())+" leaves the city through the harbour gate.\n");
   TP->move(SIL_HARBOUR("entrance"),M_GO,"west");
   return 1;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"City gates");
   Set(P_INT_LONG,
"You are standing beneath the gate which leads from the harbour to the "
"city of Silvere. The city wall is several meters thick and in excellent "
"repair. Two guards are always on duty here, making sure that no undesireable "
"individuals enter the city. The wide road passing through the archway is "
"paved with flagstones. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" WEST: to the harbour.\n\
 EAST: into the city.\n");

Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG:"You can see ships arriving and departing in the "
"harbour west of you, while to the east, you see people milling around "
    "on the city's main boulevard.",
      NIGHT_DEFAULT_MSG:"It is night. The harbour is devoid of activity, "
    "and the city's main road east of you is empty.",
      ND_SUNSET:"The sun is setting, transforming the water "
    "of the harbour into a pool of liquid gold. On the city's main "
    "boulevard east of you, the shops are closing.",
      ND_DAWN:
        "As the first hints of dawn begin to appear in the sky, you can "
    "see ships leaving the harbour west of you. The city's main street to "
    "the east is still deserted.",
      ND_SUNRISE:
        "As the sun rises, the harbour is already buzzing with activity. "
    "In the city itself, however, you can just see the first people emerging "
    "from their houses."
   ]) );


AddDetail("gate","This is the gate which leads from the harbour to the city "
	  "proper. A heavy portcullis and a massive oak portal can be closed "
	  "to seal the archway on either side.\n");

AddVItem(
	 ([ P_IDS:({"portcullis"}),
	 P_ADS:({"heavy","iron","massive"}),
	 P_LONG:
	 "A massive iron portcullis can be lowered to close off the eastern "
	 "end of the archway. It is currently open, but can probably be "
	 "closed quickly, should this become necessary.\n"
	  ]) );

AddVItem(
	 ([ P_IDS:({"portal","door","doors"}),
	 P_ADS: ({"massive","oak","double","large"}),
	 P_LONG:
	 "Large double doors built from solid oak and reinforced with iron "
	 "bands are set into the archway's eastern end. They can be closed "
	 "to prevent entrance into the city from the harbour.\n"
	  ]) );

AddDetail("archway","The archway is formed by the city wall, through which "
	  "the road leads here from the harbour into the city itself.\n");

AddVItem(
	 ([ P_IDS:({"bands"}),
	 P_ADS:({"iron","wrought-iron"}),
	 P_LONG:
	 "The portal is reinforced with wrought-iron bands which have been "
	 "bolted to the wood.\n"
	  ]) );

AddVItem(
	 ([ P_IDS:({"wood","oak"}),
	 P_ADS:({"solid","massive","old"}),
	 P_LONG:
	 "The double doors west of you have been built from solid oak. The "
	 "wood has darkened over the years and is almost coal black now. "
	 "The constant wind coming from the sea has added a salty patina "
	 "to its surface. However, the gate is kept in good repair and "
	 "does not look easily breachable.\n"
	  ]) );

AddVItem(
	 ([ P_IDS:({"patina","crust","salt"}),
	 P_ADS: ({"salty"}),
	 P_LONG:
	 "A thin crust of salt covers the surface of the portal.\n"
	  ]) );


AddDetail("harbour","The harbour is west of you. You can't see very much "
	  "of it from here.\n");

AddDetail( ({"city","silvere","city proper"}),
	   "The city is east of you. From here, you can just make out the "
	   "beginning of its main boulevard.\n");

AddVItem(
	 ([ P_IDS:({"boulevard","street","Westway"}),
	 P_ADS:({"main"}),
	 P_LONG:
	 "To the east starts Westway, Silvere's main business street. Along "
	 "this boulevard, many shops can be found offering just about "
	 "anything you might be looking for (and probably a good number "
	 "of things you weren't actually seeking.)\n"
	  ]) );

AddDetail("shops","You can't see them from here.\n");

AddVItem(
	 ([ P_IDS:({"road"}),
	 P_ADS:({"paved"}),
	 P_LONG:
	 "A road paved with flagstones leads through the gate.\n"
	  ]) );

AddDetail("flagstones","The road is paves with large flagstones, which "
	  "have been carefully swept clean.\n");

AddDetail( ({"wall","city wall"}),"The wall surrounding Silvere was clearly "
"built for defensive rather than ornamental purpose. It is several feet "
"thick and rises high above you. Guards are patrolling on top of it, and two "
"more are always on duty at the gate.\n");

AddDetail("guards",
	  "Guards are patrolling on the wall and watching the gate.\n");

AddDetail("ships","The ships are anchored in the harbour. Go there if "
	  "you want to have a closer look at them.\n");

AddDetail("people","Here at the gate, you just see the two guards.\n");

   Set(P_INT_MAP,"silvere1");
   Set(P_COORDINATES, ({ ({ -190,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into the walls. The guards give you a curious "
       "look.\n");
   AddExit("west",#'enter_harbour /*'*/);
   AddExit("east",SIL_WEST("westroad1"));
}

