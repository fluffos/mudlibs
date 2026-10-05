// jinjia.c 金甲
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(BLK"飞羽甲胄"NOR, ({"feiyu armor","jiazhou", "feiyu","jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件带有铁翼的甲胄．\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 150);
                set("armor_prop/dodge", -3);
        }
        setup();
}


