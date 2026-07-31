// Room: d/kyoto/heyuan1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "河原");
set("long", @LONG
这是就河原，是京都的中心大道，连通城内纵横交错的道路网，西
面是西京町，是京都的居住区，往东是河原町，是神社和道场集中的地
区。来此学艺的人络绎不绝。往南是飞架于护城河上的金桥，可以看到
庄严肃穆的京都御所，正是昔日皇宫。
LONG );
set("exits",  ([
        "east"  : __DIR__"heyuanting1",
        "south"  : __DIR__"jinqiao",
        "west"  : __DIR__"xijingting1",
        "north"  : __DIR__"longandao3",
      ]));
        setup();
        replace_program(ROOM);
}