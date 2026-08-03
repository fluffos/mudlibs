// pfm_control.h


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

int check_pfm_cost(object me,int at_lvl,int i,int j)
{
        int cost;
    cost=(int)me->query_con() + (int)me->query_skill("force")/4 + 50*at_lvl;
        if(i > 0) cost = cost + (int)me->query("jiali");
        if(i == 0) cost = cost + 150*(j-1);
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
        hispot=hispot+his_extra/2+at_lvl*32;
        btime=1;
        if ( random(hispot) > mepot/2 )
        btime += (hispot/6+random(hispot/6))/12;
        if(btime>5) btime=5;
        if(btime<1) btime=1;
        me->start_busy(btime);
}

void pfm_busy_other(object me,object target ,int at_lvl)
{
    int btime;
    if(at_lvl==4) btime=6;
    if(at_lvl==3) btime=5;
    if(at_lvl==2) btime=4;
    if(at_lvl==1) btime=3;
    if(at_lvl==0) btime=2;
    if((me->query_int()+me->query_dex())<(target->query_int()+target->query_dex())) btime=btime-1;
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

int check_pfm_if(object me,object target,string skill1)
{
    int ap,pp,dp;
    string skill;
        
    if(!skill1) return 0;

    ap=(int)me->query_skill(skill1,1);
    ap+=me->query_temp("apply/attack");
    if(ap<1) ap=me->query("combat_exp")/2;
    else {
    ap=(ap*ap*ap)/3;
    ap+=me->query("combat_exp")/30*me->query_dex();
    }

    skill=target->query_skill_mapped("dodge");
    if(!skill) skill="dodge";
    dp=(int)target->query_skill(skill,1);
    dp+=target->query_temp("apply/defense");
    //if(target->is_fighting())  dp=dp*(100+target->query_temp("fight/dodge"))/100;
    if(dp<1) dp=target->query("combat_exp")/2;
    dp=(dp*dp*dp)/3;
    dp=(dp+target->query("combat_exp"))/30*target->query_dex();
    if(target->is_busy()) dp/=3;

    skill=target->query_skill_mapped("parry");
    if(!skill) skill="parry";
    pp=(int)target->query_skill(skill,1);
    pp+=target->query_temp("apply/defense");
    //if(target->is_fighting())  pp=pp*(100+target->query_temp("fight/dodge"))/100;
    if(pp<1) pp=target->query("combat_exp")/2;
    pp=(pp*pp*pp)/3;
    pp=(pp+target->query("combat_exp"))/30*target->query_dex();
    if(target->is_busy()) pp/=3;

    if(random(ap+dp)<dp) return 1;
    if(random(ap+pp)<pp) return 2;
    return 3;
}

int get_pfm_damage(object me ,object target,int base_one,int base_two , int at_lvl,string add_type)
{
        int last_power;
        last_power=(base_one+random(base_two/2))*3;
        last_power+=(int)me->query("jiali")*6;
        switch (add_type) {
                case "con" :
                        last_power += (int)me->query_con()*at_lvl*5;
                        break;
                case "str" :
                        last_power += (int)me->query_str()*at_lvl*5;
                        break;
                case "dex" :
                        last_power += (int)me->query_dex()*at_lvl*5;
                        break;
                }
        last_power=last_power*20/(target->query_con()/4+15);
        if(last_power>target->query_temp("apply/armor")) last_power-=target->query_temp("apply/armor");
        last_power=last_power*2/3 + random(last_power/3);
        if (last_power > 4000) last_power=4000;
return last_power;
}

int busy_if(object me,object target)
{
int ap,dp;
mapping fam=me->query("family");
ap=(int)me->query("combat_exp")/100*((int)me->query_int()+(int)me->query_dex()+me->query("int")+random(me->query("dex")));
if(fam["family_name"]=="武当派") ap=ap+random(ap/2);
dp=(int)target->query("combat_exp")/100*((int)target->query_int()+(int)target->query_dex());
if(random(ap+dp)>dp) return 1;
return 0;
}

#endif


