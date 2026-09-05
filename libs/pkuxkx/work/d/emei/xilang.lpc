// Room: /u/cuer/emei/xilang.c

inherit ROOM;

void create()
{
	set("short", "西廊");
	set("long", @LONG
这里是两条长廊交汇的地方，往东可到千佛庵大殿，
往西就可以出西侧门到雷动坪或太子坪练功了，往南往
北都是师太们的禅房了。				
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xicemen",
  "north" : __DIR__"xilang3",
  "south" : __DIR__"xilang2",
  "east" : __DIR__"xilang6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
