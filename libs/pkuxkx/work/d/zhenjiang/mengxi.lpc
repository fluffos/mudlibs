// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", MAG"梦溪园"NOR);
        set("long", @LONG
这里庭园缘溪依山而筑，环境幽静，景色宜人。园外门前小溪流水潺潺，一
如沈括而立之年梦中所游之地。一些丁香花(dingxiang)正在开放。
LONG);
        set("outdoors", "zhenjiang");
        set("valid_startroom", 1);
        set("exits", ([     
                "south" : __DIR__"e1",   
                "west" : __DIR__"n1",
]));
        set("objects", ([
		__DIR__"npc/xiaofan" : 1,
        
        ]));  
   set("item_desc", ([
		"dingxiang" : "丁香可以入药，一般生长在花园里。你可以摘(zhai)下来。\n", 
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