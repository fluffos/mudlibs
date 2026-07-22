// Room: /d/chengdu/niangjiuwo.c
// oooc: 1998/6/28

inherit ROOM;

void create()
{
	set("short", "酿酒屋");
	set("long", @LONG
你来到一座老式的房子中间。在你的左手面有一个很大很大的
木桶，约有二人多高。在木桶的上面，站着几个精赤着上身的大汉，
手里拿着竹竿在奋力的朝木桶搅动着。正前方站着一个半老的徐娘，
在和几个小伙子眉来眼去地说笑着。
LONG
	);

	set("exits", ([
                "northwest" : __DIR__"xiaojie3",
	]));

	set("objects", ([
		__DIR__"npc/wangerniang" : 1,
		__DIR__"npc/xiaohuozi" : 3,
	]));

	setup();
	replace_program(ROOM);
}

