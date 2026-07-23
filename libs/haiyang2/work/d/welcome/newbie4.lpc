// /d/welcome/welcome.c
// 海洋II
// 星星(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "侠客行海洋II新手训练室");
  set ("long", @LONG
[1;32m如果你是一个新手就到这里来看一看吧，对你以后的游戏有很大的帮助
你所需要的游戏信息，这里几乎全部可以找到!良好的开始是成功的一半。[2;37;0m
[1;33m键入help -old是完全的帮助系统[2;37;0m
[1;33m键入help shuoming1是新手指南[2;37;0m
[1;33m键入help aboutquest是任务指南[2;37;0m
[1;33m键入help questlist 是秘密列表[2;37;0m
[1;33m键入help menpai是门派介绍[2;37;0m
[1;33m键入help maps是地图大全[2;37;0m
[1;33m键入help whatsnew是新增内容[2;37;0m
[1;33m键入help work是职业系统[2;37;0m
[1;33m键入skills2是查看你的生存技能等级。[2;37;0m
[1;33m键入help wlmm是武林秘密[2;37;0m
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"newbie1",
  //"oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("valid_startroom", "1");
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
