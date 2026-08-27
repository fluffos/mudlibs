/* source file -- Guildmaster's Chambers */
#include "path.h"

inherit "/std/room";

void setup()
{
  set_short("Guildmaster's Chambers");
  set_long("The elegance of this room belies the nature of its owner.  "+
    "Two chairs stand beside a fine table in front of an unusual "+
    "fireplace.  At the other side of the room, a bowl-shaped bed is "+
    "cowled by heavy black drapes.  In the center of the room, a bubbling "+
    "pool of steaming water fills the air with mist.  Upon one wall, a "+
    "large map of the outlying realms hangs opposite a large "+
    "portrait and a large mirror.  Most of the floor is covered with "+
    "opulent rugs.\n");
  set_light(70);
  set_zone("private");

  add_item( ({ "chairs", "chair" }),
    "The two beautiful chairs are made of polished wood and "+
    "cusioned with black leather seats.\n");
  add_item( "fireplace",
    "The fireplace is fashioned into the likeness of a yawning "+
    "dragon.  The crackling fire burns as fiery breath in his "+
    "throat.\n");
  add_item("table",
    "The table between the two chairs short, circular, and made "+
    "of sparkling crystal.  Portions of it appear to be hollow "+
    "and filled with a dark amorphous quicksilver.");
  add_item( ({"pool", "spa", "bath"}),
    "The pool is filled with warm spring water which bubles and "+
    "swirls continually.  It is only about two feet deep.\n");
  add_item( ({"bed", "bowl"}),
    "The dish-shaped bed is loaded with satin pillows and "+
    "silk sheets.  A sleeper would easily sink into its molding "+
    "embrace.  Beneath it is a large chest.\n");
  add_item( "chest", "The chest is locked and very heavy.\n");
  add_item( ({"drapes", "curtains"}),
    "The drapes are made of velvet and adorned with chaotic "+
    "patterns of dark indigo and visages of brilliant blue "+
    "on a background of black sheen.\n");
  add_item( "mirror", "The full-length mirror is framed with "+
    "twisting golden ropes.\n");
  add_item( ({"rug", "rugs" }), "The rugs arold but still "+
    "colorful and detailed.  The craftmanship looks like "+
    "appears to be from local weavers.\n");
  add_item("painting",
    "This painting represents the very paragon of darksome "+
    "thieves in action.  Needless, to say it has probably "+
    "changed ownership in that very fashion many times.  "+
    "Still, the sight of kingdoms falling into "+
    "the domain of it's nemesis can be very . . . motivating.\n");
  add_item("map", 
    "The map is very large and is very detailed.  The scale is so "+
    "large, though, that it doesn't cover a great area.\n");

  add_exit("north", ROOM + "office", "door");
}

