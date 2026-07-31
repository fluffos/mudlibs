// Room: /d/jingzhou/qingshan2.c
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
  "westup" : __DIR__"qingshan",
  "eastdown" : __DIR__"road4",
  ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

