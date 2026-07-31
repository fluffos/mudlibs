// Room: d/kyoto/yusuogate
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "御所正门");
set("long", @LONG
抬头一望，城门高耸入云，仿佛要向你压来，华贵中透着不可抗拒的威
严，这里就是京都御所的正门，门内是曾经的皇宫，门外则是天下，感受人
间变化，让人顿生“曾经沧海难为水，除去巫山不是云”的感慨。
LONG );
set("exits",  ([
        "east"  : __DIR__"hongqiao",
        "west"  : __DIR__"yuqiao",
        "south"  : __DIR__"jinqiao1",
      ]));
        setup();
        replace_program(ROOM);
}