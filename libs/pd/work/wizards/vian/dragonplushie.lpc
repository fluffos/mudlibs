#include <std.h>
inherit OBJECT;

void create() {
  ::create();
  set_name("dragon plushie");
  set_short("a %^BLUE%^%^BOLD%^blue %^RESET%^dragon plushie");
  set_long("This plushie is in the form of a baby blue dragon.  He looks very <snuggle>able.");
  set_id(({ "plushie", "dragon plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("smack", "snuggle");

}

int smack(string str) {
  object tp = this_player();
  string mymsg, roommsg, allmsg;
  int x;

  if (!str || present(str, tp) != this_object())
    return notify_fail("Snuggle what?\n");

  mymsg = "You snuggle the small dragon plushie.\n";
  roommsg = tp->query_cap_name()+" snuggles "+tp->query_possessive()+
            " small dragon plushie.\n";
allmsg = "%^BOLD%^%^BLUE%^Dragon plushie says: %^RESET%^";

  switch (random(3)) {

    case 0:
      allmsg += "I'd let you be me, but then what would I be?";
    break;

    case 1:
      allmsg += "RAWR!";
    break;

    case 2:
      allmsg = "The plushie breathes out a little puff of smoke.";
    break;

  }

  message("my_action", mymsg, tp);
  message("other_action", roommsg, environment(tp), tp);
  if (sizeof(allmsg))
    message("action", allmsg, environment(tp));

  return 1;
}

int query_auto_load() { return 1; }

