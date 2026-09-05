// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "天溪");
        set("long", @LONG
一条小溪静静流过，带着浮冰残雪，叮咚作响，沿溪水蜿蜒而上
地势渐高，两岸具是陡峭的山峰，山上白雪皑皑。溪边长着许多甘草
(gancao)。
LONG 
        );
        set("item_desc", ([
		"gancao" : "甘草可以入药，一般生长在荒漠边。你可以摘(zhai)下来。\n", 
	]));
        set("exits", ([

                "south" : __DIR__"tianhu",
//                "northwest" : __DIR__"qianbuling1",


        ]));
        set("objects", ([
//                __DIR__"npc/chou1" : 1,
//                __DIR__"npc/chou2" : 1,
//                __DIR__"npc/chou3" : 1,
//                __DIR__"npc/chou4" : 1,
//                __DIR__"npc/chou5" : 1,
        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
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
    if (me->query_temp("甘草"))
    {
        return notify_fail("甘草已经被摘完了。\n");
    }
    me->set_temp("甘草",1);
    gc=new("/d/taishan/obj/gancao");
    gc->move(me);
    message_vision("$N拣起了一颗甘草。\n",me);
    return 1;
}