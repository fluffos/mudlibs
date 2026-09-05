// Room: /d/gumu/dong.c
#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "洞口");
        set("long", @LONG
这是终南山活死人墓的入洞洞口.
LONG
        );
        set("exits", ([
  "south" : __DIR__"grass",
  "north" : __DIR__"gumu" ,
]));
        set("no_task",1);
//         set("objects",(__DIR__) );//cannot find diao.c in ./npc,maybe a mistake of lianxing. changed by icer
         create_door("north","石门","south");
        setup();
}

 int valid_leave(object me,string dir)
  {       me=this_player();
  if (me->query("family/family_name")=="古墓派" ) 
        {
          if (present("popo",environment(me)) && (dir=="south"))
                return notify_fail("神雕挡住了你的道路. \n");
        else if (dir=="north") 
          {
        me->move(__DIR__"ceshi");

         return notify_fail("ok");
          }
         }
   return ::valid_leave(me,dir);
  }
