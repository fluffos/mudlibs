// Room: /d/huashan/qingke.c
// Date: Look 99/03/25

#include <wanted.h>

inherit ROOM;

void create()
{
	set("short", "青柯坪");
	set("long", @LONG
走过崎岖的十八盘，穿过云门，就到了青柯坪。青柯坪是一山间盆地，地
势略为平坦。从这里开始，上山的路都是由原地凿出的石阶。北壁下一块大石
当路，此石叫做回心石，再上去山道奇险，游客至此，就该回头了。
　　远远望见一个小小石亭，便是赌棋亭了。相传宋太祖与华夷先生曾弈棋于
此，将华山作为赌注，宋太祖输了，从此华山上的土地就不须缴纳钱粮。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shaluo",
		"eastup" : __DIR__"qianchi",
	]));

	set("objects", ([ 
		__DIR__"npc/haoke" : 1,
	]));

	set("outdoors", "华山" );

	set("coor/x",50);
  set("coor/y",80);
   set("coor/z",10);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "eastup" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
