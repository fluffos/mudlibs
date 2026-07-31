// wanniansong.c
//  万年松

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","万年松");
	set("long",@long
这是一只大树枝，从一棵万年松上伸出。这棵树生得高大苍劲，年代古远，
树根由石缝中长出，紧紧攀着崖壁。上边就是舍身崖了。
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

	if(!arg || arg == "" || arg != "tree")	{
	write(HIR"你一下没掌握平衡，只觉得耳边呼呼风声作响，身体飞快的象下缀去....\n"NOR, me);
	write(HIC"只听得扑通一声，你掉进了一个大水潭中，咕嘟咕嘟喝了好几口水....\n"NOR, me);
	write("你身上的钱物都掉进水中，再也找不到了。\n");
	me->move(__DIR__"shuitan");
	me->unconcious();
	me->set("water", 666);
	return 1;
}
	
	if( arg == "tree") {
	message_vision("$N顺着树干慢慢爬下去。\n", me);
	me->move(__DIR__"wanniansongx");
	message_vision("$N顺着树干慢慢爬了下来。\n", me); 
	return 1; }
}