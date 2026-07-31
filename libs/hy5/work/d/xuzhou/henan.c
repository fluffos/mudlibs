
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"henan"
#define TO __DIR__"hebei"

#include "shiproom.c";

void create ()
{
  set ("short","长江南岸");
  set ("long", @LONG
这里是长江的南岸。面前是滚滚的长江，你不禁生出一股豪气。你
可以在叫船家(yell boat)，就可以乘舟到长江北岸了。
LONG);

  set("exits", ([ 

  "southeast":__DIR__"dadao6",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}


