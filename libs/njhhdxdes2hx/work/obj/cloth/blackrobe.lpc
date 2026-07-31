// black-robe.c 黑色长袍
// By dan

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("黑色长袍", ({"pao", "cloth", "chang pao"}) );
    set_weight(4500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "这是件素雅洁净的黑色长袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 3);
    }
    setup();
}
