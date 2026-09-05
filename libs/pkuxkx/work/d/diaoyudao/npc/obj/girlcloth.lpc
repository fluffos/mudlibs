// girlcloth.c 女儿装
// hongdou 98.10.02

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIM"女儿装"NOR, ({ "nver zhuang","zhuang" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是韦小宝和妻妾们住在钓鱼岛上时，没有带走衣服，虽然破旧，但仍能遮体。");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value",2000);
           }
        setup();
}

