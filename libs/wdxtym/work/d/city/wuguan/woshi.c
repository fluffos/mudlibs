//woshi.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"冬暖阁"NOR);
        set("long", @LONG
这里是武馆馆主万震山的卧室，房子并不大，很整洁简朴，被子叠的整整
齐齐，帐子挂了起来，靠窗边摆了一盘盆景，一张小桌，放着几本书。几缕阳
光透过窗外的绿荫中直射进来。
LONG
        );       
	set("no_fight",1);
        set("exits", ([
               "south" : __DIR__"zoulang3",               
        ]));        
        set("objects", ([
        ]));
	set("action_list", ([
		"跳窗":"tiao chuang",
	]));
        setup();
}
void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
}
int do_jump(string arg)
{
	object room,me = this_player();
    if( arg == "chuang" || arg == "window" || arg == "chuanghu" || arg == "chuangkou")
    {
		if(me->query_skill("dodge")<100) 
		{
			message_vision(HIY"\n$N吸了一口气，想从窗口跳出去。"NOR"\n",me);
			return notify_fail("万震山上前把手一伸："+RANK_D->query_respect(me) +"你要干什么？！"NOR"\n");
		}
		if (!(room = find_object(__DIR__"houyuan2")))
			room = load_object(__DIR__"houyuan2");
		if(!room)
		{ 
			tell_object(me,HIR"\n你无论怎么跳，发现都还在原地!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)缺少houyuan2.c文件。\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIY"\n$N吸了一口气，乘万震山不注意，突然直接从窗口跳了出去。"NOR"\n", me);
			me->move(room);
			me->start_busy(1);
			tell_room(environment(me),"\n只见一个身影飞身而过，原来是"+me->name()+"从窗户上跳下来。"NOR"\n", ({me}));                       	
		}
		return 1;
	}
	return notify_fail("万震山上前把手一伸："+RANK_D->query_respect(me) +"你要干什么？！\n");
}

