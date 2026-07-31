#include <armor.h>
#include <ansi.h>
#define DELAY 1
inherit ARMOR;
void create()
{
   set_name(HIC"风神迅即铠"NOR,({ "fengshen armor","armor"}) );
   set("long","风神家传的神圣铠甲，具有神秘的力量。\n"
         "铠甲上似乎刻着几个字 (zhan) (xzhan)？？？\n"  );
   set_weight(1500);
        if (clonep() ) 
          set_default_object(__FILE__);
        else {
          set("value",6000);           
          set("material","armor");
          set("unit","件");
          set("limit_con",30);
          set("limit_str",30);
          set("armor_prop/armor",600);
          set("armor_prop/shield",20);
          set("armor_prop/dodge",20);
          set("armor_prop/dex",20);
        }
    setup();
}

void init()
{
        add_action("do_zhan","zhan");
        add_action("do_xzhan","xzhan");
        
}

int do_zhan(string agr)
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
        message_vision("$N"+HIY+"双手在胸前交叉，"+HIB+"准备使出家传绝学中的"+MAG+"「迅捷斩」。\n"NOR,me);
        message_vision("$N"+HIB+"跃向"+NOR+"$n"+HIR+"面前。\n\n"NOR,me,target);
        me->add("angry",-random(30));   
        dx = target->query_attr("dex");
        sr = target->query_attr("str");
        SS = dx+ sr;
        for(i=0; i<13; i++)
        {       damage = (700+random(300));     
        if(i){
                if(me->query("qi") < random(1)) {
                        message_vision("$N"+HIY+"自觉实力不足只好停止攻势。\n"NOR,me);
                        break;
                }       
        else{
                msg = "$N"HIY"手张成刀，运起气劲挥出迅捷斩，向"NOR;
                if(damage > 0) {
                        msg +="$n"HIR"砍去。"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,me,target);
                        target->receive_damage("qi", damage, me);
                        target->receive_damage("jing", damage, me);
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

int do_xzhan(string agr)
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
        message_vision("$N"+HIY+"双手在胸前交叉，"+HIB+"准备使出家传绝学中的"+MAG+"「"HIW"迅捷斩·"HIC"修罗"HIB "」。\n"NOR,me);
        message_vision("$N"+HIB+"跃向"+NOR+"$n"+HIR+"面前。\n\n"NOR,me,target);
        me->add("angry",-random(30));   
        dx = target->query_attr("dex");
        sr = target->query_attr("str");
        SS = dx+ sr;
        for(i=0; i<15; i++)
        {
        damage = (1500+random(1500));   
        if(i){
                if(me->query("qi") < random(1)) {
                        message_vision("$N"+HIY+"自觉实力不足只好停止攻势。\n"NOR,me);
                        break;
                }       
        else{
                msg = "$N"HIY"使出修罗斩张手成刀，运气向"NOR;
                if(damage > 0) {
                        msg +="$n"HIR"挥出。"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,me,target);
                        target->receive_damage("qi", damage, me);
                        target->receive_damage("jing", damage, me);
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

