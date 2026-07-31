// Room: d/kyoto/jitianshenshe
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "吉田神社");
set("long", @LONG
这里就是赫赫有名的吉田神社，传说这里的创始者吉田佳光是战国时期
著名的神官，能呼风唤雨，当时身任有“风林火山，战国之虎”之称的武田
信玄的大夫大将。凭借召唤神兽帮助武田信玄一统川中岛。其玄术流传至今
，虽后人不能呼风唤雨，但仍旧威力无穷。故前来投师学艺者成千上万。门
口放有一堆巨石，上书“有缘人来”四个大字，左右各立有四个神木。上面
密密麻麻刻着经文和咒文。

LONG );
set("exits",  ([
        "south"  : __DIR__"heyuanting2",
      ]));
        setup();
        replace_program(ROOM);
}