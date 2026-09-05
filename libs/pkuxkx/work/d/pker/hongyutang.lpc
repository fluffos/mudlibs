//Made by goodtaste
//hongyutang.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "红雨堂");
        set("long", @LONG
清寒之夜听春雨，燕子归时数落红，这里正是红雨阁主人的房间，
布置的典雅华丽，清新可人
LONG
        );
        
        set("exits", ([
                "south" : __DIR__"shijie5",
                "north":__DIR__"qingfengtang",
                   
                
                ]));
         
          set("objects", ([
         
                   __DIR__"npc/ouyangmin" : 1,
                   __DIR__"npc/nvdizi" : 3,
           ]));
		set("no_task",1);
         setup();
 
}

int valid_leave(object me, string dir)
{        
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);   
        if(me->query("accomplish2")&&objectp(present("ouyang min",environment(me)))) 
             { 
               message("vision",HIR "欧阳敏用敬佩的目光上下打量你，什么也没有说，反而背过了身去\n" NOR,me);
               return ::valid_leave(me, dir);
              }
	if (!me->query_temp("gold_given")&& dir == "north"
	&&objectp(present("ouyang min", environment(me)))
	&&living(present("ouyang min", environment(me))))
	    return notify_fail("你还没有交纳入门费，不能进去.\n");
	return ::valid_leave(me, dir);
}

