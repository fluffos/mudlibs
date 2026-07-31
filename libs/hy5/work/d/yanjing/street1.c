// Room: /d/yanjing/street1.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
盛京的金的都城,店铺林立,行人如鲫,每当一队队的金兵经过之时,
喧闹的街道顿时变得一片死寂,连道边的黄犬都不敢吠叫.这街道的东面
是一家药铺,来往的人还挺多.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/person.c" : 1,
]));
	set("outdoors", "yanjing");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street4",
  "south" : __DIR__"street",
  "east" : __DIR__"yaopu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
