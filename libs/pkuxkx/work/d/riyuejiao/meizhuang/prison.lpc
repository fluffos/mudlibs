//prison.c	梅庄地牢
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","地牢");
	set("long",@LONG 
你一踏进这里，一阵霉气扑鼻而至。这囚室不过丈许见方，靠墙放有一榻(bed)。
屋里甚阴暗潮湿，墙壁上一灯如豆，令人更觉郁闷。
LONG
	);

 	set("item_desc",([
		"bed"	: "这是张铁板床，床上铺着一张席子(xi zi)。\n",
		"xi zi" : "这是一张破席子，胡乱铺在床上。天热时你可以移开(move)它，直接睡在铁板上。\n",
 	   ]));
	set("objects",([
               CLASS_D("riyuejiao") + "/ren" : 1,
		]));
	set("exits", ([
		"out"	: __DIR__"didao3",
	]));
        set("no_task", 1);



	setup();
}

