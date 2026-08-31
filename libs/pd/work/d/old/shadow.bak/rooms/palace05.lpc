#include <std.h>
#include <shadow.h>
inherit VAULT;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the northern wing of the castle.  The walls here are "
    "cold, undecorated stone.  The fancy candles that adorned previous rooms "
    "have been replaced by crude torches.  The entrance to the dungeon is here, "
    "and is only lightly guarded.  Apparently only very few people have a key.");
  set_smell("default","The smell of something rotting seeps in from the north.");
  set_listen("default","The sound of servants running about echos in from the east.");
  set_items(([({"decorations","wedding decorations"}):"The decorations here are completely gone.",
    "wall":"The exposed stone is bare and cold.",
    "torches":"The torch flickers against the wall.",
    "dungeon":"The dungeon is below the ground of the palace."]));
  set_door("door",ROOMS "dungeon1", "enter", "dungeon key");
  set_exits((["south":ROOMS "palace06","enter":ROOMS "dungeon1"]));
  set_open("door", 0);
  set_locked("door", 1);
}

void reset() {
  ::reset();
  set_open("door", 0);
  set_locked("door", 1);
  get_object(ROOMS"dungeon1")->set_open("door", 0);
  get_object(ROOMS"dungeon1")->set_locked("door", 1);
  if(!present("guard"))
    new(MOB "pguard")->move(this_object());
}
