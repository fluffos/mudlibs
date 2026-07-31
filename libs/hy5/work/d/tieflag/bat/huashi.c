 inherit ROOM;
void create()
{
        set("short", "画室");
        set("long", @LONG
屋子不大，不知何处点了支檀香，颇有一股脱尘出俗的意味，
靠东面的墙放着一张桌子，桌上文房四宝齐全，似是主人作画的
地方。奇怪的是都好象很久没有人用过。
LONG
        );
        set("exits", ([
                "east" : __DIR__"feng",
            "west" : __DIR__"shushi",
        ])); 
        set("objects", ([
        __DIR__"npc/tong4": 1,
    ])); 
        set("coor/x",3300);
        set("coor/y",30);
        set("coor/z",-20);
        setup();
}     
