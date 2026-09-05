//Cracked by Roath
// Room: /d/beijing/fuchengmen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT=HIY"阜成门"NOR;

string GATE_DESC_LONG=
HIC"这是京城西面的阜成门。城墙建于明永乐年间，
全部用砖包砌而成，城门洞也为砖砌筒壳，十分坚
固美观。门口有张告示(gaoshi)。\n"NOR
;

mapping GATE_EXITS=([
  "north" : __DIR__"tulu_fucheng_n",
  "south" : __DIR__"tulu_fucheng_s",
  "east"  : __DIR__"fuchengdajie",
  "up"  : __DIR__"fuchengmenlou",
]);


mapping GATE_OBJECTS=([
        __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="east";
// all the real definitions goes here
#include "outer_gate.h"
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/fuchengmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}