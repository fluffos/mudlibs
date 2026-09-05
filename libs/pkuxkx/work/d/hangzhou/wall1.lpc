// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"

void create()
{
	set("short", "西北宫墙");
	set("long", @LONG
这里是皇城大内宫墙，东面是大内的城门，西南面是凤凰山麓，玉牒所宗正
寺就在不远处。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"heningmen",
		//"south" : __DIR__"heningmen",
		"southwest" : __DIR__"fenghuang",
		"south" : __DIR__"wall2",
	]));
	set("building_type","玉牒所宗正寺");
	set("dirs_to_song",(["north":({"zongzhengsi","北","太庙，宗正寺"}),]));
	setup();
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing_y" : 2,
        ]));
	setup();
	make_entrance();
}

