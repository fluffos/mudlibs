 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
除了没有窗子，这实在是一间最标准的书房，就和世上大多数读书人
读书的地方完全一样。书房的左右两壁，是排满了书的书橱书架，中
间是一张精雅的大理石书桌，桌上整齐地排列着文房四宝。 
LONG
        );
        set("exits", ([ 
//              "northeast" : __DIR__"court1",
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
