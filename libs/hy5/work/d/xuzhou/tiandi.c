
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","田地");
  set ("long", @LONG
这里是一片稻田地。但是已经荒芜了，涨满了野草。一阵风吹过，
你不由的打了个寒战！旁边有几棵大树，树枝已经凋零，上面零散地落
着几只乌鸦，朝着天空哑哑地叫着。
LONG);

  set("exits",([
	  "north":__DIR__"cunzhong",
	  "east":__DIR__"dadao3",
	  ]));
  set("outdoors","xucheng");
  set("valid_startroom", 1);
  setup();
 
}

