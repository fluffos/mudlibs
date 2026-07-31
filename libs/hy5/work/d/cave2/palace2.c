 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
外面竟又是条地道，两旁是雕刻精致的石壁，壁上嵌
着发亮的铜灯。 
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace3",
                "south" : __DIR__"palace1",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
