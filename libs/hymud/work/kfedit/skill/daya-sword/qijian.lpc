

//气剑指(qijian)--大雅古剑法
//lestat /6/5/2001改编自六脉神箭

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
#include <combat.h>

inherit F_SSERVER;


string *qijian_msg = ({
//盘庚
HIC"\n$N突然跃起丈余，$n"+NOR+HIC"一抬头，发现空中并无$N的身影，而一股寒气却从后袭来！\n"NOR,
HIC"$N左斜行三步，左手小指的内力自左向右的斜攻过去，「盘庚剑」直插$n"+NOR+HIC"$l！\n"NOR,
HIC"\n$N手臂陡然一提，在手掌离$n"+NOR+HIC"不到一尺之处，立即变掌为指！\n"NOR,
//毕命
HIW"\n$N长笑一声，蓦地里$N空手猱身而上，双手擒拿点拍，攻势凌厉之极，乘$n"+NOR+HIW"惊骇之际，一招「毕命剑」空中$w"+NOR+HIW"飞刺向$n！\n"NOR,
HIW"\n$N无名指一挥，拙滞古朴的「毕命剑」剑气直射而出，端端正正地刺向$n！\n"NOR,
//罔命
HIR"\n$N欺身而上，双手幻出无数指影在$n"+NOR+HIR"的肩上一拍再横飞出去，而空中的$w"+NOR+HIR"化出「罔命剑」指向$n"+NOR+HIR"的$l！\n"NOR,
HIR"\n$N拇指一屈，食指点出，变成了「罔命剑」，一缕剑气向$n"+NOR+HIR"刺出！\n"NOR,
HIR"\n$N食指连动，「罔命剑」一剑又一剑的刺出，其轻灵迅速，快速无比！\n"NOR,
HIR"\n$N以食指运那无形剑气，却不过是手指在数寸范围内转动，「罔命剑」对着$n"+NOR+HIR"一点一戳！\n"NOR,
//至诚
HIG"\n$N中指一竖，一式「至诚剑」向前刺出！\n"NOR,
HIG"\n$N潜运内力，忽进忽退，绕着$n"+NOR+HIG"身子乱转，空中$w"+NOR+HIG"所运剑招也如狂风骤雨一般，越来越快！\n"NOR,
HIG"\n电光火石之间，$N一翻掌，身向右移，奋起神威，右手斗然探出，「至诚剑」剑气向$n"+NOR+HIG"扑来！\n"NOR,
//瞽蒙
HIY"\n$N掌托于胸前，伸出右小指，一招「瞽蒙剑」缓缓地点向$n"+NOR+HIY"的周身大穴，弹指无声！\n"NOR,
HIY"\n$N小指一弹，使一招「瞽蒙剑」，剑势如同柳絮一般，飘而不乱！\n"NOR,
HIY"\n$N一招「瞽蒙剑」，剑气回转，竟从左侧绕了过来，点向$n"+NOR+HIY"的$l！\n"NOR,
HIY"\n$N右手小指一挥，一招「瞽蒙剑」点点刺刺，宛如雕花刺画一般！\n"NOR,
//止戢
HIM"\n$N忽然化身为二，分出左右两个身影高速滑向$n"+NOR+HIM"，空中$w"+NOR+HIM"幻化不定，直刺$n"+NOR+HIM"的$l，「止戢剑」剑气如怒潮般汹涌而至！\n"NOR,
HIM"\n$N大拇指连挥，「止戢剑」便如是一幅泼墨山水相似，纵横倚斜，寥寥数笔，却是剑路雄劲！\n"NOR,
HIM"\n$N的「止戢剑」大开大阖，气派宏伟，每一剑刺出，都有石破天惊、风雨大至之势！\n"NOR,
});
string *target_msg = ({
//盘庚
"你只觉得一股无形剑气向你的$l激射而来，其变化精微，快绝无比！\n",
"那一股无形剑气当真是忽来忽去，变化精微，让你避无可避！\n",
//毕命
"你感觉到那无形剑气拙滞古朴，奇正有别，委实难以架挡！\n",
"所谓“大巧不工”，那直冲而来的无形剑气竟然使你无从躲避！\n",
//罔命
"那无形的剑气巧妙灵活，难以琢磨，幻化间直奔你而来！\n",
"无论你变招多快，也及不上那一缕剑气，瞬间已逼到了你跟前！\n",
//至诚
"你感到这一股迅疾而来的的至诚剑气大开大合，气势雄伟，根本挡无可挡！\n",
"猛然间你感到周身大穴都被一股大开大合，气势雄伟的无形剑气所包围！\n",
//瞽蒙
"待那剑气到得近前，竟是劲气弥漫，破空之声甚厉！\n",
"只见那刺来的无形剑气‘拙’而不缓，‘缓’而不弱，有如神剑！\n",
//止戢
"只见那剑路雄劲，石破天惊，逼得你左躲右闪，无法招架！\n",
"你见那无形剑气颇有石破天惊、风雨大至之势，逼得你纵高伏低，东闪西避！\n"NOR,
});

