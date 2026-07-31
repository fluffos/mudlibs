// Room: /d/jingcheng/biaoju1.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m振远镖局[2;37;0m");
	set("long", @LONG
振远镖局的创始人是老英雄萧振远。萧老英雄年事已高，早已不过
问江湖是非了。现在镖局的对外事务都由萧振远的次子萧升主理。
而内部事务则有小女萧萧决定。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dchjie2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiao-sh" : 1,
        __DIR__"npc/biaotou" : 2,
        __DIR__"npc/tz-shou" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
