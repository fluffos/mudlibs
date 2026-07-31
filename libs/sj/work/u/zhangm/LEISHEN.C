#include <armor.h>
#include <ansi.h>
#define DELAY 1
inherit FINGER;
void create()
{       set_name(HIC"暴雷降临戒"NOR,({ "leishen ring","leishen","ring"}) );
        set("long","雷神用毕生的魔力才打造出这具有神秘的力量的戒指。\n"
                         "使用  (sum) 似乎能否解开雷神的封印喔。\n"  
                  );
        set_weight(500);
        if (clonep() ) 
                set_default_object(__FILE__);
        else {
                  set("value",6000);           
        set("material","ring");
        set("unit","件");
        set("limit_int",30);
        set("limit_str",30);
        set("armor_prop/armor",100);
        set("armor_prop/shield",30);
        set("armor_prop/dodge",30);
        set("armor_prop/dex",10);
                }               
        setup();
}
void init()
{
        add_action("do_sum","sum");
}

int do_sum(string agr)
{
        int damage,i,dx,SS,sr;
        string msg;
        object* enemy,me;
        object target;
        me = environment();
        enemy=me->query_enemy();
        if(sizeof(enemy))
        target = enemy[random(sizeof(enemy))];
        if(!me->is_fighting())
            return notify_fail("你必须进入战斗状态～～！\n");
        if(me->is_busy())
            return notify_fail("你的动作还在进行中！！\n");
        message_vision("$N"+HIY+"双手朝天高举，"
            +HIB+"默念咒语准备使出"+MAG+"「天雷箭」。\n"NOR,me);
        message_vision("$N"+HIB+"飞向"+NOR+"$n"+HIR+"上方数丈。\n\n"NOR,me,target);
        me->add("angry",-random(30));   
        dx = target->query_attr("dex");
        sr = target->query_attr("str");
        SS = dx+ sr;
        for(i=0; i<37; i++)
        {
        damage = (300+random(100));     
        if(i){
           if(me->query("qi") < random(1)) 
            {
             message_vision("$N"+HIY+"自觉实力不足只好停止攻势。\n"NOR,me);
             break;
            }
           else{
             msg = "$N"HIY"手似拉弓，忽见指间射出"MAG"天雷箭，"NOR;
             if(damage > 0) {
                msg +="$n"HIR"顿时鲜血四溅。"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,me,target);
                        target->receive_damage("qi", damage, me);
                        COMBAT_D->report_status(target);
                }
                else {
                msg +="$n"HIW"并无受到任何伤害。\n"NOR;
                message_vision(msg,me,target);
                }
        } 
        }
        }
        me->start_busy(1);
        return 1;
}
int query_autoload() { return 1; }


