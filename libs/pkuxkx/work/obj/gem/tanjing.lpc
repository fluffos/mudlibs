//锻造的辅助材料，可以锻造4孔装备，只在每周一次的剿匪任务中出现一颗，控制产量。Zine
#include <ansi.h>

inherit ITEM;
int is_tanjing()
{
	return 1;
}
void create()
{
	set_name(WHT"炭精"NOR, ({ "tan jing", "tan","jing" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一小块炭精，能极高的提升炉火的温度，却是得来不易。\n");
		set("unit", "块");
		set("value", 18000);
		set("material", "wood");
	}
	setup();
}
