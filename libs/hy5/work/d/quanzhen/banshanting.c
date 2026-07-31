// banshanting.c 半山亭
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "半山亭");
        set("long", @LONG
这里是半山腰的一个小凉亭，游客们爬山爬的累了，就转个弯到
这里来坐一坐，歇一歇脚。从这里看下去，刚好可以看见翠屏峰的峰
顶。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"shijie5",
                "south" : __DIR__"shulin1",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
