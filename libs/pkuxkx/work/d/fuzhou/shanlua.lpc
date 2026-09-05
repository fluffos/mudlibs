
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山路");
        set("long", "一条小山路，西南面就是泉州城了。路边长了一些常山(changshan)。\n");
        
        set("exits", ([
               "northeast" : __DIR__"nanmen",
               // "northeast" : __DIR__"citywall1",
               // "southwest" : __DIR__"citywall2",
                "southwest" : __DIR__"shanlub",
                
        ]));
       set("item_desc", ([
		"changshan" : "常山可以入药，一般生长在山间坡旁。你可以摘(zhai)下来。\n", 
	    ]));
        set("outdoors", "fuzhou");
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