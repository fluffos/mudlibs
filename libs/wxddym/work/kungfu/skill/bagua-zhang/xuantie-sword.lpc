// 玄铁剑法
#include <ansi.h>;

inherit SKILL;

string  *msg = ({
"$N当胸平平刺出一剑，实在是毫无任何变化，而却有轰轰之声，$n只觉一股大力由$w直逼周身",
"$N凌空跃起，身随剑起，借助下行之势向下猛劈一剑，将$n周身笼于剑气之下",
"$N轻叹一声，随手横劈一剑，缓缓指向$n，看似无丝毫变化，却尽得剑法精髓，当真平淡中
蕴涵所有变化，无招胜有招",
"$N迅疾挑出一剑，但见剑势如虹，快似闪电，无可当锋！此剑之快，匪夷所思，无法分辨剑路去来",
"$N仰首长啸，令风云变幻，狂风遽起，旋及一剑平指，剑气弥漫于$n周身各处，$n只觉身处
惊涛骇浪之中，惊怖中更觉$N剑力有如海潮一般，一波一浪阵阵涌来，绵延不绝，愈发愈强",
"$N祭起$w，左手捏成剑诀置于胸前，咄喝一声，正是剑法至尊的“御剑式”，空中满是剑影，
宛若千道银链，只在$n身边游动",
"$N连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，平淡至极又匪思至极，
顺刺，逆击，横削，倒劈，无不是剑法的入门，当真返朴归真，却已不再存任何破绽",
});
string *parry_msg = ({
        "$n以攻代守，$v直向$N刺去。$N吓的连退数步，撤回了攻势。\n",
        "$n使出一招「日月无心」，将全身躲在了$v形成的剑幕中。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v连续刺出，挡住$N的全部攻势。\n",
});
int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(2)+2)*220,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":(random(2)+2)*50,
                "force":(random(2)+2)*220
        ]);
}

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 550 )
                return notify_fail("你的内力不够，没有办法练玄铁剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xuantie-sword/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,flvl;
        object weapon = me->query_temp("weapon");

        lvl  = me->query_skill("xuantie-sword", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "yunv-xinfa" )
                return;
        if (lvl < 120 ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
 if (random(2)==0)
        {
flvl=random(lvl)+50;
        if (random(3)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-random(lvl));
victim->add("eff_qi",-random(lvl));
}
                return HIR "$n" HIR "被剑气扫中要害，鲜血飞出!!\n" NOR;

}                        }
        if (damage_bonus < 50
           || lvl < 160
           || random(2)
              || ! objectp(weapon)
           || me->query("neili") < 500
           || me->query_skill_mapped("sword") != "xuantie-sword"
      		 || me->query_skill_mapped("force") != "yunv-xinfa")
      		return damage_bonus / 4;

        if (lvl / 2 + random(lvl) > victim->query_skill("parry", 1) || random(10)==0)
        {
                me->add("neili", -100);
                victim->receive_damage("qi", damage_bonus * 4 / 5+10, me);
                victim->receive_wound("qi", damage_bonus * 4 / 5+10, me);
      
                return HIW "$N" HIW "手中" + weapon->name() + HIW "犹如神助，从天而下，威不"
                       "可挡地劈向$n" HIW "，气势恢弘之极。\n" NOR;
         }
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"满场游走，招断意连，绵绵不绝，一招未毕，二招至 !$n双眼一花不知所措！\n" +NOR;
if (random(2)==0)
{
msg += HIY"$N"+HIY+"目光一闪，一把玉锋针扔出 !$n 一不当心，身上连中了几枚！\n" +NOR;	
ob->apply_condition("yf_poison",20);
}
           message_vision(msg, me, ob);
  ob->start_busy(6);  
}


           return j;
}      
int practice_skill(object me)
{
        if( (int)me->query("qi") < 60
        ||      (int)me->query("neili") < 55 )
                return  notify_fail("你的内力或气不够，没有办法练习玄铁剑法。\n"
);
        if(me->query_skill("xuantie-sword",1)>100)
        	return notify_fail("你现在只能通过learn来提高玄铁剑法。\n");
        me->receive_damage("qi", 50);
        me->add("neili", -55);
        write("你按著所学练了一遍玄铁剑法。\n");
        return 1;
}
