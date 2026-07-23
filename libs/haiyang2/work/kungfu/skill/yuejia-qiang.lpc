#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
 string *parry_msg = ({
                        "$n豪气干云，吟道：「笑谈渴饮匈奴血」，手中的$v由下而上，荡开了$N的$w。\n",
                        "$n吟道：「凭栏处，潇潇雨歇」，手中的$v舞得密不透风，将$N的$w封于丈外。\n",
                        "$n慷慨的诵道：「莫等闲白了少年头，空悲切」，手中的$v化做漫天残照，荡开了$N的$w。\n",
                        "$n手中的$v一抖，枪身暴长，向$N拿$w的手腕刺去。\n",
});

 string *unarmed_parry_msg = ({
                        "$n使出一招「怒发冲冠」，将手中的$v舞得密不透风，封住了$N的攻势。\n",
                        "$n使出一招「壮怀激烈」，整个人消失在一团枪影之中。\n",
                        "$n抽身急转，$v直刺$N的双手。\n",
                        "$n将手中的$v一抖，舞出无数枪影，迫得$N连连后退。\n",
});

mapping *action = ({

        ([      "action":               
"$N手中$w起起伏伏，忽上忽下，正是一招"+(order[random(13)])+"「怒发冲冠」"NOR"，枪锋泛起一片寒光，攻向$n的$l!",
                "damage":               370,
                "dodge":                40,
                "parry":                40,
                "force":                300,
                "post_action":  "bash_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N身形一缓，聚气凝神，使出一招"+(order[random(13)])+"「潇潇雨歇」"NOR"，身形紧绷如弓，以$w为箭，趁$n一个破绽，如电射向$n。",
                "damage":               360,
                "dodge":                70,
                "parry":                30,
                "force":                350,
                "post_action":  "bash_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N卖个破绽，却于$n疏乎之际，使出一招"+(order[random(13)])+"「抬望眼，仰天长啸」"NOR"，倒过枪柄忽如其来的敲向$n$l！",
                "damage":               360,
                "dodge":                30,
                "parry":                60,
                "force":                375,                
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N真力灌注$w，简简单单的横划出去，一招平凡的"+(order[random(13)])+"「壮怀激烈」"NOR"，在$N手中竟有如斯威力！",
                "damage":               380,
                "dodge":                60,
                "parry":                40,
                "force":                375,           
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w一晃，转身就走，突然一记"+(order[random(13)])+"「莫等闲，白了少年头，空悲切。」"NOR"由腋下刺出，$n发现时，枪尖已灵蛇般刺到$n眼前。",
                "damage":               360,
                "dodge":                30,
                "parry":                60,
                "force":                350,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w高举，凝神静气，一式"+(order[random(13)])+"「靖康耻，尤未雪」"NOR"自上直击而下，$n犹如身处炼狱洪炉，不知所措。",
                "damage":               360,
                "dodge":                30,
                "parry":                60,
                "force":                350,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
                       ([      "action":               
                                        "$N口中吟道: "+(order[random(13)])+"「待从头收拾旧山河，朝天阙。」"NOR"，手中$w倒转，枪杆\n由下至上，直向$n的$l打去",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               340,
                "damage":               360,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N长叹道："+(order[random(13)])+"「靖康耻，犹未雪，臣子恨，何时灭！」"NOR"，手中$w晃出无数\n枪影，忽然一枪向$n的$l刺去",
                                "dodge":                30,
                                "parry":                40,
                                "force":               315,
                "damage":               360,
                           "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N面带忧色，吟道："+(order[random(13)])+"「三十功名尘与土。」"NOR"枪身突转，向$n的下盘扫去",
                                "dodge":                30,
                                "parry":                30,
                                "force":               350,
                "damage":               360,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N一声清啸，"+(order[random(13)])+"「驾长车，踏破贺兰山缺。」"NOR"，大踏步向前走来，手中$w\n平平递出，直取$n的$l",
                                "force":                330,
                                "dodge":                20,
                                "parry":                30,
                "damage":               360,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N低头吟哦："+(order[random(13)])+"「八千里路云和月」"NOR"，手中$w凌空虚点，蓦地进步跟身，\n向$n扫出一排枪影",
                                "dodge":                30,
                                "parry":                30,
                                "force":               330,
                "damage":               360,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N慷慨激昂的诵道："+(order[random(13)])+"「壮志饥餐胡虏肉」"NOR"，手中长枪忽左忽右，游移不定，募然反\n身向$n的$l挑去",
                                "dodge":                56,
                                "parry":                13,
                                "force":               310,
                "damage":               360,
                                "damage_type":  "刺伤"
                        ]),
});
 
int valid_enable(string usage) { return  (usage == "club") || (usage =="parry"); }
 
int valid_learn(object me)
{
           mapping fam  = me->query("family");
         if ((int)me->query("max_neili") < 1500)
                return notify_fail("你的内力不够。\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("你的混天气功修为不够。\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 150)
               return notify_fail("你的六合掌法太低了。\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 150)
               return notify_fail("你的疯魔杖法太低了。\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 150)
               return notify_fail("你的逍遥游太低了。\n");
       if (((int)me->query_skill("dagou-bang", 1)) < 150)
               return notify_fail("你的打狗棒太低了。\n");
       if (((int)me->query_skill("chansi-shou", 1)) < 150)
               return notify_fail("你的锁喉功太低了。\n");
       if (((int)me->query_skill("suohou-gong", 1)) < 150)
               return notify_fail("你的缠丝擒拿手太低了。\n");
                              
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练。\n");
   
   
         return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"yuejia-qiang/" + action;
}
string query_skill_name(int level)
{
         int i;
         for(i = sizeof(action)-1; i >= 0; i--)
                 if(level >= action[i]["lvl"])
                         return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("yuejia-qiang",1);

         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
 mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("huntian-qigong",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "huntian-qigong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIG"$N使出一招「壮怀激烈」，整个人消失在一团枪影之中!\n"NOR;
}
if (damage_bonus <20) damage_bonus=20;
      if( random(me->query_skill("yuejia-qiang",1)) > 150 ) 
{
	  victim->receive_wound("qi", (damage_bonus)/2+120);
        return HIR "$N使出一招「怒发冲冠」，将手中的$w舞得密不透风!\n"NOR;
}
}

int practice_skill(object me)
{
         object weapon;
if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("你的混天气功修为不够。\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 150)
               return notify_fail("你的六合掌法太低了。\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 150)
               return notify_fail("你的疯魔杖法太低了。\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 150)
               return notify_fail("你的逍遥游太低了。\n");
       if (((int)me->query_skill("dagou-bang", 1)) < 150)
               return notify_fail("你的打狗棒太低了。\n");
       if (((int)me->query_skill("chansi-shou", 1)) < 150)
               return notify_fail("你的锁喉功太低了。\n");
       if (((int)me->query_skill("suohou-gong", 1)) < 150)
               return notify_fail("你的缠丝擒拿手太低了。\n");
      		
         if (!objectp(weapon = me->query_temp("weapon"))
                  || (string)weapon->query("skill_type") != "club")
                return notify_fail("你使用的武器不对。\n");
         if ((int)me->query("jing") < 70)
                return notify_fail("你的体力不够。\n");
         if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够。\n");
                
 me->receive_damage("jing", 30);           
         if((int)me->query_skill("yuejia-qiang",1)> 200)
 me->add("neili",-10);

         return 1;
}



int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        int j,neili,neili1,skill,skill1,a,p;

	object weapon;
        string msg,dodge_skill,*limbs,wpname;
        int i,  level,level2,  q;
        
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        neili = me->query("neili");
        neili1 = ob->query("neili");
        skill = me->query_skill("yuejia-qiang",1);
        skill1 = me->query_skill("yuejia-qiang",1);
a=me->query("combat_exp", 1);
p=ob->query("combat_exp", 1);

        limbs = ob->query("limbs");
        level = me->query_skill("yuejia-qiang", 1);
level2 = me->query_skill("yuejia-qiang", 1);
if (wp)
{
wpname=wp->query("name");
        if (  level2 > 100
        && random(3)==1 && me->query_skill_mapped("force") == "huntian-qigong"){
//if (1==1){
	
             msg = HIY"$N豪气干云，吟道：「笑谈渴饮匈奴血」，手中的"+wpname+"由下而上，荡出了几道枪气，让$n不知所措!\n"NOR;
             ob->start_busy(2+random(2));
           message_vision(msg, me, ob);
               }

if (me->query_skill_mapped("force") != "huntian-qigong")
return damage;

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
return damage; 

        if( living(me) 
         && random(skill)+20 > 180
         && skill > 100 
         && neili > 500 
         && random(a) > random(p)/3
         && me->query_skill_mapped("parry") == "yuejia-qiang"
         && living(ob)
         && wp 
         && random(20)>12){
            me->add("neili", -(random(50)));
         if(wp1){                    
             msg = YEL "$N吟道：「凭栏处，潇潇雨歇」，手中的"+wpname+"舞得密不透风，将$n封于丈外。\n" NOR;
           message_vision(msg, me, ob);
         if( me->is_busy()){
            me->start_busy(1);
if (!ob->is_busy())
            ob->start_busy(3);
         }
         j = -damage;
        }           
        else{
             msg = GRN "$N慷慨的诵道：「莫等闲白了少年头，空悲切」，手中的"+wpname+"化做漫天残照，荡开了$N。\n" NOR;
           message_vision(msg, me, ob);

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
                 ob->receive_damage("qi", random(level2)+30);
                 ob->receive_wound("qi", random(level2)+30);
}
                 j = -damage;            
        }

}
        return j;
    }          
}
