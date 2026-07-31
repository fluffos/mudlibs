// Room: /d/jingcheng/gzj.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m国子监[2;37;0m");
	set("long", @LONG
国子监是国家培养高级人才的地方。朝庭的学风很浓，在这里不时
可以看到三三两两的学生模样的人大声争辩着什么问题，还有一些
老先生门蹙着眉头匆匆走过，象是在思考着什么问题。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ndj2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiucai" : 2,
        __DIR__"npc/jiaoshou" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
