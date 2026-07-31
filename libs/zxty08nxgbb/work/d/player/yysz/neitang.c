
inherit ROOM;

void create()
{
        set("short","飘香堂");
        set("long",@LONG
这是一间雅致的房间，布置简单而典雅。里面好几个漂亮的少女
正和几个男童追来追去的打闹。
LONG );
        set("exits",([
            "north" : __DIR__"qinyun",
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


