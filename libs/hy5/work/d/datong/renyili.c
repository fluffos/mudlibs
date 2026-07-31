// Room: /open/dt/renyili.c

inherit ROOM;

void create()
{
	set("short", "任一力饺子馆");
	set("long", @LONG
凡是到过大同的人，没有不知道认一力的大名的，因为他做
的认一力蒸饺香得可以让站在华严路上的人肚子咕咕叫。在这家
和它的名气不大相称的饭庄里还出售太谷饼、平遥牛肉、闻喜煮
饼等名吃，每一件都可以让你吞下你的舌头。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu5",
]));

	set("objects",([
	__DIR__"npc/ren" : 1,
]));
	setup();
	replace_program(ROOM);
}
