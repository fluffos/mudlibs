//xilang4.c 西厢走廊

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
你走在一条长长的走廊上。房顶一侧支在北面的南极殿上，另一侧
则与南边元辰殿的屋顶相连。走廊二边的墙上刻着一只单角铜羊，各部
位是十二生肖的化身，即鼠耳、牛鼻、虎爪、兔嘴、龙角、蛇尾、马脸、
羊须、猴颈、鸡眼、狗腹、猪臀。往南是南极殿，往北是元辰殿。
LONG
	);

	set("exits", ([
	     "north" : __DIR__"yuanchendian",
             "southeast" : __DIR__"nanjidian",
	]));
	setup();
	replace_program(ROOM);
}
