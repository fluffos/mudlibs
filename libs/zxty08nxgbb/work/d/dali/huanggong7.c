// Room: /d/dali/huanggong7.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "曲廊");
	set("long", @LONG
这是正殿后面的一条长长的曲廊，曲廊绕过两边宫殿，下面是
一个小湖。走在桥上，但觉凉风拂体，远处传来阵阵流水声，随风
又送来阵阵花香，深宫庭院，竟然忽有山林野处意境。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanggong5",
  "northeast" : __DIR__"huanggong8",
]));

	setup();
}

