// Room: /d/chengdu/shudao9
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "山顶" NOR );
        set("long", @LONG
一座高山的山顶，临江一面是陡峭的悬崖，仔细看，有一些石窝可
以落脚，西看去，只见云雾中有好象有几栋房子。
LONG
        );
        set("exits", ([
  "down" :  __DIR__"shudao8",
  "west" : __DIR__"baidicheng",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

