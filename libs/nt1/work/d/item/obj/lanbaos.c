// lanbao-stone.c 蓝宝石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIB "蓝宝石" NOR, ({ "lanbao stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIB "蓝宝石，我国古有“瑟瑟”之称，是一种蓝色透明的刚玉，硬度非常大。\n"
                                "蓝宝石独具的深切神秘的蓝色，既沉稳又清澈，深深地吸引人们的内心\n"
                                "欲望。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "gold");
                set("magic/power", 100);
                set("armor_prop/per", 5);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

