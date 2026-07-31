// Room: /d/xiangyang/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "青龙外门");
        set("long", @LONG
这里是襄阳城的东城门，只见城门上方是三个大字“青龙门”。近年
来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵们正在盘查要离
襄阳城的人。两边是很大的草地。
LONG );
        set("outdoors", "xiangyang");

        set("exits", ([
                "west"  : __DIR__"eastgate1",

                "east"  : "/quest/quest_jun/yidao", 
        ]));
        set("objects", ([
                __DIR__"npc/pi"   : 1,
                __DIR__"npc/bing" : 2,
        ]));
        setup();
}

int valid_leave(object me,string dir)
{
       if( dir == "east" && userp(me) && !wizardp(me) 
           && !me->query_temp("jun_quest") )
       return notify_fail("军营重地，闲杂人等，不得入内！\n");

       return ::valid_leave(me,dir);
}

