// Room: fatang2.c

inherit ROOM;

void create()
{
        set("short", "法堂二楼");
        set("long", @LONG
这里是大轮寺掌门居所，四面清幽，修禅证道最妙不过。真是：
    戏招西塞山前月，来听东林寺里钟。
    悠然万虑忘，有此一楼足。
    西窗外，群山万壑，望尽天地。
    东窗外，楼台错落，几尽悠闲。
LONG
        );

        set("exits", (["down" : __DIR__"fatang",]));
        set("objects", ([
        CLASS_D("dalunsi") + "/jiumozhi" : 1,
                ]));
        setup();
}

