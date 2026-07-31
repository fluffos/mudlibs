// Room: /d/fengtian/zhai3.c

inherit ROOM;

void create()
{
	set("short", "民宅");
	set("long", @LONG
一所普通的民宅，屋里有一张饭桌，屋角还有一张床，住宅
的采光不太好，所以屋里很昏暗，在这片居民区这样的民宅随处
可见，百姓们在这里过着清苦的生活。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu1",
]));

	setup();
	replace_program(ROOM);
}
