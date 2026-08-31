#include <std.h>
#include <dragonevent.h>

inherit VAULT;

int check_event_door_opens();
int deny_door_close();

void create() {
    ::create();
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
    set_long("%^BOLD%^%^BLACK%^A crystalline light system seems to be, for the most part, absent from this room.  A faint concentration of %^RESET%^%^ORANGE%^gold flickering dust %^BOLD%^%^BLACK%^can be seen fluttering from the cracks in the ceiling to the floor, %^RESET%^%^ORANGE%^lighting %^BOLD%^%^BLACK%^up a tolerable path through the cave.  A bat screeches and winds through cracks in the ceiling, bouncing back and forth on the cave walls as a symphony of sound.  Sitting side by side is a couple of boulders covered in %^YELLOW%^glittering gold%^BLACK%^.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "south" : DRAG_ROOMS "ogre156", "north" : DRAG_ROOMS "ogre75", "east" : DRAG_ROOMS "ogre87" ]) );

    cover_exit_with_door("north", "Ogre King Event's Door");
    if(!(DRAG_D->query_data("denyEntranceToPillarRoomViaDoor")))
      set_closed("Ogre King Event's Door", 0);
    else
      set_closed("Ogre King Event's Door", 1);
    set_door_func("Ogre King Event's Door", "open", (: check_event_door_opens :) );
    set_door_func("Ogre King Event's Door", "close", (: deny_door_close :) );
//  set_door_msg("Ogre King Event's Door", "open", "%^CYAN%^A voice booms in your head:%^RESET%^ My tasks are completed. I will open for you. Proceed with caution.\nThe door slowly rumbles open and lodges itself against the cavern wall.");
    set_door_msg("Ogre King Event's Door", "open", "%^CYAN%^A voice booms in your head:%^RESET%^ My task is completed. I will open for you. Proceed with caution.\nThe door slowly rumbles open and lodges itself against the cavern wall.");
    set_door_env_msg("Ogre King Event's Door", "open", "The large door rumbles open, lodging itself against the cavern wall.");
}

int check_event_door_opens() {
  if(DRAG_D->query_data("canProveCourage")) {
    write("%^CYAN%^A voice booms in your head:%^RESET%^ You mortals are all the same. I will have nothing to do with your kind and will not open for you. Prove to me that you're not like the rest of them. Go to the northern end of this cave and retrieve an important object. You'll know it when you see it.");
    return 0;
  }
//  if(DRAG_D->query_data("canKillOgreKing")) {
//    write("%^CYAN%^A voice booms in your head:%^RESET%^ You mortals have proven your spirits and your strength to me. I have a task for you. Kill the ogre king in his throne room to the east. Then, and only then, will I open for you.");
//    return 0;
//  }
  return 1;
}

int deny_door_close() {
  write("The door will not budge.");
  return 0;
}

void reset() {
    object ob;
    ::reset();
    if (!present("ogre6", this_object()))
	new(DRAG_MOBS "ogre6")->move(this_object());
    if (!present("ogre3", this_object()))
	new(DRAG_MOBS "ogre3")->move(this_object());

  if(!present("microphone")) {
    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
}
