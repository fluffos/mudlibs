// gudi.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void init()
{
        add_action("do_pa", "pa");
        add_action("do_tiao", "tiao");
        add_action("do_jian", "jian");        
}

void create()
{
       set("short", HIG"谷底"NOR);
       set("long", @long
你来到谷底，却发现这里原来是一处碧水清潭(tan）。周围岸边有几棵大
树。树上排列着数十个蜂巢(fengchao)。而在巢畔飞来飞去的都是一些体形硕
大，颜色灰白的异种玉蜂，地上铺满了鹅卵石(shi)。
long);
       set("item_desc", ([
          "fengchao": HIY"你走近巢边观察，只见蜂巢之旁糊有泥土，实是人工所为。\n"NOR,
          "tan": HIC"你举目向潭中望去，但见水潭里面蓝森森，青郁郁，寒气逼人，似乎结满玄冰，\n"+
                    "一眼望不到底。\n"NOR,
          "shi":"一块块大大小小的鹅卵石，你忍不住想捡(jian)起来看看。\n",
       ]));

       set("objects", ([
                "/d/gumu/npc/yufeng" : 1,
       ]));

       set("outdoors", "绝情谷");
       setup();
}

int do_pa(string arg)
{
	object me;

	me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( !arg || arg != "yabi")
       		return notify_fail("你要往哪爬？\n");
	message_vision(YEL"$N颤颤噤噤地爬了上去。\n"NOR, me);
	me->move(__DIR__"yabi7");
	me->add_temp("tengacc",1);
        me->start_busy(1);
	tell_room(environment(me), me->name() + "从下面颤颤噤噤爬了上来。\n", ({ me }));
	return 1;
}

int do_tiao(string arg)
{
	object me;
	me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( !arg || arg != "tan")
       		return notify_fail("你要往哪跳？\n");
	message_vision(HIY"$N扑通一声，涌身跳入了水潭。\n"NOR, me);
	me->move(__DIR__"guditan1");
	tell_room(environment(me), me->name() + "从岸边跳了下来。\n", ({ me }));
        message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
	return 1;
}

int do_jian(string arg)
{
        object me,ob;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( !arg || arg != "shi")
                return notify_fail("你要捡起什么？\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 100) 
                return notify_fail("你的负荷过重了！\n");
        switch  (random(3)){
        case 0: ob = new(__DIR__"obj/shi1"); break;
        case 1: ob = new(__DIR__"obj/shi2"); break;
        case 2: ob = new(__DIR__"obj/shi3"); break;
        }
        ob->move(me);
        message_vision("$N弯下腰，从地上捡起了一块"+ob->name()+"。\n",me);
        return 1;
}
