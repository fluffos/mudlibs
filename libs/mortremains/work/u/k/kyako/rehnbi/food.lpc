#include <mudlib.h>
inherit OBJECT ;
void create() {
set ("id", ({ "food" }));
set("short", "FOOD, Yummy!!");
set("long", @ppp
There is not much to say about food is there?
ppp
);
set("material_type", "organic");
set("value", "100");
set("name", "Yummy Delicious food");
}

void init() {
  add_action("eat", "eat");
}

int eat (string str) {
  if (str != "food") {
    write("Eat what?\n");
    return 1;
  } else {
    write("Mmmmm.....Yummy!\n");
    say(TPN+" eats the food and enjoys it immensly.\n");
    TP -> set("hit_points", 20);
    ::remove();
    return 1;
  }
  return 0;
}
