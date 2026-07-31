inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
你的眼前出现了一个美丽的花园，花园里种着一些奇花，花从中隐约可
见一些靓女们在玩耍。花园中央有一座假山，假山旁有一个美丽的水池。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fyue_room",
]));

	setup();
	replace_program(ROOM);
}
