//Made by goodtaste
//qingfengtang.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "清风堂");
        set("long", @LONG
这里是杀手帮第二堂清风堂的所在，气势宏伟，当中一块牌匾
上写着三个大字：清风堂
LONG
        );
     
        set("exits", ([
                "south" : __DIR__"hongyutang",
                "north":__DIR__"heyuntang",
                
                ]));
         
     
          set("objects", ([
         
                   __DIR__"npc/yangxiaotian" : 1,
                   __DIR__"npc/dizi" : 3,
           ]));
		set("no_task",1);
         setup();
    
}




int valid_leave(object me, string dir)
{        
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);   
        if(me->query("accomplish2")&&objectp(present("yang xiaotian",environment(me)))) 
             { 
               message("vision",HIR "杨啸天哈哈一笑，这位"+RANK_D->query_respect(me)+"
果然英雄了得，功成归来了啊!\n" NOR,me);
               return ::valid_leave(me, dir);
              }

	if (!me->query_temp("wen_pass")&& dir == "north"
         &&objectp(present("yang xiaotian", environment(me)))
         &&living(present("yang xiaotian", environment(me))))
	    return notify_fail("你还没有通过文比，不能进去.\n");
	return ::valid_leave(me, dir);
}
