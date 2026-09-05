//liwu.c	朱雀堂里屋
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","朱雀堂里屋");
	set("long",@LONG 
这是朱雀堂的里屋，是堂下弟子休息娱乐的地方。正中央
的八仙桌上还摆着残酒剩菜，显然是刚刚有过一场大宴，椅子
上作着一位老者。
LONG
	);

	set("exits", ([
		"south" : __DIR__"zhuquetang",
	]));
	set("objects",([
               CLASS_D("riyuejiao") + "/xiang" : 1,
		]));

	setup();

}

