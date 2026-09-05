
// /d/mingjiao/shamobian.c
// west to 1
#include <room.h>
inherit ROOM;
void create()
{
       set("short","沙漠边缘");
       set("long", @LONG
这是一片一望无际的大沙漠的边缘。
东南面是黄河北岸，西边则是一片广袤的沙漠。路边长着许多甘草(gancao)。
LONG
     );
        set("exits", ([
               
                "west" : __DIR__"shamo1",
                 "southeast" : "/d/huanghenorth/dkb3",
        ]));
                set("item_desc", ([
		"gancao" : "甘草可以入药，一般生长在荒漠边。你可以摘(zhai)下来。\n", 
	]));
 set("outdoors", "mingjiao");
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

int valid_leave(object me,string dir)
{  
	if (dir=="southeast")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}