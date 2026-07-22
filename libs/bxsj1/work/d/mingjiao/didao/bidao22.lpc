// /d/mingjiao/bidao19.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
        set("short","秘室");
       set("long", @LONG
这里是明教秘道里的一间小小的秘室。
LONG
     );
    
	set("exits", ([
                  "south" : __DIR__"bidao15",
	]));             
        set("objects",([
                CLASS_D("mingjiao") + "/cheng" : 1,
        ]));
        setup();
}
