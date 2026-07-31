// /d/mingjiao/bidao19.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
       set("short","秘道");
       set("long", @LONG
这里是秘道的出口，直通明教厚土旗。
LONG
     );
    
	set("exits", ([
             "out" : "/d/mingjiao/tuqi",
             "west"  :  __DIR__"bidao20",
	]));             
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "out") {
                write(HIW"\n你出得洞来，强光闪耀，一时之间竟然睁不开眼。\n\n"NOR);
        }
        return 1;
}
