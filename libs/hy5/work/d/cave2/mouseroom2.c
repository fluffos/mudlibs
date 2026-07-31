 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ึ๗สา");
        set("long", @LONG 
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"smallroom1",
                "west" : __DIR__"smallroom2",
                "north" : __DIR__"mouseroom3",
                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}   
