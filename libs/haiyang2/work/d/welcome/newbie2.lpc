// Room: /d/welcome/newbie2
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "新手训练室");
  set ("long", @LONG
现在我们假设你已看完新手指南，关于吃喝拜师等事我们就不再多说
，要说的只是关于海洋的一些发展方向。请你先请看看身上带的那本游戏
守则，里面记载着本游戏的一些重要守则，请一定要努力配合，不要给大
家带来不便。本游戏用[1;33mhelp whatsnew[2;37;0m来记录最近的更新信息，请你每次进
游戏来时务必要看一次，以免因游戏的更新给你带来意想不到的损失。
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"newbie3",
  //"oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
