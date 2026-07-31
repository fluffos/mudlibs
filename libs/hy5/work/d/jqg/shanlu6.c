// shanlu6.c
// By River 98/09
// Modify 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
       set("short", HIW"厉鬼峰"NOR);
       set("long", @LONG
你游目四顾，原来处身于一个绝峰之顶，四下里林木茂密，远望石庄，相
距已有数里之遥。你睁大了眼四下眺望，惟见云生谷底，雾迷峰巅，空山寂寂，
微闻鸟语，天地茫茫，就只你一人而已。
LONG
        );
       set("exits", ([ 
              "southdown"  : __DIR__"shanlu5",
       ]));
       set("outdoors", "绝情谷");
       setup();
       replace_program(ROOM);
}
