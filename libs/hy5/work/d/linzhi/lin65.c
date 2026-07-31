// Room: /d/linzhi/lin66.c

inherit ROOM;

void create()
{
	set("short", "列山古墓群");
	set("long", @LONG
这里就是列山古墓群了，气势宏伟，构筑奇特，整个墓群延
绵几公司，这在西藏境内殊难再见。你走到这里，突然感到莫名
的恐惧，似乎沉睡地下的法老在呼唤着你的灵魂，你不禁加快了
脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin66",
  "southeast" : __DIR__"lin64",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}

