// eytan.c 鳄鱼潭
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short",HIB"鳄鱼潭"NOR);
          set("long",@LONG
这里黑漆漆的，你只觉得身子在水中不断往下潜沉，待沉势稍缓，拨水上
升，刚钻出水面吸了几口气，突然鼻中闻到一股腥臭，同时左首水波激荡，似
有甚麽巨大水族来袭。
LONG
);

          set("objects",([
             __DIR__"npc/eyu": 1,
             __DIR__"npc/eyu1":1,
          ]));

          set("indoor","绝情谷");
          setup();
}

void init()
{
        add_action("do_ta","ta");
}

int do_ta(string arg)
{
     object me = this_player();
     if(! arg || arg !="corpse") return 0;
     if(!objectp(present("corpse", environment(me)))) return 0;
     if( arg =="corpse"){
      if (me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着哪！\n");
      message_vision(HIC"$N右足踏在死鳄肚上，借劲跃起，接著左足在鳄鱼的背上一点。$N已跃到对岸。\n"NOR,this_player());
      me->move(__DIR__"cave1");
      tell_room(environment(me), me->name() + "从对岸飞跃而来。\n", ({ me }));
      return 1;
      }
      return notify_fail("你准备踏在什么上面过河？\n");
}
