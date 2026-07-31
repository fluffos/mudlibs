// Room: /d/jingzhou/road7.c
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "小路" NOR);
        set("long", @LONG
一条崎岖的黄土小路，路旁杂草丛生，西边可以看见荆州的官
道，向东去则可一到达扬州。
LONG
        );
        set("exits", ([
  "east" : __DIR__"road6",
  "west" : __DIR__"guandao1",
  ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

