inherit ROOM;
void create()
{
        set("short", "时空传送站");
        set("long", @LONG
这里是凤凰星的时空传送站，是利用物质高能分解与合成原理进行传送的地方。
LONG );
        set("outdoors", "fenghuang");
        set("exits", ([
             "west"  : __DIR__"eshangjie2",
        ]));
        set("objects", ([
                __DIR__"obj/transfer1" : 1,
                __DIR__"obj/transfer2" : 1,
        ]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


