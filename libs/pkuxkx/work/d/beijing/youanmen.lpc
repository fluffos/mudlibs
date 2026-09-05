//Cracked by Roath
// Room: /d/beijing/youanmen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT = HIY"右安门"NOR;
string GATE_DESC_LONG =
HIC"这里是京城外城门之一。由于距离繁华地段较近，你似乎觉得从这里就能听
见天桥的说书的，卖唱的声音。门外是通向永安门和广安门的土路。远远的你能
看见一些农田，与城里的气氛截然不同。城门上贴了一张告示 (gaoshi)。\n"NOR;
mapping GATE_EXITS=([ /* sizeof() == 4 */
  "north" : __DIR__"youandajie",
  "east"  : __DIR__"tulu_youan_e",
  "west"  : __DIR__"tulu_youan_w",
  "up" : __DIR__"youanmenlou",
]);
mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="north";
#include "outer_gate.h"

void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/youanmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}