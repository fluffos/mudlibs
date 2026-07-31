// 青铜
// edit by pian

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(CYN"青铜"NOR, ({ "qingtong" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一块用来铸造兵器或其它用品的青铜块。\n");
		set("unit", "块");
		set("value", 8000);
	}
}