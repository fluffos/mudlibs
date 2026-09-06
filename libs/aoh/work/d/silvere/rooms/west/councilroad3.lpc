// A broad road, that leads to the Council Hall.
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
//                Auryn    [20-Jun-1999]  description, details

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
   Set(P_INT_SHORT,"Elrimand Road. A statue is standing here");
   Set(P_INT_LONG,
"The street splits here to lead around a large statue. A low hedge has "
"been planted around the statue, preventing anyone from approaching closely.\n"
       );

   Set(P_INT_WIZMSG,
" EAST: To the council hall.\n\
 WEST: To the main road\n");

AddDetail("street","You are on Elrimand Road, leading from Westway to the "
"council hall.\n");

AddVItem(
	 ([ P_IDS: ({"statue"}),
	 P_ADS: ({"large","marble"}),
	 P_LONG: "The marble statue shows a middle-aged man in chainmail. "
	 "He is wielding a broadsword and wearing a crown. A cloak flows "
	 "down from his shoulders, semingly moved by a strong breeze. At "
	 "the base of the statue, you notice a small sign.\n"
	  ]) );

AddDetail("base","There is a sign at the base of the statue.\n");

AddDetail("man","The statue shows a regal looking man wearing a crown.\n");

AddDetail("chainmail","The chainmail has been sculpted so precisely you can "
	"make out every single link.\n");

AddDetail( ({"link","links"}),"Every link of the chainmail has been precisely sculpted.\n");

AddDetail( ({"sword","broadsword"}), "The statue is wielding a heavy broadsword.\n");

AddDetail("crown","The crown of Silvere, still worn by the city's ruler today.\n");

AddDetail("cloak","The statue4s cloak seems to be moved by the wind.\n");

AddVItem(
	 ([ P_IDS: ({"sign"}),
	 P_ADS: ({"small","polished","brass"}),
	 P_LONG: "A small, polished brass sign is mounted at the base of "
	 "the statue. You may read it.\n",
	 P_READ_MSG: "'Elrimand, founder of Silvere.'\n"
]) );

AddDetail( ({"hedge","low hedge"}),
	   "A low hedge of evergreen bushes has been planted around the "
	   "statue.\n");

AddDetail( ({"bushes","evergreen bushes"}),
	   "The bushes have small round leaves which are green even during "
	   "winter. They are perfectly trimmed and look quite healthy.\n");

AddDetail("leaves","The leaves of the evergreen bushes are rather small, "
	  "round and quite hard. As the plant's name suggests, they are "
	  "always green.\n");

   Set(P_INT_SMELL,"You smell a faint odour of salt coming from the ocean.\n");
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -110,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("east",  SIL_WEST("councilroad4"));
   AddExit("west",  SIL_WEST("councilroad2"));
}
