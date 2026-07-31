// Room: /d/zuojiacun/tie.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
你一走进这里，就感到一股热浪扑面而来，铁匠朱英杰挥着
大锤正在打着什么东西。每当大锤落下，就发出叮当的声音，跟
着就见火星四处飞溅。你不自觉得向旁边闪了闪，生怕烫坏了自
己的衣服。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu18",
]));
  	set("objects",([
	"/d/city/npc/smith" : 1,
]));
	setup();
	replace_program(ROOM);
}
