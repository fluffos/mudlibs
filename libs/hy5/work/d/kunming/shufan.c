// /d/kunming/dongzoulang.c
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "书房" );
        set("long", @LONG
这是一间整洁明亮的书房，四壁都是书架，上面摆满了各种书籍，
中间一张桌子，放着笔墨纸印。
LONG
        );
          
        set("exits", ([
		"east"   :__DIR__"xizoulang1"
                
        ]));
	set("objects",([
		__DIR__"npc/wusangui":1,
		]));
	set("shu_count",1);
        setup();
	   
}

int init()
{
	add_action("do_fan","fan");
}

int do_fan( string arg )
{	object me=this_player(),
	       ob=present("wu sangui", environment(me)),
	       shu;

	if ( !objectp(ob))
	{
	if (arg=="" || !arg) return notify_fail("你要翻什么？\n");
	if ( query("shu_count") && arg=="shu")
	{
	tell_object(me,"你翻了一会书，忽然发现有一本很特别的书，你赶快收了起来。\n");
	shu=new("/d/city2/obj/book14_1");
	shu->move(me);
	set("shu_count",0);
	return 1;
	}
	else return notify_fail("你四处一阵乱翻，结果什么都没发现。\n");
	}
	else 
	{ message("vision","吴三桂怒道，哪里来的贼人，竟然敢闯入王府！\n",me);
	  ob->kill_ob(me);
	}
	return 1; 
}
	  		