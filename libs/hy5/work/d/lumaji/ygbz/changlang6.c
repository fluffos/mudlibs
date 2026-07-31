// zjb /2002/3/16/
#include <ansi.h>
inherit ROOM;
void on_sun();
void create()
{
        set("short", HIC"长廊"NOR);
        set("long", @LONG 
这里又是一个长廊,一道长廊往前延伸，
尽端是夜明珠的蒙蒙清光。

LONG
        ); 
        set("exits", ([ 
                   "north"  : __DIR__"changlang5", 
                 "west"  : __DIR__"jingtou", 
         "east"  : __DIR__"changlang6",
         "south"  : __DIR__"changlang6",
                                            ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
    object me, room; 

room = find_object(__DIR__"baoku2");    me = this_player();  
message_vision(HIR"突然房里发出一阵铃响声，看来有人进来触动外面的机关了!\n"NOR, me);
{
if (me->query("neili")>99)
{
if (me->query_skill("dodge",1)>300)
{   
message_vision(HIB"$N跨步入门，忽然机括疾响。\n"NOR, this_player());
message_vision(HIB"十枝特长特粗的精钢箭矢，似是杂乱无章的从另一端暗 \n"NOR, this_player());
message_vision(HIB"黑处疾射而至，破空声带起激厉的呼啸声，在这寂静的地下\n"NOR, this_player());
message_vision(HIB"廊道更份外刺耳，$N身形一移，躲过了箭矢!\n"NOR, this_player()); 
message_vision(HIB"但是还是用了不少内力!\n"NOR, this_player());
me->add("neili",-me->query("max_neili")/5); 
}
}if (me->query_skill("dodge",1)<201) 
  {     
message_vision(HIR"$N跨步入门，忽然机括疾响。\n"NOR, this_player());
message_vision(HIR"十枝特长特粗的精钢箭矢，似是杂乱无章的从另一端暗 \n"NOR, this_player());
message_vision(HIR"黑处疾射而至，破空声带起激厉的呼啸声，在这寂静的地下\n"NOR, this_player());
message_vision(HIR"廊道更份外刺耳，$N想躲过箭矢,但是由于轻功太差，被箭矢\n"NOR, this_player()); 
message_vision(HIR"射中了,造成了重伤!\n"NOR, this_player());
  me->receive_wound("qi",me->query("max_qi")/4);
}    
if (me->query("neili")<100)
{
message_vision(HIR"$N跨步入门，忽然机括疾响。\n"NOR, this_player());
message_vision(HIR"十枝特长特粗的精钢箭矢，似是杂乱无章的从另一端暗 \n"NOR, this_player());
message_vision(HIR"黑处疾射而至，破空声带起激厉的呼啸声，在这寂静的地下\n"NOR, this_player());
message_vision(HIR"廊道更份外刺耳，$N想躲过箭矢,但是由于内力不够，被箭矢\n"NOR, this_player()); 
 message_vision(HIR"射中了,造成了重伤!\n"NOR, this_player());
  me->receive_wound("qi",me->query("max_qi")/6);
}
if (me->query("neili")<1)
 {
me->set("neili",1);
}
            }
}

