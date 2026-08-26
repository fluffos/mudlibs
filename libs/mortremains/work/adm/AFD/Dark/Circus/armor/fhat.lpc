#include <mudlib.h>
inherit ARMOR;
void create() {
  seteuid(getuid());
  set("short", "a funny-looking felt hat");
  set("long", @ENDLONG
This is a purple, felt hat.
ENDLONG
  );
  set("id", ({
    "hat",
    "felt hat",
 }));
  set("size", 10);
  set("bulk", 120);
  set("mass", 180);
  set_value(30);
  set("armor", 3);
  set_type("helmet");
  set("raise_stat", "intelligence");
  set("modifier", -3);
}