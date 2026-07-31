// Room: /d/yanjing/zoudao.c

inherit ROOM;

void create()
{
	set("short", "小走道");
	set("long", @LONG
小走道两边摆着些散架的家具.益发使得走道狭窄,两边没有灯,从
两边门口透进来的天光,使这地方显然变的朦胧了些,几只老鼠在你脚边
经过,还回头看了你几眼.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tianjin",
  "east" : __DIR__"gaosheng",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
