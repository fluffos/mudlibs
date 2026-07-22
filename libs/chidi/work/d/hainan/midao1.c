// Room: /d/hainan/midao1.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
山腹中的一条密道,十分陡斜,头顶的山石似乎就压到了脑袋上,脚下
是在山石上凿成的石阶,不知道是谁在山腹中开凿了这条山道.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"midao",
  "northup" : __DIR__"midao2",
]));

	setup();
	replace_program(ROOM);
}
