// Room: /d/yandang/shandong6.c

inherit ROOM;

void create()
{
	set("short", "玲珑洞");
	set("long", @LONG
洞中奇石林立,怪石嶙峋,如虎,如狮,如老僧拜佛,如百舸争流,千姿
百态,引人入胜.近看去,洞中有洞,石上有石.大者险峻,小者玲珑,其奇巧
处,非凡人所思,直是鬼斧神工.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandong5",
  "northup" : __DIR__"shandong7",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/big_stone.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
