// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "mo");

}
void create()
{
        set_name(HIM"阿宝"NOR, ({"amy"}));
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

                set("unit", "个");
                set("long", "一个小小的阿宝，象小兔乖乖一样的可爱，您可以试试抚摸(mo)他\n");

		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
        return notify_fail("你要摸什么？\n");
        this_player()->start_busy(20);
        this_player()->add("potential",1000);
        this_player()->add("score",200);
        message_vision("在$N的抚摸下，阿宝化做一缕青烟消失了，您顿时获得了灵感\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
