#include <std.h>
#include <roston.h>

inherit OBJECT;

void init() {
    ::init();
}

void create() {
    ::create();
    set("id", ({ "statue" }) );
    set_name("statue");
    set_long("%^BOLD%^%^WHITE%^This Statue is a Dark robed figure "
             "with beat %^RESET%^%^RED%^red%^BOLD%^%^WHITE%^ eyes. "
             "This Figure seems to have no fear at all.");
    set("short", "%^BOLD%^%^BLACK%^A Statue of a Black Dressed figure");
      set_weight(1);
     set("value", 90000);
     set_prevent_get("The statue is too heavy.");
}

int get() {
  return 0;
}
