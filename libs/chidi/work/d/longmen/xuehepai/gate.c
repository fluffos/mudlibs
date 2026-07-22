// gate。c  大门
// mlf设计，lks编程

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short","血河派大门");
	set("long",@LONG
这里是血河派的大门，大门上方跳出四角飞檐，两侧立有四根大理石
柱，柱身纹有图腾底案。大门上正中悬挂一块金匾，刻有“血河天下”四
个血红大字，笔力遒劲，为开山祖师盛长风所书。外沿的两根柱上钉着两
块竖匾一边是“大江东来，落日西尽，梧桐一夜碧落”，一边是“九天西
去，极登金顶携伴江湖遨游”。书生意气，豪情壮志，油然而生。
LONG);
	set("valid_startroom",1);
	set("outdoors","龙门");
	set("exits",([
        	"north" : __DIR__"xuehuatang",
        	"south" : "/d/longmen/shanlu5",
	]));
	setup();
              replace_program(ROOM);
}
