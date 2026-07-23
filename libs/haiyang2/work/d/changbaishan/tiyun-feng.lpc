
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","梯云峰");
  set ("long", @LONG
梯云峰岩石裸露，形状如梯。传说此峰直通天宫，是天庭和人间相
连的天梯，因此叫梯云峰。山头终年云雾缭绕，即使是晴天也看不清峰
顶的轮廓。北面就是玉柱峰。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"yuzhu-feng",
 "southwest":__DIR__"longmen-feng",
// "eastdown":"/d/clone/room/lingwu/jingzhai/wolong1",
         ]));
  set("outdoors","cbs");
  	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

