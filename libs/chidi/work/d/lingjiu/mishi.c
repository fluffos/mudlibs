
inherit ROOM;
void create()
{
    set("short", "密室");
    set("long", @LONG
这是个阴暗的密室，墙上的油灯发出昏暗的黄光。
LONG
    );
    set("exits", ([
        "south" : __DIR__"midao13",
        "north" : __DIR__"midao14",
        "east" : __DIR__"midao14",
        "up" : __DIR__"huayuan",
        ]));
    set("no_magic",1);
    set("objects",([
        __DIR__"obj/zhemeitu1" : 1,
        __DIR__"obj/zhemeitu2" : 1,
        __DIR__"obj/liuyangzhangfa1" : 1,
        __DIR__"obj/liuyangzhangfa2" : 1,
        __DIR__"obj/qijianpu" : 1,
        ]));
    setup();
        replace_program(ROOM);
}
