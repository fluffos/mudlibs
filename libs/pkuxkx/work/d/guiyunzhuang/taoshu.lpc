//taoshu.c 桃树
//By:pingpang
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","桃树");
	set("long","你正处在桃树茂密的枝叶间，树上结满了个头很大的"RED"水蜜桃"NOR"(mitao).\n");
	set("exits",(["down":__DIR__"taolin1",]));
	set("item_desc",(["mitao":"你可以去摘下(pick)它。\n"]));
	setup();
}
void init()
{
	add_action("do_pick","pick");
}
int do_pick(string arg)
{
	object ob,me;
	me=this_player();
	if(!arg||arg!="mitao")
	return notify_fail("你想摘什么?\n");
	if(arg=="mitao")
	{
		if(me->query_temp("been_get"))
			//return notify_fail("一只小猴叫道：你再摘，我们吃什么?\n"); 猴子说人话，不成了孙悟空的子孙了吗？By Zine
            return notify_fail("一只小猴跳出来，对你吱吱吱叫个不停。\n");
		else
			{message("vision",me->name()+"摘下了一个蜜桃，露出了喜悦的表情。\n",environment(me),({me}));
            tell_object(me,"你摘下了一个蜜桃。\n");
			ob=new(__DIR__"obj/mitao");
			ob->move(me);
			me->set_temp("been_get",1);
			return 1;
			}		
	}
}

		
