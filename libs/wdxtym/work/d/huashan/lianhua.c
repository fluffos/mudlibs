// Room: /d/huashan/lianhua.c

inherit ROOM;

void create()
{
	set("short", "莲花峰");
	set("long", @LONG
太华西峰－又名莲花峰，也叫芙蓉峰，峰顶有一块巨石，状如莲花，覆盖
崖巅。该处由此得名。这里悬崖陡峭，壁立千仞，登临远眺，秦川莽莽，渭、
洛二水盘屈如带。峰顶有石名“摘星石”，取“手可摘星辰”之意，以状西峰
之高。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	     "eastdown" : __DIR__"chengxiang",
	]));
	set("outdoors", "huashan");

	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/lianhua", 1);
	return;
}
