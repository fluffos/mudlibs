#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "眠龙谷");
	set("long", @LONG
 这是一个人迹罕至的山谷，远方隐约能看见陡峭的山崖，一眼
望去四周都是茫茫的树海，右边有一条蜿蜒小径直入林海之中。
LONG );
	set("exits", ([
		"west" : __DIR__"migong1",
		"east" : __DIR__"migong3",
                           	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
