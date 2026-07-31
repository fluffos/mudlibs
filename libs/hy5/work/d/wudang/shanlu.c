// /d/wudang/shanlu2.c  山路

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"山路"NOR);
        set("long", @LONG
你走在一条偏僻的山路上，四周灌木丛丛，遍地奇花异草，人迹
罕至，路径几不可寻，只有采药的人才敢进入深山。你到处乱窜寻找
出路，猛的一痛，荆棘把你给划伤了!
LONG                           
        );
        set("exits", ([
                "eastup" : __DIR__"zixiaogate",
                "south" : __FILE__,
                "west" : __FILE__,
                "north" : __FILE__,
        ]));

        set("no_npc",1);
        set("objects",([
                __DIR__"npc/caiyao" : 1,
        ]));

        setup();
        replace_program(ROOM);

}

int valid_leave(object me, string dir)
{
if( dir == "southeast" )
{
me->start_busy(3);
me->receive_damage("qi", random(10));
me->receive_damage("jing", random(10));
return 1;
}
        return ::valid_leave(me, dir);
}

