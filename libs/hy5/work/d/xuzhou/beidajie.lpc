#include <room.h>

inherit ROOM;
void create()
{
	set("short", "北大街");
	set("long", @LONG
这是徐州北大街，街道宽敞而干净，青砖砌的路面被雨水冲得光明
如镜，街道两侧的瓦房高大而宏伟，双人合抱的杨树十步一株，整齐地
排在两边。
LONG );
	set("exits", ([
		"north" : __DIR__"beimen",
		"southwest" : __DIR__"xidajie",
		"southeast"  : __DIR__"dongdajie",
	]));
	set("objects",([
     "/clone/npc/man":1,
     ]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

