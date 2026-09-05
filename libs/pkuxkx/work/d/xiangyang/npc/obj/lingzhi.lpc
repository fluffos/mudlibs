#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(YEL"灵芝"NOR, ({"ling zhi", "ling"}));
        set("unit", "只");
        set("long", "这是一棵千年灵芝，可以用来配置灵丹妙药。\n");
        set("value", 8000);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        this_player()->add("neili",300);message_vision("$N吃下了一棵灵芝，畅快极了.\n",this_player());
destruct(this_object());
	return 1;
}

