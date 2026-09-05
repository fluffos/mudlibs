// watch.c	手表
// by bing

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIG +"手表"+ NOR, ({ "watch" }));
	set("long","这是侠客行的万能手表n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",5000000);
		set("no_store",1);
		set("owner", "xkx");
		set("auto_load", 1);
		set("material", "gold");
		set("wear_msg",HIG "$N将"+query("name")+"戴在手腕上，得意地晃了晃。\n" NOR);
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
	add_action("do_time","time");
}

int do_time()
{
	write("现在的标准时间是：" + ctime(time()) + "\n");
	write("你已经在这个世界里成长了" + FINGER_D->age_string( (int)this_player()->query("mud_age")) + "。\n");
	return 1;
}

