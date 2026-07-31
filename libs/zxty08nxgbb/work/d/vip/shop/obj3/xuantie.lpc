// xuantie.c 玄铁石

#include <ansi.h>

inherit ITEM;
void owner_is_killed() { destruct(this_object()); }  
void create()
{
	set_name(BLK"玄铁精石" NOR, ({"xuan tie", "xuantie"}));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", WHT"一块黑黝黝有些泛光石头，掂在手中感到极为沉重，坚硬远胜铜铁，是锻造兵器的上好材料。\n\n"NOR);
		set("unit", "块");
		set("value", 30000);
                //set("item_origin", 1);
                set("material_attrib", "steel");
                set("can_make", "all");
                set("not_make", ({"战衣", "指套", "腰带","鞭"}));
                set("no_sell", 1);
                   set("tianya_money",3); 
                set("rigidity",250+random(30)); //设置材料硬度，也即武器硬度
                //set("no_drop", "这么珍贵的稀有金属，你可不能随意丢弃！\n");
                set("rate", 3); //设置材料等级
                set("power_point", 200+random(50)); //做成后的jiali大小
	}
}
