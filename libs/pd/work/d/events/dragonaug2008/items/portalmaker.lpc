#include <std.h>
#include <dragonevent.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("wand");
  set_id( ({ "wand", "glowing wand", "bone wand", "driftwood wand" }) );
  set_short("a glowing wand");
  set_long("This wand is made of twisted driftwood with a rounded tip of bone. "
    "It glows slightly.");
  set_weight(2);
}

void init() {
  ::init();
  add_action("open_portal_entrance", ({ "wave", "zap", "use" }));
}

int open_portal_entrance(string str) {
  if (!str || present(str, this_player()) != this_object() )
    return notify_fail(capitalize(query_verb())+" what?\n");

  if(!environment(this_player())->open_ogre_portal())
    return notify_fail("You try to "+query_verb()+" the wand, but nothing happens.\n");

  //function should only get this far if a portal was
  //never created before and a player just created
  //the portal in the right room

  this_player()->add_exp(10000);
  message("info", "%^BOLD%^You feel more experienced.", this_player());
  return 1;
}
