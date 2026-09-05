// Room: /hangzhou/td_dilao2.c
// hubo 2008/4/19
 
inherit "/d/hangzhou/song_room";
#include <ansi.h>

void create()
{
        set("short", "地牢");
        set("long", @LONG
这是提督府的地牢，里面坐着一个大内高手看守着后边的犯人。
LONG);

        set("exits", ([
                "north" : __DIR__"td_dilao3",
                "out" : __DIR__"td_dilao4",
        ]));
        
        set("objects", ([
                "/d/hangzhou/npc/zhangzhaozhong" : 1,
        ]));     
        set("no_dbr_stage",1);
		set("hsz_no_task",1);
        set("no_task",1);		
        setup();
}

int valid_leave(object me, string dir)
{
    if ( dir != "south"
        && (present("zhang zhaozhong", environment(me)))
        && living(present("zhang zhaozhong", environment(me))))
            return notify_fail("张召重拦住你说：哪里跑。\n");
    return ::valid_leave(me, dir);
}

