// Room: /d/huashan/xuanya.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "悬崖");
        set("long", @LONG
这是一面十分陡峭的悬崖，你只怕一不小心摔下去。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"xuanya2",
  "down" : __DIR__"hsxl2",
]));
      set("no_hsnewbiejob",1);
        setup();
       
}
void init()
{
        object me = this_player();
        if (!userp(me)) return;
     if( random((int)me->query_skill("dodge")) <= 30||me->query_encumbrance() * 100 / me->query_max_encumbrance() > 50)
        {
                me->receive_damage("qi", 50, "摔下悬崖");
                me->receive_wound("qi",  50, "摔下悬崖");
          message_vision(HIR"$N只觉手一滑，... 啊...！\n"NOR, me);
             me->move(__DIR__"hsxl2");
               tell_object(me, HIR"你从悬崖上摔了下来。\n"NOR);
    message("vision", HIR"只见" + me->query("name") + "从悬崖上摔了下来，躺在了地上！\n"NOR, environment(me), me);
                 me->unconcious();
        }
}
