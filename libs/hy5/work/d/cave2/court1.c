 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "彩石路");
        set("long", @LONG
行路至此，一下子宽敞起来，洞顶极高，黑漆漆的，离地三丈处似乎
还有个岩洞，可惜被青藤遮住了。不几步处又是一个分岔口，彩石路
继续向东边延伸，左边多了条石路，看样子是向上去的。
LONG
        );
        set("exits", ([ 
                "westup" : __DIR__"exit1",
                "east" : __DIR__"court2",
                "southeast" : __DIR__"yongdao7",
                        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
