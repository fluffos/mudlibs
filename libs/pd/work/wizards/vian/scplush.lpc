#include <std.h>
inherit OBJECT;

void create() {
  ::create();
  set_name("sugarcandy plushie");
  set_short("a %^BLUE%^si%^BOLD%^l%^RESET%^%^BLUE%^k %^RESET%^plushie of Sugarcandy%^RESET%^");
  set_long("This small plushie of the cutest nymph you've ever seen has been magically enchanted to move around and flirt around.  You could <molest> it, but it might be a bad idea.");
  set_id(({ "plushie", "sugarcandy plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("rape", "molest");

}

int rape(string str) {
  object tp = this_player();
  string mymsg, roommsg, allmsg;
  int x;

  if (!str || present(str, tp) != this_object())
    return notify_fail("Molest what?\n");

  mymsg = "You molest the small Sugarcandy plushie.\n";
  roommsg = tp->query_cap_name()+" molests "+tp->query_possessive()+
            " small Sugarcandy plushie.\n";
allmsg = "%^BOLD%^%^RED%^Sugarcandy plushie says: %^RESET%^";

  switch (random(3)) {

    case 0:
      allmsg += "These little plastic eyes don't work too well, but if you're Bellos, I'm gonna stab you!";
    break;

    case 1:
      allmsg += "Oooh!  Again!";
    break;

    case 2:
      allmsg = "%^BOLD%^%^RED%^The Sugarcandy plushie starts to vibrate.";
    break;

  }

  message("my_action", mymsg, tp);
  message("other_action", roommsg, environment(tp), tp);
  if (sizeof(allmsg))
    message("action", allmsg, environment(tp));

  return 1;
}

int query_auto_load() { return 1; }

