// Room: /dali/bingying.c
// bbb 1997/06/11
// Modify By River 98/12
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是大理御林军的兵营，官兵们在武将的指挥下列队操练，尽管这么多
年没有战事，官兵们还是在认真的排阵，对面就是镇南王府，士兵们不敢有任
何松懈。这里可不是闲杂人等来的地方，你最好还是赶快离开。
LONG
	);

	set("exits", ([
                "west" : __DIR__"dongjie3",
	]));

	set("objects", ([
             	__DIR__"npc/huang" : 1,
		__DIR__"npc/zhangquan" : 1,
                __DIR__"npc/bing" : 3,
	]));
	set("coor/x",-280);
  set("coor/y",-410);
   set("coor/z",-20);
   setup();
}

