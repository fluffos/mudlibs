// Room: /d/fengtian/wuguan.c

inherit ROOM;

void create()
{
	set("short", "新月武馆");
	set("long", @LONG
新月武馆是当年努尔哈赤为了提倡“尚武”精神，由他的
同门师弟在盛京开的武馆，由于北人尚武，着实有不少人家将自
己的子弟送来学习武功强身健体。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wy3",
	"north" : __DIR__"wuguan2",
]));

	setup();
	replace_program(ROOM);
}
