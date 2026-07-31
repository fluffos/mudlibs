 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "魁星阁");
        set("long", @LONG
十年前镇上出了个举人，入京前在这儿捐了个魁星老爷。不过这举人还没见到
皇上，就被强盗砍了脑袋，从此再没人光顾。自从万马堂兴起后，这儿就成了牧马
汉子们喝酒取乐，或是摔跤比武的场所。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"nstreet3",
        ]));
        set("objects", ([
         __DIR__"npc/nangong":     1,

                
        ]) );
        set("coor/x",-1115);
        set("coor/y",210);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
