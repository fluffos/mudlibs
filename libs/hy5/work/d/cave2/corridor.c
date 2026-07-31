 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "×ßÀÈ");
        set("long", @LONG 
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"palace4",
                "south" : __DIR__"corridor1",
                "north" : __DIR__"bathroom",
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
