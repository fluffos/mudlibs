// common 普通物品
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW +"淮南子"+ NOR, ({ "huainan" }));
	set("long","这是小偷送你的礼物。\n书页有点儿破，封面上写着“淮南子”三个字。\n这是西汉淮南王刘安命宾客集体纂写的。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
        set("value",10000);
		set("no_store",1);
		set("owner", "xilz");
		set("auto_load", 1);
		set("material", "gold");
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

