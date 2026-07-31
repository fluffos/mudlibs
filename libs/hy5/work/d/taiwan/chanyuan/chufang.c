
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","厨房");
  set ("long", @LONG
这里是净念禅院的厨房。禅院的弟子就在这里吃饭。有几个火工头
陀正在那里做饭。前面的桌子上放着几碗米饭，旁边还放着几碗清水。
LONG);

  set("exits", ([ 
	  "east":__DIR__"xiaolu5",
    ]));
  set("objects",([
	  __DIR__"obj/rice":4,

	  ]));
  set("resource/water",1);

  
  set("valid_startroom", 1);
  setup();
 
}

