inherit ROOM;

void create()
{
  set("short","荷塘");
  set("long",@LONG
 面前是一片荷塘，塘中荷花开的很盛，让人不禁想起一句诗
接天莲叶无穷碧，映日荷花别样红，塘中有许多活蹦乱跳的
鲤鱼。时而跳出水面，是而沉下水底。
LONG);
  set("outdoors","yinju");
set("exits",([
   "west"  : __DIR__"dadian",
  "east"  : __DIR__"zhulin",
        ]));
  setup();
}