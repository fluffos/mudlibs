
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","锦屏峰");
  set ("long", @LONG
锦屏峰位于天池西南。锦屏峰在芝盘、观日峰中间，峰顶南北各起
一峰，五色的翡翠石装点峰巅；峰前峰后立陡悬崖，宛如锦秀屏风一般，
故而得名。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"tianchi",
 "south":__DIR__"gusun-feng",
 "southeast":__DIR__"guanri-feng",
 "northwest":__DIR__"luming-feng",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

