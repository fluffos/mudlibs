// Room: /d/suzhou/liuyuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "留园");
	set("long", @LONG
留园是苏州的一大名景之一，它以结构布局紧密、厅堂华
丽宏敝、装饰精美典雅而享有“吴中第一名园”之誉。一些丁香
花(dingxiang)正在开放。
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"nandajie2",
		"west"  : __DIR__"hehuating",
	]));

    set("item_desc", ([
		"dingxiang" : "丁香可以入药，一般生长在花园里。你可以摘(zhai)下来。\n", 
	    ]));
	set("objects", ([
		__DIR__"npc/lady1" : 1,
	]));
	setup();
	
}

void init()
{ 
	add_action("do_zhai","zhai"); 
}

int do_zhai()
{
    object me=this_player();
    object gc;
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("丁香"))
    {
        return notify_fail("丁香已经被摘完了。\n");
    }
    me->set_temp("丁香",1);
    gc=new("/d/taishan/obj/dingxiang");
    gc->move(me);
    message_vision("$N摘下了一片丁香。\n",me);
    return 1;
}