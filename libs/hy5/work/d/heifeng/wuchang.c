// /d/heifeng/wuchang.c

inherit ROOM;

void create()
{
        set("short", "山间空地");
        set("long", @LONG
这里是一块空地。中央放着几个木桩，空地边上放有几个石
锁什么的。五六个像是刚入山的伙计正在用心操练着。看来这里
是专门练功用的武场。
LONG
        );
        set("exits", ([ 
            "west"   : __DIR__"corr03",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

