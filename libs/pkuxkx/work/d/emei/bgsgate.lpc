// Room: /u/cuer/emei/bgsgate.c

inherit ROOM;

void create()
{
	set("short", "报国寺大门");
	set("long", @LONG
这里是一座峨眉山下一座雄伟的寺院，寺宇依山势，逐级升
高，四重大殿结构自然，雄浑大方，掩映在苍楠翠柏之中。寺内
有花圃亭榭，玲珑精致，秀丽多姿。山门内外，香客不绝，颂佛
之声直传到山门外。寺院西面有一座山包，名唤“凤凰包”，东
面是上山的道路，稍往前走就到伏虎寺了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"gchang",
  "west" : __DIR__"fhuang",
  "east" : __DIR__"fuhusi",
  "enter" : __DIR__"bgsddian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
