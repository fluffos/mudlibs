// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黑色劲装", ({ "cloth" }) );
        set_weight(3000);
	set ("long","这是一件铁掌帮众穿的黑色劲装，上面还有铁掌帮的标志。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

