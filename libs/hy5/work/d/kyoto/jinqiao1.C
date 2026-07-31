// Room: d/kyoto/jinqiao1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "锦桥");
set("long", @LONG
原先这里是一座木桥，后来由能工巧匠用罗马运来的岗石重建，桥栏
光滑如锦缎一般，故得名锦桥。这里往北就是庄严肃穆的皇宫［京都御所］
，南面是京都生活和商业的中心上原。
LONG );
set("exits",  ([
        "north"  : __DIR__"yusuogate",
        "south"  : __DIR__"shangyuan1",
        "west"  : __DIR__"huchenghe3",
        "east"  : __DIR__"huchenghe4",
      ]));
        setup();
        replace_program(ROOM);
}