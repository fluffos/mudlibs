//Cracked by Roath
// Room: /d/beijing/dongzhimen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT = HIY"东直门"NOR;
string GATE_DESC_LONG =
HIC"这是京城东北的一座城门，门口挂这一张告示 (gaoshi)。
这里往南就是朝阳门，进城的东直门大街直通鼓楼。\n"NOR
;

mapping GATE_EXITS=([ /* sizeof() == 2 */
  "west" : __DIR__"dongzhidajie",
  "north" : __DIR__"tulu_dongzhi_n",
  "south" : __DIR__"tulu_dongzhi_s",
  "up" : __DIR__"dongzhimenlou",
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
       me->set_temp("xc/dongzhimen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}