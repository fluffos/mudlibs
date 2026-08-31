#include <std.h>
#include <arlon2.h>
inherit WEAPON;

void create() {
::create();
    set_name("staff");
    set_short("a wooden staff");
    set_long("This is a very plain looking staff.  It has been carved out of a decent sized branch of wood, and looks like it could hurt a bit if used the right way.");
    set_id(({"staff", "wooden staff"}));
    set_weight(10);
    set_type("blunt");
    set_wc(2);
    set_ac(1);
    set_curr_value("gold", 80);
}
int query_auto_load()
{
if (this_player()->query_level() > 5) return 1;
}



