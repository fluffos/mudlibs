#include <armor.h>

inherit CLOTH;

void create()
{
 set_name("黄衫", ({"cloth"}) );
    set_weight(1000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
	set("value", 20);
 set("long", "一件轻似翼的黄衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 10);
    }
    setup();
}
