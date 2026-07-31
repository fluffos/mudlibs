 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "银屋");
        set("long", @LONG
银墙后是条甬道，地上铺着厚厚的柔软的地毯，前几间屋子也算奢
华的了，但和这里一比，简直像是土窑。甬道两旁，有扇门，门上
接着珠，走在缤纷的光影里，就像是走人了七宝瑶池，走入了天上
的仙境。 
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                "east" : __DIR__"silver2",
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
