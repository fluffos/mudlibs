// /d/heifeng/corr05.c

inherit ROOM;

void create()
{
        set("short", "过道");
        set("long", @LONG
这里是路的拐角，路边长满了绿色的灌类植物。走路时可要
小心，不要被刺伤了手脚。南面有两个站哨的土匪，不知是什么
重要地方。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"hell",
            "north"  : __DIR__"corr06",
            "east"   : __DIR__"corr04",
//            "west"   : __DIR__"corr05",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

