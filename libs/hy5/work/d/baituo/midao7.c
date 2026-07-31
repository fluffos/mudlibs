#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"秘道"NOR);
        set("long", @LONG
这条阴暗的秘道在山腹中曲折延伸，不知通往何处。前面的道路越来
越暗，你快要看不见东西了。这里空气污浊，还夹杂着一股刺鼻的味道，
你一走过来便觉得头脑发晕，象是中毒了。
LONG);        
        set("objects", ([
                    __DIR__"npc/zhuye" : 1,
                    __DIR__"npc/yanjing" : 1,
        ]));
        set("exits", ([
              "west" : __DIR__"midao6",
              "east" : __DIR__"midao8",
              "south" : __DIR__"midaoout",
              "north" : __FILE__,
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query("kar")) <13 && me->query_con() < 37){ 
        	tell_object(me, HIB "你忽然感到呼吸一紧，原来是这里的空气污浊、流通不畅。\n" NOR );      
             	tell_room(environment(me), me->name()+"突然脸色变得极为难看，并深深地吸了口气。\n" NOR,({ me }));
//             	me->receive_damage("neili", 80);
             	me->receive_damage("jing", 50);
             	me->receive_wound("jing", 30);
             	}           
       add_action("do_use", "use");
}

int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write("你点燃了火折，只见地上铺满了一堆堆的蛇骨，这里的毒气便
是由这多年堆积的毒蛇尸骨所产生。由于此处空气不流通，所以
毒素越积越多，常人已无法忍受。\n");
             this_player()->set_temp("learn_poison", 1);
             return 1;
       }
}
