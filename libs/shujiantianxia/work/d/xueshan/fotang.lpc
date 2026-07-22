// Room: fotang.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "镜庐佛堂");
	set("long", @LONG
一座不大的小佛堂。歇山顶，脊吻作龙象禽兽饰，四角垂有铜铃，每当
风动，铃声清脆。窗外一泓泉水，深约三丈，水平如镜，可鉴毛发，泉边松
柏掩映，极尽清幽雅静。堂外小路一头通向后山，另一条尽头是扇黑漆木门。
LONG
	);

	set("exits", ([
		"west" : __DIR__"lingtalin",
		"southeast" : __DIR__"fanyinge",
	]));

	setup();
	create_door("southeast", "黑漆木门", "northwest", DOOR_CLOSED);
}
