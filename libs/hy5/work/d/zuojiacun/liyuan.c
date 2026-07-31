// Room: /d/zuojiacun/liyuan.c

inherit ROOM;

void create()
{
	set("short", "李士元家");
	set("long", @LONG
李士元中过举士，是村里文化最高的人，也算是有钱人了。
他常在外面跑，做一些小买卖，到过不少地方。屋里有一张八仙
桌，墙上挂着一幅字画。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu12",
]));
  	set("objects",([
	"/clone/npc/npc1" : 1,
]));
	setup();
	replace_program(ROOM);
}
