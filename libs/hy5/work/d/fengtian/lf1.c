// Room: /d/fengtian/lf1.c

inherit ROOM;

void create()
{
	set("short", "柳员外府");
	set("long", @LONG
这里是柳员外的府第，柳员外是盛京南城的有名的善人，家
底荫实，不过近年来
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kd1",
  "east" : __DIR__"lf2",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
