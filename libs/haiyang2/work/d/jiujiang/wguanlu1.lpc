
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是条官路。这里的道路非常宽敞，四周景色秀丽。不时有大队
的官兵从你的身旁走过，领头的将领不时回头打量着你。东边是九江的
西门了。这里有很多的行人。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"ximen",
 "southwest":__DIR__"wguanlu2",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

