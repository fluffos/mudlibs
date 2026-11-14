#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
  if(arg) return;

  set_name("scroll");
  set_alias("quest hint");
  set_short("A white scroll with a red seal");
  set_long(
    "This fancy scroll bears the symbol of the city Tempus, and the \n"+
    "delicate signature of the mayor himself. Perhaps you should read it?\n");
  set_weight(1);
  set_value(1);  /* to get rid of it in the shops? */
}

void init() {
  ::init();
  add_action("read_me", "read");
}

status read_me(string str) {
  if(str == "scroll") {
    write("As mayor of this fine city, I charge you with this duty...\n\n");
    environment()->quest_hint();
    return 1;
  }
  return 0;
}

