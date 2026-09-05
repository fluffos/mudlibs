// by Vast@pkuxkx
// edit by advent 061030
// all comments added by Vast
// modified by whuan@pkuxkx

#include <ansi.h>
#include <weapon.h>

inherit F_GEMS;
inherit EQUIP;

int get_grade(int min, int max); 
void setup_weapon(object ob, int flag);
varargs void gen_weapon(int seed,int min,int max);
void init_sockets();

nosave string *all_colors = ({NOR, RED, BLU, GRN, YEL, CYN, MAG, HIW});
nosave string *all_grades = ({"沉水","赤焰","荡寇","彗月","照夜","追日","断阙","刑天"});
nosave string *all_types =({"剑", "刀", "杖", "鞭", "斧", "枪", "锤", "戟", "匕"});
nosave string *all_ids=({"sword","blade","staff","whip","axe","spear","hammer","halberd","dagger"});
nosave mapping weapon_type = ([
        "sword"  : ({ "slash", "slice", "thrust", "pierce" }),
        "blade"  : ({ "slash", "slice", "hack", "chop" }),
        "staff"  : ({ "bash", "crush", "slam", "pierce", "impale" }),
        "whip"   : ({ "whip","wave" }),
        "axe"    : ({ "chop", "slice", "hack" }),
        "spear"  : ({ "thrust", "impale", "pierce" }),
        "hammer" : ({ "bash", "crush", "slam" }),
        "dagger" : ({ "pierce", "thrust" }),
        "fork"   : ({ "thrust", "pierce" }),
        "halberd"  : ({ "thrust", "impale", "pierce" }),    
        ]);

void create()
{
        int type;
        //只能在专门的地方进行买卖
        set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
        //随机共10种兵器
        type=random(9)+1;
        set("type",type);
        gen_weapon(type);
        setup();	
}
int get_grade(int min, int max)
{
        int i, grade;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 2500)      grade = 1;    //(25%)
        else if (i < 4500) grade = 2;    //(20%)
        else if (i < 6100) grade = 3;    //(16%)
        else if (i < 7300) grade = 4;    //(12%)
        else if (i < 8500) grade = 5;    //(12%)
        else if (i < 9300) grade = 6;    //(8%)
        else if (i < 9700) grade = 7;    //(4%)
        else               grade = 8;    //(3%)
        return grade;	
}
varargs void gen_weapon(int seed,int min,int max) 
{
        int i;
        int grade;
        string name,id;
        
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return; 
        	       
        grade=get_grade(min,max); //获取级别
        if (grade<1 || grade > 9) grade=1;
        set("level",grade);
        name=all_colors[grade-1]+all_grades[grade-1]+"之"+all_types[seed-1]+NOR;
        id=all_ids[seed-1];      
        	
        if(!seed) i = 1 + random(9);
        else
        {
                if(seed < 1 || seed > 9) return;
                i = seed;
        }
        set("skill_type",all_ids[i-1]);
        set("seed",i); //icer added to clone the same weapon when player using this random weapon
 				// used in /task/npc/target
        //先确定武器基本种类、属性，再生成武器的gem类公有属性
        set_name(name, ({id}) );  
        set("material", "steel");
        set("rigidity", 200+random(grade*15));
        set("value",10000+random(20000+grade*10000));  
        set("weapon/min_dam", 30+random(10*grade));
        set("weapon/max_dam", 100+random(20*grade));         
        delete("weapon_prop/damage");
        init_sockets();             
}
void init_sockets()
{
        int i, max, flag;
        string type;
        object ob = this_object();

        //1，2，3孔出现的几率为888:111:1
        //生成方式太简单，以后加强
        if(!query("sockets/max"))
        {
                i = random(1000);

                if (i < 888)
                max = 1;
                else if (i < 999)
                max = 2;
                else if (query("unqiue")) //非Unique武器最多两个孔
                max = 3;
                else
                max = 2;
                set("sockets/max", max);
        }

        if( !stringp(type = ob->query("skill_type")) )                
                ob->set("skill_type", "sword"); //如果没有设置则设成sword
        if(query("two_hand")) flag = 1;
        setup_weapon(ob, flag);	
}
void setup_weapon(object ob, int flag)
{
        int hole, i;
        string longdes;

        //基本信息
        if(stringp(ob->query("weapon/name")))
        set_name(ob->query("weapon/name"), ob->parse_command_id_list());

        ob->set("unit", "柄");

        //set long_desc
        if (!stringp(ob->query("weapon/long")))
        longdes = "随机装备\n"+"★★★★★★"+ob->query("name")+"★★★★★★\n";
        else
        longdes = ob->query("weapon/long");

        longdes += set_weapon_desc(ob);

        set("long", longdes);

        //材料
        if (!ob->query("material")) ob->set("material", "iron");
        //硬度
        if (!ob->query("rigidity")) ob->set("rigidity", 300);
        if (!ob->query("max_rigidity")) ob->set("max_rigidity", ob->query("rigidity"));

        //wield,unwield msg
        if (!stringp(ob->query("wield_msg")))
        set("wield_msg", "$N装备$n做武器。\n");
        else
        set("wield_msg", ob->query("wield_msg"));

        if (!stringp(ob->query("unwield_msg")))
        set("unwield_msg", "$N放下手中的$n。\n");
        else
        set("unwield_msg", ob->query("unwield_msg"));


        // init_sword
        ob->set("flag", 2 | (int)flag | EDGED);
        if( !ob->query("actions") )
        {
                ob->set("actions", (: call_other, WEAPON_D, "query_action" :) );
                ob->set("verbs", weapon_type[query("skill_type")]);	
        }
}

