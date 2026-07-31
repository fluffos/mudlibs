
// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2050,3950,5}));
	set("short", "香茗坊二楼");
	set("long",
"这是茶楼的二层，附近的文人墨客常喜欢在此品茗作赋。里首摆着个棋盘。\n"
);
        set("exits", ([
                "down"  : __DIR__"tearoom" ]) );

	set("objects", ([
                __DIR__"npc/chess_player" : 1,
	]) );

        setup();

}


