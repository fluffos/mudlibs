// Room: /d/ruzhou/xiaozheng.c 小镇
// llm 99/02

inherit ROOM;

void create()
{
	set("short", "汝州小镇");
	set("long", @LONG
这里已经进入汝州地界了。小镇不大，但是位于中原驿道旁，南
珲北往的客人便使得这里慢慢繁荣起来了。甚至使得这里的本地人口
甚少，到处都是行色匆匆的江湖客人。
LONG
	);

	set("exits", ([
		"east" : "/d/houjizhen/muqiao",
		"south" : "/d/nanyang/yidao3",
		"north" : __DIR__"ruzhou",
              "west" : __DIR__"yingbin-lou1",
	]));

	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



