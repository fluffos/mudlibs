// Room: /d/jingzhou/qingshan.c
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "山顶" NOR );
        set("long", @LONG
爬上山顶，只觉空气清新，登高望远，心旷神怡。向东望去，只见
扬洲城有如一个小黑点，极目向西，却茫茫而不见。南面，只见一条大
江如彩带一般，那就是长江了！
LONG
        );
        set("exits", ([
  "eastdown" : __DIR__"qingshan2",
  "westdown" : __DIR__"qingshan1",
  "southdown" :__DIR__"chibi1"
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

