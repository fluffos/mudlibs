inherit ROOM;

void create()
{
        set("short", "西大街");
	set("long", @LONG
这里是西大街，熙熙攘攘，热闹非凡，两边是鳞立栉比的店
铺，五颜六色的幌子满街飘荡煞是鲜艳。南面有个木匠铺，听说
那里的木匠手艺很是了得。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"xijie1",
                "south" : __DIR__"mujiangpu",
	]));
        set("objects", ([
            __DIR__"npc/flowerg" : 1,
            __DIR__"npc/chike" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

