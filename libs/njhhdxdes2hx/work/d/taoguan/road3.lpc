
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条用石板铺成的山道，两旁是茂密的树木。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road4",
  "southdown" : __DIR__"road2",
]));
	set("outdoors", "taoguan");
	setup();
	replace_program(ROOM);
}
