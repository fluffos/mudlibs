// Room: /d/menggu/shulin.c

inherit ROOM;

void create()
{
	set("short", "杂树林");
	set("long", @LONG
风动树林,树叶刷刷作响,昏黄的月光下几只绿幽幽的眼睛在林中无声
的移动.突然响起的尖叫令人毛骨悚然,又突兀的停止,东面向上是荒山山
顶,出了林子就是草原.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhucong.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"hill1",
  "west" : __DIR__"caoyuan1",
]));

	setup();
	replace_program(ROOM);
}
