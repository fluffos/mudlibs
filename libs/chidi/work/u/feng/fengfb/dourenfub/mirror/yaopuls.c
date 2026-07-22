//make by yixiang
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "药铺内室");
        set("long", @LONG
这是药铺的内室，帮助药铺老板分配中药，可以增加经验，潜力呀。
LONG
        );
        set("exits", ([
                "south" : __DIR__"yaopu",
                
]));
        setup();
}

//是镜像
int is_mirror() { return 1; }