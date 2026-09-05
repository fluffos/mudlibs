#include <room.h>
inherit ROOM;
void create()
{
	set("short", "雪峰山腰");
set("outdoors","xiangyang");
	set("long", @LONG
这里雪峰的半山腰,面前是陡峭的岩石,连手攀的地方都没有,
一阵寒风吹来,你查点没掉下去!好险好险!你咬咬牙,继续向上攀去.
LONG
	);
	set("exits", ([
		"down" : __DIR__"westr5",
		"up" : __DIR__"xuefeng2",
	]));
	setup();
	replace_program(ROOM);
}

