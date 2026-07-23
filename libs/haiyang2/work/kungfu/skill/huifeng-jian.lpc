//huifeng-jian.c 回风拂柳剑
#include <ansi.h>
inherit SKILL;  
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name":   "清风袭月",
        "action" : "$N剑尖剑芒暴长，一招"+(order[random(13)])+"「清风袭月」"NOR"，手中$w自左下大开大阖，
一剑向右上向$n的$l",
        "force" : 250,
        "dodge" : 20,
        "damage" : 300,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "name":   "飘雪穿云",
        "action" : "$N长剑圈转，一招"+(order[random(13)])+"「飘雪穿云」"NOR"，手中$w平展下刺，一剑轻轻划
过$n的$l",
        "force" : 260,
        "dodge" : 20,
        "damage" : 280,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "name":   "千峰竞秀",
        "action" : "$N长剑轻灵跳动，剑随身长，右手$w使出一式"+(order[random(13)])+"「千峰竞秀」"NOR"刺向$n的
$l",
        "force" : 280,
        "dodge" : 15,
        "damage" : 350,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "name":   "万流归宗",
        "action" : "$N长剑下指，剑意流转，一招"+(order[random(13)])+"「万流归宗」"NOR"直取$n的$l",
        "force" : 200,
        "dodge" : 15,
        "damage" : 280,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "name":   "乌龙搅柱",
        "action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式"+(order[random(13)])+"「乌龙搅柱」"NOR"，剑势曼妙，
刺向$n的$l",
        "force" : 220,
        "dodge" : 25,
        "damage" : 300,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "name":   "大雁啼沙",
        "action" : "$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式
"+(order[random(13)])+"「大雁啼沙」"NOR"跃跃洒洒飘向$n的$l",
        "force" : 340,
        "dodge" : 25,
        "damage" : 320,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "name":   "进退龙游",
        "action" : "$N挥剑分击，剑势自胸前跃出，右手$w一式"+(order[random(13)])+"「进退龙游」"NOR"，毫无
留恋之势，刺向$n的$l",
        "force" : 360,
        "dodge" : 115,
        "lvl" : 0,
        "damage" : 400,
        "damage_type" : "刺伤"
]),
([      "name":   "天地鹤翔",
        "action" : "$N退步，左手剑指划转，腰部一扭，右手$w一记"+(order[random(13)])+"「天地鹤翔」"NOR"自下
而上刺向$n的$l",
        "force" : 400,
        "dodge" : 135,
        "damage" : 400,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("你的临济十二庄火候太浅。\n");
//        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("huifeng-jian", 1))
//                return notify_fail("你的基本剑法火候太浅。\n");
        return 1;
}
string *juejian_msg = ({ 
	HIR"蓦地里$N$w疾闪，青光闪处，剑尖已指到了$n$l，恰似雷震电掣，剑招狠辣之极"NOR,
	HIW"$N$w一晃，径往$n$l削去，剑势夭矫飞舞，忽分忽合，有如天神行法，凌厉无端"NOR,
	HIC"却见$N飘身而上，半空中举剑上挑，剑光已封住了$n身周数尺之地，攻得精巧无比"NOR,
	HIM"$N纵前抢攻，剑势如风，剑招愈来愈奇，$w颤动，飕飕飕向$n连环三剑，皆是极凌厉的攻势"NOR,
	HIG"$N一个箭步纵到$n身前，手腕微颤，挥剑斜撩，横削$n$l，剑法极尽灵动轻捷"NOR,
});

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("huifeng-jian", 1);

        if (random(me->query_skill("huifeng-jian",1)) > 200 &&	
	 random(me->query_skill("linji-zhuang",1))>120 &&
            me->query_skill("force",1) > 200 )	
	{
		return (["action": random(2) == 1 ?
				HIR"$N$w"HIR"微侧，第一招便即抢攻，剑尖直指$n丹田要穴，出手之凌厉猛悍，直是匪夷所思"NOR
				: juejian_msg[random(sizeof(juejian_msg))],
			 "force" : 500,
			 "dodge" : 50,
			 "damage": 500,
			 "damage_type": random(2)?"刺伤":"割伤" ]);
	}
	else for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练回风拂柳剑。\n");
        me->receive_damage("qi", 10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N 五心向天，运行日月二庄，益气升阳，益阴潜阳，
升降反正，天地二气交泰于身，并配合峨嵋九阳功。灭绝之间顿时大起!！\n"NOR;
msg += "$N神色一变,恢复了些活力！\n",  
           message_vision(msg, me, ob);
           return j;
}       
        wa = me->query_temp("weapon");
        skill = (int)me->query_skill("huifeng-jian", 1);
        neili = (int)me->query("neili");
                me->reset_action();
                limb = ob->query("limbs")[random(sizeof(ob->query("limbs")))];

                

     if(  wa && wa->query("skill_type") == "sword"
        && random(skill) > ((int)ob->query_skill("parry", 1)/3)
         && random((int)me->query("combat_exp")) > (int)ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "huifeng-jian"
         && me->query_skill_mapped("sword") == "huifeng-jian"
         && me->query_skill_mapped("force") == "linji-zhuang"
         && (int)me->query_skill("linji-zhuang", 1) > 50
         && neili > 300 && skill > 50 && living(me)
         && (int)me->query("qi") > 500
         && userp(me))
         {
               if(random(3) >= 1)
               {
               i = random(sizeof(action));// if(i=0) i=2;
                       msg = "$N不顾$n的进攻，身影轻盈一闪，贴身反击。\n";
               
                                 msg += HIC"就在$n发招之时，"+action[i]["action"]+"！\n"NOR;
                                                
               msg += "$n没有料到$N的招数居然后发先至，匆忙之间，手足无措！\n";
               ob->receive_damage("qi", damage);
               p = ob->query("qi")*100/ob->query("max_qi");
               msg += damage_msg(damage/2, "刺伤");
               msg += "( $n"+eff_status_msg(p)+" )\n";
                j = -(damage/2);               
               }
                else{                                                
                 msg = HIC"就在$n发招之时，"+action[i]["action"]+"！\n"NOR;
                                        
                 msg += "$n大吃一惊，但是$p经验老道，见$P攻了过来，紧接着反身又发一招。\n";
                 j = -damage/3; 
               }           

                        msg = replace_string( msg, "$w", wa->name() );
                                msg = replace_string( msg, "$l", limb );

                                message_vision(msg, me, ob);
         return j;
                }
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 90 ) return 0;

        if( random(2)==0 && me->query_temp("huifeng/jue")) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 30) / 2 );
                return HIR "$n的伤口被$N剑气穿过，飞出一阵血花！\n";
        }
}