// xiaohuayuan1.c 小花园
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小花园");
        set("long", @LONG
这里是重阳观里的小花园，空气中飘着一股鲜花的香味。再往
北去，就是金鱼池了。这个花园不大，却是全真弟子练功间隙最爱
来游玩的地方。园中见不到一根杂草，也许专门有人负责管理这里。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southwest" : __DIR__"houtang3",
                "northeast" : __DIR__"xiaohuayuan2",
        ]));

        set("objects", ([
                __DIR__"npc/zhangyuan" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
