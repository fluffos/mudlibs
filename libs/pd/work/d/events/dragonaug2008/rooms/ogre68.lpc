#include <std.h>
#include <dragonevent.h>
inherit ROOM;

int counter = -1;

string *scenes = ({
  "The magical blast recedes back into a glowing black gem, held by an ogre.",
  "The ogre grins toothily at you.",
  "The ogre waves the gem around in a circle.",
  "%^BOLD%^%^BLACK%^A glowing portal appears.%^RESET%^",
  "The glow from the gem ebbs away, leaving it dull black in the ogre's hand.",
  "The ogre looks at the gem and scratches his head.",
  "The ogre leaps through the portal.",
  "%^BOLD%^%^BLACK%^The portal expands momentarily, making some mountains and the ogre visible.%^RESET%^",
  "%^BOLD%^%^BLACK%^The portal suddenly closes with a loud sucking sound.%^RESET%^",
});

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
    set_long("%^BOLD%^%^BLACK%^The ceiling in this stretch of rock creeps down to the ground, barely presenting a passage out.  Without a second glance, this could be a dead end.  Rodents scurry between the opening, squeaking back and forth.  The %^WHITE%^white crystals %^BLACK%^seem to be in a less concentrated state toward the opening.  %^WHITE%^Light %^BLACK%^invades the room through numerous holes in the slanting ceiling.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northwest" : DRAG_ROOMS "ogre56" ]) );
}

void init() {
  object tp = this_player();
  object ogre;
  ::init();
  if (DRAG_D->query_data("canloadgemogre") == 1 && !sizeof(children(DRAG_MOBS+"gemogre"))) {
    DRAG_D->set_data("canloadgemogre", 2);
    ogre = load_object(DRAG_MOBS+"gemogre");
    ogre->set_paralyzed(sizeof(scenes)*4 + 2);
    ogre->move(this_object());
    set_heart_beat(2);
    counter = 0;
    tp->set_paralyzed(sizeof(scenes)*4 + 6, "The magic holds you!");
    message("magic", "%^YELLOW%^"
      "You are paralyzed by a sudden %^BOLD%^%^BLACK%^blast%^YELLOW%^ of magic!\n\n%^RESET%^", tp);
  }
}

int receive_objects(object ob) {
  if (query_heart_beat() && counter != -1 && ob && ob->is_player()) {
    message("magic", "%^BOLD%^%^BLACK%^A barrier prevents you from entering.%^RESET%^", ob);
    return 0;
  }
  return 1;
}

void heart_beat() {
  if (counter >= sizeof(scenes)) {
    object ob;
    set_heart_beat(0);
    if (ob = present("gem ogre", this_object()))
      ob->go_to_random_room();
    return;
  }

  message("info", scenes[counter], this_object());
  counter++;
}
