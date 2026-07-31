// Room: /d/chengdu/shudao4
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "江边小路" NOR );
        set("long", @LONG
你走在长江边上的一条小路上，再往西走，就进入了
绵绵的四川山区了，东南方向有条小路，不知道通往哪里。
LONG
        );
        set("exits", ([
  "east" :  __DIR__"shudao3",
  "west" : __DIR__"shudao5",
  //"southeast": __DIR__"xiaolu1"
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

