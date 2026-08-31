//  Christmas Garland

#include <std.h>
#define COLOR ({"%^GREEN%^%^BOLD%^green", "%^RED%^%^BOLD%^red"})
inherit OBJECT;

void create() {
    int i;
    ::create();
    i=random(sizeof(COLOR));
    set_name("garland");
    set_short(COLOR[i]+" garland");
    set_long("This is "+COLOR[i]+"%^RESET%^ colored garland.  It looks "
      "just like the garland that hangs around the city.");
    set_curr_value("gold", 40);
    set_weight(2);
}

