// Room: d/kyoto/mianshidian
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "面食店");
set("long", @LONG
这是京都闻名的面食点，里面出售各种男女老少喜欢的寿司，糕点。
而且这里的食品以味道可口，保质期长而闻名，一般做长途旅行的人们都
会来这里买上很多的饭团，糕点之类。门边放着一块价目牌（paizi），
明码标价。
LONG );
set("exits",  ([
        "north"  : __DIR__"qianbending4",
        "south"  : __DIR__"xiaoxiang3",
      ]));
        setup();
        replace_program(ROOM);
}