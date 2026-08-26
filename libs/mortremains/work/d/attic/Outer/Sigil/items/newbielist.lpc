//ilz

#include <mudlib.h>

inherit OBJECT;

void create() {
	set("id", ({ "list", "newbielist" }) );
	set("short", "a list of newbie kills");
set("long", "find these kills in sigil:\n"+
 "fell, grixitt, harys, hashkar, kesto, phineas, marian, morvun,"+
"nye, omott, parakk, saure, seamus, rat\n");
        set("name", "list");
  }
void init() {
  object ob = environment(this_object());
  if (!living(ob))
    call_out("remove", 1);
}

void remove() {
  object ob = environment(this_object());
  if (ob) 
    tell_room(environment(this_object()), 
    "The newbie item crumbles to dust and blows away.\n");
  ::remove();
}
