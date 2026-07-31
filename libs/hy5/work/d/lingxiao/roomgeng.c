//LUCAS 2000-6-18
// Room: roomgeng.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","居室");
        set("long",@LONG 
这是一间安静的居室，是凌霄城第六代弟子耿万钟的房间。
桌上放着一卷《冰雪心法》，墙上挂着一柄剑。束束阳光从窗
格中射入，照在墙上，映得一副《万里江山图》分外雄伟。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang1", 
        ]));
        set("objects", ([  
                __DIR__"npc/geng" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

