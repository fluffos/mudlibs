// Room: /d/menggu/boershu.c

inherit ROOM;

void create()
{
	set("short", "亲卫营");
	set("long", @LONG
亲卫营是专为保护铁木真和其家人所设立的,多是铁木真的远亲子弟或
武功高强者,地位在一般士兵之上.蒙古人崇尚朴实,所以营帐中除了些刀枪外
就没有些什么奢侈东西.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingwei2.c" : 2,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
