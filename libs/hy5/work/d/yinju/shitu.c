inherit ROOM;

void create()
{
  set("short","实土地");
  set("long",@LONG
 你走在一片实土地上。心理踏实多了，西面传来隐隐灯光。
LONG);
  set("outdoors","yinju");
set("exits",([
   "out"  : __DIR__"damen",
  "southeast"  : __DIR__"maowu",
      ]));
  setup();
}
