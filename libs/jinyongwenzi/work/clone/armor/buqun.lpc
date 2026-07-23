// OBJ : /d/wudang/obj/cloth.c 青布花裙
// By lius 99/8
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青布花裙", ({"cloth", "huaqun"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件普通的青布所做花裙。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
