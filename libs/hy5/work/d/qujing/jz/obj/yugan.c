//Cracked by Roath
//yugan.c

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("鱼竿", ({"yu gan"}));
        set_weight(1000);
                set("unit", "把");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N把$n握在手中．\n");

        setup();
}
void init()
{
  add_action("do_fish", "fish");        
}
int do_fish()
{
   object me=this_player();
     string env;
    if( me->query("fish") )
        return notify_fail("你现在不正在钓吗？\n");
if(interactive(me) &&me->query("combat_exp") >100000 )
        return notify_fail("你还是去找点其它事情干吧，钓鱼嘛，就让给小辈干吧。\n");
    if ( time() - me->query("last_fish") < 30 )
        return notify_fail("我看你还是过会再来钓吧。\n");
    if(me->is_busy())
        return notify_fail("你正忙着呢！\n");
if((int)me->query("qi") <80)
        return notify_fail("你现在精神状况不好，是钓不上来鱼的！\n");
    me->set("fish");
    message_vision( CYN "$N穿好鱼饵，用力一甩，把钩子甩到了河中间。\n" NOR, me);
    me->start_busy(5);
    call_out("zhai1",1,me);
    call_out("zhai2",3+random(2),me);
    call_out("finish_zhai",5,me);
    return 1;
}
void zhai1(object me)
{
   message_vision( GRN "$N盯着鱼浮，但是它好象根本就没有动过。\n"NOR, me);
}
void zhai2(object me)
{
   message_vision( YEL "$N看到鱼浮好象动了一下，仔细看！有鱼上钩了！\n", 
me); 
}
void finish_zhai(object me)
{
   object ob;    
   if ( random(3) == 1) {
   tell_object(me,"真倒霉，你什么也没有钓上来。\n");
   return 0;  }
   if ( me->query("combat_exp") < 1000000 ) {
   if ( me->query("combat_exp") < 10000 )
   ob = new("/d/qujing/jz/obj/fish1");
   if ( me->query("combat_exp") < 100000)
   ob = new("/d/qujing/jz/obj/fish2");
   else 
   ob = new("/d/qujing/jz/obj/fish3");
        }   
   ob->move(environment(me));      
   tell_object(me,"你钓上了一条" + ob->query("name") +"。\n");
   me->add("combat_exp",10+random(10));
   me->add("potential",2);
   me->delete("fish");
   me->set("last_fish",time());
}                                                 
