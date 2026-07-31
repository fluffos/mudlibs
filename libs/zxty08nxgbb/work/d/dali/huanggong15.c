// Room: /d/dali/huanggong15.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "小园");
	set("long", @LONG
这里是勤政殿前的一个小园，适逢茶花盛开的季节，园中的茶花
争奇斗艳，竞相开放。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanggong16",
  "northup" : __DIR__"huanggong13",
]));

	setup();
}

