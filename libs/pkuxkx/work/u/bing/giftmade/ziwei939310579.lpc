// clothing	衣服
// by bing

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(BNK + HIC +"水晶舞鞋"+ NOR, ({ "dancing shoes","shoes" }));
    set("long","这是一双" + HIC + BNK + "水晶" + NOR + GRN + "做的舞鞋，亮晶晶的，象天上的" + HIC + BNK + "星星" + NOR + GRN + "。\n据说灰姑娘就是穿着这双" + BNK + HIC + "水晶舞鞋" + NOR + GRN + "跟王子跳舞的。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "ziwei");
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

