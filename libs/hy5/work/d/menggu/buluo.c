// Room: /d/menggu/buluo.c

inherit ROOM;

void create()
{
	set("short", "铁木真部落");
	set("long", @LONG
铁木真部落是当今蒙古草原上最强盛的一族,由于他有勇有谋,善于用
人,草原上的英雄都愿意为他效力,你目光所到之处,牛肥马壮,连绵的蒙古
包遮盖了举目所见的整的草原.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"buluo2",
  "north" : __DIR__"buluo1",
  "southwest" : __DIR__"caoyuan6",
]));

	setup();
	replace_program(ROOM);
}
