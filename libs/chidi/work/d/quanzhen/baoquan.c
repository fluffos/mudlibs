// baoquan.c 宝泉 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "宝泉");
        set("long", @LONG
这里是终南山的山腰，形如美玉，味似甜蔗，四周风景如画。这里
又有一泉眼，用其水泡茶，堪称神州一绝，当地人称其为宝泉，因而这
也成了天下一品茗体憩之佳地。往东是独松阁。
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : "/d/gumu/lyy",
                "east" : __DIR__"dusongge",
        ]));
        set("objects", ([
                "d/wudang/npc/monkey" : 1, 
   ]));

        setup();
        replace_program(ROOM);
}


