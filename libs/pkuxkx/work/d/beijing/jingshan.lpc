// Room: /d/beijing/jingshan.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT=HIY"景山"NOR;
string GATE_DESC_LONG =
HIC"这是一条位于鼓楼西南面的背街，十分僻静冷落，路上几乎见不
到什麽行人，东北面鼓楼大街喧哗声不时传到这里来。街边有一间小
庙，上有几个大字『火神庙』。\n"NOR;
mapping GATE_EXITS = ([ /* sizeof() == 2 */
  "north" : __DIR__"dianmen",
  "east"  : __DIR__"chaoyangdajie",
  "enter"  : __DIR__"huoshenmiao",
  "south"  : "/d/beijing/zijin/shenwumen",
]);

mapping GATE_OBJECTS = ([
    __DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"
