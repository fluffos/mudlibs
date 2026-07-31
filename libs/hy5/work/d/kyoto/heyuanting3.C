// Room: d/kyoto/heyuanting3.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "河原町");
set("long", @LONG
这里就是著名的河源町，是神社和道场集中的地方，北面就是赫赫有名
的宇治道场，道场主人精通天下各种武学，门下弟子上千，有抱负的青年都
投身道场习武，希望有朝一日成为武学泰斗。
LONG );
set("exits",  ([
        "north"  : __DIR__"yuzhidaochang",
        "west"  : __DIR__"heyuanting2",
      ]));
        setup();
        replace_program(ROOM);
}