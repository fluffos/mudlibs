#include <std.h>

inherit OBJECT;

object dest;

int do_enter(string str);

void create() {
  ::create();
  set_id( ({ "portal" }) );
  set_name("portal");
  set_short("A glowing portal");
  set_long("The portal swirls with color and sound.");
  set_prevent_get("The portal is insubstancial.");
}

void init() {
  ::init();
  add_action("do_enter", "enter");
}

void set_destination(object d) { dest = d; }

int do_enter(string str) {
  object tp = this_player();
  object env = environment(tp);

  if (!str || present(str, env) != this_object())
    return notify_fail("Enter what?");

  message("info", "You enter the portal.\n"
    "%^BOLD%^%^GREEN%^Swirling, twisting forces pull you "
    "through to the other side.%^RESET%^", tp);

  tp->move_player(dest, "into the portal");

  if (random(100+tp->query_stats("wisdom")) < 25)
    tp->set_paralyzed(2+random(3), "The vertigo disorients you for a moment.");

  return 1;
}
