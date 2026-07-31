// Room: /d/lumaji/roupu.c

inherit ROOM;

void create()
{
	set("short", "肉铺");
	set("long", @LONG
这家肉铺虽然不大，但却能在这里买到别处没有的野味，因
为附近的猎户常到这里来卖一些没用的猎物。店老板坐在柜台后
面抽着汗烟袋，看到你进来冲你笑了笑。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu10",
]));

	set("objects",([
	__DIR__"npc/roupu_boss" : 1,
]));

	setup();
	replace_program(ROOM);
}