string spec_effect(object me, object victim, int damage_bonus, string act)
{
        int damage, magic, kar;
        string msg = "";
        object weapon;

        //成功率(可能设定简单了一点)
        magic = me->query_temp("apply/magic");
        kar = me->query_kar();
        if (kar > 40) kar = 40;
        if (random(100) + kar / 5 + kar * magic / 1000 < 90) return msg;

        switch (act) {
        case "weapon_effect_jing":
                msg = HIY"一道黄光猛的闪过，$n只觉得意识越来越模糊！\n"NOR;
                damage = query("weapon_effect/jing");
                //if (damage > 1000) damage = 1000;
                victim->receive_damage("jing", damage, me);
                victim->receive_wound("jing", damage / 4 + random(damage * 3 / 4), me);
                if (wizardp(me))
                        tell_object(me, sprintf("jing damage is: %d\n", damage));
                break;
        case "weapon_effect_poison":
                msg = HIG"只见一道绿气迅速的从伤口渗入了$n的经脉！\n"NOR;
                victim->apply_condition("emerald_poison", victim->query_condition("emerald_poison") + query("weapon_effect/poison"));
                if (!victim->is_killing(me->query("id"))) victim->kill_ob(me);
                break;
        case "weapon_effect_suck":
                msg = WHT"忽然间，$n只觉鬼哭狼嚎声不绝于耳，三魂六魄都给吸了出去！\n"NOR;
                damage = damage_bonus * query("weapon_effect/suck") / 10;
                if (victim->query("qi") < damage)
                        damage = victim->query("qi");
                if (damage > 0)
                {
                        victim->receive_damage("qi", damage, me);
                        me->receive_curing("qi", damage);
                        if (wizardp(me))
                                tell_object(me, sprintf("suck qi: %d\n", damage));
                }
                damage /= 2;
                if (victim->query("neili") < damage)
                        damage = victim->query("neili");
                if (damage >  0)
                {
                        victim->add("neili", - damage);
                        me->add("neili", damage);
                        if (me->query("neili") > me->query("max_neili") * 2)
                                me->set("neili", me->query("max_neili") * 2);
                        if (wizardp(me))
                                tell_object(me, sprintf("suck neili: %d\n", damage));
                }
                break;
        }
        return msg;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int i;
        mapping effect;
        string act, msg = "";

        //随机出现一种效果
        //weapon_effect/jing,poison,suck
        effect = me->query_temp("apply");
        if (mapp(effect))
        {
                i = sizeof(effect);
                act = keys(effect)[random(i)];
                msg += spec_effect(me, victim, damage_bonus, act);
        }
        return msg;
}
