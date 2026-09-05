// ring2.c	戒指(not auto_load)
// by bing

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIR +"名字"+ NOR, ({ "ＩＤ" }));
	set("long","LONG\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
//in case that player may use it to do quest, set no_drop, so cannot give,drop,can sell
		set("no_drop",1);
		set("value",100000);
        set("no_give",1);
		set("no_store",1);
		set("material", "gold");
		set("wear_msg",HIG "$N喜气洋洋地将"+query("name")+HIG "戴在手指上。\n" NOR);
		set("armor_prop/armor", 1);
	}
	setup();
}	



