// fagate.c 稀世玛瑙

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "稀世玛瑙" NOR, ({ "flawless agate" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR "一块光彩照人的大玛瑙，美仑美奂，世所罕有。"NOR"\n");
		set("base_value", 100000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("can_be_enchased", __DIR__"magate");
		set("enchased_need", 3);
		set("magic/type", "fire");
		set("magic/power", 125);
	}
	set_amount(1);
	setup();
}
