// Room: d/kyoto/longandao2.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "龙安道");
set("long", @LONG
这是龙安道，是京都城北的交通要冲，人来人往好不繁华，此地因
龙安寺而得名。西面就是龙安寺，是京都著名的寺庙，寺中高僧云集，
寺中有可以使龙安服的咒符，前代高僧以此治水，但是传说这种咒也可
以召唤神龙，被邪恶之徒所得就会祸患人间。
LONG );
set("exits",  ([
        "north"  : __DIR__"longandao1",
        "west"  : __DIR__"longangate",
        "south"  : __DIR__"longandao3",
      ]));
        setup();
        replace_program(ROOM);
}