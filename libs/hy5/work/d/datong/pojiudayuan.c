// Room: /open/dt/pojiudayuan.c

inherit ROOM;

void create()
{
	set("short", "破旧大院");
	set("long", @LONG
院子里生满了齐膝高的杂草，风吹过残破的厅堂发出“呜呜”
的声音，大厅的门只剩半扇了，一晃一晃的发出令人牙酸的声音，
似乎有个人正在门背后用力的推着，黑洞洞的门里好像有无数双
眼睛正盯着你看，你不禁打了个哆嗦，还是赶紧离开这地方吧。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu5",
]));

	setup();
	replace_program(ROOM);
}
