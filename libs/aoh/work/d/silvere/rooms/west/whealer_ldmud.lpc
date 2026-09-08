// This is the house of the healer.
// created:          Sonic [08-Jun-1997]
// last changed:     Sonic [01-Jul-1997] Added regions/coordinates
//                   Tune  [ sometime  ] Details
//                   Tune  [09-Oct-1997] Drink soup, details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <stdrooms.h>
#include <health.h>
#include <macros.h>

inherit HEALER;

string sign;

int leave_healer(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"building")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"healer")!=-1)
   {
      write("You leave the house of the healer.\n");
      TP->move(SIL_WEST("whealer1"),M_GO,"south");
      return 1;
   }
}

varargs void create()
{
   ::create();
   seteuid(getuid());

   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"The house of the healer");
   Set(P_INT_LONG,
    "This is the house of one of the local healers. A sign on the "
    "wall explains her terms and prices. Bunches of dried herbs hang "
    "in the windows, and long shelves contain glass cannisters, "
    "jars, bottles and vials. In the center of the room is a table "
    "with several chairs pulled up to it. A brick hearth spans the "
    "far wall, and a strange-smelling mixture bubbles in the pot "
    "hanging from the trivet over the fire.\n");

   SetIntSmell(
    "A pungent, odd odor wafts up from the bubbling mixture over "
    "the fire and mingles with the spicy aroma of dried herbs.\n");


   Set(P_INT_WIZMSG,
    "The exit is to the south. Or simply leave the building.\n");

   SetHealer(NPC("westhealer"));

   AddDetail(({"cannisters","glass cannisters"}),
    "Large glass cannisters are lined up neatly on the shelves, "
    "each one labeled on the front in spidery handwriting.\n");

   AddDetail(({"herbs","dried herbs"}),
    "The herbs hang in bunches, stems up. All colors of green, "
    "some with pods, some gnarled and twisted, a few in yellowish "
    "shades.\n");

   AddDetail(({"roots", "curled roots"}),
    "Some of the cannisters contain creepy-looking roots in "
    "various sickly shades of brown and yellow.\n");

   AddDetail("labels",
    ({
    "Exotic names, written in a spidery, even hand with brown ink.\n",
    "You read names such as wallow log, yarroch root, clapsute, "
    "blamwort, clocksaw and yellow dog jaw, just to name a few.\n"
   }) );

   AddDetail("table",
    "Just a simple table, strewn with the instruments of the healer's "
    "craft: a stone mortar and pestle, a small brass scale, "
    "strips of linen, a jar of vinegar, a few small bowls, and "
    "a strainer.\n");

   AddDetail("strainer",
    "Most likely for making tea from dried herbs.\n");

   AddDetail("pestle",
    "A smallish, club-shaped stone tool which the healer uses to"
    " crush dried herbs.\n");

   AddDetail("mortar",
    "A stone bowl in which the healer crushes dried herbs with "
    "her pestle.\n");

   AddDetail("shelves",
    "Long neat rows of glass cannisters filled with oddly colored "
    "powders, twisted, gnarled roots and dried herbs, glass bottles "
    "and vials of oils, linaments and ointments, and jars of creams "
    "and liquids.\n");

  AddDetail("trivet",
    "A simple iron contruction of 3 legs and an arm, set amongst"
    "the red-hot glowing coals in the hearth.\n");

   AddVItem(
    ([  P_IDS : ({ "hearth", "fireplace" }),
	P_ADS: ({ "brick" }),
	P_LONG :
         "The simple brick hearth is devoid of decoration.\n"
     ]) );

   AddVItem(
    ([  P_IDS : ({ "soup", "stew", "mixture", "brew" }),
        P_ADS : ({ "strange", "smelly", "strange-smelling", "bubbling" }),
        P_SMELL : "The foul mixture reeks strongly, not at all unlike "
                  "damp cellars and \nrotten fruit.\n",
        P_LONG :  "The bubbling mixture is rather difficult to identify..."
                  "perhaps it's old tea which Brianna forgot to remove "
                  "from the fire, or maybe some nasty potion she's "
                  "concocting today.\n",
        P_NOISE : "...slurpp, bubble, bubble..."
    ]) );

   sign =
 "  -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
 " |            Brianna's Herbal Shoppe and Healing Practice             |\n"
 " |\\                   ~ open morning to night ~                       /|\n"
 " | \\_________________________________________________________________/ |\n"
 " |         I can treat your wounds:                                    |\n"
 " |         ....light wounds                [" +
     calc_cost(HEAL_COST(LIGHT_WOUNDS))+" copper]                |\n"
 " |         ....serious wounds              [" +
     calc_cost(HEAL_COST(SERIOUS_WOUNDS))+" copper]                |\n"
 " |         ....critical wounds             [" +
     calc_cost(HEAL_COST(CRITICAL_WOUNDS))+" copper]                |\n"
 " |                                                                     |\n"
 " |         I can also cure poisoning and treat diseases.               |\n"
 " |                                                                     |\n"
 " |     If you want some general information about your health,         |\n"
 " |     ask me. If you know of a certain disease you might have,        |\n"
 " |     you can ask me and I may be able to tell you about it.          |\n"
 " |     ___________________________________________________________     |\n"
 " |          ++ Payment expected in Full and in Advance ++              |\n"
 " |           Member Apothecaries' and Alchemists' Guild                |\n"
 "  -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n" ;

 AddVItem(
  ([  P_IDS: "sign",
      P_LONG: sign,
      P_READ_MSG: sign
  ]) );

   SetTreatMsg(
    "The healer shakes her head at you...\n");

   AddRoomCmd("leave",#'leave_healer /*'*/);
   AddRoomCmd("drink", "cmd_drink");
   AddRoomCmd("taste", "cmd_drink");

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -180,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("south",SIL_WEST("whealer1"));

}


// TODO - a little more interesting..

int cmd_drink(string str)
{
  mixed arr;
  object ob;

  if(!str)
  {
    notify_fail("What would you like to do?\n");
    return 0;
  }

  arr = norm_id(str, 1);
  if(!pointerp(arr))  arr = ({ arr });

  // the logic here is that the object of the command should always
  // be the last word. Not perfect, but what is?

  if(-1 == member( ({"mixture","soup", "tea", "brew"}), arr[sizeof(arr)-1] ) )
  {
    notify_fail("Do you see that here?\n", NOTIFY_NOT_VALID);
    return 0;
  }

  write("Hmmm....that tasted...a little strange...\n\n"
        "        ...and your head feels a bit funny, now...\n\n"
        "   ...a little fuzzy, maybe...\n\n");

  ob = clone_object(OBJ("strange_mixture"));
  ob->move(this_player(), M_SILENT);
  ob->start_babbling();

  return 1;
}
