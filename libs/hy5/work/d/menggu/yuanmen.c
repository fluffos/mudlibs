// Room: /d/menggu/yuanmen.c

inherit ROOM;

void create()
{
	set("short", "辕门");
	set("long", @LONG
辕门把兵营和居民帐篷分隔开来.原木的辕门边有守卫监视通行的每
一个人.两排旌旗迎风招展,一条直道向北通向铁木真的营帐.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"buluo1",
  "north" : __DIR__"road1",
]));

	setup();
	replace_program(ROOM);
}
