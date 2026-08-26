#include <mudlib.h>

inherit CONTAINER;

create() {
    ::create();
    seteuid(getuid());
    set("name", "purse");
    set_open_long(
      "A small leather purse that holds coins.\n"
    );
    set("short", "a coin purse");
    set("id", ({ "purse", "coin purse" }));
}
