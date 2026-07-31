// Room: /d/hainan/cave4.c

inherit ROOM;

void create()
{
	set("short", "小山洞");
	set("long", @LONG
从落笔洞壁旁的一个小洞钻下来,你真怀疑自己走错了地方,这个洞
口只能勉强容人通过,连转身都有所不能,洞中十分黑暗潮湿,时有滑溜溜
的动物从身边挤过.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"cave3",
  "northeast" : __DIR__"cave5",
]));
	set("objects",([
		__DIR__"npc/man3":1,
	]));
	setup();
	replace_program(ROOM);
}
