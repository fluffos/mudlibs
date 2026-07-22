
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","睡房");
  set ("long", @LONG
这里就是洛阳客栈的卧室了。你来到这里，不禁感到困了，打了一
个呵欠。
LONG);

  set("exits", ([ 
  
	
	  "down":__DIR__"kedian",
         ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(dir=="down")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}

