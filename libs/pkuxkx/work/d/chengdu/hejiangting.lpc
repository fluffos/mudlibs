
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIM"合江亭"NOR);
        set("long", "合江亭是在府、锦两河汇合之处所建的一座亭台。相传晋国伐东吴的战船就\n是在这里起航。\n");
       

        set("exits", ([
               "north" : __DIR__"jinjiang4",
               "west" : __DIR__"southstreet1",
               
                
        ]));
        set("self_build_entry",1);
        set("outdoors", "chengdu");
        setup();
   
}

void init()
{
    object me=this_player();
    if (me->query_temp("jn/step3c"))
    {
        tell_object(me,"一条倩影在你眼前一闪，似乎往百花潭方向纵去。\n");
        me->delete_temp("jn/step3c");
        me->set_temp("jn/step3d",1);
    }
    return;
}

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
           return notify_fail("锦江看看就好了，难道你真要投河自尽吗？\n");
        
    }
	return ::valid_leave(me, dir);
}