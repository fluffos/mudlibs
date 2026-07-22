// shuitan.c
// 水潭

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","水潭");
	set("long",@long
这是一个大水潭，潭中水清凉无比，一下就把你激醒了。潭水正缓缓向东
流去。两岸山石峻峭，山上绿树荫蔽。不知道这是哪里呢？
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

	if(!arg || arg == "" || arg != "up")	
	return notify_fail("你要向哪里爬？\n");
	
	if( arg == "up") {
          if(me->query("jingli") < 100)
                 return notify_fail("你想爬上去，可是却发现自己全身脱力！\n");
	  me->move(__DIR__"qingyinge");
          me->add("jingli", -100);
	  message_vision("$N水淋淋地从江中爬了上来。\n", me);
          me->start_busy(1);
	  return 1; }
}
