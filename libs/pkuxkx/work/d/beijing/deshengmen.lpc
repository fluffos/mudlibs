//Cracked by Roath
// Room: /d/beijing/deshengmen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT=HIY"德胜门"NOR;
string GATE_DESC_LONG=
HIC"这是京城西北角的得胜门。从这里往北就是通往蒙古，俄罗斯
的大路。大路边的军营里操练的声音一阵阵传来，中间夹杂着教官
的喝斥，你忍不住想去看一眼。门口有张告示(gaoshi)。\n"NOR
;

mapping GATE_EXITS=([ /* sizeof() == 2 */
  "southwest" : __DIR__"tulu_desheng_sw",
  "east"  : __DIR__"tulu_desheng_e",
  "southeast" : __DIR__"xizhidajie",
  "up"  : __DIR__"deshengmenlou",
  "northwest" : "/d/saiwai/guandaose",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="southeast";
#include "outer_gate.h"
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/deshengmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}

