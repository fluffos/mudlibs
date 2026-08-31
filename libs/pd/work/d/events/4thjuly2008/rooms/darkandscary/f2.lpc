#include <std.h>
#include <id4.h>
inherit ROOM;

mapping stones = ([
  "gold" : "%^YELLOW%^",
  "silver" : "%^BOLD%^",
  "black" : "%^BOLD%^%^BLACK%^",
  "bronze" : "%^ORANGE%^",
  "turquoise" : "%^CYAN%^",
]);
string *have = ({ "turquoise", "silver", "black", "bronze" });

void touch_stone(string);

void create() {
::create();
set_properties( ([ "no teleport" : 1, "light" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("a dark alcove");
set_long("This alcove houses a rock ledge with four glowing stones. The walls "
"are black rock, and the floor is very uneven.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
"stones" : "The stones are colored "+list(have)+". You feel the need to <touch> one.",
]));
set_touch(have, (: touch_stone :) );
set_exits(([
"east" : ROOMS "/darkandscary/final",
]));
}

void touch_stone(string what) {
  object tp = this_player();
  object env = environment(tp);
  object *tmp;
  object cage;

  if (tp->query_busy()) return;

  tp->set_disable(1);

  message("info", "You touch the "+stones[what]+what+"%^RESET%^ stone.", tp);
  message("info", tp->query_cap_name()+" touches the "+stones[what]+what+
    "%^RESET%^ stone.", env, tp);

  message("info", "Nothing happens.", env);
  return;

  if (random(100) > 25)
    message("info", "Nothing happens.", env);
  else
    message("info", "A buzzing sound can be heard in the main cavern.", env);

  tmp = children(ITEMS+"cage");
  tmp = filter(tmp, (: environment($1) :) );
  cage = tmp[0];
  if (!cage) return;

  if (random(1000) < 4)
	cage->set_ok(1);
  else
	cage->set_ok(0);
}

