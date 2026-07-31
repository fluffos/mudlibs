// Room: /d/huashan/shaluo.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "莎萝坪");
	set("long", @LONG
沿着玉泉，踏过累累石涧，由山径迤逦而上，就来到了莎萝坪。从这里山
路开始陡峭，南面一条迂回盘旋的山道，称作「十八盘」，通往山上。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northwest" : __DIR__"path1",
		"southup" : __DIR__"qingke",
		"northeast" : __DIR__"shanhong",
	]));

	set("no_clean_up", 0);
	set("outdoors", "华山" );

	set("objects", ([ 
		__DIR__"npc/haoke" : 1,
	]));

	set("coor/x",50);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}