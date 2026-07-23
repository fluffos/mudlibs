
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","村子中心");
  set ("long", @LONG
这里是村子的中心。整个村子不见一个人影，站在这里更有一种恐
怖的感觉。地上有几具尸骸，四周都是烧毁或倒掉的房屋，一股荒凉的
气氛。
LONG);

  set("exits",([
	  "west":__DIR__"cundong",
	  "east":__DIR__"cunxi",
	  "south":__DIR__"tiandi",
	  ]));
  set("outdoors","xucheng");
  set("valid_startroom", 1);
  setup();
 
}

