inherit ROOM;

void create()
{
  set("short","竹林");
  set("long",@LONG
 这是一片茂密的青竹林，一走进来，你仿佛迷失在竹
的海洋中，真是一处隐居的好地方。
LONG);
  set("outdoors","yinju");
set("exits",([
   "west"  : __DIR__"hetang",
  "east"  : __DIR__"shishi",
"north"  : __DIR__"xiangfan",
        ]));
  setup();
}