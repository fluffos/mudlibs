#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_properties( (["no attack" : 1, "no steal" : 1, "indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("A small cavern");
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
    set_long("%^BOLD%^%^WHITE%^"
      "This is a small cavern with a wide domed ceiling that looks like the inside of a geode. "
      "A few small stones litter the ground. An oddly bright light fills the room."
      "%^RESET%^");

    set_listen("default", "A soft buzzing sound echoes quietly.");
    set_exits( ([ "west" : DRAG_ROOMS "ogre119", "southwest" : DRAG_ROOMS "ogre131", "south" : DRAG_ROOMS "ogre132", "southeast" : DRAG_ROOMS "ogre133", "east" : DRAG_ROOMS "ogre121", "northeast" : DRAG_ROOMS "ogre109", "north" : DRAG_ROOMS "ogre108", "northwest" : DRAG_ROOMS "ogre107" ]) );
}

void reset() {
  object ob, ogre;
  ::reset();
  if (!present("dragon prison"))
    new(DRAG_ITEMS+"dragon_prison")->move(this_object());

  if (DRAG_D->query_data("canloadgemogre") == 2 && !sizeof(children(DRAG_MOBS+"gemogre"))) {
    ogre = load_object(DRAG_MOBS+"gemogre");
    ogre->go_to_random_room();
  }

  if (!sizeof(children(DRAG_MOBS+"guidedragon"))) {
    ob = load_object(DRAG_MOBS+"guidedragon");
    switch (ob->query_speech()) {
/*
      case 0: ob->move(DRAG_ROOMS+"summit"); break;
      case 1: ob->move(DRAG_ROOMS+"ogrebeach"); break;
      case 2: ob->move(this_object()); break;
      case 3: ob->move(DRAG_ROOMS+"dragnorth37"); break;
*/
      case 1: ob->move(DRAG_ROOMS+"summit"); break;
      case 2: ob->move(DRAG_ROOMS+"ogrebeach"); break;
      case 3: ob->move(this_object()); break;
      default: ob->move(DRAG_ROOMS+"dragnorth37"); break;
    }
  }

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


