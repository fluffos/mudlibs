// Obj: /d/tianshan/obj/bag.c
// By Linux
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"布袋"NOR, ({ "bu dai", "bag", "dai" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "这是一口寻常的布袋，但里面似乎装着什么东西。\n");
                set("value", 100);
		set("no_get","布袋对你而言太重了。\n");
                set("no_drop","你不能丢下这样东西。\n");
		set("no_sell","你是人贩子啊。\n");
                set("treasure",1);
                set("location", 1);
        }
}

void init()
{
        add_action("do_open", ({"open", "dakai"}));
}

int do_open(string arg)
{
        object me = this_player(),ob,ob2 = this_object();

        if( (!arg) || !((arg == "bu dai") || (arg == "布袋") || (arg == "dai") || (arg == "袋")))
		return notify_fail("你要打开什么？\n");

        if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	if (ob2->query("opened"))
		return notify_fail("袋子已经解开了。\n");

	if (ob2->query_temp("owner") != me->query("id"))
		return notify_fail("这个袋子不是你的。\n");

	if (!me->query_temp("tonglao/pass3"))
		return notify_fail("你只觉得自己手脚笨拙，怎么解也解不开这个袋子。\n");

        message_vision(YEL"$N当即打开布袋口，扶了一人出来。\n\n"NOR, me);
	message_vision(CYN"女童说道：“见了长辈也不行礼，这般没规矩。若不是念在你相救有功，姥\n"+
			"姥一掌早便送了你的狗命！”\n"NOR, me);
	ob2->set("opened",1);
        ob = new("/d/tianshan/npc/nvtong");
	ob->move(environment(me));
	call_out("do_destruct", 4, ob2);
	return 1;
}

void do_destruct(object ob2)
{
	if (!ob2) return;
	message_vision("一阵风吹来，把布袋吹走了。\n", ob2);
	destruct(ob2);
}
