inherit ROOM;

void create()
{
	set("short", "城南官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
北面通往建康府了，东面一条小路可以进无想山。
LONG );
	set("outdoors", "yingtianfu");
	set("exits", ([
		"southeast"     : __DIR__"guandaose1",
		"north" : __DIR__"guandaos1",
		"eastup" : __DIR__"wuxiangw2",
	]));
	setup();
}


int valid_leave(object me,string dir)
{
	if (dir=="eastup"&&!userp(me))
	return 0;
	return ::valid_leave(me,dir);
}