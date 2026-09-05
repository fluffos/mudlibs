
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"入川古栈道"NOR);
        set("long", "蜀道难行，自古有云：蜀道难，难于上青天。路边小坡长了一些鸡血藤(teng)。\n");
        set("exits", ([
               
               "southwest" : __DIR__"shudao1",
               "northwest" : __DIR__"shudao3",
                
        ]));
        set("item_desc", ([
		"teng" : "鸡血藤可以入药，一般生长在高原浅坡。你可以摘(zhai)下来。\n", 
	    ]));
        set("outdoors", "chengdu");
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
    if (me->query_temp("鸡血藤"))
    {
        return notify_fail("鸡血藤已经被摘完了。\n");
    }
    me->set_temp("鸡血藤",1);
    gc=new("/d/taishan/obj/jixueteng");
    gc->move(me);
    message_vision("$N摘下了一片鸡血藤。\n",me);
    return 1;
}

int valid_leave(object me,string dir)
{  
	object pl=this_player();
        if (time() - pl->query_temp("shudao/last_go_time") <= 3+random(3))
        {
            return notify_fail("你小心翼翼往前挪动，遇到艰险难行处，只好放慢脚步。\n");
        }
        else
        {
            pl->set_temp("shudao/last_go_time",time());
        }
    
	return ::valid_leave(me, dir);
}