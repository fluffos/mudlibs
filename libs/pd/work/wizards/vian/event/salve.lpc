#include <std.h>
inherit OBJECT;
int used;

void create() {
  ::create();
  set_name("a vial of dragon healing salve");
  set_id( ({ "salve" }) );
  set_short("a vial of dragon healing salve");
  set_long("This is a vial of dragon healing salve made through alchemy.  It
can be applied on dragon eggs to re-fertilize and heal them.");
  used = 0;
}

void init() {
  ::init();
  add_action("cmd_apply", "apply");
}

int cmd_apply(string str) {
  object tp = this_player();
  object env = environment(tp);
  object egg;
  string what;

  if (!str)
    return notify_fail("Apply what?");

  if (sscanf(str, "salve to %s", what) != 1)
    return notify_fail("Apply the salve to what?");

  if (used)
    return notify_fail("The salve is all used up.");

  egg = present(what, env);

  if (!egg)
    return notify_fail("You do not see that here.");

  if (!egg->id("arlon_event_egg_corrupted")) {
    string who;
    if (egg->is_living())
      who = egg->query_cap_name();
    else
      who = definite_article(egg->query_name());
    message("info", "You rub a little salve on "+who+
      ", but nothing happens.", tp);
    message("info", tp->query_cap_name()+" rubs a little salve on "+who+
      ", but nothing happens.", env, tp);
  }
  else {
    message("info",
      "You rub a little salve on the egg.\n"
      "It miraculously heals!", tp);
    message("info",
      tp->query_cap_name()+" rubs a little salve on the egg.\n"
      "It miraculously heals!", env, tp);
    egg->remove();
    egg = new("/wizards/vian/event/healed_egg");
    egg->set_property("keep", tp->query_name());
    egg->move(env);
    used = 1;
  }

  return 1;
}
