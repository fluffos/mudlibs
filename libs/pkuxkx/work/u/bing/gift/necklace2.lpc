// necklace2.c	项链(not autoload)
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
		set("value",50000);
//in case that player may use it to do quest, set no_drop, so cannot give,drop,can sell
		set("no_drop",1);
        set("no_give",1);
		set("owner", "OWNER");
		set("no_store",1);
		set("material", "gold");
		set("wear_msg",HIG "$N高高兴兴地将"+query("name")+HIG "戴了起来。\n" NOR);
		set("armor_prop/armor", 1);
	}
	setup();
}	

