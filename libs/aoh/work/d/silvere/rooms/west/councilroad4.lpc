// A broad road, that leads to the Council Hall.
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates
//                Auryn    [20-Jun-1999]  description, details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

int enter_council(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"hall")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You enter the Council Hall.\n");
      TP->move(SIL_WEST("councilenter"),M_GO,"east");
      return 1;
   }
   return 0;
}


string CheckTree()

{
   switch(({int})NIGHTDAY->QuerySeason())
   {
      case WINTER: return
	"The branches are bare and covered with snow.\n";
         break;
      case SPRING: return
	"Pale green buds show on the branches, and between them myriads "
	"of tiny pink blossoms bloom.\n";
         break;
      case SUMMER: return
	"Large, dark green leaves grow on the branches, rustling gently in "
	"the light breeze.\n";
         break;
      case AUTUMN: return
	"The leaves have turned golden yellow and orange, making the branches "
	"appear like they had been coated with gold.\n";
	break;
   }
   return 0;
}

string CheckBuds()
{
  switch(({int})NIGHTDAY->QuerySeason())
    {
    case WINTER: return
		   "There are no buds showing yet.\n";
    break;
    case SPRING: return
		   "They are pale green, hiding the leaves inside.\n";
    break;
    default: return
	       "There are no buds, just leaves.\n";
    }
    return "There are no buds, just leaves.\n";
}

string CheckLeaves()
{
 switch(({int})NIGHTDAY->QuerySeason())
    {
    case SUMMER: return
		   "The leaves are dark green and heart-shaped.\n";
    break;
    case AUTUMN: return
		   "The leaves seem to glow in fiery colours: golden yellow, "
		   "orange and red.\n";
    break;
    default: return
	       "There are no leaves on the tree at this time of the year.\n";
    }
    return "There are no leaves on the tree at this time of the year.\n";
}


string CheckSnow()
{
  if (({int})NIGHTDAY->QuerySeason()==WINTER)
    return "Snow covers the branches.\n";
  else return "There is no snow here.\n";
}

string CheckBlossoms()
{
  if (({int})NIGHTDAY->QuerySeason()==SPRING)
    return "Tiny pink blossoms cover the branches of the tree. Unfortunately, "
      "they are not within your reach.\n";
  else return "There are no blossoms here at this time of the year.\n";
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Elrimand Road, just outside the council hall");
   Set(P_INT_LONG,
"The street ends here in front of the large building housing the council "
"hall. Right in the centre of the small square in front of the entrance is "
"an enormous tree. Its branches extend like a roof almost over the entire "
"square. Behind the thick trunk, you can make out the large double doors "
"leading into the hall.\n"
);


   Set(P_INT_WIZMSG,
" EAST: (or ENTER) the council hall.\n\
 WEST: To the main road\n");

AddDetail("tree","The tree is really large. It is said that it has been "
"planted by Elrimand himself centuries ago, and looking at the massive "
"trunk you are inclined to believe it. Legend has it that as long as "
"the tree is healthy, Silvere too will flourish. Looking at the branches "
"swaying gently in the wind you assume that everything must indeed be "
"fine in the city.\n");

AddDetail("branches",SF(CheckTree));

AddDetail("leaves",SF(CheckLeaves));

AddDetail("buds",SF(CheckBuds));

AddVItem(
	 ([ P_IDS: ({"blossoms"}),
	 P_ADS: ({"tiny","pink"}),
	 P_LONG: SF(CheckBlossoms)
	  ]) );

AddDetail("snow",SF(CheckSnow));

AddDetail("trunk","The tree's trunk is so thick it probably takes several "
"men to span it. This tree has clearly been here for centuries, and looking "
"as healthy as it does, probably will still be here centuries from now.\n");

AddDetail("square","The street widens here to form a small square in front "
"of the council hall. In the centre of the square a large tree is growing.\n");

AddDetail("street","Elrimand Road ends here in front of the council hall.\n");

AddVItem(
	 ([ P_IDS: ({"building","hall","council hall"}),
	 P_ADS: ({"large","white","marble"}),
	 P_LONG: "A large white marble building houses the hall of the city "
	 "council. It was built by Elrimand, the founder of Silvere, but "
	 "doesn't look like it's centuries old. Though plain and unadorned, "
	 "the building looks very elegant, the fine white marble used for "
	 "building it being all the decoration it needs.\n"
	  ]) );

AddDetail( ({"doors","double doors"}),
"The large wooden doors of the council hall usually stand wide open, inviting "
"the citizens to enter.\n");

AddDetail("marble","Only the finest white marble has been used for the "
"building. It gleams like snow in the light of the sun and moon.\n");

   AddRoomCmd("enter",#'enter_council /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_COORDINATES, ({ ({ -100,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("east",  SIL_WEST("councilenter"));
   AddExit("west",  SIL_WEST("councilroad3"));
}
