// Room: /d/city2/ximenwai.c

inherit ROOM;

void create()
{
	set("short", "西门外");
	set("long", @LONG
这里是北京的西城门外。人来人往，煞是热闹。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"ximen",
		"southeast" : "/d/heimuya/road3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