string *winner_msg = ({
        CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
        CYN "\n$N双手一拱，笑着说道：承让！\n\n" NOR,
        CYN "\n$n向后一纵，说道：阁下武艺果然高明，这场算是在下输了！\n\n" NOR,
        CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
        CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
        CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
        CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

string *winner_animal_msg = ({
        CYN "\n$N退在一旁，警戒地向$n盯视！\n\n" NOR,
        CYN "\n$N退守开来，但仍然毫不放松地盯着$n！\n\n" NOR,
        CYN "\n$N退了几步，但随时可能再冲过来！\n\n" NOR
});



int check_fight(object me, int amount, object weapon);
int check_qijian(object me, object target);
private int remove_effect(object me, int amount);
int perform(object me, object target)
{       
        string msg;
        int damage, p, skill;
        int damagea,extra,exp;
      
                object weapon = me->query_temp("weapon");  
        if(!me->query_skill("daya-sword", 1)) return 0;  
        
        if(((int)me->query_skill("daya-sword", 1) < 300 ||
            (int)me->query_skill("sword", 1) < 300))
                return notify_fail("你的剑术基本功夫还不够娴熟，就想乱用「气剑指」？\n");


        if(((int)me->query_skill("daya-sword", 1) < 800 && userp(me)))
                return notify_fail("你的这门剑法不到家，就想乱用「气剑指」？\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("请使用无争心法!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
      
        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("你的内力修为太弱，根本使不出「气剑指」来！\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够！\n");
      if( me->query_temp("zxzx") ) 
        return notify_fail("你正在运功,不能分心他用！\n");
        if(me->query_temp("start_qijian")) return notify_fail("你已经在运用气剑指的无形剑气了！\n");

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「气剑指」只能在战斗中使用。\n");

//        tell_object(me, HIW"\n你先行存念，手中长剑脱手飞起,然后鼓气出指，内劲真气勃发，开始运用气剑指！\n"NOR);
        msg = HIW"\n$N先行存念，手中$w"+NOR+HIW"脱手飞起，绕周身盘旋飞舞，然后鼓气出指，内劲真气勃发，开始运用气剑指！\n" NOR;
                msg=replace_string(msg,"$w",weapon->query("name"));
                message_vision(msg, me, target);
                me->set_temp("start_qijian", 1);
                skill = me->query_skill("daya-sword");
if (skill > 500) skill=500;
        me->add_temp("apply/dodge",  skill*2);    
    me->add_temp("apply/parry",  skill*2);
    me->add_temp("apply/attack",  skill/2);
                check_fight(me, skill, weapon);
//        remove_call_out("check_qijian");        
//        remove_call_out("checking");
//        call_out("check_qijian", 2, me, target);
//        call_out("checking", me->query_skill("daya-sword", 1), me);
                check_qijian(me,target);
        return 1;
}
/*
int checking(object me)
{
        if(me->query_temp("start_qijian")){
              me->delete_temp("start_qijian");
              tell_object(me, HIW"\n你内劲运行一周天，将气剑指的招数用了一遍！\n"NOR);
              }
        return 1;
}
*/
int check_qijian(object me, object target)
{
        string msg, *limbs, dodge_skill, str, limb;
        int lv, i, force, ap, dp, damage, p, j;
        mapping act, *action;
        object wep;
                object weapon = me->query_temp("weapon"); 
        lv = (int)me->query_skill("daya-sword", 1);

       
 action = ({
([      "action" : qijian_msg[random(3)],
        "t_msg" : target_msg[random(2)],
        "damage" : 5,
        "lvl" : 0,
        "skill_name" : "盘庚剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[3+random(2)],
        "t_msg" : target_msg[2+random(2)],
        "damage" : 6,
        "lvl" : 30,
        "skill_name" : "毕命剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[5+random(4)],
        "t_msg" : target_msg[4+random(2)],
        "damage" : 6,
        "lvl" : 60,
        "skill_name" : "罔命剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[9+random(3)],
        "t_msg" : target_msg[6+random(2)],
        "damage" : 5,
        "lvl" : 90,
        "skill_name" : "至诚剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[12+random(4)],
        "t_msg" : target_msg[8+random(2)],
        "damage" : 5,
        "lvl" : 120,
        "skill_name" : "瞽蒙剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[16+random(3)],
        "t_msg" : target_msg[10+random(2)],
        "damage" : 7,
        "lvl" : 150,
        "skill_name" : "止戢剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[random(sizeof(qijian_msg))],
        "t_msg" : target_msg[random(sizeof(target_msg))],
        "damage" : 2+random(8),
        "lvl" : 200,
        "skill_name" : "大雅剑",
        "damage_type" : "刺伤"
]),
});

        if (lv >= 200) j = 6;
        else if (lv >= 150) j = 5;
        else if (lv >= 120) j = 4;
        else if (lv >= 90) j = 3;
        else if (lv >= 60) j = 2;
        else if (lv >= 30) j = 1;
        else j = 0;
        act = action[random(j)];
        damage = act["damage"];
        msg = act["action"];
        force = (int)me->query("neili");        

        if(!living(target) || !target || !me->is_fighting() || environment(me) != environment(target)){
                me->delete_temp("start_qijian");
                return 1;
                }
       if(!me->query_skill("daya-sword", 1) || !me->query_temp("start_qijian")){
                me->delete_temp("start_qijian");
                return 1;
                } 

        if(force < 2500){
                tell_object(me,"你发现自己现在的真气太弱，已经不够使出「气剑指」了。\n");           
                me->delete_temp("start_qijian");
                return 1;
                }      
        if(me->is_busy()){
                call_out("check_qijian", 2+random(8-j), me, target);
                return 1;
                }

        ap = me->query_skill("force") + me->query_skill("daya-sword", 1) + me->query_int();
        dp = target->query_skill("force", 1) + target->query_skill("dodge") + target->query_int();
        ap *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;
        
        limbs = target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        msg = replace_string(msg, "$l", limb);
       if (me->query_temp("weapon"))
                msg=replace_string(msg,"$w",weapon->query("name"));
        message_vision(msg, me, target);
        tell_object(target, HIR+act["t_msg"]+NOR); 
        wep = target->query_temp("weapon");

        if( random(ap+dp) > dp/2 || random(3)==0){
             me->add("neili", -damage*3);
             damage *= lv/2;
             damage -= target->query_temp("apply/armor")/2;
             damage += me->query("force_factor")*4;
             if(force > target->query("neili")*2) damage = damage*2;          
             if(damage > 23500) damage = 23500;

//the target has a weapon in hand
             if(objectp(wep) && random(2) == 1){   
//                       if(objectp(wep)){
                   if(me->query("neili") < target->query("neili")/2){
                        me->start_busy(1);
                        msg = HIY"结果只听哐的一声，$n"HIY"用手中$W"HIY"竟然接下了那$w！\n" NOR;                        
                        }
                   else if(me->query("neili") >= target->query("neili")*2){
                         if(wep->query("rigidity") >= 3){
if (!wep->query("systemmake") && !wep->query("ownmake"))
{
                               me->start_busy(1);
                               //wep->move(environment(target));
                               wep->unequip();
                               target->receive_damage("qi", 150,me);  
                               target->receive_wound("qi", 125,me);   
                               msg = HIW"结果只听啪的一声，$n"HIW"拿捏不住$W"HIW"被脱手震飞，虎口也在猛烈撞击下震裂！\n" NOR;
                               target->reset_action();
}
                               }
                         else{
                                me->start_busy(1);
if (!wep->query("systemmake") && !wep->query("ownmake"))
{
                                msg = HIW"结果只听拍的一声响，$n手中$W"HIW"为$N的$w"HIW"所断，化为寸许的二三十截，飞上半空，闪出点点白光！\n" NOR;
                                msg = replace_string(msg, "$W", wep->name());
                                wep->unequip();
//                                wep->move(environment(target));
                                wep->set("name", wep->query("name")+"碎片");
                                wep->set("value", 0);
                                wep->set("unit", "些");
                                wep->delete("long");
                                wep->set("weapon_prop", 0);
                                target->reset_action();
 }
                                }
                        }       
                   else {       
                         if(wep->query("rigidity") >= 8){
                                me->start_busy(1);
                                msg = HIY"结果只听一声大响，$W"HIY"在$w"HIW"的冲击下不住颤抖，飞花四溅！\n" NOR;
                                }
                         else{
if (!wep->query("systemmake") && !wep->query("ownmake"))
{
                                me->start_busy(1);
                                wep->move(environment(target));  
                                msg = HIW"$n慌忙举$W"HIW"一挡，当的一声后，那"+wep->query("unit")+"$W"HIW"又被震飞！\n" NOR;
                                target->reset_action();
}
                                }
                         }
                   msg = replace_string(msg, "$W", wep->name());
                   msg = replace_string(msg, "$w", "无形剑气");          
                   message_vision(msg, me, target);
                   call_out("check_qijian", 2+random(8-j), me, target);
                   }
             else{
                   target->receive_damage("qi", damage,me);
                   target->receive_wound("qi", damage/(2+random(4)),me);          
                   p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                   msg = damage_msg(damage, act["damage_type"]);
                   msg += "( $n"+eff_status_msg(p)+" )\n";
                   msg = replace_string(msg, "$l", limb);
                   msg = replace_string(msg, "$w", "无形剑气");          
                   message_vision(msg, me, target);
                   if(wizardp(me)) tell_object(me, "qijian_damage: "+damage+" \n");
                                   msg=HIB"\n但见空中蓝光闪烁，$w"HIB"在空中盘旋,时而飞回$N手中。\n"NOR;
if (me->query_temp("weapon"))
                                   msg=replace_string(msg,"$w",weapon->query("name"));
                                   message_vision(msg, me, target);
                   call_out("check_qijian", 2+random(8-j), me, target);                   
                   }
            }
        else{
             me->start_busy(1);
//             HIY"$N全力向后一纵一闪，凶险万分地避开了那急速而来的无形剑气！\n"NOR, target);
             dodge_skill = target->query_skill_mapped("dodge");
             if( !dodge_skill ) dodge_skill = "dodge";
             message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
             call_out("check_qijian", random(8-j), me, target);    
             } 
//              call_out("check_qijian", 1, me, target);  
/*       if(target->query("kee")*2 <= target->query("max_kee")
           && !target->is_killing(me->query("id"))
           && !me->is_killing(target->query("id"))){
             me->remove_enemy(target);
             target->remove_enemy(me);
             if (me->query("race") == "人类") {
                                if (!me->query("mute") && target->query("mute"))
                                        message_vision( winner_msg[random(sizeof(winner_msg)/2)], me, target);
                                        if (me->query("mute") && !target->query("mute"))
                                                message_vision(winner_msg[sizeof(winner_msg)/2 + random(sizeof(winner_msg)/2)], me, target);
                                        if (!me->query("mute") && !target->query("mute"))
                                                message_vision( winner_msg[random(sizeof(winner_msg))], me, target);
                        } else message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, target);
             }
*/
       return 1;
}       

int check_fight(object me, int amount, object weapon)
{  
    object wep;    
    if(!me) return 0;
    wep = me->query_temp("weapon");  
    if(!me->is_fighting() || !living(me) || me->is_ghost() || !wep || weapon != wep )
        remove_effect(me, amount);

    else {
        call_out("check_fight", 1, me, amount, weapon);
//        me->start_perform(1, "气剑指");
    }
    return 1;
}

private int remove_effect(object me, int amount)
{
        string msg;
        object weapon = me->query_temp("weapon"); 
        object target;
        me->add_temp("apply/dodge", -amount*2);
    me->add_temp("apply/parry", -amount*2);
    me->add_temp("apply/attack", -amount/2);
    me->delete_temp("start_qijian");
    if(living(me) && !me->is_ghost())
if (me->query("weapon"))
{
                msg=replace_string(msg,"$w",weapon->query("name"));         msg = HIB"\n一道蓝光闪过，$w"HIB"飞回$N手中！\n" NOR;
                message_vision(msg, me, target);
//              msg=replace_string(msg,"$w",weapon->query("name"));
//      message_vision(HIB"一道蓝光闪过，$w飞回$N手中。\n"NOR, me);
}
    return 0;
}




