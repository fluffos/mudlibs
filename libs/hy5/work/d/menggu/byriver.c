// Room: /d/menggu/byriver.c

inherit ROOM;

void create()
{
	set("short", "水塘边");
	set("long", @LONG
草原上的一个小水塘,边上是几棵半枯萎的老树.塘边的青草半拖了到水
中,塘水有些浑浊.塘的北边是个畜栏,东面是个干草堆,旁边的一间小茅屋虽
然简陋,依然能看出江南的风格.
LONG
	);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"river",
  "northeast" : __DIR__"chulan",
  "east" : __DIR__"caodui",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
