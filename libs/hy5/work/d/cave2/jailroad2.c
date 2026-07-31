 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
道路狭窄。 
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad1",
                "north" : __DIR__"jailroad3",
                "east" : __DIR__"jail1",
                "west" : __DIR__"jail2",
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
