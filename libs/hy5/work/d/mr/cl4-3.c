// /u/beyond/mr/cl4-3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"长廊"NOR);
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、家丁
们走来走去，都忙着自己的事情，南面是长廊的延伸。
long);
         set("exits", ([
             "west" : __DIR__"cl4-2",
             "south" : __DIR__"cl4-4",
             "east" : __DIR__"fanting",
]));
        set("objects",([
           __DIR__"npc/jiading" : 1,
]));
         setup();
    //     replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query("family/family_name") != "姑苏慕容"
	&& objectp(present("jia ding", environment(me))))
		return notify_fail("家丁喝道：“到慕容山庄不要乱闯”。\n");

	return ::valid_leave(me, dir);
} 
