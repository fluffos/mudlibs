// dagou-bang.c 打狗棒法

#include <ansi.h>;
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"强间穴","风府穴","大雅穴","灵台穴","悬枢穴",}); 

string  *msg = ({

"$N举起$w，居高临下使一招"+(order[random(13)])+"「打草惊蛇」"NOR"敲向$n的$l",

"$N手中$w左右晃动，一招"+(order[random(13)])+"「拨草寻蛇」"NOR"向$n的$l攻去",

"$N施出"+(order[random(13)])+"「拨狗朝天」"NOR"，$w由下往上向$n撩去",

"$N使出一招"+(order[random(13)])+"「棒打双犬」"NOR"，听得棒声飒然，横扫$n的$l",

"$N倏地伸出$w，棒头搭在$n的$l上，一招"+(order[random(13)])+"「压肩狗背」"NOR"，轻轻向下按落",

"$N手中$w高高扬起，一招"+(order[random(13)])+"「立地劈狗」"NOR"，打向$n的$l",

"$N手中$w横扫左右，一招"+(order[random(13)])+"「扫地赶狗」"NOR"，舞起一片杖影",

"$N手臂一伸，反手$w向$n打出，好一招"+(order[random(13)])+"「关门打狗」"NOR"",
 
"$N$w从旁递出，一招"+(order[random(13)])+"「恶狗拦路」"NOR"，竹棒侧抖旁缠，向外斜甩",

"$N一招"+(order[random(13)])+"「风驰电闪」"NOR"，手中$w化作两道青光砸向$n的$l",

});


