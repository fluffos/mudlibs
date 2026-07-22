// Room: /d/dzd/xiliu1.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","溪流");
	set("long",@LONG
走到这里，你突然眼前一亮，清澈的溪水顺流而下。溪边长着无数奇花异草，散发出浓郁
的香气，仔细辨认着，发现其中水仙花模样的，竟是极其罕见的醉仙灵芙。西面是一片草
地,东边是一片树林。
LONG
	);
	set("outdoors","大智岛");
	set("exits",([
		"east" : __DIR__"shulin1",
		"west" : __DIR__"caodi1",
		"north" : __DIR__"xiliu2",
		"south" : __DIR__"haitan1",
	]));
	set("objects",([
		__DIR__"npc/eyu" : random(2),
		__DIR__"npc/obj/flower" : 1,
	]));
	setup();
}

int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && me->query_temp("dzd_quest/no_poison")) {
		ob = present("flower",environment(me));
		if(ob) ob->delete_temp("poison");
		me->delete_temp("dzd_quest/no_poison");
	}
	return ::valid_leave(me, dir);
}
