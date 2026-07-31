// Room: /d/heifeng/lu4.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你来到了山半腰，一条平坦的山路向北面延伸，西面一条崎
岖的小路通向山下，路边是陡峭的山壁，顺着山壁向上望去云雾
缭绕中的山顶隐约可见。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lu5",
  "westdown" : __DIR__"lu3",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
