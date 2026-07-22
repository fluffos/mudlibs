inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这里是一家专卖乱七八糟东西的小铺子，据说除了人什么都卖。这
里面的客人很多，店小二在那里忙个不停。因为地方小，所以这里显得
乌烟瘴气。
LONG );
	set("exits", ([
		"west" : __DIR__"nanjie",
	]));
	set("objects",([
	   __DIR__"npc/xiaoer2":1,
	   ]));
	setup();
	replace_program(ROOM);
}

