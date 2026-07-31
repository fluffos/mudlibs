// Room: d/kyoto/tengweiyaoshe
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "藤尾药社");
set("long", @LONG
这里是一间老字号的药社，藤尾家祖上是战国时期的名医，医术代代
相传，如今的老板藤尾雄一向来享有手到病除的美名。药铺里也兼卖各种
药品或材料，如果出得起价钱，什么灵药都能买到。而且老板藤尾雄一广
交江湖朋友，如果有好的药材，他会出相当惊人的价钱。而且会告诉你一
些鲜为人知的江湖秘密。
LONG );
set("exits",  ([
        "south"  : __DIR__"qianbending5",
      ]));
        setup();
        replace_program(ROOM);
}