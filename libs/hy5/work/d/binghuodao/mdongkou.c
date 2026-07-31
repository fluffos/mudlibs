// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "迷洞口");
        set("long", @LONG
又湿又潮的一个石洞,还散发着野兽的腥臭.

LONG );
set("exits", ([
               "enter" : __DIR__"midong",
                "south"   : __DIR__"dongcross",
        ]));
set("objects", ([
                __DIR__"npc/wolf" : 1,
                        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
       object ob;
        if ( dir == "south")
{
    ob=find_living("wolf");
   if(!ob)
    {
        return ::valid_leave(me, dir);
   }
    else 
     { 
       if( environment(me)== environment(ob) )
          { ob->kill_ob(me);
          return notify_fail("雪狼挡者路口!\n");}

       }
     }
        return ::valid_leave(me, dir);
     
}
