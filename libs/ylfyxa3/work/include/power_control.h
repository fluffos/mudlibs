// power_control.h
// by newart 2000/8/2
#ifndef __power_control__
#define __power_control__
#define attack_lvl_normal          0
#define attack_lvl_middle          1          
#define attack_lvl_high            2
#define attack_lvl_super           3
#define attack_lvl_superhigh       4

#define defense_lvl_normal          0
#define defense_lvl_middle          1          
#define defense_lvl_high            2
#define defense_lvl_super           3
#define defense_lvl_superhigh       4

#define at_type_hand                0
#define at_type_weapon              1

int get_based(int damage)
{
        if (damage > 100)
           damage=100 + random(damage-100);
        return damage;
}
mapping query_my_power(object me , int tlvl,int at_type,int at_lvl,int df_lvl)
{

        int d,f,mydex,myparry;
        mydex=random((int)me->query_dex())-random(10);
        myparry=random((int)me->query_con())-random(10);
        if (tlvl < 80 )   tlvl=80;
        if (tlvl  > 200)  tlvl  = 200 + (tlvl  - 200)/4;
        if ( at_type > 0 )
                {
                        f=random(tlvl);
                        d=get_based(tlvl)+random(tlvl);
                }
        else
                {
                        f=get_based(tlvl)+random(tlvl);
                        d=random(tlvl);
                }

        switch(at_lvl) {
                case attack_lvl_normal:
                        d=d+random((int)me->query("str"));
                        f=f+random((int)me->query("con"));
                        break;
                case attack_lvl_middle:
                        d=d+random((int)me->query_str());
                        f=f+random((int)me->query_con());
                        break;
                case attack_lvl_high:
                        d=d+random((int)me->query_str()*2);
                        f=f+random((int)me->query_con()*2);
                        break;
                case attack_lvl_super:
                        d=d+random((int)me->query_str()*3);
                        f=f+random((int)me->query_con()*3);
                        break;
                case attack_lvl_superhigh:
            d=d+random((int)me->query_str()*4);
            f=f+random((int)me->query_con()*4);
                        break;
                }
        switch(df_lvl) {
                case defense_lvl_normal:
                        break;
                case defense_lvl_middle:
                        mydex=mydex+random(10);
                        myparry=myparry+random(10);
                        break;
                case defense_lvl_high:
                        mydex=mydex+random(10)*2;
                        myparry=myparry+random(10)*2;
                        break;
                case defense_lvl_super:
                        mydex=mydex+random(10)*3;
                        myparry=myparry+random(10)*3;
                        break;
                case defense_lvl_superhigh:
                        mydex=mydex+random(10)*4;
                        myparry=myparry+random(10)*4;
                        break;
                }

        return (["damage":d,"force":f,"dodge":mydex,"parry":myparry ]);
}

#endif

