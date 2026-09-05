// clothing	衣服
// by bing

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIR +"太阳鸟之羽毛"+ NOR, ({ "sunbird" }));
	set("long","在大海的东海岸有棵太阳树。\n太阳树上住有10个太阳鸟。\n每10年从一个太阳鸟的脖子上的取下的一根羽毛。\n终于做成了这件神奇的衣服。\n穿上它会给你带来神奇的力量和好运。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "jingl");
		set("auto_load", 1);
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
}

