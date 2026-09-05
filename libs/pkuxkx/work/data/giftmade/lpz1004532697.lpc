// necklace2.c	项链(not autoload)
// by bing

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIG +"水晶项链"+ NOR, ({ "loveneck" }));
	set("long","一个由玛瑙作成的美丽手镯。\n");;set("value",5000);setup();}\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("value",50000);
//in case that player may use it to do quest, set no_drop, so cannot give,drop,can sell
		set("no_drop",1);
        set("no_give",1);
		set("owner", "lpz");
		set("no_store",1);
		set("material", "gold");
		set("wear_msg",HIG "$N高高兴兴地将"+query("name")+HIG "戴了起来。\n" NOR);
		set("armor_prop/armor", 1);
	}
	setup();
}	

