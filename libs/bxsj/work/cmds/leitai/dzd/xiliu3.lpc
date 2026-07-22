// Room: /d/dzd/xiliu3.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","溪流");
	set("long",@LONG
走到这里，你突然眼前一亮，清澈的溪水顺流而下。溪边长着无数奇花异草，散发出
浓郁的香气，仔细辨认着，发现其中水仙花模样的，竟是极其罕见的醉仙灵芙。西面是一
片草地，东边是一片黑压压的森林,北面是一个大瀑布。
LONG
	);
	set("outdoors","大智岛");
	set("exits",([
		"east" : __DIR__"senlin4",
		"west" : __DIR__"caodi3",
		"north" : __DIR__"pubu",
		"south" : __DIR__"xiliu2",		
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
	if(userp(me) && me->query("no_poison")) {
		ob = present("flower",environment(me));
		ob->delete("poison");
		me->delete("no_poison");
	}
	return ::valid_leave(me, dir);
}
