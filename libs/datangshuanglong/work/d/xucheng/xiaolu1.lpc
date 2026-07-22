
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路，看样子很少有人走。南面面好象有一个村子。这里
几乎没有什么人，一片荒凉萧瑟的气氛。四周杂草丛生，只有几只野兔
不时从你的脚前跑过。
LONG);

  set("exits",([
	  "northwest":__DIR__"dadao12",
	  "south":__DIR__"cundong",
	  ]));
  set("outdoors","xucheng");
  set("valid_startroom", 1);
  setup();
 
}

