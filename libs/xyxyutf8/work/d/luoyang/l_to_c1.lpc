//洛阳洛阳近郊
#include <room.h>
inherit ROOM;

void create()
{       
set("short", "洛阳南郊");
set("long", @LONG
这里是洛阳的南郊，虽然已是郊区，但来往的旅客依然是络绎不绝，
前方便是洛阳的乾元门。
沿着脚下宽阔笔直的大路向南走，便能到达两京地带。

LONG);  
set("exits", ([
        "north" : __DIR__"qianyuan",
        "south" : __DIR__"l_to_c2",
]));
set("outdoors", "luoyang");
set("no_close",1);
set("day_open",1);
create_door("north", "乾元门", "south", DOOR_CLOSED); 
setup();
replace_program(ROOM);
}

