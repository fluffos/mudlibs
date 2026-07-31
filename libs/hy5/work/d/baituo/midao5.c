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
        set("exits", ([
              "westup" : __DIR__"midao2",
              "eastdown" : __DIR__"midao6",    
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query("kar")) <13 && me->query_con() < 35){ 
        	tell_object(me, HIB "你忽然感到呼吸一紧，原来是这里的空气污浊、流通不畅。\n" NOR );      
             	tell_room(environment(me), me->name()+"突然脸色变得极为难看，并深深地吸了口气。\n" NOR,({ me }));
//             	me->receive_damage("neili", 80);
             	me->receive_damage("jing", 50);
             	me->receive_wound("jing", 25);
             	}           
}