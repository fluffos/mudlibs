#include <armor.h>

inherit CLOTH;

void create()
{
 set_name("嫁衣", ({"marrycloth", "cloth"}) );
    set_weight(1000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
 set("long", "一件大红的上有喜字的嫁衣。\n");
        set("material", "cloth");
        set("armor_prop/armor", 100);
    }
    setup();
}
