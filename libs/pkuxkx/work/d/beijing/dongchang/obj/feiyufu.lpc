// feiyufu.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIG"飞鱼服"NOR, ({ "feiyu fu", "fu", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件锦衣卫通常穿着的服装。\n");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

