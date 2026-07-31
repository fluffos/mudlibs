
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIW"万年玄冰"NOR, ({"wannian xuanbing", "xuanbing"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", HIW"这是块在海底冰山中混合了稀有金属，冰封数万年的玄冰，坚硬抗压，是锻造兵器的上好材料。\n");
                set("no_sell", 1);
                set("value", 10000);
                //set("no_drop", "这么珍贵的宝物，你可不能随意丢弃！\n");
                set("rate", 3); //设置材料等级
                set("rigidity",200+random(30)); //设置材料硬度，也即武器硬度
                set("can_make", "all");
                set("not_make", ({ "鞭", "锤", "战衣", "指套", "腰带","靴子" }));
                set("material_attrib", "silver");
                set("power_point", 200+random(30)); //做成后的jiali大小
        }

        setup();
}
