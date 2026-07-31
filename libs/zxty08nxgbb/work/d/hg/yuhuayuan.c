// Room: /u/cass/hg/yuhuayuan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "御花园");
	set("long", @LONG
园门上面桶花泥鳅瓦，那门栏窗格，皆是细雕新鲜花样，并无朱粉涂饰，
一色水磨群墙下面白石台矶，凿成西番草花样，左右一望，雪白粉墙下面虎
皮石随势砌去，果然不落富丽俗套。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kunninggong",
  "north" : __DIR__"jiashan",
]));

	setup();
	replace_program(ROOM);
}
