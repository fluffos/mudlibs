// Room: /d/linzhi/lin59.c

inherit ROOM;

void create()
{
	set("short", "巨柏王");
	set("long", @LONG
这是被称为"神树"的古柏树了，树高约50米，干围18米，据
说该树已有2000－2500年历史了。树身上缠挂着许多风马，附近
林中到处是玛尼堆。常有信徒远道前来朝拜。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin58",
  "south" : __DIR__"lin60",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
