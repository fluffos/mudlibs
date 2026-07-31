// Room: /d/wizard/fightroom1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "比武场正门");
    set("long", @LONG
你现在正站在演练场的入口，两只巨大的石狮镇守在大门的两侧，里面是
各路武林好汉比试武艺的擂台，不时传来兵刃相交的声音，通过大门往南是武
林大会场的出口。
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"fightroom2",
  "south" : __DIR__"fightroom4",
]));
    setup();
}
int valid_leave(object me, string dir)
{
    mixed *local;
    local=localtime(time());
//     if ( dir=="east" && (local[6]==6 || local[6]==0) )
//      return notify_fail("今天比武场不开放!\n");
          if (!userp(me) && dir=="east")         return 0;
      return ::valid_leave(me, dir);
}
