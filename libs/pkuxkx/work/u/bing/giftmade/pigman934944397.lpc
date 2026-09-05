// clothing	衣服
// by bing

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
	set_name(BLK +"扬过和小龙女"+ NOR, ({ "lover" }));
	set("long","这是扬过和小龙女送你的宝衣。它刀枪不入。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "pigman");
		set("auto_load", 1);
		set("material", "cloth");
		set("armor_prop/armor", 100);
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

