// shijie3.c 石阶

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
你走在一条坚实的石阶上，不时地有进香客从你的身边走过。一边是
峭壁，一边是悬崖，抬头隐约可见笼罩在云雾中的山峰，听着流水淙
淙，令人心旷神怡。
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"yuqingchi",
                "northup" : __DIR__"shijie4",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/guest" : 2, 
   ]));
        setup();
        replace_program(ROOM);
}

