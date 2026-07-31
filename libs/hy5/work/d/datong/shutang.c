// Room: /open/dt/shutang.c

inherit ROOM;

void create()
{
	set("short", "书堂");
	set("long", @LONG
几十名少年正在跟着教书先生念书，一阵朗朗的读书声在书
堂中回荡。大同人尚武，所以一般人家的孩子很少有到书堂念书
的，这儿的这些少年多是官宦子弟。教书先生是一位老学究，戴
着一副眼镜，摇头晃脑的只顾念书，似乎没有觉查你的到来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu3",
]));

	setup();
	replace_program(ROOM);
}
