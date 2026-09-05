// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "观音山");
        set("long", "观音山山势险峻，绿树茂密，山寺古朴，是极目滇池山光水色的游览胜地，\n观音山麓，还是白族集聚的村落。树下长了许多茯苓(fuling)。\n");
        set("exits", ([
               //"northeast" : __DIR__"xunyanglou",
               "eastdown" : __DIR__"dianchib1",
               //"up" : __DIR__"yueyang2",
               "north" : __DIR__"xishan",
               
                
        ]));
        set("item_desc", ([
		"fuling" : "茯苓可以入药，一般生长在马尾松下。你可以摘(zhai)下来。\n", 
	    ]));  
        set("outdoors", "kunming");
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