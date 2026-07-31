 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "内室");
        set("long", @LONG
走过书房便是一间内室，一间普通的不能再普通的内室。一张床，一
把太师椅，东边的墙上挂着一柄长剑。屋子里唯一的奢侈品是地上的一张
虎皮，一张没有一根杂毛的白虎皮。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"studyroom",
                        ]));
                        
        set("objects", ([
                __DIR__"npc/biehe" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
