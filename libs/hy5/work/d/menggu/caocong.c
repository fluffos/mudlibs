// Room: /d/menggu/caocong.c

inherit ROOM;

void create()
{
	set("short", "草丛中");
	set("long", @LONG
西方天边黑云重重叠叠的堆积，头顶却是一片暗蓝色的天空，更无片云。
西北风一阵缓，一阵急，明月渐至中天，月旁一团黄晕。月光之下,草丛中
三堆白色的东西，模样甚是诡奇。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/baigu.c" : 3,
  __DIR__"npc/mei" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hill1",
]));

	setup();
	replace_program(ROOM);
}
