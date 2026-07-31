//houyuan.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "后院");
        set("long", @LONG
这里落脚似乎是一个大院了，四周堆满了杂物，似乎很久没有人来，远远
望去是馆主冬暖阁的窗口。只是四周墙壁似乎有些奇怪。东面墙总感觉像新砌
的一样；西面墙确是下面一小半陷落，似乎可以从洞口钻过去。
LONG
    );
	set("no_fight",1);
	set("action_list", ([
		"跳窗":"tiao chuang",
		"钻洞":"zuan dong",
	]));
	setup();
}
void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
	add_action("do_enter", ({"zuan"}));
}
int do_jump(string arg)
{
	object room,me = this_player();
    if( arg == "chuang" || arg == "window" || arg == "chuanghu" || arg == "chuangkou")
    {
		if(me->query_skill("dodge")<100) 
		{
			message_vision(HIY"\n$N吸了一口气，想从窗口跳出去。"NOR"\n",me);
			return notify_fail("万震山上前把手一伸：这位"+RANK_D->query_respect(me) +"，你要干什么？！"NOR"");
		}
		if (!(room = find_object(__DIR__"woshi")))
			room = load_object(__DIR__"woshi");
		if(!room)
		{ 
			tell_object(me,HIR"\n你无论怎么跳，发现都还在原地!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)缺少woshi.c文件。\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIY"\n$N吸了一口气，乘万震山不注意，突然直接从窗口跳了进去。"NOR"\n", me);
			me->move(room);
			me->start_busy(1);
			tell_room(environment(me),"\n只见一个身影飞身而过，原来是"+me->name()+"从窗户下跳了进来。"NOR"\n", ({me}));                       	
		}
		return 1;
	}
	return 0;
}
int do_enter(string arg)
{
	object room,me = this_player();
    if( arg == "dong" )
    {
		if (!(room = find_object(__DIR__"citang")))
			room = load_object(__DIR__"citang");
		if(!room)
		{ 
			tell_object(me,HIR"\n你无论怎么钻，发现都还在原地!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)缺少citang.c文件。\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIY"\n$N慢慢探下身来，从洞口爬了进去。"NOR"\n", me);
			me->move(room);
			me->start_busy(1);
			tell_room(environment(me),"\n只见一个人丛一个角落爬了出来，原来是"+me->name()+"。"NOR"\n", ({me}));                       	
		}
		return 1;
	}
	return 0;
}

