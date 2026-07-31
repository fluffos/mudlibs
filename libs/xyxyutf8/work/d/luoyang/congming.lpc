// Cracked by 凌惊雪 1-3-2003

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "崇明门");
        set("long", @LONG
这里是洛阳城的东门崇明门。西面就到了城中，远望人山人海，往来
行人车流不绝。东面一条大路通向远方。城门下有一些执勤的兵士。
时下虽已天下太平，但一干兵将还是英姿勃勃，警惕的盯着往来人士。

LONG);  
        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"congming2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 3,
        ]));


        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
