// Room layout. Southeastern tower
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

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Entrance to the southeastern tower");
   Set(P_INT_LONG,
    "There's little light in here and most of it comes from the torches "
    "hanging from the torch-holders set in the wall and the little light "
    "that seeps from the arrow slits that dot the walls. The room is quite "
    "high and two doors lead out, one to the eastern battlement and the "
    "other one to the southern battlement. There's also a staircase leading "
    "up to the top of the tower and down to the tower lower level.\n");

   Set(P_INT_WIZMSG,
    " South: SW Corner of SE tower, level 2.\n"
    " East:  NE Corner of SE tower, level 2.\n"
    " North: Enter the eastern battlement.\n"
    " West:  Enter the southern battlement.\n"
    " Up:    Top of the SE tower, level 3.\n"
    " Down:  Bottom of the SE tower, level 1.\n");

   AddDetail( ({"floor","ground"}),
    "The floor is made of stone slabs and quite clean. The stones are "
    "chipped at some places.\n");

   AddDetail( ({"wall","walls"}),
    "Made of stone, they look strong and solid without cracks. They are "
    "darkened where the torch-holders hold the torches. Next to you, two "
    "doorways pierce the walls as do some arrow slits on the walls a bit "
    "further south and west.\n");

   AddDetail( ({"ceiling"}),
    "Big wooden beams hold the stone ceiling.\n.");

   AddDetail( ({"torch-holders","holders"}),
    "Beautifully crafted from iron, they are set into the wall, holding "
    "the torches that give light to the tower.\n");

   AddDetail( ({"torch","torches"}),
    "The torches are the only light source here, their flickering light "
    "creates shadows in the room.\n");

   AddDetail( ({"slit","slits","arrow slit","arrow slits"}),
    "The arrow slits are too far away from where you stand to allow "
    "you to peek outside.\n");

   AddDetail( ({"door","doors"}),
    "The doors looks quite sturdy, made of oak and bound with metal straps, "
    "an iron bar can be used to block the doors.\n");

   AddDetail( ({"shadow","shadows"}),
    "Shadows play around the room, created by the flickering light of the "
    "torches.\n");

   AddDetail( ({"stairs","staircase"}),
    "A narrow staircase opens before you, leading upwards to the top of "
    "the tower and downwards to the tower base.\n");

   AddDetail( ({"doorway","doorways"}),
    "The doorways narrow and "
    ".\n");

   SetIntSmell("It smells of smoke and sweat are quite strong here.\n");

   Set(P_INT_MAP,"fortress");
   Set(P_REGION,REGION_CITY);
//   Set(P_COORDINATES, ({ ({ -50,20,0 }), C_SILVERE }) );


   Set(P_NOWAY_MSG,
    "You run into a wall, must be the lack of light.\n");

   AddExit("north",  SIL_FORTRESS("eabat8"));
   AddExit("south",  SIL_FORTRESS("seto23"));
   AddExit("east",   SIL_FORTRESS("seto22"));
   AddExit("west",   SIL_FORTRESS("sobat6"));
   AddExit("up",     SIL_FORTRESS("seto31"));
   AddExit("down",   SIL_FORTRESS("seto11"));

}