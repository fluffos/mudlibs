// Room: /d/fengtian/mofang.c

inherit ROOM;

void create()
{
	set("short", "磨坊");
	set("long", @LONG
这是一家老店了，这里磨出的豆浆在全盛京都很有名，另外
他出名的地方就是当年“努尔哈赤”战死沙场后，磨坊店的老
板捐钱买地，在磨坊对面建了一个盛京很著名的“神武祠”，到
今天“神武祠”香火很旺了，而老磨坊也因为年青的老板经营有
方而更兴旺了。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xh2",
]));

	setup();
	replace_program(ROOM);
}
