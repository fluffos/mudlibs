//Cracked by Roath
//fear 2002 1 30
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", GRN"花园"NOR);
        set("long", @LONG
石子路旁有许多花草，一棵梅树(tree)孤立一旁。一丛丛花束点缀着蓝
天。梅树下摆着一张小桌，桌上摆了壶茶和一张棋盘，散落的棋子似乎诉说
些什么。凉风吹过，却不甚寒冷。
LONG
        );
        set("exits", ([
               "south" : __DIR__"room1",
        ]));
       set("item_desc", ([
       "tree" : "这棵梅树已有近数百年历史了，但依然茂盛如初。枝虬风韵洒落，一朵朵的
梅花傲霜绽放，香气沁人肺腑，催人欲醉。来到这里的人都不住停下脚，在
树下欣赏一番。\n"NOR
       ]));       
        set("outdoors", "lingshedao");
        set("objects", ([ /* sizeof() == 1 */
        "/d/lingshedao/obj/meihua" : 1,
         ]));
		set("cost", 1);
		setup();
//		replace_program(ROOM);
}

void init()
{
        add_action("do_push", "push");
        add_action("do_push", "tui");
}
/*
int valid_leave(object me, string dir)
{
    if ((dir == "west")&& !userp(me)) return 0;
    return ::valid_leave(me, dir);
}
*/
int do_push(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="tree" )
	{
		if(me->query("rided"))
		return notify_fail("你骑着马，不能这麽干！\n");
//		if( (fam = me->query("family")) && fam["family_name"] == "明教" ) 
		else 
		{
			message_vision("$N推了推梅树，花丛后面露出一个小洞。\n", me);
			message("vision",
				me->name() + "一弯腰往花丛里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/lingshedao/huacong");
                	message("vision",
				me->name() + "从花从里走了进来。\n",
                		environment(me), ({me}) );
			return 1;
		}
//		else 
//			return notify_fail("推了推梅树，什么反应也没有。\n");
	}
}	
