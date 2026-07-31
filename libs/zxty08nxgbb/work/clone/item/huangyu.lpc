
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIG"独山皇玉"NOR, ({ "dushan huangyu","dushan","huangyu"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",HIG"这是大明皇室收藏的一块极品独山芙蓉玉，它质地细腻，坚硬致密，整块玉石光泽莹润，令人爱不释手。\n"
		    						"它似乎是制造兵器的绝好材料。\n\n"NOR);
                set("no_sell", 1);
                //set("no_drop", "这么珍贵的极品皇家玉石，你可不能随意丢弃！\n");
                set("rate", 4); //设置材料等级
                set("rigidity",250+random(50)); //设置材料硬度，也即武器硬度
                set("can_make", "all");
                set("not_make", ({ "鞭", "战衣","护甲", "靴子", "腰带" ,"指套"}));
                set("material_attrib", "stone");
                set("power_point", 290+random(30)); //做成后的jiali大小
              }
}

