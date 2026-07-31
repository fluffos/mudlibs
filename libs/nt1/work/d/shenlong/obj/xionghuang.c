#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("雄黄", ({"xiong huang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包雄黄,据说可驱百毒。\n");
		set("value", 1000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	return notify_fail("想死啊？雄黄不能吃。\n");
}
