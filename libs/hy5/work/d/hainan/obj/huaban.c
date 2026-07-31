
#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("花瓣", ({ "hua ban" ,"flower"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "粉色的桃花花瓣。\n");
                set("unit", "片");
                set("base_unit", "片");
                set("base_weight", 2);
                set("base_value", 1);
                set("value", 0);
              }
        set_amount(1);
        init_throwing(111);
        setup();
}
