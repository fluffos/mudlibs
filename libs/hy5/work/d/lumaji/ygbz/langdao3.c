// zjb /2002/3/16/
#include <ansi.h>
inherit ROOM;
void on_sun();
void create()
{
        set("short", "廊道");
        set("long", @LONG 
这是又一个廊道,末端没入暗黑里，令人难测远近 
深浅，但扑面而来的空气更觉清新!

LONG
        );  
        set("exits", ([ 
                   "north"  : __DIR__"langdao4",
                "south"  : __DIR__"langdao2",
                "west"  : __DIR__"langdao3",
              "east"  : __DIR__"langdao3",
                              ]));

set("objects", ([
		__DIR__"obj/corpse" : 1,
	]));                              
        set("no_clean_up", 0);
        setup();
}
void init()
{
    object me;
    me = this_player(); 
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


