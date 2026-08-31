#include <std.h>;
inherit OBJECT;

void create() {
  ::create();

  set_name("paper");
  set_short("piece of paper");
  set_long("An old, frail note with a message on it.");
  set_id(({"piece of paper", "note", "paper"}));
  set_mass(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("read", "read");
}

int read(string str) {
  if(!str || present(str, this_player()) != this_object())
    return notify_fail("Read what?\n");
  write("You read the note...\n\n"
        "  Dear Mr Lomack,\n"
        "    We've heard word of your recent experiments.  We are very\n"
        "   excited about your recent discoveries.  Unfortunately, we have\n"
        "   also heard of the side effects.  When you can show us that it\n"
        "   works on adults, we will join you in your\n\n"
        "The rest of the note is in too bad of a condition to read.\n\n");
  say("As "+this_player()->query_cap_name()+" reads the note, it crumbles in their hands.");
  write("The note crumbles in your hands.");
  this_object()->remove();
  return 1;
}
