// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
西面是成都城，往东北方向就是著名的蜀道了。
LONG );
	set("outdoors", "chengdu");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast"     : __DIR__"shudao1",
		"west" : __DIR__"eastgate",
	]));
	setup();
	
}

int valid_leave(object me, string dir)
{
	me->set_temp("shudao/last_go_time",time());
	return ::valid_leave(me, dir);
}