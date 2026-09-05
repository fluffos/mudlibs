//Cracked by Roath
// Room: /d/beijing/xuanwumen.c
#include <ansi.h>
inherit ROOM;

string GATE_DESC_SHORT = HIY"宣武门"NOR;
string GATE_DESC_LONG =
HIC"这里是南通菜市口，天桥，西达长安街的交通要道。这里来往的老百姓都被
严加查问。门上的告示 (gaoshi) 似乎写着些什么。\n"NOR
;
mapping GATE_EXITS_NIGHT=([ /* sizeof() == 3 */
  // "north" : "/d/beijing/zijin/tianansquare",
  "east" : __DIR__"xidan",
  "south" : __DIR__"xuanwudajie",
  "north" : __DIR__"fuchengdajie_s",
  "up" : __DIR__"xuanwumenlou",
]);
mapping GATE_EXITS=([ /* sizeof() == 3 */
  // "north" : "/d/beijing/zijin/tianansquare",
  "west" : __DIR__"xibianmen",
  "east" : __DIR__"xidan",
  "south" : __DIR__"xuanwudajie",
  "north" : __DIR__"fuchengdajie_s",
  "up" : __DIR__"xuanwumenlou",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

void fix_exits_for_night(int is_night)
{
  if (is_night) {
    set("exits", GATE_EXITS_NIGHT);
  }else{
    set("exits", GATE_EXITS);
  }
}

#include "inner_gate.h"
