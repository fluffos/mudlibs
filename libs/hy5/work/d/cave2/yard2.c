 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
一间破旧的屋子，陈设却极为简陋。屋子里到处都积着灰
尘，像是已许久没有人来过！蛛网。在风中飘摇，有些蛛
网巳被风吹断了，蜘蛛正忙着在重新绘起。 
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"yongdao7",
                "east" : __DIR__"yard2",
                
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
