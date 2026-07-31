// Room: d/kyoto/beimen.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "京都北门");
set("long", @LONG
这是北城门，因为曾经失火，到现在城墙还是黑乎乎的，往这里去
东北面就是著名的琵琶湖，传说六天魔王--织田信长就葬于湖底，传说
中的秘密也同信长一样被埋于琵琶湖。往南就是繁华的京都，是夕日天
皇都城所在。

LONG );
set("exits",  ([
        "south"  : __DIR__"longandao1",
      ]));
        setup();
        replace_program(ROOM);
}