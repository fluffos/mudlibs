// Room: /d/fengtian/jjf4.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
绕过会客厅的屏风就到了皇帝府的天井，天井的入口是个月
亮门，小小的天井里种了不少花草，很有一点曲径通幽的感觉。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lian",
  "west" : __DIR__"jjf3",
  "east" : __DIR__"jjf5",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
