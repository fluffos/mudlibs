// hyd_condition.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        int qi;

        if( duration < 1 )
        {
            me->delete_temp("death_cond_origin/hyd_condition");
            return 0;
        }
        if( living(me) ) {
                message("vision",HIR+me->name()+HIR"身上衣衫火苗乱窜，一股股焦糊味冒了出来，烧得"
                        +me->name()+HIR"呲牙咧嘴，双手胡乱扑打着。\n"NOR,environment(me), me);
        }

        if(me->query("eff_qi") < 300) {
                tell_object(me, RED "你觉得浑身上下象有无数把小刀在乱插，钻心地疼痛！你快忍受不下去了。\n" NOR );
                message("vision", HIR+me->name()+HIR"身上火苗逐渐减小，但肌肤被烧成了黑碳颜色。"
                        +me->name()+HIR"双手在空中无力地挥舞，看来快不行了。\n"NOR,environment(me), me);
        }

        qi = me->query("max_qi")/20;
        if (qi>300) qi=300;
        if (qi<50) qi=50;

        me->set_temp("death_cond_id", "hyd_condition");
        me->receive_damage("qi",qi, "被"+cond_def["hyd_condition"]["name"]+"烧成焦碳而");
        me->receive_wound("qi",qi, "被"+cond_def["hyd_condition"]["name"]+"烧成焦碳而");
        COMBAT_D->report_status(me);
        me->apply_condition("hyd_condition", duration - 1);

        if( (int)me->query_temp("hyd/dec") != 1 ) {
                me->set_temp("hyd/dec",1);
                me->set_temp("hyd/dodge" , me->query_skill("dodge")/3 );
                me->add_temp("apply/dodge", -me->query_temp("hyd/dodge"));
                call_out("remove_effort",30+random(30),me);
        }

        if( random(10)>5 )
		me->add_busy(5);

        return CND_CONTINUE; 
}

void remove_effort(object me)
{
        if ( !objectp(me) || (int)me->query_temp("hyd/dec")!=1 ) 
                return;

        me->delete_temp("hyd/dec");
   me->add_temp("apply/dodge", me->query_temp("hyd/dodge"));
        me->delete_temp("hyd/dodge");
}


string query_type(object me)
{
	return "injure";
}

