// yabi2.c
// 崖壁

inherit ROOM;
#include <ansi.h>
void create()
{	
	set("short", "崖壁");
	set("long",@long
你站在崖壁上的石缝间，要紧紧扒住崖壁突出的地方才不至于摔下去。石
缝里除了沙石草木，什么也没有。
long);
	setup();
}

void init()
{
	add_action("do_pa", "pa");
}
int do_pa(string arg)
{
	object me = this_player();

	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");

	if(!arg || arg == "" || arg != "down")	{
	write(HIR"你一下没掌握平衡，只觉得耳边呼呼风声作响，身体飞快的象下缀去....\n"NOR, me);
	write(HIC"只听得扑通一声，你掉进了一个大水潭中，咕嘟咕嘟喝了好几口水....\n"NOR, me);
	write("你身上的钱物都掉进水中，再也找不到了。\n");
	me->move(__DIR__"shuitan");
	me->unconcious();
	me->set("water", 666);
	return 1;
}
	
	if( arg == "down") {
	message_vision("$N扒着崖壁向下边爬去。\n", me);
	me->move(__DIR__"shangu");
	message_vision("$N扒着悬崖从爬下来。\n", me); 
	return 1; }
}