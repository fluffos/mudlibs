// yun_control.h
// by newart 2000/8/25

#ifndef __yun_control__
#define __yun_control__

#define yun_lvl_a          4
#define yun_lvl_b          3          
#define yun_lvl_c          2
#define yun_lvl_d          1
#define yun_lvl_e          0
#define time_rate_none     1
#define time_rate_low      3
#define time_rate_normal  3
#define time_rate_high     8
#define time_rate_super    10
#define yun_base_can      100

int check_yun_cost(object me,int at_lvl)
{
        int cost;
        cost = (int)me->query_skill("force")
/2 + (int)me->query_con()*at_lvl;
        if( (int)me->query("neili") > cost + yun_base_can )
        {
                me->add("neili",-cost);
                return 1;
        }
        return 0;
}
int get_add_point(int num) 
{
        num=num/10;
        if ( num > 20 )
                num= 20 + random(num -20 )/2;
        return num;
}
#endif

