// Zine dec 7 2010 ,铜雀台
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW"江河通"NOR, ({ "jianghe tong","river pass"}));
	set_weight(500);
    set("value",1);
	set("is_river_pass",1);
	set("valid_period",3600*24*30);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一张大明特别发行的江河通，交给任意艄公后可以在一月内随意乘坐长江黄河渡船。\n");
			set("unit", "张");
		}
}
