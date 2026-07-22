// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
    set("short", "斗母宫");
    set("long", @LONG
上了一段山路，游人一般都会在这里稍为休息。这里的地势已
经比泰山邻近的徂徕山为高，从这里往东北走便是石经峪。
LONG
    );
    set("exits", ([
        "eastup" : __DIR__"shijin",
        "southdown" : __DIR__"yitian",
        "1" : __DIR__"1",
        "2" : __DIR__"2",
        "3" : __DIR__"3",
        "4" : __DIR__"4",
        "5" : __DIR__"5",
        "6" : __DIR__"6",
        "7" : __DIR__"7",
        "8" : __DIR__"8",
        "9" : __DIR__"9",
    ]));
    set("objects",([
"/u/seabird/nainiu" : 1,
        __DIR__"npc/jian-ke" : 1,
    ]));
    set("outdoors", "taishan");
    setup();
    replace_program(ROOM);
}
