// Room: /d/xiaozhen/biaoju3.c

#include <room.h>

inherit ROOM;


void setup();

void create()
{
	set("short", "内室");
	set("long", @LONG
这里是镖局的内室，接了镖还没来得及运走的货物都先存放
在这里。西面有一扇铁门。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"biaoju2",
]));
	set("objects",([
	__DIR__"obj/tie_xiang" : 3,
]));

if (random(30)==0)
	{
	set("objects",([
		__DIR__"obj/sword_and_qiao" : 1,
		__DIR__"obj/letter" : 1,
	__DIR__"obj/tie_xiang" : 3,
]));

	}
	setup();

}

