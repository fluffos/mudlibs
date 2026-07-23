
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧房");
  set ("long", @LONG
这里就是客栈的卧室了。你来到这里，不禁感到困了，打了一个呵
欠。
LONG);

  set("exits", ([ 
  
	
	  "out":__DIR__"kezhan",
         ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(dir=="out")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}

