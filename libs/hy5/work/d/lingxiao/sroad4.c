//LUCAS 2000-6-18
// Room: sroad4.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","天风川");
        set("long",@LONG
你正站在一块晶莹剔透的万年冰川之上，只觉脚部不断传来
一阵透骨的冰凉。雪山上北风怒号，万里愁云淡雾笼罩雪域，四
周一片苍茫，已经看不见半点生命迹象了。片片雪花从空中鹅毛
般飞撒而下。足底溜滑，道路更是难於辨认。可谓“雪道难，难
于上青天”。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "southdown"  : __DIR__"shiya",
            "northup"  : __DIR__"sroad5",
        ]));
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "northup" || dir == "southdown") {
                me->add("jing", -30);
                me->add("qi", -30);
        }
        return 1;
}       
