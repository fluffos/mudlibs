//Made by goodtaste
//sleeproom.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "黑云堂");
        set("long", @LONG
这是杀手帮黑云堂主柳随风的房间，空空荡荡的，只在北面的墙上挂这一张虎皮
看的出来，主人必是个勇武之人
LONG
        );
        
        set("exits", ([
                "south" : __DIR__"qingfengtang",
                "north":__DIR__"zonghengfu",
                
                ]));
         
      
          set("objects", ([
         
                   __DIR__"npc/liusuifeng" : 1,
                   __DIR__"npc/dizi" : 3,
           ]));
         set("no_task",1);
         setup();
       
}


int valid_leave(object me, string dir)
{       
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);   
    if(me->query("accomplish2")&&objectp(present("liu suifeng",environment(me)))) 
    { 
        message("vision",HIR "柳随风靠上来搭讪，这位"+RANK_D->query_respect(me)+"
        这么厉害，将来帮主提拔可别忘了兄弟我啊!\n" NOR,me);
        return ::valid_leave(me, dir);
     } 
	if (!me->query_temp("wu_pass")&& dir == "north"
	&& objectp(present("liu suifeng", environment(me)))
	&& living(present("liu suifeng", environment(me))))
	    return notify_fail("你还没有通过武比，不能进去.\n");
	return ::valid_leave(me, dir);
}

