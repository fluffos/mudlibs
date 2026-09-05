// Room: /d/beijing/bingbuyamen2.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"兵部府衙"NOR);
        set("long",
CYN"衙内十分宽敞高大，四周墙壁之上挂有各式各样几十件的兵器，除了
刀剑之类普通的武器外，最显眼的就是那几把罗刹国制造的火枪，有长有
短，都制作得十分的精美，正堂一张大案上铺着张地图，图上画有许多圈
圈点点的符号。\n"NOR
        );

        set("exits", ([
                "north" : __DIR__"bingbuyamen",

        ]));
        set("objects", ([
			__DIR__"npc/bb_shilang":1,
                            __DIR__"npc/mingzhu":1,

        ]));
        setup();
        replace_program(ROOM);
}


