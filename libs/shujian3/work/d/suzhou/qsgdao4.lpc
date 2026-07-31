inherit ROOM;

void create()
{
	set("short", "西门官道");
	set("long",@long
你走在一条青石大道上，人来人往显得非常繁忙，不时地有人骑着马匆匆
而过，大道两旁有一些小货摊，似乎是一处集市。东边通向苏州城西门。
long);
	set("outdoors", "苏州");
	set("exits",([
		"east" : __DIR__"qsgdao3",
		"west" : __DIR__"qsgdao5",
	]));
	set("objects", ([
		NPC_D("poorman") : 1,
	]));
	setup();
}
