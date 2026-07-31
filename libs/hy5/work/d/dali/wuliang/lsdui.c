// Room: lsdui.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "乱石堆");
        set("long", @LONG
这里到处都是一堆一堆的乱石，乱石间是齐腰高的荒草，看起来是人迹罕至。
但是如果仔细寻找的话，在荒草乱石只见似乎有条羊肠小道蜿蜒延伸，不知道通
向哪里。
LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"xiaolu2",
            "northeast" : "/d/dali/shennong/xiaodao4",

        ]));
        /*set("objects", ([
                __DIR__"npc/sikong_xuan" : 1, 
        ]));*/
        set("outdoors", "大理");

        setup();
}

