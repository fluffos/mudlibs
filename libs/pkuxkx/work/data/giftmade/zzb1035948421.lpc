// clothing	衣服
// by bing

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIG +"至尊宝的破鞋"+ NOR, ({ "zzbshoes" }));
	set("long","这是强盗头子至尊宝的一双破鞋，\n上面有好几个破洞，\n不时散发出令人呕吐的臭气，\n看了片刻，你忍不住呕吐起来。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "zzb");
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

