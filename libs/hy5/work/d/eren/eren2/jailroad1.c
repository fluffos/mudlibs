 inherit ROOM;
void create()
{
        set("short", "巨石");
        set("long", @LONG
一块巨大的岩石挡在路的中央，所幸两边还留了不少空隙，可供一人
侧身挤过。但如此一来，岩石后面的动静一点也看不见，只是黑乎乎的一
片，凉风从石缝中穿过呜呜的响，仿佛一声声的啸叫，令人不寒而栗。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"yongdao7",
                "north" : __DIR__"jailroad2",
        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
