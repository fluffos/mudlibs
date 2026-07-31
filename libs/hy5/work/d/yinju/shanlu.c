inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
这里是陡峭的山路。一般人不会到这里来，不
小心很容易便会跌堕到崖谷之中。
LONG);
  set("outdoors","yinju");
 set("exits",([
   "east"    : __DIR__"shanpo",
   "west"  : __DIR__"shiliang",
        ]));
  setup();
}