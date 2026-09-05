// common 普通物品
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR +"骑士勋章"+ NOR, ({ "badge" }));
	set("long","这是一款宇宙一刀流授予的一等勋章，由铂金和橡木精心打造而成，仅颁发给做出的不可磨灭的贡献的人。勋章背面刻着几个小字“罗盘定”\n");
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
		set("owner", "luopan");
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

