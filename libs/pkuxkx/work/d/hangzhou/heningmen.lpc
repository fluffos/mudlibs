// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
	set("short", "和宁门");
	set("long", @LONG
这里是皇城大内的北门，也是御街的起点。附近一大片建筑正是大宋中枢所
在。
LONG
	);
        set("outdoors", "hangzhou");
	
	set("exits", ([
		"east" : __DIR__"walla",
		"south" : __DIR__"palace/heningnei",
		"west" : __DIR__"wall1",
		"north" : __DIR__"nandajie2",
	]));
	set("building_type","中枢");
	set("dirs_to_song",(["north":({"heningbei","北","中枢"}),"south":({"heningnan","南","六部"}),"west":({"heningxi","西","台谏"}),"east":({"heningdong","东","三司使，兵部，步马都"})]));
	set("is_GaTe",1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing_y" : 2,
        ]));
	setup();
	make_entrance();
}

