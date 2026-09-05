#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", HIM"里屋"NOR);
	set("long", 
	HIM"这是民宅的里屋，看样子是给女孩子住的，一截土炕，上面
铺着绿色的褥子，虽然破旧，但很整洁。桌上摆着一面铜镜，还有一把木梳。
一个姑娘坐在桌边，手托下颚，不知道在想些什么.\n"NOR
	);
	set("objects", ([
                __DIR__"npc/xiaolan" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"minzhai",
                
	]));
   	setup();
	replace_program(ROOM);
}

