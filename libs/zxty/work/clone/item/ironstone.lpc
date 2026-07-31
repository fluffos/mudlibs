// ironstone.c
inherit ITEM;
#include <ansi.h>
inherit F_UNIQUE;
void owner_is_killed() { destruct(this_object()); }   

void create()
{
	set_name(HIB"外星陨铁"NOR, ({ "iron stone","stone"}));
	set_weight(35000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long",HIB"这是一块极珍贵的陨星铁石，分量奇重，表面烧得焦黑，内里却透出一股奇异的寒意。\n它似乎是制造兵器的绝好材料！\n");
                //set("item_origin", 1);
                set("material_attrib", "steel");
                set("can_make", "all");
                set("not_make", ({ "鞭", "战衣", "靴子", "腰带" ,"指套"}));
                set("no_sell", 1);
                //set("no_drop", "这么珍贵的稀有金属，你可不能随意丢弃！\n");
                set("rate", 4); //设置材料等级
                set("rigidity",300+random(50)); //设置材料硬度，也即武器硬度
                set("power_point", 300+random(50)); //做成后的jiali大小
	}
}

