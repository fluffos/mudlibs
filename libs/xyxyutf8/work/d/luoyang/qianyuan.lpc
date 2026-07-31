// Cracked by 凌惊雪 1-3-2003
//扩展 snowtu 2007/06
#include <room.h>
inherit ROOM;

void create()
{       
set("short", "乾元门");
set("long", @LONG
这里是洛阳城的南门乾元门。北面就到了城中，远望人山人海，往来
行人车流不绝。南面一条大路通向远方。城门下有一些执勤的兵士。
时下虽已天下太平，但一干兵将还是英姿勃勃，警惕的盯着往来人士。

LONG);  
set("exits", ([
        "north" : __DIR__"qianyuan2",
        "south" : __DIR__"l_to_c1",
]));
set("objects", ([ 
        __DIR__"npc/wujiang" : 1,
        __DIR__"npc/bing" : 3,
]));
set("outdoors", "luoyang");
set("no_clean_up", 0);
set("no_close",1);
set("day_open",1);
create_door("south", "乾元门", "north", DOOR_CLOSED); 
setup();
replace_program(ROOM);
}

