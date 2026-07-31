// hostage_2.c
// Created by Numa 19991101

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        object ob;
        
        if (duration < 1 ) {
                if((int)me->query_temp("hostage/passed_l")
                && objectp(ob = present("ling huchong",me))) {
                        tell_room(environment(me),"令狐冲不耐烦地对"+me->name()+"哼叽，你怎么比猪还慢啊？要么大伙拱你算了！\n");
                        tell_room(environment(me),"令狐冲快步离开了。\n");
                        me->delete_temp("hostage/passed_l");
                        if (me->query_temp("hostage/failed_l"))
                                me->add_temp("hostage/failed_l",1);
                        else
                        	me->set_temp("hostage/failed_l",1);
                        ob->move("/d/huashan/siguoya"); 
                }
                me->delete_temp("hostage");
                me->clear_condition("hostage11");
                return 0;
        }
        if( me->query_temp("hostage/killed") < (random(me->query_kar()/10 + 1) + 2)
          && random(me->query_kar()) < 10
          && (interactive(me))
          && !me->is_busy()
          && !environment(me)->query("no_fight")
//          && me->query_temp("hostage/passed_l")
          && !present("mojiao shashou",environment(me))
          && duration%4 == 1) {
               tell_object(me, HIY "你觉的有些不妙，似乎被人跟踪上了！\n" NOR);
		me->add_busy(2+random(4));
               call_out("zuji",1, me);
        }
        me->apply_condition("hostage11", duration - 1);
        me->add_busy(1+random(2));
        return CND_CONTINUE;
}

void zuji(object me)
{
        object npc; 
        
        tell_object(me, RED "糟糕！魔教杀手追了过来，似乎是要来阻拦你!\n" NOR);
        npc = new("/d/hmy/npc/killer2");
        npc->set_temp("target",me->query("id"));
        npc->move(environment(me));
        return;
}

