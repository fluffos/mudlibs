#include <room.h>

inherit ROOM;
void create()
{
	set("short", "酒馆");
	set("long", @LONG
这是一家小酒馆，紧挨着徐州西门，五开间的门面，规模颇颇大。
来来往往的行人多到这里来打尖歇脚，叫上一盘阿訇宰杀的牛羊肉，喝
上几口醇香的马奶酒，酒足饭饱离店之际带上几个有脸盆大小的馕，花
钱不多又很实惠，生意特别兴旺。北面是厨房，南面是上楼的楼梯，东
面有条布帘。
LONG );
	set("exits", ([
		"south" : __DIR__"xidajie",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

