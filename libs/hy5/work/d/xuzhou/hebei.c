
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"hebei"
#define TO __DIR__"henan"

#include "shiproom.c";

void create ()
{
  set ("short","长江北岸");
  set ("long", @LONG
这里是长江的北岸。面前是滚滚的长江，你不禁生出一股豪气。你
可以在叫船家(yell boat)，就可以乘舟到长江南岸了。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"dadao7",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}


