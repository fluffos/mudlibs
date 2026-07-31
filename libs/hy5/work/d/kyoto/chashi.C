// Room: d/kyoto/chashi
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "茶室");
set("long", @LONG
这里是一间茶室，装潢的不算考究，里面人声嘈杂，有抱怨评论维新
政府得失的各种言论，也有人谈论幕末时期各派成名剑客的传说，其中最
神奇的就是被人称为“拔刀斋”的绯村剑心的传奇。听说拔刀斋在幕末最
惊心动魄的对新撰组组长“壬生之狼”斋藤一一战就发生在旁边的小巷里。
LONG );
set("exits",  ([
        "north"  : __DIR__"qianbending3",
        "south"  : __DIR__"xiaoxiang2",
      ]));
        setup();
        replace_program(ROOM);
}