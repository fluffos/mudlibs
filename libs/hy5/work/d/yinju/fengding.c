inherit ROOM;

void create()
{
  set("short","峰顶");
  set("long",@LONG
 这里是无名的山岭的峰顶，怪石攒簇，最高的地方一石
卓立，有擎天之势，。
LONG);
  set("outdoors","yinju");
set("exits",([
   "down"    : __DIR__"xishui",
   "west"  : __DIR__"pingdi",
        ]));
  setup();
}