#include <room.h>

inherit ROOM;
void create()
{
	set("short", "西大街");
	set("long", @LONG
这是徐州西大街，街道宽敞而干净，青砖砌的路面被雨水冲得光明
如镜，街道两侧的瓦房高大而宏伟，双人合抱的杨树十步一株，整齐地
排在两边。大街南面有几家店铺，街道有点冷清。
LONG );
	set("exits", ([
		"north" : __DIR__"jiuguan",
		"northeast" : __DIR__"beidajie",
		"southeast"  : __DIR__"westdao",
                "west" : __DIR__"ximen",
	]));
	set("objects",([
     "/clone/npc/man":1,
     "/clone/misc/dache":1,
     ]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

