#include <ansi.h>
#include <ansi.h>;
inherit FORCE;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *dodge_msg = ({
        "$n微微一动，已然远去，使$N的进攻全然无用。\n",
        "$n霎时间平移了数步，如鬼如魅，使$N全然无法掌握。\n",
        "$n忽的一退，闪去天下任何追击。\n",
        "$n足不离地，腰肢猛摆，居然将$N的进攻全部躲过。\n",
});

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", }); 

string *parry_msg = ({
"$n左一拨，右一拨，上一拨，下一拨，将$N的招数尽数拨开。这四下拨挡，周身竟无半分破绽。\n",
"$n右手大拇指和食指捏住一根绣花针，向上一举，挡住来势，$N的招式便使不下去。\n",
"$n不挡不闪，左手食指颤动，向$N的左目急刺，竟是两败俱伤的打法。\n",
"$n左拨右挡，兀自好整以暇的啧啧对$N连赞：“好功夫，好功夫！”\n",
"$n从怀中取出一块雪白的绸帕，轻轻抹了抹脸，简直便如是戏台上的花旦。$N一呆，竟停住了自己的招式。\n"
});

string  *msg = ({
"$N身形一变，如闪电般欺到$n身前，相距不过一尺，手中$w已经刺到$n的$l",
"但见红影闪处，$N手中的$w向$n的$l直戳而来，势如奔雷，避不可避",
"$N欺身而上，左手在$n的肩上一拍再横飞出去，而手中的$w却指向$n的$l",
"$N突然跃起丈余，$n一抬头，发现空中并无$N的身影，而一股寒气却从后袭来",
"$N左一拨，右一拨，上一拨，下一拨，将$n的招数尽数拨开，右手一转，刺向$n",
"蓦地里$N空手猱身而上，双手擒拿点拍，攻势凌厉之极，乘$n惊骇之际弹出$w刺向$n",
"$N身形飘忽，有如鬼魅，转了几转，移步向西，一剑刺向$n。出手之奇之快，直是匪夷所思",
"$N脚下一顿，站立片刻，忽向$n的左后方滑出丈余，跟着快速无伦的回到原处",
"$N潜运内力，忽进忽退，绕着$n身子乱转，手中$w所使剑招也如狂风骤雨一般，越来越快",
"突然$N手中$w向上一撩，就在$n微一分神之际直取$n的$l，势道劲急无伦"NOR,
"就在$n一呆之际，$N向右跃开两尺，右足刚著地，身子跟著弹起，刷刷两剑，向$n攻去",
"$N忽然化身为二，分出左右两个身影高速滑向$n，手中$w幻化不定，直刺$n的$l",
"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
"$N一声尖叫，飞身纵起，在半空中一转，快绝无比的飞落下来，手中$w破空直刺$n$l",
"$N忽然化身为二，分出上下两个身影高速滑向$n，手中$w变幻莫测，直刺$n的$l",
"$N的身形如鬼如魅，飘忽来去，直似轻烟，手中的$w却总是对着$n身子",
"$N一声冷笑，蓦地里疾冲上前，当真是动如脱兔，一瞬之间，与$n相距已不到一尺，两人的鼻子几乎要碰在一起",
"$N右手伸出，在$n手腕上迅速无比的一按，跟着手臂回转，又在$n手肘下一推",
"$N一剑挺刺，极尽都雅，神态之中，竟大有华山派女弟子所学‘玉女剑十九式’的风姿，只是带着三分阴森森的邪气",
"$N左手一圈，倒转$w，蓦地刺出，刷刷刷急攻三式，招招尽是指向$n的要害"
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "force" || usage =="parry"; 
}
mapping query_action(object me, object weapon)
{               
       return ([
          "action":msg[random(sizeof(msg))],
          "attack":30,
          "damage":(random(6)+2)*100,
          "damage_type": "刺伤",
          "dodge": random(180)+30,
          "force":(random(500)+150),
       ]);
}
string query_parry_msg()
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        if ((int)me->query("neili") < 1500)
                return notify_fail("你的内力不够。\n");
       if (((int)me->query_skill("kuihua-feiying", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的葵花飞影术太低了。\n");
       if (((int)me->query_skill("kuihua-xinfa", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的葵花心法太低了。\n");

       if (((int)me->query_skill("tmdao", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔刀太低了。\n");

       if (((int)me->query_skill("tmjian", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔剑太低了。\n");
       if (((int)me->query_skill("tmzhang", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔掌太低了。\n");
       if (((int)me->query_skill("tmdafa", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔大法太低了。\n");
       if (((int)me->query_skill("changquan", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的长拳太低了。\n");

        if ((int)me->query_skill("pixie-jian", 1) < 180)
                return notify_fail("你的「辟邪剑法」火候太浅。\n");

    if ( (string)me->query("gender")=="女性" )
        return notify_fail("女子不能学.\n");

   if ( (string)me->query("gender")=="男性" )
        return notify_fail("你必须先自宫,才能练.\n");

        return 1;
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
               return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("pixie-jian", 1) < 180)
                return notify_fail("你的「辟邪剑法」火候太浅。\n");
       if ((int)me->query_skill("kuihua-dafa", 1) < 180)
               return notify_fail("你还没有领会葵花神功的精髓，不能自行练习。\n");
       if (((int)me->query_skill("kuihua-feiying", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的葵花飞影术太低了。\n");
       if (((int)me->query_skill("kuihua-xinfa", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的葵花心法太低了。\n");
       if (((int)me->query_skill("tmdao", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔刀太低了。\n");
       if (((int)me->query_skill("tmjian", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔剑太低了。\n");
       if (((int)me->query_skill("tmzhang", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔掌太低了。\n");
       if (((int)me->query_skill("tmdafa", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的天魔大法太低了。\n");
       if (((int)me->query_skill("changquan", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("你的长拳太低了。\n");


    if ( (string)me->query("gender")=="女性" )
        return notify_fail("女子不能学.\n");

   if ( (string)me->query("gender")=="男性" )
        return notify_fail("你必须先自宫,才能练.\n");

       if ((int)me->query("jing") < 130)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 70)
               return notify_fail("你的内力不够了。\n");
       me->receive_damage("jing", 80);
       me->add("neili", -50);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuihua-dafa/" + action;
}

string exert_function_file(string func)
{
       return __DIR__"kuihua-dafa/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
        object weapon;
        string name;
 int i,attack_time,isok;
 int level, level2;
        int ap, dp, mp;
         level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
 weapon = me->query_temp("weapon");

        ap = (int)me->query("combat_exp");
        dp = (int)victim->query("combat_exp");
if (me->query_skill_mapped("force") != "kuihua-xinfa")
return;

if (me->query_skill_mapped("sword") != "kuihua-dafa")
return;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return;
if (me->query("neili") < 500)
return;
if (!weapon) return;
        if (me->query_temp("weapon"))
	        name = "手中" + weapon->name();
        else
	        name = "双掌";

        attack_time = (int)(me->query_skill("kuihua-dafa", 1) / 60);

        if (attack_time > 6)
                attack_time = 6;

        if (me->is_busy()
           || random(3) == 0
           || ! living(victim)
           || damage_bonus < 120
           || me->query("neili") < 300
           || me->query_temp("action_flag") == 1
           || me->query_skill("kuihua-dafa", 1) < 200)
        	return 0;

        // 避免在使用Pfm时讯息重复
if (!me->query_temp("action_flag") && random(ap) > dp/3 && random(2)==0)
{
        if (! me->query_temp("kuihua-mogong/hit_msg"))
	        message_vision(HIW "\n霎时间只见$N" HIW "身子猛摆，顿时化分为无数身影，" + name +
        	               HIW "\n宛若流星般分从不同的方位同时刺向$n" HIW "！\n"
                	       NOR, me, victim);

	//me->start_busy(2);
        //me->add("neili", -attack_time * 20);
        me->set_temp("action_flag", 1);
        for (i = 0; i < attack_time; i++)
        {

                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}
isok=0;
if (level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
isok=1;	
}
if (weapon)
{
   if( random(me->query_str()) > victim->query_str()/3 || isok=1){
	victim->receive_wound("qi", me->query_str()+random(100));
	 return HIR "只听「嗤」一声，一缕血丝从"+victim->name()+"被刺的针孔处喷出！\n" NOR;
	}
}



}



int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        object wp1;
        int skill, neili, neili1;
        int level2,damage2;
        level = (int) me->query_skill("tmdafa",1);
        level2= (int) me->query_skill("tmdafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/8;
if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "一声冷笑! 吸星大法!! " HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
       
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
        j=damage;
if (me->query_skill_mapped("force") != "kuihua-xinfa")
return damage;
if (me->query_skill_mapped("sword") != "kuihua-dafa")
return damage;


if (me->query("neili") < 500)
return damage;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return damage;

             if (random(ap) > dp/3 && random(2)==0 )
             {
                switch (random(4))
                {
                case 0:

                        result = HIW "$N" HIW "眼睛一花，$n" HIW "已没了踪"
                                            "影。突然$n" HIW "从身后拍了一下$N" HIW "的"
                                            "头，轻轻跃开。\n" NOR;
                        break;
                case 1:
                        result = HIW "$N" HIW "眼前一花，似乎见到$n" HIW "身"
                                            "形一晃，但随即又见$n" HIW "回到原地，却似"
                                            "从未离开。\n" NOR;
                        break;
                case 2:
                        result =  HIW "$n" HIW "尖啸一声，忽然身子一转已不见了踪影，$N" HIW
                                           "只觉耳边风声不断，但随即又见$n" HIW "回到了原地。\n" NOR;
                        break;
                case 3:
                        result =  HIW "$n" HIW "尖啸一声，忽然身子一转已不见了踪影，$N" HIW
                                           "只觉耳边风声不断，但随即又见$n" HIW "回到了原地。\n" NOR;
                        break;

                default:
                        result = HIW "忽然间，只见$n" HIW "腰枝一摆，顿时出现无数个"
                                            "$n" HIW "的影子，$N" HIW "却无法辨别出$n" HIW "的方位。\n" NOR;
                        break;
                        }
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi"))
me->add("qi",damage/5);
if ((int)me->query("eff_qi") < (int)me->query("max_qi"))
me->add("eff_qi",damage/5);
                    message_vision(result,ob,me);
             }
             
            return j;
}
