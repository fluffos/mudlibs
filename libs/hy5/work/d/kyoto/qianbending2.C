// Room: d/kyoto/qianbending2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "千本町");
set("long", @LONG
这里就是千本町，贯穿京都东西的大动脉，也是最繁华的街区，两边
行馆店铺鳞次栉比。北面就是最著名的池田屋，是诚州倒幕派同新撰组发
生激战的地方。南面就是绯村剑心为保护维新志士同新撰组激战的小巷。
事隔十年，仿佛还能听到刀剑相交的声音。让人血脉膨胀。
LONG );
set("exits",  ([
        "east"  : __DIR__"qianbending3",
        "west"  : __DIR__"qianbending1",
        "north"  : __DIR__"chitianwu",
        "south"  : __DIR__"xiaoxiang1",
      ]));
        setup();
        replace_program(ROOM);
}