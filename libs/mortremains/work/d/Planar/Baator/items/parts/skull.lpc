#include <mudlib.h>

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("value", 25) ;
  set("mass", 1) ;
  set("bulk", 1) ;
  set("short", "a human skull");
  set("long", @BLOOD
A fresh new human skull.
BLOOD
  );
  set("author", "chronos");
  set("id", ({ "skull", "human skull" }) );
}
