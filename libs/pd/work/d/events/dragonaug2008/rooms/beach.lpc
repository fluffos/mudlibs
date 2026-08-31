#include <std.h>
#include <dragonevent.h>

inherit BEACH;

void check_entrance();

int toggle = -1;
string daylong =
  "An underutilized, weathered beach filled with brambles and branches. The beach is bumpy and uneven, overgrown with vines and thorny scrubs. There is nothing but wide open water to the northwest, the beach is a bit less than half a circle, with rocky mountain cliffs cutting off access to the bulk of the land to the northeast and the south. The skyline is blocked by large mountain jags in all directions but that which leads out to sea."
;
string nightlong =
  "An underutilized, weathered beach overgrown with rough and thorny foliage. Light is cast unevenly across the sand, with shadows pooling behind large bumps in the ground and underneath the overgrowth. Jagged mountain ridges pierce the night sky in all directions but to the northwest, where the ocean water glints in the night sky."
;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "beach" : 1, "coords" : ({ 135, 15, 0 }) ]));
  set_short("a beach");
  set_items( ([
    "beach" : "A sandy beach. It appears weathered and unused, there are bumps in the sand and brambles and branches scattered across it.",
    ({ "vines", "scrubs", "brambles", "branches" }) : "They litter the beach, adding the the overall feel of it being unused and uncared for.",
    ({ "ocean", "sea" }) : "You can see it flow gently onto the beach, washing a few stray items onto the sand here and there.",
    "sand" : "It litters the beach.",
    "mountain" : "The mountain consists of many tall peaks, with tall ridges interconnecting them. It stands tall with the bulk of its mass towards the south and the southeast.", 
    ({"fragments", "fragment"}) : "Two large mountain peaks with jut up into the air to the east. The path winds inbetween them.",
    ({"jag", "jags"}) : "Mountain peaks that shoot up into the sky.",
    ({ "bumps", "bump" })  : "The sandy shore is weathered and uneven, leaving behind fairly large bumps in the sand.",
    ({ "shadows", "shadow" }) : "Shadows are artifacts of poor lighting. These are too dark to see into, and obscure the content within.",
    "overgrowth" : "It consists of long vines and extensive branches that crawl across the beach.",
  ]) );
  set_listen("default", "You can hear the tide gently ebbing and flowing against the beach.");
  set_smell("default", "A thin salt spray from the ocean hangs in the air.");
  set_letter("m");
  check_entrance();
}

void init() {
  ::init();
  check_entrance();
}

void check_entrance() {
  int ok = DRAG_D->query_data("eventstarted") || DRAG_D->query_data("eventfinished");
  if (DRAG_D->query_data("testing")) ok = 0;
  if (toggle == -1) toggle = !ok;
  if (!toggle && ok) {
    toggle = !toggle;
    set_day_long(daylong+" The beach cuts a path inbetween two large mountain fragments winding to the southeast.");
    set_night_long(nightlong+" The dark beach yawns and stretches into a moderately sized path to the southeast which splays below two mountain fragments which cast heavy shadows upon it.");
    set_item("path", "A path begins to form to the southeast. It consists almost entirely of beach, and seems to lead up into the mountain.");
    add_exit(DRAG_ROOMS+"dragnorth01", "southeast");
    if (!sizeof(children(DRAG_MOBS+"dragon_swim1")))
      new(DRAG_MOBS+"dragon_swim1")->move(this_object());
  }
  else if (toggle && !ok) {
    toggle = !toggle;
    set_day_long(daylong);
    set_night_long(nightlong);
    remove_exit("southeast");
    remove_item("path");
  }
}
