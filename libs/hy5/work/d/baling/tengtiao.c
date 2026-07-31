
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",YEL"山间飘荡的藤条"NOR);
  set ("long", @LONG
你双手紧紧的抓着一根长长的藤条，藤条的另一端透过迷迷蒙蒙的 
白雾伸向大河对岸的山崖。风，在耳边呼啸，湍急的黄河水在下面奔腾， 
你不由闭上了双眼，身子向着对面山崖荡了过去，口中还声嘶力竭的喊 
着：“啊——啊——啊啊啊......”。 
LONG);

 set("outdoors","tengtiao");
  set("valid_startroom", 1);
  setup();
 
}

