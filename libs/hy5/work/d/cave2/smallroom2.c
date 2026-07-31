 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小石室");
        set("long", @LONG
每间洞室都很整洁，甚至可以说都很华丽，而且还
都有张很柔软、很舒服的床。 
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"mouseroom2",
                
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
