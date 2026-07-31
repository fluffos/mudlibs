//houyuan.c 后院

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是后院，几个道童很忙碌的走来走去,院四周种着几棵古树,院正中有一口
水井，是全真教生活用水的主要来源。往南是第三殿，往北有一条小路通向后山，
往西是食堂，往东是藏经阁。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaolu1",
		"south" : __DIR__"disandian",
              "west" : __DIR__"shitang",
             "east" : __DIR__"cangjingge",
	]));
	
	set("outdoors", "quanzhen");
	
	setup();
	replace_program(ROOM);
}
