// datang3.c 大堂三进
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大堂三进");
        set("long", @LONG
这里是大堂的第三进，是全真教弟子议事的地方。全真教祖师王
重阳王真人最近闭关修炼，教内的俗事一般都交给大弟子马钰来处理。
遇有事时，马真人便会召集六位师弟师妹，包括三代弟子中的部分大
弟子来到此地议事。
LONG
        );
        set("exits", ([
                "east" : __DIR__"laojundian",
                "south" : __DIR__"nairongdian",
                "west" : __DIR__"datang2",
                "north" : __DIR__"guozhendian",
        ]));
        set("objects", ([
                __DIR__"npc/fang" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
