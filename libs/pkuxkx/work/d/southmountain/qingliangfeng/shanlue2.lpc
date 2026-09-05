// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
	set("short", "山路"+NOR);
	set("long", @LONG
这里似乎已经行走在山间，西南方向是清凉峰，东面是畲寨。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"southwest" : __DIR__"changgengshang",
		//"northeast" : __DIR__"shanluw4",
		"east" : __DIR__"shanlue1",
		//"eastdown" : __DIR__"fengshu",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/shebing" : 2,
        ]));
	set("entry_direction","southwest");
    set("migong","/d/southmountain/qingliangfeng/qingliang");
    set("migong_posi","south");
    set("look_refuse_msg","这时候清凉峰没啥好去的。\n");
    set("enter_refuse_msg","这时候清凉峰没啥好玩的。\n");
	setup();
}
