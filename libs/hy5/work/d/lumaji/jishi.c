// Room: /d/lumaji/jishi.c

inherit ROOM;

void create()
{
	set("short", "马集");
	set("long", @LONG
这是一间用草搭成的棚子，主人杜六儿的四周围着好几个贩
马的人，好像正在和他商量着价钱。这里即买又卖，且方原几十
里内只有这一个马市，所以这里经常如此热闹。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yuan",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
