// Room: d/kyoto/yuzhidaochang
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "宇治道场");
set("long", @LONG
这里就是赫赫有名的宇治道场，道场主人精通天下各种武学，门下弟子
上千，有抱负的青年都投身道场习武，希望有朝一日成为武学泰斗。这里的
武师负责教授各种基本的武功。是个强身健体的好地方。如果投缘，主人便
会告诉你如何找到神道无念流的传人桂小五郎（诚州倒幕派领袖，幕末时期
绯村剑心的上司，剑术高手）。                    .
LONG );
set("exits",  ([
        "south"  : __DIR__"heyuanting3",
      ]));
        setup();
        replace_program(ROOM);
}