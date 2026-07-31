
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南昌广场");
  set ("long", @LONG
南昌是江西省省会，也是我国的历史文化名城，地处赣中偏北，
赣江和抚河的下游，濒临鄱阳湖，江湖纵横，境内高山、丘岭、平
原相间，地势多变，自然资源丰富。南昌有着悠久的历史文化，南
昌建城2200年以来，一直都是府、州、省、道治所，人文荟萃，楼
台相望，素有“物华天宝，人杰地灵”之美誉。
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie1",
  "north":__DIR__"beidajie2",
  "west":__DIR__"xidajie1",
  "east":__DIR__"dongdajie1",
         ]));
  set("objects",([
	  __DIR__"npc/youke1":1,
	  __DIR__"npc/guniang":1,
"/clone/misc/dache":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

