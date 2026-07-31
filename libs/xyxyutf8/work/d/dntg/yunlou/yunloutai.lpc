#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "云楼台");
  set ("long", @LONG

此乃宫上一小台，远望仙境，见金光万道滚红霞，瑞气千条喷紫
烟。远上长桥碧雾蒙，天宫宝殿映云光。当真是天上自来有仙境，
不堕人间点污泥。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "down": __DIR__"yunlou",
  ]));
  set("objects", ([ /* sizeof() == 3 */
   __DIR__"npc/litianwang":1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
set("outdoors", 1);
  setup();
}


void init()
{
add_action("do_none","bian");
add_action("do_none","ji");
add_action("do_none","kill");
add_action("do_none","get");
}

int do_none()
{
write("OK.\n");
return 1;
}
