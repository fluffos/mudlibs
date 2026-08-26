#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "a badger skin loincloth");
  set("long", @ENDLONG
This loincloth was made to fit an extremely large human,
or a very small giant.  The loinclth was roughly made
but the tough flesh of a badger may provide you with
some protection, if it would fit you.
ENDLONG
  );
  set("id", ({
    "cloth",
    "loincloth",
  }));
  set("size", 10);
  set("bulk", 2);
  set("mass", 4);
  set_value(350);
  set("armor", 3);
  set_type("costume");
}
