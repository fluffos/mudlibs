//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short", "玄紫天雉殿");
        set("long", @LONG

大殿通体紫色，一个女子在殿中翩翩起舞，整个大殿中弥漫
着一种怪异的气氛，大殿中到处都是用玉石雕刻的雉鸡，屏
风上是雉鸡图，座椅上铺着雉鸡羽毛做成锦缎......

LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ximei" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sleeproom.c",
  "northwest" : __DIR__"beiji.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

