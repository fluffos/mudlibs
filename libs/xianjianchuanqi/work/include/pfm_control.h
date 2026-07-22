// pfm_control.h
// by newart 2000/8/25

#ifndef __pfm_control__
#define __pfm_control__

#define pfm_busy_a          4
#define pfm_busy_b          3          
#define pfm_busy_c          2
#define pfm_busy_d          1
#define pfm_busy_e          0

#define pfm_lvl_a          4
#define pfm_lvl_b          3          
#define pfm_lvl_c          2
#define pfm_lvl_d          1
#define pfm_lvl_e          0
        
#define pfm_going_time     8
#define pfm_type_busy      2
#define pfm_type_attack    0
#define pfm_type_combat    9
#define pfm_type_powerup   2
#define pfm_base_cost    100

void bei_old(object me) {
        if((int)me->query_temp("can_old")!=1)
                return;
        me->prepare_skill(me->query_temp("old_basic"),me->query_temp("old_skill"));
        me->delete_temp("old_basic");
        me->delete_temp("old_skill");
        me->reset_action();
}

void bei_none(object me,string str_type) {
        mapping pmap;
        string *skill;
        int i;
        mapping valid_types = 
        ([
                "finger":       "指法",
                "hand":         "手法",
                "cuff":         "拳法",
                "claw":         "爪法",
                "strike":       "掌法",
                "leg":          "腿法"
        ]);
        pmap = me->query_skill_prepare();
        skill = keys(valid_types);
        me->set_temp("can_old",0);
        for (i=0; i<sizeof(skill); i++) {
                if( !me->query_skill(skill[i]) || !pmap[skill[i]] || skill[i]==str_type ) continue;
                me->set_temp("old_basic",skill[i]);
                me->set_temp("old_skill",pmap[skill[i]]);
                me->set_temp("can_old",1);
                }
        skill = keys(pmap);
        for (i=0; i<sizeof(skill); i++) 
                me->prepare_skill(skill[i]);
        me->reset_action();
}

void set_pfm_type(object me,int i)
{
  me->set_temp("pfm_time_add",i);
}

int check_pfm_cost(object me,int at_lvl,int i)
{
        int cost;
    cost=(int)me->query_con() + (int)me->query_skill("force")/4 + 30*at_lvl;
        if(i > 0) cost = cost + (int)me->query("jiali");
        if( (int)me->query("neili") > cost)
        {
                me->add("neili",-cost);
                return 1;
        }
        return 0;
}

int get_pfm_power(object me , int base_one,int base_two , int at_lvl,string add_type)
{
        int last_power;
    last_power=(base_one+random(base_two/2))/4;
        last_power+=at_lvl*( ((int)me->query("int") -10)*2 + ((int)me->query_int()-(int)me->query("int"))/4 );
        switch (add_type) {
                case "con" :
                        last_power+=at_lvl*( ((int)me->query("con") -10)*2 + ((int)me->query_con()-(int)me->query("con"))/4 );
                        break;
                case "str" :
                        last_power+=at_lvl*( ((int)me->query("str") -10)*2 + ((int)me->query_str()-(int)me->query("str"))/4 );
                        break;
                case "dex" :
                        last_power+=at_lvl*( ((int)me->query("dex") -10)*2 + ((int)me->query_dex()-(int)me->query("dex"))/4 );
                        break;
                }
    if (last_power > 300)
        last_power=300;
return last_power;
}

int get_pfm_damage(object me , int base_one,int base_two , int at_lvl,string add_type)
{
        int last_power;
        last_power=(base_one+random(base_two/2))*3;
        last_power+=(int)me->query("jiali")*5;
        switch (add_type) {
                case "con" :
                        last_power += (int)me->query_con()*at_lvl*3;
                        break;
                case "str" :
                        last_power += (int)me->query_str()*at_lvl*3;
                        break;
                case "dex" :
                        last_power += (int)me->query_dex()*at_lvl*3;
                        break;
                }
        last_power=last_power*2/3 + random(last_power/3);
        if (last_power > 2000) last_power=2000;
return last_power;
}

void start_pfm_busy(object me , object target , string add_type,int at_lvl)
{
        int btime,mepot,hispot,me_extra,his_extra;
        mepot=(int)me->query_int();
        hispot=(int)target->query_int();
        switch (add_type) {
                case "con" :
                        me_extra=(int)me->query_con();
                        his_extra=(int)target->query_con();
                        break;
                case "str" :
                        me_extra=(int)me->query_str();
                        his_extra=(int)target->query_str();
                        break;
                case "dex" :
                        me_extra=(int)me->query_dex();
                        his_extra=(int)target->query_dex();
                        break;
                }
        mepot=mepot+me_extra/2;
        hispot=hispot+his_extra/2+at_lvl*4;
        btime=1;
        if ( random(hispot) > mepot/2 )
        btime += (hispot/6+random(hispot/6))/8;
        me->start_busy(btime);
}

void pfm_busy_other(object target ,int base_one ,int base_two,int at_lvl)
{        int btime;
         btime=base_one+base_two/2;
         btime=btime/5 + random(btime/5);
         btime=btime/10 + random(at_lvl);
         btime=btime/2 +random(btime/2);
         if ( btime <3 ) btime=3 ;
         if ( btime >6 ) btime=6 ;
         target->start_busy(btime);
}

void pfm_busy_me(object me ,int base_one ,int base_two,int at_lvl)
{        int btime;
         btime=base_one+base_two/2;
         btime=btime/5 + random(btime/5);
         btime=btime/10 + random(at_lvl);
         btime=(btime/2 +random(btime/2))/2;
         if ( btime <2 ) btime=2 ;
         if ( btime >4 ) btime=4 ;
         me->start_busy(btime);
}

int get_pfm_going_time(object me)
{
    return pfm_going_time + (int)me->query_temp("pfm_time_delay") - (int)me->query_temp("pfm_time_add")-(int)me->query_int()/25;
}

int check_exp_combat(object me ,object target)
{
        int me_exp,target_exp;
        me_exp=(int)me->query("combat_exp");
        target_exp=(int)target->query("combat_exp");
        if (me_exp > 2987654 )
                me_exp=2987654;
        if (target_exp > 2987654 )
                target_exp=2987654;
        if( random(me_exp) > target_exp/3 )
                return 1;
        return 0;
}

#endif
