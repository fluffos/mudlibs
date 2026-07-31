// Room: /d/chengdu/sanxia3
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "瞿塘峡" NOR );
        set("long", @LONG
这里是长江三峡的瞿塘峡，河水由东流来，进入峡谷，河道变
窄，水流变急，两岸的高山中间夹着一条河流，就好象一条丝带一
般，蜿蜒而行。
LONG
        );
        set("exits", ([
  "southeast" :  __DIR__"sanxia2",
  "west" : __DIR__"shudao11",
  
   ]));
//        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

