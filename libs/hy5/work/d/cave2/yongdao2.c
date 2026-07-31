 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "甬道");
        set("long",  @LONG
地势由此向下，又多转折之处，甬道越走越窄，洞壁上湿漉漉的长满
了青苔，地上也滑溜异常，一不小心就会摔倒。好在洞里的人似乎想得很
周到，每过十多尺便有照明的灯烛。烛光晃动，在洞壁上拖下长长的影子，
不知哪里又吹来阵阵阴风，令人毛骨悚然。
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao3",
                "southup" : __DIR__"yongdao1",
                "east" : __DIR__"yongdao2a",
        ]));
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
