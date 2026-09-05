//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", WHT"乌龙潭"NOR);
        set("long", 
"这里是一处大湖，名唤『乌龙潭』。水上飘了一些鱼腥草(cao)。\n"

        );
        set("item_desc", ([
		"cao" : "鱼腥草可以入药，一般生长水上。你可以摘(zhai)下来。\n", 
	    ]));
        set("exits", ([
                
              
                "westup" : __DIR__"qls",
                
        ]));
        set("objects", ([
                __DIR__"npc/fisher" : 1,
        ]));
        set("couldfish",1);
        set("outdoors", "yingtianfu");
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
    if (me->query_temp("鱼腥草"))
    {
        return notify_fail("鱼腥草已经被摘完了。\n");
    }
    me->set_temp("鱼腥草",1);
    gc=new("/d/taishan/obj/yuxingcao");
    gc->move(me);
    message_vision("$N摘下了一片鱼腥草。\n",me);
    return 1;
}
