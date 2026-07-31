// lingzhi.c 千年雪莲
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"小人物"NOR, ({"hxsd"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
    set("value", 0);
set("liwu",1);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");

		set("unit", "棵");
                set("long", "这是一个小小的小人物，正在你手中活蹦乱跳，据说吃一个很补身体。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
        this_player()->start_busy(30);
        this_player()->add("max_neili", 20);
        this_player()->add("eff_neili",20);
        message_vision("$N吃下一个小人物，随着一股浊气从体内排出，感觉到自己的内力又强了不少 !\n", this_player());

	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
