// Room: /d/jingzhou/qingshan1.c
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "青山" NOR );
        set("long", @LONG
顺山而走，山势渐渐陡了起来，杂草荆棘丛生， 使你难以行走。
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"road5",
  "eastup" : __DIR__"qingshan",
  "west" : "/d/baling/shulin1",	
  ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

