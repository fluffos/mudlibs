
#include <std.h>
#include <saahr.h>

inherit ROOM;

void create() {
  ::create();
  set_properties(([
    "light":2,
    "night light":2,
    "indoors":0,
    "town":1
  ]));
  set_short("the center of a small town");
  set_long(
    "A round path circles about a grassy area here. Amidst the grass, "
    "a raised platform sits to mark the center of the town. "
    "Benches and tables for gatherings are scattered around as well. "
    "Tall trees shade the platform and most of the tables. "
  );
  set_items(([
    "path" : "A dirt path. It leads in every direction.",
    ({ "grass", "area" }) : "Thick %^BOLD%^%^GREEN%^grass%^RESET%^ that "
      "covers a large, roughly round area.",
    "platform" : "A basic wooden stage that can hold performers or speakers.",
    ({ "benches", "tables" }) : "Each table has one or two benches "
      "next to it. All are made of a smooth, heavy wood.",
    "trees" : "The trees provide shade during hot times. They are usually "
      "full of big leaves.",
  ]));
  set_exits(([
    "north":VPROOMS"town12_7",
    "northeast":VPROOMS"town13_7",
    "east":VPROOMS"town13_8",
    "southeast":VPROOMS"town13_9",
    "south":VPROOMS"town12_9",
    "southwest":VPROOMS"town11_9",
    "west":VPROOMS"town11_8",
    "northwest":VPROOMS"town11_7"
  ]));
}

void reset() {
  object ob;
  ::reset();
  if (!present("nymph "+(1+random(2)))) {
    for (int i = random(3); i--; i >= 0) {
      ob = new(MOBS+"nymph");
      ob->move(this_object());
    }
    if (ob) {
      ob->set_moving(1);
      ob->set_speed(35);
    }
  }
  if (!present("satyr "+(1+random(2)))) {
    for (int i = random(2); i--; i >= 0) {
      ob = new(MOBS+"satyr");
      ob->move(this_object());
    }
    if (ob) {
      ob->set_moving(1);
      ob->set_speed(25);
    }
  }
}

