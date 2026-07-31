//citang.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "破祠堂");
        set("long", @LONG
穿过后花园就来到破祠堂内。里面空荡荡的，地上满是灰尘，桌椅都是甚
为残破，看来很长时间没人光顾了。屋角蜷缩着一个满身是灰，蓬头垢面的中
年乞妇，一个人在那里喃喃自语。
LONG
        );
        	 
        set("exits", ([
               "southwest" : __DIR__"houhuayuan",               
        ]));
	set("no_fight",1);
        set("objects", ([
        ]));
	set("action_list", ([
		"钻洞":"zuan dong",
	]));
        setup();
}
void init()
{
	add_action("do_enter", ({"zuan"}));
}
int do_enter(string arg)
{
	object room,me = this_player();
    if( arg == "dong" )
    {
		if (!(room = find_object(__DIR__"houyuan2")))
			room = load_object(__DIR__"houyuan2");
		if(!room)
		{ 
			tell_object(me,HIR"\n你无论怎么钻，发现都还在原地!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)缺少houyuan2.c文件。\n", me->name(1),me->query("id")) );	
		}
		else
		{
                        message_vision(HIY"\n$N萎在一个角落里，竟然找到一个黑乎乎的洞口。\n$N慢慢探下身来，从洞口爬了进去。"NOR"\n", me);
			me->move(room);
			me->start_busy(1);
                        tell_room(environment(me),HIC"\n只见一个人丛一个角落爬了出来，原来是"+me->name()+"。"NOR"\n", ({me}));                              
		}
		return 1;
	}
	return 0;
}
