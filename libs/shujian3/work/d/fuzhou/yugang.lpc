// yugang.c 福州渔港
// Lklv 2001.9.11
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"渔港码头"NOR);
	set("long", @LONG
这是福州的一个渔港，岸边停满了渔船。渔夫们正挑着大担大担的鱼走
着，箩里的鱼还在鲜蹦活跳。不远处有十几个乞丐正挨在船边晒太阳，看神
情很是自在。其中有几个叫化子身上还别着两三个布口袋。
LONG
	);
	set("outdoors","福州");

	set("exits", ([
		"enter" : __DIR__"yuchuan1",
		"west" :  __DIR__"haigang",
		"south" : __DIR__"yuchuan1",
        ]));

	set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
                CLASS_D("gaibang/zfdizi") : 1,
	]));

	setup();
}
