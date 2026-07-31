//Cracked by Roath

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "红颜洞");
  set ("long", @LONG

一间占地不大的岩洞，石榻石桌石椅，布置得高雅脱俗。
石桌上放着一副松枝松子所制的棋具，屋角焚着一炉百花
香，散发着淡淡花香。香炉边摆着一具松木瑶琴。百花仙
子闲来无事时，便在此与好友百草仙子、麻姑、织女抚琴
弈棋，消遥自在。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"penglai",
  "south" : __DIR__"baihuajiao",
    "out": __DIR__"bomingyan",
]));
  set("objects", ([ 
     __DIR__"npc/baihua-xianzi" : 1,
     "/d/baihuagu/npc/xiaotong" : 1,
]));
  
  setup();
}
