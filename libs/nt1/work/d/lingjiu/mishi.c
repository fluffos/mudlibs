
inherit ROOM;

void create()
{
    set("short", "密室");
    set("long", @LONG
这是个阴暗的密室，墙上的油灯发出昏暗的黄光。
LONG );
    set("exits", ([
        "up" : __DIR__"huayuan",
    ]));
    set("objects",([
        "/clone/book/zhemei_book1" : 1,
        "/clone/book/zhemei_book2" : 1,
        "/clone/book/liuyang_book1" : 1,
        "/clone/book/liuyang_book2" : 1,
        "/clone/book/qijianpu" : 1,
    ]));
    setup();
}

