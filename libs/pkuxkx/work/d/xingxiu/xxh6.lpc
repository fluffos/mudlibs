// room: /d/xingxiu/xxh6
// Jay 5/13/96

inherit ROOM;
#include "/d/xingxiu/flower.h"
void create()
{
        set("short", "石道");
        set("long", @LONG
这是星宿海边有人用石头铺成的一条小道，周围弥漫着沼泽的瘴气和一
种说不出来的香味。路边有个石洞。
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"xxh4",
            "enter" : __DIR__"xiaoyao",
        ]));
        set("objects", ([ 
            __DIR__"npc/caihua" : 1,
            flower:random(2) ,
         ]) );

        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
       

    if (dir =="enter" ) {
	if (present("caihua zi", environment(me))) 
        {
            if (me->query("family/family_name")!= "星宿派" && !me->query_temp("apprentice/step"))
		    return notify_fail("采花子挡住了你：我的小妞可不是给你们邪派弟子准备的！\n");
            
            
//               if  (me->query("gender")=="无性")
/*
            if (!(int)this_player()->query_temp("marks/花"))
                return notify_fail("采花子挡住了你：喂，你总该意思意思吧？\n");
*/
        }
	
   }
   return ::valid_leave(me, dir);
}

