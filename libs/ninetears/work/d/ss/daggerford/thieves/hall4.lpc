/* source file -- End of Gallery */
#include "path.h"

inherit "/std/room";

void setup()
{
  set_short("Gallery of Rogues");
  set_long("At this end of the gallery, there is only "+
    "another iron-bound door to one side and an archway "+
    "across from it.  Between them, another tapestry "+
    "hangs from the wall.  To each side of the entrances "+
    "two more torches burn intently.\n");
  set_light(70);
  set_zone("guild");

  add_item( ({"arch", "archway"}), "You can see "+
    "absoulely nothing within the arch.  No torch "+
    "will reveal the other side.  Anything that is "+
    "passed through it disappears.\n");
  add_item( "door", "The door is plated with iron "+
    "and has a small sliding embrasure like the "+
    "other doors.  This one, however, has a small "+
    "symbol on it.\n");
  add_item("symbol", "It is the symbol of a black "+
    "mask.\n");
  add_item( ({"torches", "torch"}),
    "They are just like the other torches.\n");
  add_item( "tapestry",
    "The tapestry is a scene involving a large "+
    "group of rogues.  They stand eagerly within "+
    "the darkness and watch the order of the world "+
    "around while instigating and employing their "+
    "own vile plan.  It is entitled 'Judgement "+
    "Day'.\n");

  add_exit("west", ROOM  + "meeting", "door");
  add_exit("east", ROOM +  "office", "door");
  add_exit("north", ROOM + "hall3", "door");
  add_exit("temple", ROOM + "temple",  "door");
  modify_exit("temple", ({ "obvious", 0, "message",
    "N$N evanesces into the shadows.\n" }) );
}

