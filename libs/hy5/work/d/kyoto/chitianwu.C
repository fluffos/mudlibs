// Room: d/kyoto/chitianwu
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "池田屋");
set("long", @LONG
这里就是最著名的池田屋，十年前诚州倒幕派维新志士在这里秘密集
会，结果遭遇新撰组，双方发生激战，维新志士死伤惨重，幸亏绯村剑心
及时赶到，救了桂小五郎和其他主要的领导者，维新运动才能成功。这里
如今已经成为了重要的历史纪念地，其地位同中国的中共一大会址差不多。
LONG );
set("exits",  ([
        "south"  : __DIR__"qianbending2",
      ]));
        setup();
        replace_program(ROOM);
}