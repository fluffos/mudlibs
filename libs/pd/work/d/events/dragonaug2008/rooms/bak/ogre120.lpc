#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_properties( (["no attack" : 1, "no steal" : 1, "indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("A small cavern");
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


