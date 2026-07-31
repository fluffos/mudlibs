// Room: /d/fengtian/yizui.c

inherit ROOM;

void create()
{
	set("short", "孙一嘴家");
	set("long", @LONG
一嘴先生是盛京有名的艺术家，hehe一嘴的说的书盛京没人
不爱听的，后来一嘴经常给富人家里去说书，老百姓就很少有机
会听一嘴说书了。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xm4",
]));

	setup();
	replace_program(ROOM);
}
