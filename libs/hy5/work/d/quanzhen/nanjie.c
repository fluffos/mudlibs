// nanjie.c 南街
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "南街");
        set("long", @LONG
这里是武功的南街，说是街，不过是一条小胡同而已。路上一个
人也没有。街的尽头有一扇小门。从这里往北，就是武功镇的中心了。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"zhongxin",
                "southeast" : __DIR__"fu-cemen",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
