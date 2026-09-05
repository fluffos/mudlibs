//Cracked by Roath
// Room: /d/beijing/guanganmen.c
#include <ansi.h>
inherit ROOM;
string GATE_DESC_SHORT=HIY"广安门"NOR;
string GATE_DESC_LONG=
HIC"这是京城西边的城门之一。由于不是很繁华，这里的城墙已经
有些不那么光鲜了。绕城的土路也没有许多人来往。西面远处听说
时常有强人出没。门边的告示 (gaoshi) 也已经有些褪色。\n"NOR
;

mapping GATE_EXITS=([
  "south" : __DIR__"tulu_guangan_s",
  "east"  : __DIR__"caishikou",
  "north" : __DIR__"tulu_guangan_n",
  "up" : __DIR__"guanganmenlou",
  "southwest" : "/d/jinyang/guandaoe3",
]);

mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":4,
    __DIR__"npc/captain_guangan":1,
]);

string GATE_ENTER_DIR="east";
#include "outer_gate.h"
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/guanganmen",1);
      }
    add_action("do_guard", "guarding");
    add_action("do_allow", "allow");
    add_action("do_climb", "climb");
}

