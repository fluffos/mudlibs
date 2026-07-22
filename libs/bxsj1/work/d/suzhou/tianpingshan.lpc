#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "天平山");
        set("long",@long
过了灵岩山，距离几里地就到了天平山。它为苏州西南诸山之最高峰。
因地势平坦如砥而得名。又因山势高峻，白雾缭绕，也称“白云山”。具载：
宋仁宗赵祯将天平山赐与范文正公，故也称“范文山”。
long);
set("outdoors", "suzhou");
set("exits",([
"northeast" : __DIR__"qsgdao",
"north" : __DIR__"shihu",
"southeast" : __DIR__"lingyanshan",
"eastup" : __DIR__"baiyunquan",
]));
set("coor/x",110);
  set("coor/y",-280);
   set("coor/z",0);
   setup();
}
