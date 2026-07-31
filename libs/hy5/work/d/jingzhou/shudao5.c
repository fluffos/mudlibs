// Room: /d/chengdu/shudao5
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "栈道" NOR );
        set("long", @LONG
栈道是通连接四川和中原的唯一道路，为了在险峻的山脉中
打开这条道路，不知道花费了多少人力物力，死了多少人，路是
沿江而修的，用大木桩钉在悬崖上，上面铺以木板，仅能过一两
个人。栈道年久失修，走起来摇摇晃晃的，好不危险。 
LONG
        );
        set("exits", ([
  "east" :  __DIR__"shudao4",
  "northwest" : __DIR__"shudao6",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

