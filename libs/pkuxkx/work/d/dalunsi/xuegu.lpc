// Room: xuegu.c

inherit ROOM;

void create()
{
        set("short", "雪谷");
        set("long", @LONG
这里是群山环绕中的一个山谷，人迹罕至。仰面向上看，四面山峰高耸入云，
覆盖着冰雪。周围茫茫雪原，甚至连野兽的足迹都看不到。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"qianbuling1",
        ]));

        set("objects", ([CLASS_D("dalunsi") + "/laozu" : 1,"/clone/npc/camel1": 0,]));
// set("objects", ([__DIR__"npc/laozu" : 1,]));
        setup();

}

