 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "林间小屋");
        set("long", @LONG
屋子里很简朴，很干净，雪白的墙上，挂着一幅人像。画得并不好的人像，却
很传神。一个白面微须、目光炯炯有神的中年人，微微仰着脸，站在一片柳林外，
身子笔挺，就像是一杆标枪一般。他穿的是一件紫缎锦袍，腰畔的丝带上，挂着一
柄刀，漆黑的刀！人像前还摆着香案，白木的灵牌上，写着的是：恩公白大侠之灵
位。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"woods2",
        ]));
        set("objects", ([
                __DIR__"npc/zhaodafang":        1,
                __DIR__"npc/yidajing":  1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1150);
        set("coor/y",50);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
