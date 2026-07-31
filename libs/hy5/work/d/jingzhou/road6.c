// Room: /d/jingzhou/road5.c
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "小路" NOR);
        set("long", @LONG
一条崎岖的黄土小路，路旁杂草丛生，西边只见黄土飞扬，好象是条大
官道。东面则有一座青山，山上树木茂密。
LONG
        );
        set("exits", ([
  "east" : __DIR__"road5",
  "west" : __DIR__"road7",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

