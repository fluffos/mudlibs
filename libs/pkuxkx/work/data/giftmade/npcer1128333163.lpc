// clothing	衣服
// by bing

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
	set_name(HIR +"人皮魔甲"+ NOR, ({ "xinzhuang" }));
	set("long","这件护甲用人皮制成，并以龙血处理过，它发出死亡的恶臭。\n只有真正邪恶的人才能使用这件邪恶的护甲。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "npcer");
		set("auto_load", 1);
		set("material", "cloth");
		set("armor_prop/armor", 1);
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

