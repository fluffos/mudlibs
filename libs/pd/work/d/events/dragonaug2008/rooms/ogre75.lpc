#include <std.h>
#include <dragonevent.h>

inherit VAULT;

int deny_door_close();
int check_event_door_opens();

void create() {
    ::create();
    set_no_clean(1);
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_items(([ "crystals" : "Natural formations that are translucent and multifaceted.",
    "shadows" : "They spread out from every rock and crevice.",
    ({"water","pool"}) : "Water that drips and collects in the cave.",
    "stalagmites" : "Sharp extensions of rock that stick up from the ground.",
    "stalactites" : "Sharp outcroppings of rock that hang from the ceiling.",
    "dust" : "Sparkling gold colored dust that lies on the rocks here.",
    "icicles" : "Long, sharp drippings that have slowly frozen into stalactite shape.",
    ({ "insects", "fireflies" }) : "They flit around.",
    ({ "rodents", "bats" }) : "They squeak and get out of sight as quickly as possible.",
    "rocks" : "Many small bits of rock that lie around the cave floor.",
    "wood" : "Charred completely black.",
    "sparkles" : "Whitish sparkling bits of rock.",
    "skeleton" : "It is unidentifiable.",
  ]));
    set_long("%^BOLD%^%^BLACK%^Shadows dance off the cave walls as if moving to a slow internal beat.  Although the darkness slinks into the corners of the area, small %^WHITE%^white crystals %^BLACK%^peek out from the crevices, allowing the cavern to be magically %^WHITE%^lit%^BLACK%^.  Tiny droplets of %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^trickle down the maze of %^WHITE%^crystals %^BLACK%^toward a little %^BLUE%^pool %^BLACK%^on the rock floor.  The %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^sings a soft song against the ground, providing more rhythm for the dancing shadows.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "south" : DRAG_ROOMS "ogre86", "southwest" : DRAG_ROOMS "ogre85", "northwest" : DRAG_ROOMS "ogre63" ]) );

  foreach (string ex in query_exits()-({"south"}))
    cover_exit_with_door(ex, DRAG_GEM_DOOR_ID);
  set_closed(DRAG_GEM_DOOR_ID, 0);
  set_door_name(DRAG_GEM_DOOR_ID, "magical barrier");
  set_door_func(DRAG_GEM_DOOR_ID, "enter",
    (: write("%^YELLOW%^The magical barrier stops you from leaving.%^RESET%^") :), "active");

    cover_exit_with_door("south", "Ogre King Event's Door");
    if(!(DRAG_D->query_data("denyEntranceToPillarRoomViaDoor")))
      set_closed("Ogre King Event's Door", 0);
    else
      set_closed("Ogre King Event's Door", 1);
   //no players should ever be on this side of the door when it is closed, but just in case..
    set_door_func("Ogre King Event's Door", "open", (: check_event_door_opens :) );
    set_door_func("Ogre King Event's Door", "close", (: deny_door_close :) );
}

int check_event_door_opens() {
  write("As you reach for the door, you fall through it and find yourself on the other side.");
  this_player()->move_player(DRAG_ROOMS"ogre86", "through the door");
  return 0;
}

int deny_door_close() {
  write("The door will not budge.");
  return 0;
}

void reset() {
  object ob;
  ::reset();
  if (!present("carved pillar")) {
    ob = new(DRAG_ITEMS+"pillar");
    ob->move(this_object());
    ob->set_color("red");
  }
}
