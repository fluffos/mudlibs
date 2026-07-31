
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是净念禅院的小路。西面是禅院的厨房，那里传了阵阵的饭菜
香气。阵阵梵呗诵经之声，悠悠扬扬的似从遥不可知的远处传来，传遍
寺院。
LONG);

  set("exits", ([ 
	  "eastup":__DIR__"changlang5",
	  "west":__DIR__"chufang",
     ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

