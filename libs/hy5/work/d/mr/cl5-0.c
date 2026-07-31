// /u/beyond/mr/cl5-0.c
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
们走来走去，都忙着自己的事情，不敢有一点怠慢。长廊西面是书房，南面是
长廊的延伸。
long);
         set("exits", ([
             "south" : __DIR__"cl5-1",
              "east" : __DIR__"fanting1",
             "west" : __DIR__"shufang",
]));
          set("objects",([
__DIR__"npc/guanjia1" : 1,
]));
         setup();
 //        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query("family/family_name") != "姑苏慕容"
	&& objectp(present("guan jia", environment(me))))
		return notify_fail("管家喝道：“到慕容山庄不要乱闯”！\n");

	return ::valid_leave(me, dir);
} 
