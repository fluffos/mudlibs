// Room: /d/emei/houshan/shandao.c

inherit ROOM;

void create()
{
	set("short", "山道");
set("outdoors","emei");
	set("long", @LONG
这里是一条小山道，往南就是千佛庵的后门了。往北
分出三条岔道，正北就是峨嵋派的后山了，往西是通往静
修庵和药王洞的小道，往东是通往金顶和九老洞的小道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shandao1",
  "north" : __DIR__"houshan1",
  "south" : "/d/emei/houmen",
  "northwest" : __DIR__"shandao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
