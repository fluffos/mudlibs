// Room: d/kyoto/wushixingguan
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "武士行馆");
set("long", @LONG
这里是京都的武士行馆，里面可以供武士休息，也有人在里面切磋武
艺，虽然多数都是泛泛之辈，但某一天可能碰到绝顶高手，人们到现在都
还津津乐道于十年前一位其貌不扬的老者居然使出了公认无刀流第一的“
无刀取--居合剑法”。
LONG );
set("exits",  ([
        "north"  : __DIR__"qianbending1",
      ]));
        setup();
        replace_program(ROOM);
}