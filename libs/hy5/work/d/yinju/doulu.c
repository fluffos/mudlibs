inherit ROOM;

void create()
{
  set("short","陡路");
  set("long",@LONG
这是一条陡峭的山路，连山羊都不一定上去。
LONG);
  set("outdoors","yinju");
set("exits",([
   "westdown"    : __DIR__"yangchang",
   "eastup"  : __DIR__"pubu",
        ]));
  setup();
}