// chexiangtan.c 车厢潭 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "车厢潭");
        set("long", @LONG
这里位于高冠瀑布的上游，四周巨石突兀，环绕而成一潭，称车厢潭。
潭清见底，细石如鳞，历历可数，为寻幽探奇之佳地。往上可道舍身台。
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"gaoguanpubu",
                "westup" : __DIR__"sheshentai",
        ]));
        set("objects", ([
                __DIR__"npc/ji" : 1, 
   ]));

        setup();
        replace_program(ROOM);
}


