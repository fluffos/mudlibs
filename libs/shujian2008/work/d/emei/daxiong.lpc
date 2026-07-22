// daxiong.c
// 大雄宝殿

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "华藏庵大雄宝殿");
	set("long",@long
这是峨嵋山华藏庵的大雄宝殿。正中供奉着普贤菩萨。一群青衣小师太正
在地上诵经。后面有道小门通往后殿。
long);
	set("exits",([
	    "south" : __DIR__"houdian",
	    "east" : __DIR__"huazanganzt",
	    "west" : __DIR__"huazangancf",
	    "northdown" : __DIR__"huazangangc",
]));
create_door("south", "小门", "north", DOOR_CLOSED);
	setup();
}
