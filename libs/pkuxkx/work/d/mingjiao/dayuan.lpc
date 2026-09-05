//square.c
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大院");
        set("long", @LONG
你走进了明教总舵广场，却发现这里人声鼎沸，五散人群聚于此，
看来有要事发生了。来往教众匆匆忙忙。广场右侧就是光明顶明教总舵了。
LONG );
        set("exits", ([
                "east"    : __DIR__"guangchang",

        ]));
        set("objects",([
             __DIR__"npc/shuobude":1,
             __DIR__"npc/zhangzhong":1,
             __DIR__"npc/pengyingyu":1,
             __DIR__"npc/zhoudian":1,
             __DIR__"npc/lengqian":1,
        ]));

        set("outdoors", "mingjiao");
        setup();

}

