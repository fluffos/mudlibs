// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"金山"NOR);
        set("long", @LONG
金山是长江中的一个岛屿，万川东注，一岛中立。金山以绮丽著称，相传唐
代法海和尚在此掘土得金，水上飘了一些鱼腥草(cao)。
LONG);
        set("outdoors", "zhenjiang");
        set("item_desc", ([
		"cao" : "鱼腥草可以入药，一般生长水上。你可以摘(zhai)下来。\n", 
	    ]));
        set("exits", ([     
                "southeast" : __DIR__"tulu11",  
                "northwest" : "/d/changjiang/dkn1a",
                "up" : __DIR__"jinshansi",
                
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

int valid_leave(object me,string dir)
{  
	if (dir=="northwest")
    {
           return notify_fail("你远远望去，大江滚滚东去入海，却没有路通过去。\n");
        
    }
	return ::valid_leave(me, dir);
}
