//Cracked by Roath
// Room: /d/xiyou/nanhai/zhaifang

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "斋房");
  set ("long", @LONG

这里是普陀山门人弟子们吃饭用斋的场所，桌子上摆着一些
蔬菜水果。由于来此者大多是僧人，因此斋房只提供素席。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zoulang2",
]));

  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
