// Room: d/kyoto/longangate
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "龙安寺正门");
set("long", @LONG
这是龙安寺的正门，牌坊直入云霄，巍巍壮观，朱红色的大门让人
感到庄重和敬畏。再往里去就是高僧云集之所，寺中有可以使神龙安服
的咒符，前代高僧以此治水。
LONG );
set("exits",  ([
        "east"  : __DIR__"longandao2",
      ]));
        setup();
        replace_program(ROOM);
}