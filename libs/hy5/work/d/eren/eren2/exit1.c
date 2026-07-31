 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "泥道");
        set("long", @LONG
一脚踩下去，竟然陷下三分，原来石路已到了尽头。路旁的烛火少了
许多，只能依稀看清个轮廓，一不小心便被突出的岩角撞了头。耳旁呼呼
地有风刮过，风里好像还带着水汽。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"court1",
                "southup" : __DIR__"exit2",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
