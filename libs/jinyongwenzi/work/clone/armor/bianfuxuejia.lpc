// bianfuxuejia.c

#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(RED"蝙蝠血甲"NOR, ({ "bianfuxue jia" , "armor", "jia"  }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "bronze");
		set("value", 5000);
                set("armor_prop/armor", 15); // cut 50 -> 15 River@SJ
                set("long","这件铠甲以无数片铜片串接而成，护肩以舒展双翼的蝙蝠为形，猩红色的内衬寓意沾满敌人的鲜血。\n");
           }
        setup();
}
