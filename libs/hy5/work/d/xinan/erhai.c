#include <room.h>
inherit ROOM;


void create()
{
        set("short", "洱海风光");
        set("long", @LONG
洱海象是嵌在群山之中的一颗明珠。它的北面是俊秀的鸡足山，西面是山顶
覆雪的点苍山，洱海就处在这群山环抱之中，湖水湛蓝，水面平整如镜，映着天
空上的朵朵白云；水边山岩上生着各种各样奇异的花草，湖面上一只只野鸭和大
雁在悠闲地游荡。
    北面大理城背靠点苍，面临洱海，是大理国现在的国都，向西则可登上点苍
山。
LONG
        );
        set("exits", ([
                "south"     : __DIR__"taihe_cun",
                "east"      : __DIR__"nongtian1",
	                "northeast" : "/d/dali/road4",
                "west" : "/d/dali/xiaguan",
        ]));
        set("outdoors","xinan");
	set("objects",([
		__DIR__"npc/xiang" : 1,
		__DIR__"npc/yan"   : 1,
		]) );
        setup();
}
