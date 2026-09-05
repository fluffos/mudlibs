//jingtang.c -- 经堂
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"经堂"NOR);
  set("long", @LONG
这里中间供奉着一幅密集金刚像。画像中的金刚，三头六臂，三头中
，各个面目不同，或文静、或忿怒、或威严；六臂中则各持金刚杵、法轮
、莲花、宝剑等法器。画像前的供桌上，贡品、香烛一应俱全。王妃平日
吃斋信佛，还特地从西藏大轮寺重金礼聘得道高僧，每日为汝阳王诵经，
以化解他的冤孽。

LONG
  );
  
  set("objects", ([
		__DIR__"npc/jingtang-fashi" : 1,
	]));

  set("exits", ([     
      "south" : __DIR__"shuzhai",   
      "northeast" : __DIR__"mingyuelou", 
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
