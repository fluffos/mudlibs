// Room: kuxiuzhacang.c

inherit ROOM;

void create()
{
	set("short", "苦修扎仓");
	set("long", @LONG
一座罕见的三角形的大殿堂，以青砖砌成。殿顶及两壁满布大幅彩色壁画，
内容均为佛经中勉励修炼的题材。殿内墙边摆些练功所用的器具，几个弟子正
在你来我往的练习。
LONG
	);

	set("exits", ([
		"north" : __DIR__"jingangyuan",
		"east" : __DIR__"hufazhacang",
	]));
        set("objects", ([ CLASS_D("xueshan") + "/shengdi" : 1 ]));
	setup();
}
