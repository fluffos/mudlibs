//bye enter

inherit ROOM;

void create()
{
        set("short", "青石巷");
        set("long",@LONG
你走在一条青石巷上，整条小巷静悄悄的，跟春熙路的
热闹情景完全不一样，你总觉得气氛有点不对劲。
LONG
        );

        set("exits", ([
                "west" : __DIR__"qingshixiang1",
                "east" : __DIR__"qingshixiang3",
            ]));
        setup();
        replace_program(ROOM);       
}


