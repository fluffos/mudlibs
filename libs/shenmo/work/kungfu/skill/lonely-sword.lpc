// lonely-sword.c 独孤九剑

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
        "却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
        "$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
        "$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。\n",
        "$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来。\n"
        "$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。\n",
        "$n突然使出青城派松风剑法的「鸿飞冥冥」，长剑对着$P一绞，企图突破$P的攻势。\n"
        "$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。\n",
        "只见$n不退反进，身如飘风，一式「天柱云气」动向无定，挡住了$P的\n进攻。\n",
        "$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！架开了$P的这招\n",
        });

mapping *action = ({
([      "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的"+(order[random(13)])+"「来鹤清泉」"NOR"直刺$n
的$l！",
        "force" : 110,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N奇诡地向$n挥出"+(order[random(13)])+"「泉鸣芙蓉」"NOR"、"+(order[random(13)])+"「鹤翔紫盖」"NOR"、"+(order[random(13)])+"「石廪书声」"NOR"、"+(order[random(13)])+"「
天柱云气」"NOR"及"+(order[random(13)])+"「雁回祝融」"NOR"衡山五神剑！",
        "force" : 110,
        "dodge" : 60,
        "damage": 250,
        "lvl" : 7,
        "damage_type" : "刺伤"
]),
([
        "action" : "$N剑随身转，续而刺出十九剑，竟然是华山"+(order[random(13)])+"「玉女十九剑」"NOR"，但奇的
是这十九剑便如一招，手法之快，直是匪夷所思！",
        "force" : 110,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 14,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢
推去！",
        "force" : 120,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 21,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里
，尽括嵩山剑势击向$n的$l！",
        "force" : 120,
        "dodge" : 80,
        "damage": 250,
        "lvl" : 28,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟
化"+(order[random(13)])+"「泰山十八盘」"NOR"为一剑攻向$n！",
        "force" : 130,
        "dodge" : 100,
        "damage": 255,
        "lvl" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑招突变，使出衡山的"+(order[random(13)])+"「一剑落九雁」"NOR"，削向$n的$l，怎知剑到中
途，突然转向，大出$n意料之外！",
        "force" : 140,
        "dodge" : 100,
        "damage": 260,
        "lvl" : 42,
        "damage_type" : "刺伤"
]),
([      "action" : "$N吐气开声，一招似是"+(order[random(13)])+"「独劈华山」"NOR"，手中$w向下斩落，直劈向$n的
$l！",
        "force" : 150,
        "dodge" : 100,
        "damage": 280,
        "lvl" : 49,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w越转越快，使的居然是衡山的"+(order[random(13)])+"「百变千幻云雾十三式」"NOR"，剑
式有如云卷雾涌，旁观者不由得目为之眩！",
        "force" : 160,
        "dodge" : 100,
        "damage": 290,
        "lvl" : 56,
        "damage_type" : "刺伤"
]),
([      "action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融"+(order[random(13)])+"「达摩剑」"NOR"为一式，闲舒地刺
向$n！",
        "force" : 170,
        "dodge" : 100,
        "damage": 300,
        "lvl" : 63,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举起$w运使"+(order[random(13)])+"「太极剑」"NOR"剑意，划出大大小小无数个圆圈，无穷无尽
源源不绝地缠向$n！",
        "force" : 280,
        "dodge" : 100,
        "damage": 320,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，"+(order[random(13)])+"「伏摩
剑」"NOR"的剑意表露无遗！",
        "force" : 290,
        "dodge" : 105,
        "damage": 330,
        "lvl" : 77,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N突然虚步提腰，使出酷似武当"+(order[random(13)])+"「蜻蜓点水」"NOR"的一招！",
        "force" : 200,
        "dodge" : 105,
        "damage": 360,
        "lvl" : 84,
        "damage_type" : "刺伤"
]),
([      "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是"+(order[random(13)])+"「伏
魔剑」"NOR"的"+(order[random(13)])+"「龙吞式」"NOR"。",
        "force" : 220,
        "dodge" : 100,
        "damage": 395,
        "lvl" : 91,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然运剑如狂，一手关外的"+(order[random(13)])+"「乱披风剑法」"NOR"，猛然向$n周身乱刺乱
削！",
        "force" : 240,
        "dodge" : 100,
        "damage": 320,
        "lvl" : 98,
        "damage_type" : "刺伤"
]),
([      "action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的
虚实！",
        "force" : 260,
        "dodge" : 100,
        "damage": 350,
        "lvl" : 105,
        "damage_type" : "刺伤"
]),
([      "action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什
么剑法！",
        "force" : 280,
        "dodge" : 100,
        "damage": 380,
        "lvl" : 112,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知
如何是好！",
        "force" : 200,
        "dodge" : 100,
        "damage": 485,
        "lvl" : 119,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫
得$n不得不守！",
        "force" : 320,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 126,
        "damage_type" : "刺伤"
]),
([      "action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n
难以看清剑招来势！",
        "force" : 340,
        "dodge" : 105,
        "damage": 480,
        "lvl" : 133,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招
式。",
        "force" : 460,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 140,
        "damage_type" : "刺伤"
]),
([      "action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可
思议！",
        "force" : 480,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 147,
        "damage_type" : "刺伤"
]),
([      "action" : "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n
的$l！",
        "force" : 500,
        "dodge" : 100,
        "damage": 520,
        "lvl" : 154,
        "damage_type" : "刺伤"
]),
([
    "action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！",
        "force" : 600,
        "dodge" : 100,
        "damage": 665,
        "lvl" : 180,
    "damage_type" : "刺伤"
]),
([      "action" : HIW "但见$N手中$w" HIW "破空长吟，平平一剑刺向$n，毫无招式可言",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 250,
        "damage_type" : "刺伤"
]),
([      "action" : HIW "$N揉身欺近，轻描淡写间随意刺出一剑，简单之极，无招无式",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 300,
        "damage_type" : "刺伤"
]),
([      "action" : HIW "$N身法飘逸，神态怡然，剑意藏于胸中，手中$w" HIW "随意挥洒而出，独孤"
                   "九剑已到了收发自如的境界",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 350,
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "华山派"|| myfam["master_id"] != "feng qingyang")
                return notify_fail("独孤九剑只有向风清扬老前辈学习。\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练独孤九剑。\n");
        if( (int)me->query_skill("zixia-shengong",1)<100)
                return notify_fail("独孤九剑必须配合紫霞神功才能练习。\n");
       if (((int)me->query_skill("huashan-sword", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的剑宗华山剑法太低了。\n");
       if (((int)me->query_skill("kuangfeng-jian", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的气宗狂风快剑太低了。\n");
       if (((int)me->query_skill("poyu-quan", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的破玉拳太低了。\n");
       if (((int)me->query_skill("hunyuan-zhang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的混元掌太低了。\n");
       if (((int)me->query_skill("feiyan-huixiang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的飞燕回翔太低了。\n");
       if (((int)me->query_skill("huashan-neigong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的剑宗内功太低了。\n");
       if (((int)me->query_skill("zixia-shengong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的气宗内功太低了。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("独孤九剑只能通过"+(order[random(13)])+"「总诀式」"NOR"来演练。\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	int damage;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("lonely-sword", 1);
        if (random(me->query_skill("lonely-sword",1)) < 100 ||		             me->query_skill("force",1) < 100 )
        return 0;

	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("zixia-shengong",1);
        level2= (int) me->query_skill("zixia-shengong",1);
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "zixia-shengong")
{
if (random(2)==0)
{
	victim->start_busy(2);
}
else 	victim->receive_wound("qi", (random(damage_bonus))+200);
                  return random(2) ? HIR "$N" HIR "运起紫霞神功，一剑攻出，剑气横飞，,$n双眼一花,不知如何是好!\n" NOR:
                                     HIR "$N" HIR "剑随意走,手中" + weapon->name() + HIR "犹如生了眼睛一般，随意挥出几剑,$n双眼一花,不知如何是好!\n"NOR;
}
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("zixia-shengong",1);             
	if (random(3)==1 && me->query_skill("zixia-shengong",1)>300)
	{
	if( damage_bonus > 50 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)));
	return HIM"$N剑气纵横! 一道剑气划过了$n的$l。结果鲜血狂奔!\n"NOR;
        }
}

if (me->query_skill_mapped("force") != "zixia-shengong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("sword") != "lonely-sword")
return 0;
if (me->query_skill_mapped("parry") != "lonely-sword")
return 0;

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return 0; 
        ap = (int)me->query("combat_exp");
        dpp = (int)victim->query("combat_exp");
        switch(random(5))
        {
           case 1:
              if (random(ap) > dpp/2 && random(lvl)> 180)
              {
                  me->add("neili", -20);
                  victim->receive_wound("qi", (damage_bonus) , me);
                  
                  return random(2) ? HIR "$N" HIR "一剑攻出，剑气横飞，" + weapon->name() + HIR
                                     "时若游龙穿空，时若惊鸿渡云，却不知这普通的"
                                     "一剑之中竟蕴藏着如此威力。\n" NOR:
                                     HIR "$N" HIR "手中" + weapon->name() + HIR "犹"
                                     "如生了眼睛一般，一剑随意挥出，竟直刺向$n" HIR 
                                     "小腹，看似平淡，但方位、力道却拿捏得恰倒好处。\n" NOR;
             }
             break;

           case 2:
              if (random(ap) > dpp/2 && me->query("con") >= 36 && random(lvl)> 180)
              {
                  me->add("neili", -120);
                  victim->receive_wound("qi", (damage_bonus ) , me);
                  
                  return random(2) ? HIR "$N" HIR "一剑攻出，剑气横飞，" + weapon->name() + HIR
                                     "时若游龙穿空，时若惊鸿渡云，却不知这普通的"
                                     "一剑之中竟蕴藏着如此威力。\n" NOR:
                                     HIR "$N" HIR "手中" + weapon->name() + HIR "犹"
                                     "如生了眼睛一般，一剑随意挥出，竟直刺向$n" HIR 
                                     "小腹，看似平淡，但方位、力道却拿捏得恰倒好处。\n" NOR;
             }
             break;

          case 3:
             message_vision(HIC "\n$N" HIC "随意挥洒手中的" + weapon->name() +
                            HIC "，招招从出其不意的方位直指$n" HIC "招式中的"
                            "破绽！\n" NOR, me, victim);

             if (! me->is_busy() && random(lvl)> 180)
             {
                  weapon = me->query_temp("weapon");
                  weapon2 = victim->query_temp("weapon");
                  if (random(ap) > dpp/2 && weapon2
                      && !weapon2->query("ownmake") )
                  {
                           msg = HIW "$n" HIW "觉得眼前眼花缭乱，手中"
                                 "的" + weapon2->name() + HIW "一时竟"
                                 "然拿捏不住，脱手而出！\n" NOR;
                           weapon2->move(environment(me));      
                           me->add("neili", -100);                 
                  } else
                  {
                           msg = HIY "$n" HIY "略得空隙喘息，一时间却"
                                 "也无力反击。\n" NOR;
                           me->add("neili", -10);
                  }
             }else 
             if (random(ap) > dpp/2 && random(lvl)> 180)
             {
                          msg = HIY "$n" HIY "连忙抵挡，一时间不禁手忙脚乱，"
                                "无暇反击。\n" NOR;

                          me->start_busy(1);
                          victim->start_busy(2 + random(lvl / 30));
             }
             else
             {
                          msg = HIC "$N" HIC "随意挥洒着手中的" + weapon->name() +
                                HIC "刺向$n" HIC "，不过$n" HIC "防守的异常严密，$N"
                                HIC "一时竟然无法找到破绽。\n" NOR;
                          me->start_busy(1);
                          victim->start_busy(3);
             }
             message_combatd(msg, me, victim);
             break;
          
          case 4:
             if (random(ap) > dpp/2 && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian") &&
                 me->query("dex") >= 36
                 && random(lvl)> 180
                 )
             {
                weapon = me->query_temp("weapon");
                message_vision(HIY "\n$N" HIY "胸藏剑意，手中" + weapon->name() + HIY 
                             "随意挥洒而出，速度之快，方位之准，显是独孤九剑已达到"
                             "\n收发自如的境界。\n" NOR,
                             me, victim);

                me->add("neili", -20);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 7; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(2);

                    COMBAT_D->do_attack(me, victim, weapon, 0);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
          
          default :
             if (random(ap) > dpp/2 && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian")
                 && random(lvl)> 180)
             {
                weapon = me->query_temp("weapon");
                message_vision(HIY "\n$N" HIY "胸藏剑意，手中" + weapon->name() + HIY 
                             "随意挥洒而出，速度之快，方位之准，显是独孤九剑已达到"
                             "\n收发自如的境界。\n" NOR,
                             me, victim);

                me->add("neili", -20);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 7; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(2);

                    COMBAT_D->do_attack(me, victim, weapon, 0);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
       }

        if (random(me->query_skill("lonely-sword",1)) > 200 &&
        random(me->query_skill("sword",1))>180 &&
     	me->query_skill("force",1) > 250 
     	&& !victim->is_busy())
{
        me->add("neili", -50);
        victim->map_skill("dodge");

  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+2);
}
        message_vision(HIC "$n突然举剑一刺，剑招随便无章，却莫明奇妙地突破了$N的攻势，大出$N意料！" NOR, victim,me  );
        return HIR"$n大吃一惊，竟然忘了闪避！\n"NOR;
        
}
        if (random(me->query_skill("lonely-sword",1)) > 140 &&	
	 random(me->query_skill("sword",1))>140 &&
            me->query_skill("force",1) > 200 
            && !victim->is_busy())	
{
        
        me->add("neili", -30);
        victim->map_skill("parry");
  if( !victim->is_busy() )
{
        victim->start_busy(random(2)+2);
}
        message_vision(HIC "$n举剑反攻，后发先至地刺向$N，不仅把$N招术封死，更进一步发出攻击！" NOR, victim,me);
        return HIY"$n难以看清剑招来势,竟然忘了招架！\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 130 &&	
        random(me->query_skill("sword",1))>130 &&
	 me->query_skill("force",1) > 150
	 && !victim->is_busy())
{
        me->add("neili", -50);
  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+2);
}
        message_vision(HIC "$n提剑回刺，落点正是$N的破绽，$N不得不撤招严守，身形一晃间已退出丈许！" NOR, victim,me );
        return HIG"$n手忙脚乱，慌乱不堪！\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 100 &&
        random(me->query_skill("sword",1))>100 &&
      	me->query_skill("force",1) > 120
      	&& !victim->is_busy() )	
{
if (victim->query("neili")>600)
{
        victim->add("neili", -500);
}
        message_vision(HIC "$n一转剑势，剑招源源而出，对$N发动攻势！\n" NOR, victim,me );
	return HIM"$n使出浑身解数才脱出剑圈！\n"NOR;
}
        if (random(me->query_skill("lonely-sword",1)) > 80 &&	
        random(me->query_skill("sword",1))>80 &&  
	  me->query_skill("force",1) > 100 
	  && !victim->is_busy())	
{

  if( !victim->is_busy() )
{        victim->start_busy(random(2)+2);
}
        message_vision(HIC "$n眼见避无可避，只好提剑乱刺一通，居然出乎意料地将$N的攻击接去大半。" NOR, victim,me );
	return HIW"$n顿时手足无措，不知如何是好！\n"NOR;
  } 
	
	jiali = me->query("jiali");

if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(me->query_skill("lonely-sword",1))>140 
	&& me->query("fengset")
	) {
	victim->receive_wound("qi", (random(jiali)+200));
	return HIM"$N剑气纵横! 一道剑气划过了$n的$l。结果鲜血狂奔!\n"NOR;
}
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
j=damage;
if (me->query_skill_mapped("force") != "zixia-shengong")
return damage;
if (me->query_skill_mapped("sword") != "lonely-sword")
return damage;
if (me->query_skill_mapped("parry") != "lonely-sword")
return damage;

if (me->query("neili") < 500)
return damage;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return damage;

             if (random(ap) > dp/2 && random(2)==0)
             {
                        result = HIG "$n" HIG "不理会$N" HIG "的攻势，"
                                    "随意挥出一剑，反攻向$N" HIG "。\n" NOR;
                                    if (!ob->is_busy()) ob->start_busy(3);
                    message_vision(result,ob,me);
             }
             
  if (random(ap) < dp/2  && me->query("fengset") 
  && random(2)==0)
        {
                switch (random(9))
                {
                case 0:
                        result = HIC "却见$n" HIC "踏前一步，剑式斜指$P" HIC
                                            "右臂，招式迅捷无比，使得$N" HIC "闪身而退"
                                            "。\n" NOR;
                        break;

                case 1:
                        result = HIC "可$n" HIC "以攻为守，以进为退，凝神运"
                                            "气向$N" HIC "猛攻快打地挥出方位大异的泰山"
                                            "「" NOR + YEL "快活三" NOR + HIC "」剑法。"
                                            "\n" NOR;
                        break;

                case 2:
                        result = HIC "$n" HIC "突然一剑点向$N" HIC "，虽一剑"
                                            "却暗藏无数后着，$N" HIC "顿时手足无措，攻"
                                            "势不由自主停了下来。\n" NOR;
                        break;

                case 3:
                        result = HIC "可是$n" HIC "不闪不避，举剑闪电般使出"
                                            "「" NOR + HIG "叠翠浮青" NOR + HIC "」反削"
                                            "$N" HIC "手腕，挡开了此招。\n" NOR;
                        break;

                case 4:
                        result = HIC "却见$n" HIC "突然使出青城派松风剑法「"
                                            NOR + CYN "鸿飞冥冥" NOR + HIC "」，长剑对"
                                            "着$N" HIC "一绞，顿时突破了攻势。\n" NOR;
                        break;

                case 5:
                        result = HIC "$n" HIC "挺剑而射，若一招「" NOR + HIW
                                            "白云出岫" NOR + HIC "」回刺$N" HIC "，顿"
                                            "时已将攻势化解。\n" NOR;
                        break;

                case 6:
                        result = HIC "只见$n" HIC "不退反进，身如飘风，一式" 
                                            "「" NOR + HIW "天柱云气" NOR + HIC "」动向"
                                            "无定，挡住了进攻。\n" NOR;
                        break;

                case 7:
                        result = HIC "但见$n" HIC "不退反进，使出恒山剑招「"
                                            NOR + HIY "绵里藏针" NOR + HIC "」，剑气四"
                                            "溢，架开了$N" HIC "这招。\n" NOR;
                        break;

                default:
                        result =  HIC "$n" HIC "剑法突变，剑势伸缩不定，奔腾"
                                            "矫夭，逆使嵩山剑法的「" NOR + HIY "天外玉"
                                            "龙" NOR + HIC "」企图迫使$N" HIC "变招。\n"
                                            NOR;
                        break;
                }
message_vision(result,ob,me);
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi"))
me->add("qi",damage/3);
if ((int)me->query("eff_qi") < (int)me->query("max_qi"))
me->add("eff_qi",damage/3);
            damage=100;
            j=100;
            return j;

        }
             
        
if ((int)me->query("qi")>1 && (int)me->query("eff_qi")>1)
{
if ((int)me->query("qi") < (int)me->query("eff_qi"))
        i = (int)me->query("eff_qi") / (int)me->query("qi") + 1;
else         i = (int)me->query("max_qi") / (int)me->query("eff_qi") + 1;
        if ( i > 5 ) i = 5;
}
else i=1;
        limbs = ob->query("limbs");
        level = me->query_skill("lonely-sword", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 100 /i 
         && me->query_skill_mapped("sword") =="lonely-sword"
         && me->query_skill_mapped("parry") =="lonely-sword"
         && me->query("fengset")
         && weapon
         && weapon->query("skill_type") == "sword"
         && me->query_skill("sword") > 300
         && random(me->query_skill("sword",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 4000
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIW"$N身子摇摇欲坠，行动不便，知道这一招无可躲避，当即挺剑刺出，后发先至，噗的一声刺向$n的咽喉。\n"NOR;
            if ( random(level) > ob->query_skill("dodge", 1) / i){
             q = damage * i ;
             if ( q > 3500 ) q = 3500 + ( q - 3500 )/ 100;
             ob->receive_damage("qi", q);
             ob->receive_wound("qi", q/2);
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
             if ( random(me->query("combat_exp")) > ob->query("combat_exp") / i)
             p = ob->query("qi")*100/ob->query("max_qi");
             msg += damage_msg(damage, "刺伤") + "( $n"+eff_status_msg(j)+" )\n";
             msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
             msg = replace_string(msg, "$w", "剑刃");
             j = -(damage/2+random(damage/2));
            }
            else {
              dodge_skill = ob->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(ob, 1);
              j = -damage/4; 
            }
            message_vision(msg, me, ob);
            return j;
        }
}
