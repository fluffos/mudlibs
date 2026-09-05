// clothing	衣服
// by bing

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
	set_name(HIY +"黄金手镯"+ NOR, ({ "bangles" }));
	set("long","这是一双精工打造的黄金手镯。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("material", "cloth");
		set("armor_prop/armor", 100);
	}
	setup();
}	

void init()
{
	if (environment()->query("name")!="孤竹无名")
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
}

