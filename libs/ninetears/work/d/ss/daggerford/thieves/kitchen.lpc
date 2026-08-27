/* source file -- Kitchen and Mess Hall */
#include "path.h"

inherit "/std/room";

void setup()
{
  set_short("Mess Hall");
  set_long("Gods and Grace, something smells good!  "+
    "In the center of the room, a few men are enjoying "+
    "a hearty meal around a large dinner table.  "+
    "To one side of the kitchen, a large fireplace is "+
    "blazing and equiped with spits, grills, and hooks. "+
    "Opposite the fireplace, a large trough or cistern "+
    "sticks out from the wall. "+
    "Along the wall between them, rows of shelves are "+
    "stacked with dishes, pots, and pans and "+
    "a large cooking table is right beneath the shelves.  "+
    "Huge slabs of meat and other "+
    "foodstuffs hang from hooks that cover the ceiling.\n");
  set_light(70);
  set_zone("guild");

  add_item( ({"cistern", "trough"}),
    "The cistern is filled with very cold water and "+
    "perishable edibles and ingredients.\n");
  add_item( ({ "stove", "fireplace", "hearth" }),
    "The huge fireplace is about five feet high and eight feet "+
    "wide.  Within it, an assortment of grills and spits harbor a sizzling "+
  "variety of meats and steaming pots of casseroles, soups, stews, "+
  "and many more dishes.\n");
  add_item( ({ "slabs", "meat" }),
    "Most of the slabs of meat comprise game animals such as deer, "+
    "fowl, and wrapped fish.  Some of the larger pieces are beef, pork, "+
    "and a few unrecognizable ones.\n");
  add_item ( ({ "pots", "pans", "dishes", "plates", "bowls" }),
    "The cookware is spread all over the room.  Some of the dirty "+
    "ones lie by a washbasin near the cistern, while most of the "+
    "others are either being used or are on the shelves.\n");
  add_item( ({ "shelves", "shelf" }),
    "The shelves hold all forms of cookware and diningware.\n");

  add_exit("east", ROOM + "hall2", "door");
}
