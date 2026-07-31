// Room: /d/yanjing/cave.c

inherit ROOM;

void create()
{
	set("short", "洞穴内");
	set("long", @LONG
四下里黑呼呼的,浑看不清些什么,头顶的入口离地面约四五丈高.
月光从头顶洒下来,地上散落着几个死人骷髅头,由脚下的感觉来看,显
然是硬泥地,凭你的武功,看来无法跃出洞去.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"gardon1",
  "north" : __DIR__"didao",
]));

	setup();
	replace_program(ROOM);
}
