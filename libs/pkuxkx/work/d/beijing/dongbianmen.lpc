//Cracked by Roath
// Room: /d/beijing/dongbianmen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT=HIY"东便门"NOR;
string GATE_DESC_LONG=
HIC"这是京城外城女墙朝东向的偏门，此处城墙比起外城其他
处的城墙要低矮一些，守军也较少，盘查也不如其他外城门那
么严厉，走此门的大多是运水、倒粪操持贱业之人。城门边的
告示(gaoshi)上沾满了灰尘。\n"NOR
;

mapping GATE_EXITS=([
   "north" : __DIR__"tulu_dongbian_n",
   "south" : __DIR__"tulu_dongbian_s",
   "west"  : __DIR__"chongwenmen",
   "up"  : __DIR__"dongbianmenlou",
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
       me->set_temp("xc/dongbianmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}