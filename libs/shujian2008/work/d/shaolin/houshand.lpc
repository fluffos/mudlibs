#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这是一个小小的山洞，洞里没有任何物品。几个老和尚分坐左右，面向石
壁，闭目参禅。这里空空荡荡，奇怪的是地上居然放着一小堆木屑，不知道有
什么用途。
LONG
        );

        set("exits", ([ 
		"out" : __DIR__"yading",
	]));

        set("objects",([ 
		"/kungfu/class/shaolin/wu-xiang" : 1,
	]));

        setup();
}

void init()
{
	add_action("do_bo", ({ "bo" }));
} 

int do_bo(string arg)
{
	object me=this_player();

	if( !me->query("wxz/done") )
		return 0;
	if( !arg || arg!="木屑" )
		return notify_fail("你要拨什么？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if( me->query_skill("wuxiang-zhi",1)>200 ) 
		return notify_fail("你感觉已经无法继续利用碎木屑提高自己无相劫指的修为了。\n");

	if(me->query("neili")<50) return notify_fail("你的内力不够。\n");
	if(me->query("jingli")<100) return notify_fail("你的精力不够。\n");

	message_vision("$N双手笼袖，运气鼓劲，地上的碎木屑突然飞舞跳跃起来，便似有人以一根无形的细棒挑动搅拨一般。\n",me);
	me->add("neili",-50);
	me->add("jingli",-100);
	me->improve_skill("wuxiang-zhi", me->query_int());
	return 1;
}
