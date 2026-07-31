#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "21点牌室");
set("long", "这里是长安乐坊的21点牌室。当夜幕降临后，
这里就格外热闹。进进出出的客人有达官贵人，南来北往的商旅，
浪迹天涯的游子，三五成群的兵士，有时也能看见一些作俗客打
扮的僧人或道士。\n");

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"club",
]));
    set("objects",  ([
    "clone/game/pai21"  :  1,
    ]));
set("no_fight",1);
set("no_npc",1);
  setup();
}

