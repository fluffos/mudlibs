// Room: /d/menggu/buluo1.c

inherit ROOM;

void create()
{
	set("short", "铁木真部落");
	set("long", @LONG
铁木真部落是当今大漠最强盛的一族,隐有一统蒙古之势.练绵的帐
蓬望不到边,来往的人们手中多拿着武器,向北去就是辕门.东西两边都
是部落中人居住的蒙古包.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/menggukid.c" : 2,
]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"menggubao1",
  "west" : __DIR__"menggubao",
  "north" : __DIR__"yuanmen",
  "south" : __DIR__"buluo",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
