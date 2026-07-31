// Room: /d/gaochang/room35.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
一步跨进，脚下喀喇一声，踏碎了一堆枯骨。这是一条仅可容身的狭
长甬道，刀剑四散，到处都是骸骨。火光下只见门后刀痕累累，斑驳凹凸。
走完甬道，慢慢前行，跨过一堆堆白骨，转了个弯，前面突然出现一座大
殿。
LONG );
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room36",
]));
	set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/yusword" : 2,
  __DIR__"obj/yuaxe" : 2,
  __DIR__"obj/skeleton" : 6,
  __DIR__"obj/yublade" : 2,
]));

	setup();
	replace_program(ROOM);
}
