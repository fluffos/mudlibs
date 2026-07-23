
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","冠冕峰");
  set ("long", @LONG
冠冕峰又名玉雪峰，位于天池正南与天豁峰、天池瀑布相望。冠冕
峰主要为白色的浮石，终年不化的积雪，远眺之四季皆白，雪石难辩，
阳光之下，雪光皑皑。下有蔚蓝色的天池衬托，别具风趣。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"longmen-feng",
"northeast":__DIR__"tianhuo-feng",
"north":__DIR__"wohu-feng", 
         ]));
  set("outdoors","cbs");
  	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

