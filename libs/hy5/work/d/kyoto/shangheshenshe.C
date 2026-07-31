// Room: d/kyoto/shangheshenshe
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "上贺神社");
set("long", @LONG
密密的树丛掩映中，隐约可见一间古刹，原来这里就是上贺神社，据
说这里封印了上古时期可怕的力量。只有胸怀救世之心或是想毁灭人间的
人才能获得这种力量，然而对于人间却会产生两种截然不同的结果。
LONG );
set("exits",  ([
        "west"  : __DIR__"juechuan",
      ]));
        setup();
        replace_program(ROOM);
}