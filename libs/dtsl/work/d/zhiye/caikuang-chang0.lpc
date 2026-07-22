// 采矿场入口
// caikuang-chang0.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","采矿场入口");
	set("long",
"这里是一座巨大的矿山的山脚，此地盛产各种矿石，而矿石是打造兵器不
可缺少原料，所以此地经常有采矿工人出没，很是热闹。但是山路也十分陡峭
，山雾还容易造成幻像，所以常常有采矿工人走错方向跌下山崖而死。好在官
府已经在山路的各个险要之处竖立了指示牌以指明方向，同时还派巡捕巡查山
路，防止凶杀事件。
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"northeast" : "/d/huanghe/shulin2",
		"westup" : __DIR__"caikuang-chang10",
	]));
	
	set("outdoors", "扬州郊外");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}