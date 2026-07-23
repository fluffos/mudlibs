// chungongtu.c 春宫图
// By iceland
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"春宫图"NOR, ({ "chungong tu", "tu" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("treasure",1);
		set("long", HIM"这是一本薄薄的绢书，上面绘制了一些小人，正在干着一些事情。\n"NOR);
		set("value", 15000);
		set("material", "silk");
	}
	setup();
}

void init()
{
	add_action("do_kan", ({"kan"}));
}

int do_kan(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你想看什么？\n");

	else {
		message_vision(HIM"$N翻开春宫图专注的看着，不一会只觉呼吸急促，浑身躁热起来。\n"NOR, me);
		return 1;
	}
}
