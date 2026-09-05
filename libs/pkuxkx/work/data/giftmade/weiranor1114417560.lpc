// ring.c	戒指
// by bing

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIR +"玄霜"+ NOR, ({ "jshuang" }));
	set("long","艳比霜华\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",2000000);
		set("no_store",1);
		set("owner", "weiranor");
		set("auto_load", 1);
		set("material", "gold");
		set("wear_msg",HIG "$N喜气洋洋地将"+query("name")+HIG "戴在手指上。\n" NOR);
		set("armor_prop/armor", 1);
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的手指上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
}

