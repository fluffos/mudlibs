//Cracked by Roath
// Room: /d/beijing/xibianmen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT = HIY"西便门"NOR;
string GATE_DESC_LONG =
HIC"这是京城外城女墙朝西向的偏门，此处城墙比起外城其他
处的城墙要低矮一些，守军也较少，盘查也不如其他外城门那
么严厉，走此门的大多是运水、倒粪操持贱业之人。门口的告
示(gaoshi)上已经沾了许多泥垢.\n"NOR
;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "south" : __DIR__"tulu_xibian_s",
  "north" : __DIR__"tulu_xibian_n",
  "east"  : __DIR__"xuanwumen",
  "up"  : __DIR__"xibianmenlou",
  ]);

mapping GATE_OBJECTS=([
        __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="east";
#include "outer_gate.h"
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/xibianmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}