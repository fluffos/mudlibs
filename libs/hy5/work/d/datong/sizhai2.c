// Room: /d/datong/sizhai2.c

inherit ROOM;

void create()
{
	set("short", "私宅");
	set("long", @LONG
这里是一座气派堂皇的住宅。漆黑的大门终日紧闭着，透着
一股神秘之气。你问了一下周围住着的人家，但他们都不知道是
哪位达官贵人住在此处，但瞧着这片宅院的气势，看来住在这里
的不是财大气粗的商人便是武林中赫赫威名的人物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huayanlu5",
//  "north" : __DIR__"zhai2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shaonian" : 1,
]));

	setup();
	replace_program(ROOM);
}
