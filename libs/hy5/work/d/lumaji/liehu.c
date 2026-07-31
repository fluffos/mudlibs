// Room: /d/lumaji/liehu.c

inherit ROOM;

void create()
{
	set("short", "赵猎户家");
	set("long", @LONG
这里就是赵猎户家。赵猎户以打猎为生，所以经常不在家。
有时打猎回来，就把一些多下的猎物卖给肉铺老板。由于他技艺
高超，常有人来找他出高价请他打一些稀少的野味。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu13",
]));

	set("objects",([
	__DIR__"npc/liehu_zhao" : 1,
]));

	setup();
}

int valid_leave(object ob,string dir)
{
	ob->delete_temp("liehu_zhao");
	return ::valid_leave(ob,dir);
}