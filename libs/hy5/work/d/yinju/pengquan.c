inherit ROOM;

void create()
{
  set("short","喷泉");
  set("long",@LONG
这是因山势而形成的天然喷泉，天然的毫无人工的痕迹。
LONG);
  set("outdoors","yinju");
set("exits",([
   "westdown"    : __DIR__"tiezhou",
   "eastup"  : __DIR__"xishui",
        ]));
  setup();
}