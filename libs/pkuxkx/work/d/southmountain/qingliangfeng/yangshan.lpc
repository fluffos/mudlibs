// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
	set("short", "阳山"+NOR);
	set("long", @LONG
这里是阳山封顶，名虽为山，其实就是一座土丘，比西面的清凉峰矮了不少。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		//"northeast" : "/d/southmountain/shezhai/shezhai2",
		"eastdown" : __DIR__"shanlue3",
		"west" : __DIR__"taizijian",
		//"eastdown" : __DIR__"fengshu",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/shebing" : 2,
        ]));
	set("entry_direction","west");
    set("migong","/d/southmountain/qingliangfeng/qingliang");
    set("migong_posi","north");
    set("look_refuse_msg","这时候清凉峰没啥好去的。\n");
    set("enter_refuse_msg","这时候清凉峰没啥好玩的。\n");
	setup();
}
