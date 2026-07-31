 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "巨石");
        set("long", @LONG
一块巨石，道路狭窄。 
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"yongdao7",
                "north" : __DIR__"jailroad2",
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
