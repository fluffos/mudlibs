//Cracked by Roath
// Room: /d/beijing/zuoanmen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT = HIY"左安门"NOR;
string GATE_DESC_LONG =
HIC"这是京城南面的偏门，进城的多是赶集的百姓，偶尔有些马车
路过。门边上许多人正围着看告示 (gaoshi)，两边的土路通向永安
门和广渠门。\n"NOR
;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "east"  : __DIR__"tulu_zuoan_e",
  "west"  : __DIR__"tulu_zuoan_w",
  "north" : __DIR__"guangqudajie",
  "up" : __DIR__"zuoanmenlou",
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
       me->set_temp("xc/zuoanmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}