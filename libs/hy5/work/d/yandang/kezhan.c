// Room: /d/yandang/kezhan.c

inherit ROOM;

void create()
{
	set("short","芙蓉客栈");
	set("long", @LONG
客栈门口挂了一串灯笼,上面用红纸贴着四个大字'芙蓉客栈',两
扇木板门有些年头了,已看不出原来的木料,黑沉沉的,旁边的院墙一人
多高,想爬上去真有点困难.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"yuanluo",
  "east" : __DIR__"jiedao2",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
