//Cracked by Roath
// Room: /d/beijing/andingmen.c
#include <ansi.h>
inherit ROOM;
string GATE_DESC_SHORT=HIY"安定门"NOR;
string GATE_DESC_LONG=
HIC"这是京城正北的安定门。西边是得胜门，南边是去鼓楼的大道。
这里远离闹市，只有些乡农来往运菜进京。城门口的告示(gaoshi)
似乎也没什么人看。\n"NOR
;
mapping GATE_EXITS=([ /* sizeof() == 2 */
  	"south" : __DIR__"zhonglou",
  	"west"  : __DIR__"tulu_anding_w",
    "east"  : __DIR__"tulu_anding_e",
    "up"  : __DIR__"andingmenlou",
      "north"  : "/d/changbai/guandao4",
	]);
mapping GATE_OBJECTS=([
    __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="south";

#include "outer_gate.h"
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/andingmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}
