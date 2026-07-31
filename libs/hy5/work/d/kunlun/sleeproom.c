// sleeproom.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
set("short","卧室");
	set("long",@long
这里是何太冲最宠爱的第五小妾五姑的卧房。刚一进房，扑鼻便是一股药
气，里面还能闻到一股十分古怪的气息，过了片刻，更觉得这气息忽浓忽淡，
甚是奇特。床上躺着一个人，这人面向帐里，喘气甚急，象是扯着风箱。窗
子(window)都是紧紧关着。
long);

set("item_desc", ([
"window" : "房里很闷，你不禁想打开窗子透透气。\n",
]));

set("objects",([
 "/kungfu/class/kunlun/zhanchun.c" :   1,
]));

set("exits", ([
"east" : __DIR__"tieqinju",
]));
	  set("no_clean_up", 0);
create_door("east", "小门", "west", DOOR_CLOSED);
	  setup();
}
