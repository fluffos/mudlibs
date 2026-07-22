inherit ROOM;

void create()
{
        set("short", "凤凰城中心");
        set("long", @LONG
凤凰城是一个繁华空港城市。每天都会有很多旅客从这里经过，或者在这里做买卖。
所以这里十分喧哗。一条繁华的商业街横贯东西。    
LONG );
        set("exits", ([
                "north" : __DIR__"bjie1",
                "south" : __DIR__"shentang",
                "east"  : __DIR__"eshangjie1",
                "west"  : __DIR__"shangjie1",
        ]));
           set("objects",([
                __DIR__"npc/bing" : 6,
        ]));
//      set("no_clean_up", 0);
        set("outdoors", "fenghuang");
        setup();
        replace_program(ROOM);
}

// zhangm  1999.12.17      


