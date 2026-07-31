
inherit ROOM;

void create()
{
        set("short", "天音庭");
        set("long",@LONG
只见墙上挂有萧管之类的乐器，桌上放有一沓乐谱，想是御云山庄
演练乐曲的所在了。再向西就到了珠江岸边，向东则是御云山庄接待宾
客的壁蔑天下厅了。
LONG );
        set("exits", ([
            "east"  : __DIR__"longfeng",
            "west"  : __DIR__"bozhou",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

