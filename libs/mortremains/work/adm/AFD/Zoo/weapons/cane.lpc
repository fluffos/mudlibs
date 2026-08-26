#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a sturdy cane");
  set("long", @ENDLONG
It's a sturdy cane, made of solid oak.
ENDLONG
  );
  set("id", ({ "cane", "sturdy cane" }));
  set("name", "cane");
  set("mass", 3);
   set("bulk", 1);
  set_value(50);
  set("weapon", 5);
  set("damage", ({ 2, 5 }));
  set_type("blunt");
  set("size", 5);
  set_verbs(({
    "swing at",
    "attack",
  }) );
} 

void init() {
  add_action("beat", "beat");
}

int beat(string str) {
  object ob;
  if (!str) {
    write("Beat who?\n");
    return 1;
  }
  ob = present(str, environment(TP));
  if (!ob) {
    write("Beat who?\n");
    return 1;
  }
  if (ob==TP) {
    write("You can't beat yourself, silly.\n");
    return 1;
  }
  if (!living(ob)) {
    write("You can't beat that.\n");
    return 1;
  }
  write("You beat "+capitalize(str)+" over the head with your cane.\n");
  tell_object(ob,
   TPN+" beats you over the head with "+TP->query_possessive()+ " cane.\n");
  message("ha", TPN +" beats "+capitalize(str)+" over the head with "+
  TP->query_possessive()+" cane.\n", environment(TP), ({ TP, ob }) );
  return 1;
}
