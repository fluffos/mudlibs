// yel_cloth.c
//
// created by pretty

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY "淡黄衣衫" NOR, ({ "yellow cloth", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件女子穿的淡黄衣衫，做工非常精致。\n");
		set("value", 10000);
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

