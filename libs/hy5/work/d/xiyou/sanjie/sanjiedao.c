// sanjie sanjiedao.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "三界岛");
  set ("long", @LONG
	
	　　　天	　纯	　　　天
	　　　妖	　阳	　　　魔
	　　　降	　先	　　　降
	　　　世	　师	　　　临

	　　　凡	　降	　　　大
	　　　间	　魔	　　　难
	　　　必	　伏	　　　临
	　　　乱	　妖	　　　头

		　　　＃＃＃＃＃
		　　　＃指路牌＃
		　　　＃＃＃＃＃

			天一宫
			　↑	
		　天妖宫　|　天魔宫
			\ | /
			 \|/
			三界岛

不知不觉已经走到半山腰，这里四处无物，有的只有怪石，
分别有三个路口，不知道分别通向什么地方，看来要仔细查
看方能找到自己想去的地方。
LONG);

  set("exits", ([ 
  "northup" : __DIR__"tianyilu1",
  "northwest" : __DIR__"tianyaolu1",
  "northeast" : __DIR__"tianmolu1",
  "east" : __DIR__"langerdian1",
  "down" : __DIR__"shanlu9",
]));
  set("outdoors", 1);
  
  setup();
}
