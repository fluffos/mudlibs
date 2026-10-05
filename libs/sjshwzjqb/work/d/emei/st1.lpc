//Room: st1.c 深潭
//Date: Oct. 21 1997 by That
#include <ansi.h>

inherit ROOM;
void create()
{
    set("short","深潭");
    set("long",@LONG
四周黑蒙蒙，什么都看不清。潭水发着恶臭，偶尔还触及一两根不知是人
是兽的枯骨，让你全身直起鸡皮疙瘩。你漂浮在水中，无助至极。情急之下，
四处张望(wang)。
LONG);
    set("no_fight",1);
    set("no_sleep_room",1);
      set("exits",([ /* sizeof() == 1 */
      "up"	: __DIR__"huayanding",
       ]));
    set("objects", ([
        __DIR__"npc/frog" : 1,
    ]) );
    set("no_clean_up", 0);
    setup();
}
