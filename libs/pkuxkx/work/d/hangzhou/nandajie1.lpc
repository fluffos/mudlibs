// Room: /hangzhou/nandajie1.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
	set("short", "御街");
	set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。西面通往清波门，东面是雄
武营的驻地。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"xiongwu",
		"south" : __DIR__"nandajie2",
		"west" : __DIR__"xijie",
		"north" : __DIR__"bazi",
	]));
	set("dirs_to_song",(["northwest":({"sinongsi","西北","司农寺"}),"southwest":({"taifusi","西南","太府寺"}),"northeast":({"jiangzuojian","东北","将做监"}),"southeast":({"junqijian","东南","军器监"}),]));
	setup();
	make_entrance();
}

