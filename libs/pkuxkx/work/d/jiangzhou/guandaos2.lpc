// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山林间郁郁葱葱，东面就是鄱阳湖了。南面不远就是南昌地界。树下长了许
多茯苓(fuling)。
LONG );
	set("outdoors", "jiangzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"     : __DIR__"guandaos3",
        "east" : __DIR__"hubian",
		"north" : __DIR__"guandaos1",
	]));
    set("item_desc", ([
		"fuling" : "茯苓可以入药，一般生长在马尾松下。你可以摘(zhai)下来。\n", 
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
    if (me->query_temp("茯苓"))
    {
        return notify_fail("茯苓已经被摘完了。\n");
    }
    me->set_temp("茯苓",1);
    gc=new("/d/taishan/obj/fuling");
    gc->move(me);
    message_vision("$N摘下了一片茯苓。\n",me);
    return 1;
}