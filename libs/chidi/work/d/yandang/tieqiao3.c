// Room: /d/yandang/tieqiao3.c

inherit ROOM;

void create()
{
	set("short", "лЗкВге");
	set("long", @LONG
уБйгр╩вЫ©М╫Жа╫Ёъ╣длЗкВге,сий╝хЩ╦ЫлЗкВвИЁи,иоцФ╟закр╩©И©И
╬╟Е,сисз╥Г╢╣хуи╧,дЙ╢З╬цт╤,сп╣д╣ь╥╫ря╬╜ффх╠,геоб╬мйгмРуииН╧х,
╬щк╣Ёёспхк╣Вобх╔.дЦря╬╜въакр╩╟Как,©╢ве╫еоб╡╩╤ор║╩н╣длЗкВ,дЦ╨╕
еб╪╚ак,╩╧йг╥╣╩ь╟и.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao4",
  "south" : __DIR__"tieqiao2",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