int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query_skill("staff", 1) < 30)
                return notify_fail("你的基本棒法太差, 还领会不了打狗棒法。\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("你的混天气功修为不够。\n");
       if (((int)me->query_skill("liuhe-zhang", 1)+200) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("你的六合掌法太低了。\n");
       if (((int)me->query_skill("fengmo-zhang", 1)+100) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("你的疯魔杖法太低了。\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)+300) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("你的逍遥游太低了。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够。\n");
        
    if ((me->query_skill("dagou-bang",1)>20) && (me->query_skill("begging",1)<101))
        if (me->query_skill("dagou-bang", 1) > me->query_skill("begging", 1)+20)
        return notify_fail("打狗棒法需要相应等级的叫花绝活。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
                i=me->query_skill("begging",1);
                level=me->query_skill("dagou-bang",1);
        if (i>140) i=140+i/10;
                if (level>140) level=140+level/10;

        if ( random(10) > 6
        &&      ( (int)me->query_skill("staff", 1) >= 120 ) 
        &&      ( (int)me->query_skill("dagou-bang", 1) >= 120 )
        &&      ( (int)me->query_skill("force",1) >= 120 )
        &&      ( (int)me->query("neili") >= 500 )
         ) {
                me->add("neili", -50);
                return ([
                "action": HIG"$N眼中射出一道青芒，手中$w使出"RED""+(order[random(13)])+"「天下无狗」"NOR""HIG"，劈天盖地般攻向$n"NOR,
                "damage": 500,
                "dodge":50,
                "parry":80,
                "force": 600,
                "damage_type": "内伤"]);
        }
return ([
                "action":msg[random(sizeof(msg))],
                "damage":random(50)+i/2+level/2+190,
                "parry":random(i/8)+50+random(level/8),
                                "dodge":random(i/5)+60,
                "force":level+i/2+160+random(50),
                "damage_type": "挫伤",
        ]);
       
}

int practice_skill(object me)
{
        object weapon;
     if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("jing") < 40)
                return notify_fail("你的体力不够练打狗棒法。\n");  

        if ((int)me->query("neili") < 140)
                return notify_fail("你的内力不够练打狗棒法。\n");  
if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("你的混天气功修为不够。\n");
       if (((int)me->query_skill("liuhe-zhang", 1)+200) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("你的六合掌法太低了。\n");
       if (((int)me->query_skill("fengmo-zhang", 1)+100) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("你的疯魔杖法太低了。\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)+300) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("你的逍遥游太低了。\n");
        me->receive_damage("jing",30);
        me->add("neili", -35);  
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg,name;
    int i,j,damage,a,p;
    object weapon, weapon1;     
         name = xue_name[random(sizeof(xue_name))];
    weapon = me->query_temp("weapon");
    weapon1 = victim->query_temp("weapon");
    i = me->query_skill("begging", 1);
    j = me->query_skill("dagou-bang", 1);
a=me->query("combat_exp", 1);
p=victim->query("combat_exp", 1);
    if( damage_bonus < 10 ) return 0;

if (me->query_skill_mapped("force") != "huntian-qigong")
return 0;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
return 0; 

if (!victim) return;

    if(j > 100 &&
       me->query_skill_mapped("parry") == "dagou-bang" &&
       me->query("neili") > 400 && me->query("max_neili") > 1000
        &&  random(j) > 150
        && random(a) > random(p)/3 ){
       if (random(4)>1){
              switch(random(4)){
            case 0 :
               message_vision(HIG"$N"+weapon->name()+"挥出，以“绊”字诀着地扫去，一绊不中，二绊续至，连环钩盘，绵绵而不绝。\n"NOR,me, victim);
               if (!victim->is_busy()) victim->start_busy(3);
                           if (!random(2))
                           message_vision(HIR"$n纵身稍慢，被"+weapon->name()+"在左胫上一拨，右踝上一钩，扑地倒了。\n"NOR,me, victim);             
               else
                           message_vision(HIR"$n尚未落地，被"+weapon->name()+"又是一挑一打，$n立足不住，仰天一交摔倒。\n"NOR,me, victim);             
               break;
            case 1 :
                message_vision(HIG"$N使出“劈”字诀，挥舞起手中"+weapon->name()+"如狂风暴雨般的打去！\n"NOR,me, victim);
                damage = damage_bonus/10 + random(damage_bonus)/3;
if (victim->query("qi") >damage/3)
{
                victim->receive_danage("qi",damage/3);
                                victim->receive_wound("qi", damage/3);
}
                //me->add("neili", -damage/6);
                            break;
                        case 2 :
              message_vision( HIG"$N使出“戳”字诀，手中"+weapon->name()+"直上直下，点东打西，招招向$n的要害戳去！\n"NOR,me, victim);
                damage = damage_bonus/5 + random(damage_bonus)/10;
                if (victim->query("qi") > damage/2)
                victim->receive_wound("qi", damage/2);
                //me->add("neili", -damage/4);
              break;
            case 3 :
             message_vision( HIG"$N棒法再变，使出了“转”字诀。但见"+weapon->name()+"化成了一团碧影，猛点$n后心各大要穴。\n"NOR,me, victim);
                           if((!random(5)))
                                {
                                if (!victim->is_busy()) victim->start_busy(3);
                                //me->add("neili",-40);
                               if (victim->query("qi") > me->query_skill("dagou-bang",1)/5+damage_bonus/5)
{
                                victim->receive_damage("qi", me->query_skill("dagou-bang",1)/5+damage_bonus/4);
                                victim->receive_wound("qi", me->query_skill("dagou-bang",1)/5+damage_bonus/4);       
}
                                 message_vision(HIR"$n被"+weapon->name()+"点中"RED+name+HIR"，受了点伤！\n" NOR,me, victim);
                        }                 
               break;
            }
           } else if (weapon1 && random(20)<7) 
                   {
             switch(random(2)){
            case 0 :
                           if (random(2)!=1){ 
                message_vision( HIG"$N"+weapon->name()+"疾翻，搭在"+weapon1->name()+"尺许之处，运起“引”字诀，顺势向外牵引! \n"NOR,me, victim);
               } else {
              message_vision( HIG"$N"+weapon->name()+"缩回，使起“挑”字诀，搭住"+weapon1->name()+"向上甩出，将$n疾奔的力道传到"+weapon1->name()+"上! \n"NOR,me, victim);
                           }
                           if (!victim->is_busy()) victim->start_busy(3);
                           if (!random(4)){
                         message_vision( HIR"$n只感"+weapon1->name()+"似欲脱手飞出，一个把握不住，手中兵器被对方夺了过去。\n"NOR,me, victim);            
               weapon1->unequip();
               weapon1->move(environment(victim));
                           }
                           break;
            case 1 :
              message_vision( HIG"$N使个“缠”字诀,"+weapon1->name()+"挥到东，"+weapon->name()+"跟向东，"+weapon1->name()+"打到西，"+weapon->name()+"随到西，如影随形，借力制敌。\n"NOR,me, victim);
               damage = damage_bonus/10 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage) 
                                 { victim->set("jing",0); }
                                 else {
if (victim->query("jing") >damage)
                 victim->receive_damage("jing", damage); 
                                 }
                if (!victim->is_busy()) victim->start_busy(3);
                //me->add("neili", -damage);    
                           break;
                          }
                  }
           }
        if (random(5)==0)
        {
                victim->receive_wound("qi", (damage_bonus - 30) , me);
return HIY "只听「碰」一声，"+victim->name()+"被无数的棒影扫倒在地！\n" NOR;
        }
}
int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        int j,neili,neili1,skill,skill1,a,p;

	object weapon;
        string msg,dodge_skill,*limbs;
        int i,  level,level2,  q;
        
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        neili = me->query("neili");
        neili1 = ob->query("neili");
        skill = me->query_skill("dagou-bang",1);
        skill1 = me->query_skill("xianglong-zhang",1);
a=me->query("combat_exp", 1);
p=ob->query("combat_exp", 1);

        limbs = ob->query("limbs");
        level = me->query_skill("dagou-bang", 1);
level2 = me->query_skill("dagou-bang", 1);

        if (  level2 > 100
        && random(3)==1 && me->query_skill_mapped("force") == "huntian-qigong"){
//if (1==1){
	
             msg = HIY"$N连续使出缠字诀，封字决，让$n不知所措!\n"NOR;
             //if (!ob->is_busy())
             ob->start_busy(2+random(2));
           message_vision(msg, me, ob);
               }

if (me->query_skill_mapped("force") != "huntian-qigong")
return damage;

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
return damage; 


        


        if( living(me) 
         && random(skill)+20 > 180
         && skill > 100 
         && neili > 500 
         && random(a) > random(p)/3
         && me->query_skill_mapped("parry") == "dagou-bang"
         && living(ob)
         && wp 
         && random(20)>12){
            me->add("neili", -(random(50)));
         if(wp1){                    
            message_vision( HIG "$N一招甫出，但见$n使个“封”字诀，棒影飘飘，登时将自己\n"
                + "身前数尺之地尽数封住了。$N无奈之下，只有后退一步，静观变化。\n" NOR,ob,me);
         if( me->is_busy()){
            me->start_busy(1);
if (!ob->is_busy())
            ob->start_busy(3);
         }
         j = -damage;
        }           
        else{
           message_vision( HIG "$N的手指刚要碰到$n手腕，突然青影闪动，"
                   + wp->name() + HBGRN "一势“封”字诀，来势神妙无方，\n"
                   + "手腕已被重重地敲了一下。$N慌忙后退两步，变色斜睨，背上惊出了一阵冷汗。\n" NOR,ob,me );
           if( me->is_busy()){
                 me->start_busy(1);
if (!ob->is_busy())
                 ob->start_busy(3);
            }
            else
                 if (!ob->is_busy())
                 ob->start_busy(3);
if (ob->query("qi") > damage/2)
{
                 ob->receive_damage("qi", damage/2 > 0?damage/2:10, me);
                 ob->receive_wound("qi", damage/6 > 0?damage/10:2, me);
}
                 j = -damage;            
        }
        return j;
    }          
}
