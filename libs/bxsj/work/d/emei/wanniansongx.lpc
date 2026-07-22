// wanniansongx.c
// 万年松下

inherit ROOM;
#include <ansi.h>
void create()
{	
	set("short", "万年松下");
	set("long",@long
你已经到了万年松树下。这棵松树年代古远，树根由石缝中长出，紧紧攀
着崖壁。
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

	if(!arg || arg == "" || arg != "left")	{
	write(HIR"你一下没掌握平衡，只觉得耳边呼呼风声作响，身体飞快的象下缀去....\n"NOR, me);
	write(HIC"只听得扑通一声，你掉进了一个大水潭中，咕嘟咕嘟喝了好几口水....\n"NOR, me);
	write("你身上的钱物都掉进水中，再也找不到了。\n");
	me->move(__DIR__"shuitan");
	me->unconcious();
	me->set("water", 666);
	return 1;
}
	
	if( arg == "left") {
	message_vision("$N扒着崖壁向左边爬去。\n", me);
	me->move(__DIR__"yabi");
	message_vision("$N你扒着崖壁从右边爬了过来。\n", me); 
	return 1; }
}