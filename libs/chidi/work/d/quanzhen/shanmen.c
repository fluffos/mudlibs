// shanmen.c 全真山门

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "山门");
        set("long", @LONG
        一幢高大的牌坊竖立在你的面前，正中一块横匾刻着三个鎏金大
字“全真教”，牌坊两边站着几个持剑的全真第子。往北是全真教广场。
LONG);
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"shijie4",
                "northup" : __DIR__"tyroad1",
        ]));

        set("objects", ([
                __DIR__"npc/daoshi" : 2, 
   ]));
 
        setup();
        replace_program(ROOM);
}

