// Room: /d/welcome/newbie1
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "新手训练室");
  set ("long", @LONG
如果你肚子饿了可以(eat)，渴了可以(drink)，地上有东西你可以
(get)，当然，你最好还是去买(buy),你也可以把你不用的东西当掉，
(sell),如果你累了，可以睡上一觉(sleep)，当然你必需找到能睡觉的
地方。
海洋的入世之路是一条混沌之路，这路通向的是诡变的江湖，为了你
能在今后的江湖路上过得一帆风顺，建议你先看一遍[1;33mhelp newbie[2;37;0m，在那
里面详细的解说了一个新手在泥潭中的生存之道。要入世，看它是必不可少。
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"newbie2",
 // "oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
