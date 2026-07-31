// Pill: sanxiaosan.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("三笑逍遥散", ({"sanxiaoxiaoyao san", "xiaoyao san", "san"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一包无色的粉末, 看样子不是寻常物品. \n");
		set("unit", "包");
		set("pour_type", "sanxiao_poison");
		set("value", 20000);
	}
	setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	if(arg=="san" || arg=="xiaoyao san")
	{
		message_vision("$N仰头咽下一包" + name() + "。\n", me);
		this_player()->die();
		destruct(this_object());
	}
	return 1;
}
