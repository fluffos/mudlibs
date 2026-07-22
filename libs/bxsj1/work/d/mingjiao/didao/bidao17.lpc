// /d/mingjiao/bidao17.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{ 
       set("short","秘道");
       set("long", @LONG
这是一条弯曲而上的秘道。
LONG
     );
       set("exits", ([
		"northdown" : __DIR__"bidao16",	
		"southup"  :  __DIR__"bidao18",
                "eastdown"  :  __DIR__"bidao4",
       ]));             
       setup();

}

int valid_leave(object me, string dir)
{
        if (dir == "eastdown" )
         return notify_fail(HIY"\n你想往下走去，但洞身确实太陡无法着脚。\n\n"NOR);
        return ::valid_leave(me, dir);
}
