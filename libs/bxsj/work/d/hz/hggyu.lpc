// /u/beyond/hangzhou/hggyu.c 花港观鱼
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIR"花港观鱼"NOR);
        set("long", @LONG
从前，这里有一条小溪从花家山流入西湖，故名花港。南宋时有内侍在
此建园凿池养鱼，人们常来此凭栏观鱼，此地故名花港观鱼。东面是红鱼池，
过桥、出廊往北就是牡丹园。南面就是虎跑泉，东南面可遥望净慈寺,北面就
是苏堤了。
LONG
        );
        set("exits", ([
        "north" : __DIR__"sudi",
"south" : __DIR__"hubian2",
"southeast" : __DIR__"hubian1",
        "east" : __DIR__"hongyuchi",
        "west" : __DIR__"mudanyuan",
]));
        set("coor/x",90);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}
