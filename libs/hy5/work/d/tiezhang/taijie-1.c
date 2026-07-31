// Room: /u/bobo/tiezhang/taijie-1.c

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
一排石阶笔直而下，消失在浓浓的黑暗中。石阶上长满的绿色的青苔，滑
不留脚。你用足目力，还是看不清远处的情景。
LONG
        );

        set("exits", ([ 
"out" : __DIR__"trdx",
"westdown" : __DIR__"taijie-2",
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

