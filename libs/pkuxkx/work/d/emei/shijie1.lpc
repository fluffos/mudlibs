// Room: /d/emei/shijie1.c

inherit ROOM;

void create()
{
	set("short", "石阶");
set("outdoors","emei");
	set("long", @LONG
这里是峨眉山的山脚，一条长长的石阶向北延伸，虔
诚的进香客来来往往。沿途很是热闹，不是有小贩沿路叫
买，还有峨眉的女尼和俗家弟子来来往往。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shijie12",
  "northup" : __DIR__"shijie3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
