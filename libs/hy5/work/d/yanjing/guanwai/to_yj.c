// Room: /d/yanjing/to_yj.c

inherit ROOM;

void create()
{
	set("short", "燕京大道");
	set("long", @LONG
这条道向西北直通[金]的都城[燕京],西北边是个三叉路口,分别通
向漠北蒙古和京城,道上的积雪还未完全溶化,许多已经冻成冰凌,踩上去,
吱吱的响.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/guanwai/road8",
  "northeast" : __DIR__"to_yj1",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
