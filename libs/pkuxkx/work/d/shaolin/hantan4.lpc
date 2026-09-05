// Room: /d/shaolin/hantan4.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "古洞");
        set("long", @LONG
这是在洞中，微弱的油灯下，坐着一个老僧，正在入定。
LONG
        );
        set("objects",([
//        "/kungfu/class/shaolin/wuming":1,
        "/kungfu/class/shaolin/wuming2":1,
         ]));
        set("exits", ([
              "up" : __DIR__"tianjing",
         ]));
        set("no_task", 1);
        setup();
}

int valid_leave(object me, string dir)
{
  int i, ifind;
  object *ob;
  
  ifind = 0;
  ob = all_inventory( environment( me ));
  for(i=0; i<sizeof(ob); i++)
  {
    if( ob[i]->query("id") == "wuming laoseng" )
    {
      ifind = 1;
    }
  }
  
  if ( ifind )
  {
    return ::valid_leave(me, dir);
  }

	// when wuming is here || not find wuming 
        return notify_fail("你让少林寺的高僧不醒人事，那些和尚不会善罢甘休吧？\n");
}

