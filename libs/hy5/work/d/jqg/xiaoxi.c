// By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"独峰岭"NOR);
        set("long", @LONG
溪流一路而下，将舟送至一个极其险恶的境地，这里两边山峰壁立，抬头
望天，只余一线。山青水碧，景色极尽清幽，只是四下寂无声息，隐隐透著凶
险，溪心有九块大石迎面耸立，犹如屏风一般，挡住了去路。溪边停着一叶小
舟(boat)，正是你来时所乘之舟。
LONG
        );

        set("exits", ([
                "northup": __DIR__"glt",
        ]));
        set("item_desc",([
          "boat": "一叶小舟，停在溪边的山石之上，看来要推(tui)下小溪才能使用。\n",
        ]));
        set("outdoors", "绝情谷");
        setup();
}

void init()
{
        add_action("do_jump",({"tiao", "jump", "yue"}));
        add_action("do_tui", "tui");
}

int do_tui(string arg)
{
        object me=this_player();
        if( me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着哪！\n");
        if( !arg || arg != "boat") 
             return notify_fail("你要推什么？\n");
        if( arg =="boat"){
          if ( me->query_temp("weapon"))
                 return notify_fail("你拿着兵刃怎么推动小舟？\n");
          message_vision("$N双掌一使劲，用力将小舟推入溪中。\n",me);
          me->start_busy(1);
          me->set_temp("jqg/tui", 1);
          return 1;
        }
}

int do_jump(string arg)
{
        object me = this_player();
        if( me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着哪！\n");
        if( !arg ||(arg != "boat" && arg != "zhou")) 
             return notify_fail("你要往哪里跳？\n");
        if( arg =="zhou" || arg=="boat"){
          if (! me->query_temp("jqg/tui"))
                return notify_fail("小舟还在岸上，你跳上去又有何用？\n");
          tell_object(me,"你吸了口气，纵身向小舟上跳将过去。\n");
          tell_room(environment(me), me->name() + "纵身往小舟上跳将过去。\n", ({ me }));
          me->delete_temp("jqg");
          me->move(__DIR__"boat3");
          tell_room(environment(me), me->name() + "稳稳地站落在小舟之上。\n", ({ me }));
          tell_object(me,"你屏气凝神，稳稳地站落在小舟之上。\n");
          return 1;
        }
}
