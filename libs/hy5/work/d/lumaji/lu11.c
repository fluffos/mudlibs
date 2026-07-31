// Room: /d/lumaji/lu11.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在黄土小路上，路的北面是农田，一些农户正在田里忙
碌着。路面被洒上了水，所以没有什么尘土。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nongju2",
  "west" : __DIR__"lu10",
  "northeast" : __DIR__"lu12",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
