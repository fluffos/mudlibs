 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "八角型的屋子");
        set("long", @LONG
这里竟是个八角型的屋子，那八面墙，有的是铁，有的是钢，有的
是石板，竟还有一面像是金子。屋子里，没有桌子，没有橱子．因
为在地底，所以也没有蛛网、积尘，空气也不知是哪里进来的。
屋子里只有绞盘，大大小小、形状不同的机关统盘，有的是铁铸，
有的是石造，自然，也有的是金子的。 
LONG
        );
        set("exits", ([ 
                "gold" : __DIR__"gold",
                "silver" : __DIR__"silver",
                "copper" : __DIR__"copper",
                "iron" : __DIR__"iron",
                "tin" : __DIR__"tin",
//              "earth" : __DIR__"earth",
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
