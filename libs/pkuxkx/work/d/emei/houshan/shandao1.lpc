// Room: /u/cuer/emei/shandao1.c

inherit ROOM;

void create()
{
	set("short", "山道");
set("outdoors","emei");
	set("long", @LONG
这是一条山中小道，道上人迹罕至，小道在这里分
出三岔，往西南通向千佛庵后门，往东南通向一条小溪，
往北就是去静修庵和药王洞的路了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"xiaoxi1",
  "northeast" : __DIR__"shandao3",
  "southwest" : __DIR__"shandao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
