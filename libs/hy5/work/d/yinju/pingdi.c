inherit ROOM;

void create()
{
  set("short","平地");
  set("long",@LONG
 过了峰顶忽然一片开阔的山地，平坦如砥。
LONG);
  set("outdoors","yinju");
set("exits",([
   "east"    : __DIR__"fengding",
   "west"  : __DIR__"shanpo",
        ]));
  setup();
}