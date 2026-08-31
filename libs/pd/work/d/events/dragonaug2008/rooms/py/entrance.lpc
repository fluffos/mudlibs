#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
  set_short("Ogre Caves");
  set_long("%^BOLD%^%^BLACK%^The cave gets %^WHITE%^narrower%^BLACK%^, and twists to the north into a %^RESET%^%^RED%^much darker%^BLACK%^%^BOLD%^ area. To the north, the cave walls seem to shimmer and shake, as if %^RESET%^%^GREEN%^reality itself%^BLACK%^%^BOLD%^ is about to be torn asunder. The %^WHITE%^crystals%^BLACK%^ that are ever present in the cave to the west seem to disappear, leaving only nondescript walls behind. A faint %^RESET%^%^ORANGE%^orange glow%^BOLD%^%^BLACK%^ can be seen stretching across the tunnel entrance to the north.%^RESET%^");
  set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
  set_listen("default", "Dripping water can be heard throughout the area.");
  set_exits( ([
    "west" : DRAG_ROOMS"ogre15",
    "north" : DRAG_ROOMS"py/daroqscave",
   ]) );
  add_pre_exit_function("north", "enter_cave_of_courage");
}

int enter_cave_of_courage() {
  object nextRoom;
  if(!this_player()->is_player()) return 0;
  if(!DRAG_D->query_data("canProveCourage")) { return 1; }
  load_object(DRAG_ROOMS"instance_d")->destruct_group_instance_pairing(this_player()->query_name(), "Event Test Of Courage Instance");
  this_player()->dismount_all("You seem to have become separated from your riders.", "You seem to have become separated from your mount.");
  this_player()->move_player(DRAG_ROOMS"py/1", query_verb());
  return 0;
}

void init() {
  ::init();
  add_action("do_peer", "peer");
}

int do_peer(string str) {
  if(str == "north" || str == "n") {
    write("As you try to peer north, the orange portal becomes opaque and blocks your view.");
    return 1;
  }
  return 0;
}

void reset() {
  object ob;
  ::reset();
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
