// Room: d/kyoto/heyuanting1.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "河原町");
set("long", @LONG
这里就是著名的河源町，是神社和道场集中的地方，北面就是赫赫有名
的神光院，在外面就能听到僧吕和术士诵读经文咒文。日日不息。江湖人士
更是络绎不绝，都想获得超凡的咒文的帮助。
LONG );
set("exits",  ([
        "west"  : __DIR__"heyuan1",
        "north"  : __DIR__"shenguangyuan",
        "east"  : __DIR__"heyuanting2",
      ]));
        setup();
        replace_program(ROOM);
}