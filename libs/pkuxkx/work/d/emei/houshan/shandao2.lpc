// Room: /u/cuer/emei/shandao2.c

inherit ROOM;

void create()
{
	set("short", "山道");
set("outdoors","emei");
	set("long", @LONG
这是一条山中小道，道上人迹罕至，小道在这里分
出三岔，往东西南通向千佛庵后门，往西南通向九老洞，
往北就是去云海和金顶的路了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shandao",
  "northwest" : __DIR__"yhrkou",
  "southwest" : __DIR__"xiaojin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
