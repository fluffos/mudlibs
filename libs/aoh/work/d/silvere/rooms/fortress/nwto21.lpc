// Room layout. Northwestern tower
// created:       Isorn    [22-Jul-2001]
// changed:       Isorn    [24-Jul-2001] Added Nigh/Day thanks to Sonic
//

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit SILBASEROOM;

string QueryIntNoise()
{
  string *tmp;

  tmp = ({
   "A guard's shout can be heard from outside.\n",
   "Faintly from below, snores can he heard.\n",
   "The chapel bell rings in the distance.\n",
   });

  return random_select(tmp);
}

string CheckSlit()
{
   string desc;

   desc=
    "The arrow slits are narrow and tall letting in a bit of wind from "
    "outside. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
          "It is dark outside and you can see nothing at all.\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
          "There's little light outside, allowing you to get a  "
          "dim view of the fields below.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
          "It's day outside of the tower. Some light shines through "
          "the arrow slits and helps illuminate the tower. Peeking "
          "outside you take a glance of the fields that surround the "
          "fortress.\n";
         break;
      default:
         desc+=
          "There is something outside of the tower, but "
          "you can't clearly define it.\n";
         break;
   }
   return desc;
}

string CheckFields()
{
   string desc;

   desc=
    "Looking out the arrow slits ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
          "into the dark of the night you don't seem to be able to "
          "discern anything.\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
         desc+=
          "to the west the fields are still shrouded in darkness but "
          "the first rays of the sun illuminate the green shadow over "
          "the hills in the distance. To the north, the first light "
          "of the day crawl across the fields.\n";
         break;
      case ND_TWILIGHT..ND_EVENING:
         desc+=
          "to the north the shadows grow longer in the diminishing "
          "light of the day while to the west the last light of the "
          "day shines over the fields and the green shadow that "
          "marks the edge of the forest, crowning the rolling "
          "hills far away into the distance.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
          "to the north you can see fields stretching as far as the "
          "eye can see, while looking west you can see fields and a "
          "green shadow crowning the rolling hills, marking the edge "
          "of the forest far into the distance.\n";
         break;
      default:
         desc+=
          "There is something outside of the tower, but "
          "you can't clearly define it.\n";
         break;
   }
   return desc;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Northwestern corner of the northwestern tower");
   Set(P_INT_LONG,
    "There's little light in here and most of it comes from the torches "
    "hanging from the torch-holders set in the wall and the little light "
    "that seeps from the arrow slits that dot the walls. There's a barrel "
    "filled with arrows next to the wall. A bit to the southeast lies a "
    "staircase that blocks the view of the tower entrance.\n");

   Set(P_INT_WIZMSG,
    " South: SW Corner of NW tower, level 2.\n"
    " East:  NE Corner of NW tower, level 2.\n");

   AddDetail( ({"floor","ground"}),
    "The floor is made of stone slabs and quite clean. The stones are "
    "chipped at some places.\n");

   AddDetail( ({"wall","walls"}),
    "Made of stone, they look strong and solid without cracks. They are "
    "darkened where the torch-holders hold the torches. A bit to the "
    "southeast the staircase blocks the sight of the doorway while "
    "around you there are several arrow slits.\n");

   AddDetail( ({"ceiling"}),
    "Big wooden beams hold the stone ceiling.\n.");

   AddDetail( ({"torch-holders","holders"}),
    "Beautifully crafted from iron, they are set into the wall, holding "
    "the torches that give light to the tower.\n");

   AddDetail( ({"torch","torches"}),
    "The torches are the only light source here, their flickering light "
    "creates shadows in the room.\n");

   AddDetail( ({"shadow","shadows"}),
    "Shadows play around the room, created by the flickering light of the "
    "torches.\n");

   AddDetail( ({"slit","slits","arrow slit","arrow slits"}),#'CheckSlit /*'*/);

   AddDetail( ({"field","fields"}),#'CheckFields /*'*/);

   AddDetail( ({"door","doors"}),
    "The doors can't be seen clearly from here as the staircase blocks almost "
    "all the sight to them and the entrances.\n");

   AddDetail( ({"stairs","staircase"}),
    "A narrow staircase opens a bit to the southeast, it looks like it leads "
    "up and down.\n");

   AddDetail( ({"barrel"}),
    "It's a big barrel, filled with arrows for its use when the fortress "
    "is besieged.\n");

   SetIntSmell("It smells of smoke and sweat are quite strong here, mixed "
    "with the smell of plants the wind blows into the room.\n");

   Set(P_INT_MAP,"fortress");
   Set(P_REGION,REGION_CITY);
//   Set(P_COORDINATES, ({ ({ -50,20,0 }), C_SILVERE }) );


   Set(P_NOWAY_MSG,
    "You run into a wall, must be the lack of light.\n");

   AddExit("south",  SIL_FORTRESS("nwto23"));
   AddExit("east",   SIL_FORTRESS("nwto22"));

}