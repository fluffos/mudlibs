//Cracked by Roath
// Room: /d/beijing/zhaoyangmen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT=HIY"朝阳门"NOR;
string GATE_DESC_LONG=
HIC"这是京城东向的朝阳门。城墙建于明永乐年间，全部用
砖包砌而成，城门洞也为砖砌筒壳，十分坚固美观。出门往
东是通往东北的大道。门口有一张告示(gaoshi).\n"NOR
;

mapping GATE_EXITS=([
  "east": __DIR__"road1",
  "west" : __DIR__"chaoyangdajie",
  "north": __DIR__"tulu_chaoyang_n",
  "south": __DIR__"tulu_chaoyang_s",
  "up": __DIR__"chaoyangmenlou",
]);

mapping GATE_OBJECTS=([
    __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/chaoyangmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}