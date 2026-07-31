// Room: d/kyoto/xiaoxiang3
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "小巷");
set("long", @LONG
走在一条小巷上，昏昏暗暗的，一边是上原，北面是一间面食点，出
售各类寿司，糕点。从斑驳的墙面可以看出这条小巷历史的久远。
LONG );
set("exits",  ([
        "west"  : __DIR__"shangyuan4",
        "north"  : __DIR__"mianshidian",
      ]));
        setup();
        replace_program(ROOM);
}