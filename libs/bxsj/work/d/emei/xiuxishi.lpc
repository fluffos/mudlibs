// xiuxishi.c 
// 休息室
inherit ROOM;
#include <room.h>
void create()
{
	set("short", "休息室");
	set("long",@long
这里是峨嵋华藏庵的休息室。窗帘拉下来，房里整整齐齐放了很多木床。
有几个夜晚守庵的小师太正在睡觉。
long);
	set("exits",([
	    "north" : __DIR__"huazangancf",
]));
create_door("north", "小门", "south", DOOR_CLOSED);
        set("no_get_from", 1);
	set("sleep_room", 1);
     set("no_fight",1);
	setup();
}
