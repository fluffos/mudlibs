#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("¿Ý»ÆµÄÒ¶", ({ "deadleaf", "leaf" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("base_unit", "ÕÅ");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(1);
        ::init_throwing(2);
}      
