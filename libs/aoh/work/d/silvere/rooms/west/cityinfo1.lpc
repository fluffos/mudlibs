// This road leads to the room with one of the city elders.
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates
//                Auryn    [26-Apr-1999]  Changed description,
//                                        added details
//                Auryn    [30-Apr-1999]  added time check for business hours


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

int GoEast()
{
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_SUNRISE..ND_SUNSET:
      {
         write("You enter the City Elder Office.\n");
         TP->move(SIL_WEST("cityinfo"),M_GO, "east");
         break;
      }
      default:
         write("The office is closed for the night. Come back after "
               "sunrise.\n");
         break;
   }
   return 1;
}

int enter_office(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str || !TP) return 0;
   if(strstr(lower_case(str),"building")!=-1 ||
      strstr(lower_case(str),"office")!=-1 ||
      strstr(lower_case(str),"house")!=-1)
   {
      GoEast();
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"A street leading south off Westway");
   Set(P_INT_WIZMSG,
" NORTH: Back to the mainroad.\n\
 SOUTH: The road continues to the citypark, another newbie area\n\
 EAST (or ENTER):  to the office of the City Elder.\n");

   Set(P_INT_LONG,
"You are walking down Park Lane, a small street leading from Westway north "
"of you to the city park to the south. The high wall surrounding the city "
"runs parallel to the street. The houses here don't look as luxurious as "
"the ones along Westway, and the street is paved with cobblestones instead "
"of flagstones. Still, everything looks neat, clean and inviting. The "
"house east of you is somewhat larger than the others. A sign next to the "
"door proclaims it the City Elder's office.\n");


   AddVItem(
	 ([ P_IDS: ({ "lane", "street" }),
	 P_ADS: ({ "small", "clean", "neat", "inviting", "paved" }),
	 P_LONG:
	 "Park Lane is narrower than Westway, but every bit as neat and "
	 "clean.\n"
	  ]) );


   AddDetail("westway","Westway is just north of you.\n");


   AddDetail( ({"park","city park"}),"The city park is to the south. "
   "Park Lane leads right to it.\n");


   AddVItem(
	 ([ P_IDS: ({ "wall","city wall" }),
	 P_ADS: ({"high","massive", "defensive"}),
	 P_LONG:
	 "The city wall rises to the west of you. It runs parallel to the "
	 "street. It was built from huge blocks of grey stone and looks "
	 "very massive. Guards are always on patrol on top of it.\n"
	  ]) );


   AddVItem(
	 ([ P_IDS: ({ "blocks", "stone" }),
	 P_ADS: ({ "grey", "huge" }),
	 P_LONG:
	 "Huge blocks of grey stone form the city's defensive wall.\n"
	  ]) );


   AddDetail("houses","Half-timbered houses line the street. They are "
	     "less colourfully decorated than those along Westway, but "
	     "kept clean and in good repair.\n");


   AddDetail( ({"stones", "cobblestones"}), "The street is paved with "
                "cobblestones. It is slightly uneaven, but swept quite "
                "clean.\n");


   AddVItem(
	    ([ P_IDS: ({"house","office","building"}),
	    P_ADS: ({"larger", "large"}),
	    P_LONG:
	    "The house containing the City Elder's office is slightly "
	    "larger than the others. You can enter it and ask for some "
	    "information concerning the city and its sights.\n",
	    ]) );
   AddVItem(
	    ([ P_IDS: ({"door"}),
	    P_ADS: ({"wooden", "painted"}),
	    P_LONG:
	    "The wooden door leading into the office has been painted "
	    "bright blue. A polished brass sign is mounted next to it.\n"
	     ]) );

   AddVItem(
	    ([ P_IDS: ({"sign"}),
	    P_ADS: ({"brass", "polished"}),
	    P_LONG:
	    "A carefully polished brass sign is fixed next to the door. "
	    "You can read it.\n",
	    P_READ_MSG:
	    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	    "                    CITY OF SILVERE                       \n"
            "                   Information Office                     \n"
	    "                Ciaran Hargall, City Elder                \n"
	    "                                                          \n"
	    "            Business Hours: Sunrise to Sunset             \n"
	    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	     ]) );



   AddRoomCmd("enter",#'enter_office /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -180,20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("north",SIL_WEST("westroad1"));
   AddExit("south",SIL_WEST("citypark1"));
   AddExit("east", SF(GoEast));
}
