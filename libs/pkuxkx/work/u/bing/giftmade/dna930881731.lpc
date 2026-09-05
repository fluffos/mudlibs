// common2 普通物品(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN +"烟灰缸"+ NOR, ({ "gang" }));
	set("long","水晶烟灰缸，晶莹剔透\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        set("value",500);
//in case that player may use it to do quest, set no_drop, so cannot give,drop,can sell
		set("no_drop",1);
		set("no_store",1);
        set("no_give",1);
		set("owner", "dna");
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	

