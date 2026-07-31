// Room: d/kyoto/heyuanting2.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "河原町");
set("long", @LONG
这里就是著名的河源町，是神社和道场集中的地方，北面就是赫赫有名
的吉田神社，传说这里的创始者吉田佳光是战国时期著名的神官，能呼风唤
雨，当时身任有“风林火山，战国之虎”之称的武田信玄的大夫大将。凭借
召唤神兽帮助武田信玄一统川中岛。其玄术流传至今，随后人不能呼风唤雨
，但仍旧威力无穷。故前来投师学艺者成千上万。
LONG );
set("exits",  ([
        "east"  : __DIR__"heyuanting3",
        "north"  : __DIR__"jitianshenshe",
        "west"  : __DIR__"heyuanting1",
      ]));
        setup();
        replace_program(ROOM);
}