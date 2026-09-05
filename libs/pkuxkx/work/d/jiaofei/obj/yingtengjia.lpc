#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIW"硬藤甲"NOR, ({ "ying tengjia","armor" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "这是用五指山特产的一种硬藤经过捶打制作的盔甲，能有效的防御箭矢的伤害。但对刀剑抵御力不高。\n");
        set("material", "cloth");
		set("value", 500);
        set("armor_prop/armor", 30);
        set("naijiu",30);
        }
        setup();
}

