inherit ROOM;

void create()
{
  set("short","水塘边");
  set("long",@LONG
 你来到了水塘边。好险差点调进了池塘，东面传来隐隐的灯光。
LONG);
  set("outdoors","yinju");
set("exits",([
   "out"  : __DIR__"damen",
  "northeast"  : __DIR__"maowu",
   ]));
  setup();
}
