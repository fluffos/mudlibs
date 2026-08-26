#include <mudlib.h>

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("value", 15) ;
  set("mass", 1) ;
  set("bulk", 1) ;
  set("short", "some bloody entrails");
  set("long", @BLOOD
Fresh entrails.  They smell horrible.
BLOOD
  );
  set("smell", "They smell fucking disgusting.\n");
  set("author", "chronos");
  set("id", ({ "entrails", "bloody entrails" }) );
}
