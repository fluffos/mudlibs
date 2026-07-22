
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是合肥的东大街。东边就是合肥的东门了。南边有一家兵器铺，
只听里面传来了乒乓敲打的声音，有几个武士打扮的人从里面走出，神色
满意地看着手中的钢刀。
LONG);

  set("exits", ([ 
	  "west":__DIR__"dongdajie2",
  	  "east":__DIR__"dongmen",
  	  "south":__DIR__"bingqipu",
  ]));
  
  set("objects",([
  	__DIR__"npc/maichanggirl":1,
  ]));

  set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

