//Cracked by Roath
// Room: /d/beijing/guangqumen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT=HIY"广渠门"NOR;
string GATE_DESC_LONG=
HIC"这是京城外城朝东向的城门。这里的城墙相比显得略微
破旧，守备也不如内城森严，但毕竟京畿重地，气度不凡；
过往的行人都在围看一张告示(gaoshi).\n"NOR
;

mapping GATE_EXITS=([
  "west" : __DIR__"guangqudajie",
  "north" : __DIR__"tulu_guangqu_n",
  "south" : __DIR__"tulu_guangqu_s",
  "up" : __DIR__"guangqumenlou",
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
       me->set_temp("xc/guangqumen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}