// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
北面就是成都城了。这里道路开始分叉，西南面通向大理，南
面通向峨眉山。路边长了一些常山(changshan)。
LONG );
	set("outdoors", "chengdu");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"     : __DIR__"guandaos3",
        "southwest" : __DIR__"guandaosw1",
		"northdown" : __DIR__"guandaos1",
	]));
    set("item_desc", ([
		"changshan" : "常山可以入药，一般生长在山间坡旁。你可以摘(zhai)下来。\n", 
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
    if (me->query_temp("常山"))
    {
        return notify_fail("常山已经被摘完了。\n");
    }
    me->set_temp("常山",1);
    gc=new("/d/taishan/obj/changshan");
    gc->move(me);
    message_vision("$N摘下了一片常山。\n",me);
    return 1;
}