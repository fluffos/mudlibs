//jnlwang.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "紧那罗王殿");
	set("long", @LONG
大殿正中供奉着紧那罗王的三座塑像。四周的墙壁上绘满了西方胜境，
四十八愿，二十四尊天的壁画，构图宏伟，色彩绚丽，线条流畅，画工精细
。殿中有几名香客正在顶礼膜拜。
LONG
	);

	set("exits", ([
//		"north" : __DIR__"hguangz2",
                "west" : __DIR__"pingtai",
       ]));
         set("objects",([
		CLASS_D("shaolin") + "/dao-pin" : 1,
	        __DIR__"obj/muchui" : 1,
         ]));

		setup();
}



