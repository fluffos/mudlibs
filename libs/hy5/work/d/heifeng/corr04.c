// /d/heifeng/corr04.c

inherit ROOM;

void create()
{
        set("short", "过道");
        set("long", @LONG
一条人踏出来的小路，两旁长着几棵松树，还有一些灌类植
物丛生周围。
LONG
        );
        set("exits", ([ 
//            "south"  : __DIR__"corr",
//            "north"  : __DIR__"corr03",
            "east"   : __DIR__"corr03",
            "west"   : __DIR__"corr05",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

