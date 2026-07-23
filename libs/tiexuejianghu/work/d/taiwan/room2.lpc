// Room: /d/taiwan/room2.c

inherit ROOM;

void create()
{
	set("short", "依红楼二楼");
	set("long", @LONG
这里是依红楼的二楼,一间空荡荡的屋子,不知怎的,里面充满了一股
烟雾,隐隐带着血腥味道.有一面墙上似乎还写着些字.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "墙" : "已经变成黯黑色的血迹,隐约能看出'魔王....眼睛.....九....'
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tingtang",
]));

	setup();
	replace_program(ROOM);
}
