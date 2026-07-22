
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器库");
  set ("long", @LONG
这里是净念禅院的兵器库。这里放着几把钢刀，铁剑。旁边还有一
个工匠在打磨着兵器。旁边的墙上还贴着一张白纸，上面写着「慈悲为怀」。
LONG);

  set("exits", ([ 
	  "east":__DIR__"caodi1",

         ]));
 set("objects",([
	 __DIR__"obj/staff":2,
	 //__DIR__"obj/blade":2,
	 ]));
  
  set("valid_startroom", 1);
  setup();
 
}

