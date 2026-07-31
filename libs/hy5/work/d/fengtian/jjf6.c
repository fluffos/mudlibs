// Room: /d/fengtian/jjf6.c

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
皇帝府的后花园很大，花园里还有一个小的湖，上面厅台楼
榭修的十分别致，在夏天这个后花园十分美丽。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jjf5",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
