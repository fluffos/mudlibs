inherit ROOM;

void create()
{
  set("short","厢房");
  set("long",@LONG
这是一间很大的厢房，陈设十分简陋。靠墙放了几张小木床，
西边有张床是空的，你蹑手蹑脚地走了过去。
LONG);
  set("outdoors","yinju");
  set("sleep_room", "1");
set("exits",([
   "south"  : __DIR__"zhulin",
     ]));

  setup();
}
