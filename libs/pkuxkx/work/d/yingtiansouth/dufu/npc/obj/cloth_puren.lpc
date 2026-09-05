#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name("粗布衣", ({"cu buyi", "cloth", "yi"}) );
    set_weight(4000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件普普通通的粗布衣服。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
