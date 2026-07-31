// Room: /d/menggu/maowu.c

inherit ROOM;

void create()
{
	set("short", "郭家茅屋");
	set("long", @LONG
几根粗糙的木头搭起一个架子,上面的树皮都还没剥落.塞北草原长长
的茅草覆盖在木头上,组成这个小茅屋.里面的一切都是江南模式,用木头草草
搭起的床,一边是个泥土灶,一边的墙上还开了个小窗.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/liping.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"caodui",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
