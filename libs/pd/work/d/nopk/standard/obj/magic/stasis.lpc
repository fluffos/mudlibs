//    Stasis object.
//    By Nightshade.
 
#include <std.h>
inherit OBJECT;
 
void create() {
  ::create();

  set_name("crazie");
  set_heart_beat(1);
  set_short("");
  set_long("blah");
  set_weight(0);
  set_value(0);
  set_id(({"stasis_object"}));
  call_out("finish", this_player()->query_skill("conjuring")/5);
}

void init() {
  ::init();
  add_action("blah","", 1);
}

int blah(string str) {
  string verb;

  if(wizardp(this_player()))
    return 0;

  verb = query_verb();

  if(verb == "quit")
    return 0;

  switch(verb) {
      case "look":
      case "say": return 0;
      default:
  }

  write("The entire room has been hit with stasis!");

  return 1;
}

void finish() {
  if(environment(this_object()))
    message("info", "As the stasis wears off, movement becomes possible.%^RESET%^",environment(this_object()));
    this_object()->remove();
    if(this_object())
        destruct(this_object());
}
