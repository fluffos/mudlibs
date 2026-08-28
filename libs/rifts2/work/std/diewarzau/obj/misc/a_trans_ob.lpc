//    Shadow form object.c
#include <rooms.h>

inherit "/std/Object";

object shadow;

void set_shadow(object ob) { shadow = ob; }

int drop() { return 1; }

void create() {
  ::create();
  set_short(0);
  set_long(0);
  return;
}

void init() {
  ::init();
  add_action("sorry", "cast");
  add_action("sorry", "get");
  add_action("sorry", "use");
  add_action("sorry", "take");
  add_action("sorry", "say");
  add_action("sorry", "yell");
  add_action("remove_trans", "remove");
}

int sorry(string null) {
  write("You are unable to do that while in animal form.");
  return 1;
}

int remove_trans(string arg) {
  if(arg != "transformation") return 0;
  if(!shadow) {
    remove();
    return 0;
  }
  message("info", (string)this_player()->query_short()+
    " begins to change, and suddenly transforms into "+
    capitalize((string)this_player()->query_name())+"!",
    environment(this_player()), ({ this_player() }));
  shadow->external_destruct(shadow);
  message("info", "You transform back to normal form.",
    this_player());
  remove();
  return 1;
}

