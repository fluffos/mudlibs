
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是净念禅院的长廊。南面是禅院的正殿大雄宝殿。北面是禅院
的藏经阁。阵阵梵呗诵经之声，悠悠扬扬的似从遥不可知的远处传来，
传遍寺院。
LONG);

  set("exits", ([ 
	  "north":__DIR__"changlang3",
	  "southdown":__DIR__"daxiong-baodian",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

