// /d/heifeng/sentry2.c

inherit ROOM;

void create()
{
        set("short", "哨塔");
        set("long", @LONG
一个大约四人高的哨塔出现在你的眼前，塔上的哨兵来回的
巡视着。你向他招了招手，却得不到任何响应。
LONG
        );
        set("exits", ([ 
            "east"   : __DIR__"corr",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

