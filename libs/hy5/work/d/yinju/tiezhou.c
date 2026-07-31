inherit ROOM;

void create()
{
  set("short","铁舟");
  set("long",@LONG
 一叶铁舟，最多也就能载俩个人。舟通体是铁制的，连桨
也是铁的。
LONG);
  set("outdoors","yinju");
   set("exits",([
   "westdown"    : __DIR__"pubu",
   "eastup"  : __DIR__"pengquan",
        ]));
  setup();
}