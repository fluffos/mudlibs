// Room: /d/diaoyudao/shuding.c 树顶
// hongdou 98.09.20

#include <ansi.h>

inherit ROOM;

void init()
{
        add_action("do_kan", "kan");
}

void create()
{
	set("short", "树顶");
	set("long", @LONG
你爬到大树顶部，扶着树枝(zhi)，拨开繁茂的树叶，向四周了望，看
看有没有通道可以离开这片树林。只见树连海，海连天，只有东边好象能够
出去。
LONG
	);
	set("item_desc", ([
               "zhi" : "这是大树上一根笔直的树枝，如果把它砍下来，加工加工可能有些用处。\n",
       ]));

	set("exits", ([
                "down" : __DIR__"shulin8",
	]));

	set("outdoors", "diaoyudao");
	setup();
}

int do_kan(string arg)
{
	object ob,gun;
        object me = this_player();
	if( !arg || arg!="zhi" ) 
	{
	     if ( !arg ) return notify_fail("你要砍什么？\n");
             if ( arg!="zhi" )  return notify_fail("没事瞎砍什么？\n"); 
        }
	if (arg=="zhi")
	{
	  if (!(ob = present("chai dao", this_player())))
               return notify_fail("你没有适用的工具。\n");
	  if (this_player()->query_temp("marks/砍1") ) 
                 return notify_fail("请你注意环保，不要乱砍乱伐！！！\n");
	  tell_object(me, HIY"砍下了一根树枝，并且加工成了一根细长的木棍。\n"NOR);
	  message("vision",me->name()+"砍下了一根树枝。\n",environment(me),({me}));
	  gun = new(__DIR__"obj/changgun");
          gun->move(me);
	  this_player()->set_temp("marks/砍1", 1);
	  return 1;
	}
}
