// Room: /d/fengtian/jiuguan.c

inherit ROOM;

void create()
{
	set("short", "小酒馆");
	set("long", @LONG
酒馆不大，内有四五张方桌，不少对面威远镖局的镖头在这
里喝酒，还有一些不当差的衙役也经常在这里小聚。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xm1",
]));

	setup();
	replace_program(ROOM);
}
