#include <room.h>

inherit ROOM;
void create()
{
	set("short", "东大街");
	set("long", @LONG
这是徐州东大街，同样的宽阔与干净，相比东西大街的要热闹的多
了，街上人来人往，熙熙攘攘，几个小孩正在胡同口玩耍，南面有不少
人围在一起，路边有条狗正在追一只猫。
LONG );
	set("exits", ([
		"southwest" : __DIR__"eastdao",
		"north" : __DIR__"chema",
		"northwest"  : __DIR__"beidajie",
		"east"  : __DIR__"dongmen",
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

