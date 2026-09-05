// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
#include <ansi.h>
void create()
{
	set("short", HIM"凤凰山"NOR);
	set("long", @LONG
临安皇城依凤凰山而建，登临凤凰山，可以俯瞰全城。北面的道路却被一队
兵丁把守着。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"southeast" : __DIR__"wall2",
		"up" : __DIR__"fenghuang2",
		"northeast" : __DIR__"wall1",
		"west" : "/d/southmountain/dongtianmu/fenghuangxi",
	]));

	set("building_type","瑞石山");
	set("dirs_to_song",(["north":({"ruishi","北","太庙，宗正寺"}),]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing_y" : 2,
        ]));
	set("forbid_npc_dir","west");
	setup();
	make_entrance();
}
