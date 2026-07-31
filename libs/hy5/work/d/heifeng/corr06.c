// /d/heifeng/corr06.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
曲折的小路盘山而上，周围丛生的树林之间夹杂着一些下雨
时滚落的石头。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr05",
            "north"  : __DIR__"corr07",
//            "east"   : __DIR__"corr04",
            "west"   : __DIR__"restrm",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

