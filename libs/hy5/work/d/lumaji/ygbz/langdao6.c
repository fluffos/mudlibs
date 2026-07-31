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
            "enter"  : __DIR__"baoku",
                   "north"  : __DIR__"langdao5",
                "south"  : __DIR__"langdao6",
                "west"  : __DIR__"langdao6",
              "east"  : __DIR__"langdao6",
                              ]));
              set("no_clean_up", 0);
        setup();
}
void init()
{
    object me;
    me = this_player(); 
{
if (me->query_temp("jinbaoku"))
{
call_out("on_jinbaoku", 1);
}
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
        add_action("do_push", "push"); 
}


void on_jinbaoku(object room)
 {
  object me = this_player(); 
   message_vision(HIC"$N突然想到，既然墙壁可以射箭，那么墙壁因该还有另一边，何不推(push)进去试试呢!\n"NOR, this_player()); 
}
int do_push(string arg)
{
        object me; 
      string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("你要推什么东西!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="墙壁" || dir=="wall") {
   message_vision(HIR"$N用力推开了墙壁，现出了一条活路!。\n"NOR, this_player());  
        set("exits/out", __DIR__"dishi");
call_out("on_guan", 5);
              return 1;
}
         else {
            write("你想推什么东西?\n");
            return 1;
        }
}
} 

void on_guan(object room)
{
      message_vision(HIB"突然出现咔咔的响声，墙壁又合上了!\n"NOR, this_player());
delete("exits/out");
}

