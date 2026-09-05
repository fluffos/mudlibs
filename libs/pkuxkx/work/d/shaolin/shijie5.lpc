// Room: /d/shaolin/shijie5.c
// Date: YZC 96/01/19
// Modified by iszt@pkuxkx, 2007-04-26, added exit eastup

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
一挂巨大的瀑布白龙出霄般横越山间，水气已浓得仿佛可以
滴下水珠儿来。山峦间升起薄薄的青雾，凝聚不散。哗哗的水声
震耳欲聋。石阶上满是水渍，走上去滑得可以让人打跌。路边长
了一些薄荷(bohe)。
LONG);

        set("exits", ([
                "southdown" : __DIR__"shijie4",
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"fxjing",
        ]));
        set("item_desc", ([
		"bohe" : "薄荷清凉醒脑，可以入药，一般生长在山间。你可以摘(zhai)下来。\n", 
	    ]));
	      set("objects",([
		            "/newbiequest/shaolin/cjg/npc/huseng" : 2,
       	]));

        set("outdoors", "shaolin");
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
    if (me->query_temp("薄荷"))
    {
        return notify_fail("薄荷已经被摘完了。\n");
    }
    me->set_temp("薄荷",1);
    gc=new("/d/taishan/obj/bohe");
    gc->move(me);
    message_vision("$N摘下了一片薄荷。\n",me);
    return 1;
}