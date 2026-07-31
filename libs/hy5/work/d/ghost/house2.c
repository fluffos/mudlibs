 inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
屋子不大，但布置得很雅致。正面靠墙放着一张大床，床单雪白
被褥崭新。左面床头是一张梳妆台，台上放着一面铜镜，几盒胭脂。
LONG
        );
        set("exits", ([
                "north" : __DIR__"groad5",
        ]));
        set("objects", ([
                __DIR__"npc/hua" : 1,
        ]));
        set("coor/x",-1110);
        set("coor/y",-120);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}   
