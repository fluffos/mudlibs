// 鬼手射
//by mudy
#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"action":		"skip_action",
		])
});
mapping *act=({
		([ 
		"throw":  HIG"$N"+HIG"使出［漫天鬼手］，一扬手中的$w"+HIG",$w"+HIG"急射向$n"+HIG"，只见漫天都是暗器！\n"NOR,
		"shoot":   HIG"$n"+HIG"一声惨嚎，$w"+HIG"已经射入$n"+HIG"身体，留下一个深可见骨的伤痕!\n"NOR,
		"dodge":   HIY"$n"+HIY"一个就地十八滚，躲了开去!\n"NOR,
		"damage":  10,
		"poison": 0,
		]),
		([ 
		
		"throw":  HIR"$N"+HIR"一招［如影随形］，暗用内力将手中的$w"+HIR"从袖中射出，直取$n"+HIR"太阳穴！\n"NOR,
		"shoot":   HIR"$n"+HIR"一声惨叫，避无可避,$w"+HIG"在$n"+HIR"的太阳穴上留下一个可怕的伤痕!\n"NOR,
		"dodge":   HIY"$n"+HIY"听风辩位，不慌不忙躲了开去!\n"NOR,
		"damage":  20,
		"poison": 0,
		]),
		([ 		
		"throw":  MAG"$N"+MAG"一招［鬼使神差］，手中的$w"+MAG"从不可思议的角度向$n"+MAG"射去！\n"NOR,
		"shoot":   HIB"$n"+HIB"闷哼一声，已被$w"+HIB"击中，只觉一阵剧痛!\n"NOR,
		"dodge":   HIM"$n"+HIM"纵身一跃，跃过了$N"+"射来的暗器！\n"NOR,
		"damage":  30,
		"poison": 0,
		]),
		([ 		
		"throw":  HIW"$N"+HIW"一招［如鬼如魅］，身体摇摆不定，手中$w"+HIW"却是以弧线射出，绕道$n"+HIW"身后向$n"+"的背心射去！\n"NOR,
		"shoot":   HIC"$n"+HIC"哪里见过这种怪招！顿时已被$w"+HIC"击中背部，哇的一声，吐了一口鲜血!\n"NOR,
		"dodge":   HIY"$n"+HIY"不退反进，期到$N身前，突然转身，用内力震飞$N"+"射来的暗器！\n"NOR,
		"damage":  40,
		"poison": 0,
		]),
		([ 		
		"throw":  BLU"$N"+BLU"一招［荼毒人间］，将指甲里的毒粉弹于，$w"+BLU"之上，用指力将$w"+BLU"平平射出！\n"NOR,
		"shoot":   MAG"$n"+MAG"只觉一阵蓝光闪过，还没注意就觉得已被击中！\n"NOR,
		"dodge":   HIY"$n"+HIY"向后一仰，也平平向后飞去，用指力将暗器弹开!侥幸躲过。\n"NOR,
		"damage":  10,
		"poison": 1,
		]),
		   
		   

});


int valid_learn(object me)
{
	object weapon;

	if( (int)me->query_skill("literate", 1) < 40 )
		return notify_fail("你的文学修养不足，不能领悟鬼手射的精髓。\n");
		
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，没有办法使用鬼手射。\n");
	weapon=me->query_temp("weapon");
	if( !weapon )
		return notify_fail("你必须先拿起暗器才能练鬼手射。\n");

	if( weapon->query("skill_type") != "throwing" )
		return notify_fail("你必须先拿起暗器才能练鬼手射。\n");

	return 1;
}

int valid_enable(string usage) { return usage == "throwing" || usage == "parry"; } 

mapping query_action(object me, object weapon)
{
//	mapping action_hit,action_type;
//	action_type=action[1+random(sizeof(action)-1)];
//	action_hit->set("action","");//action_type["action"]+action_type["dodge"]);
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	notify_fail("你只能用向师傅学或多实践的方法来提高鬼手射的水平。\n");
}

string perform_action_file(string action)
{
        return __DIR__"guishoushe/" + action;
}
 

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object *inv,anqi;
	int damage,level;
	string msg;
	inv=all_inventory(me);
//                tell_object(me,sizeof(inv));
	for(int i=0;i<sizeof(inv);i++)
	{
		if(inv[i]==me->query_temp("weapon")) continue;
		if(inv[i]->query("skill_type")=="throwing")
		{
			anqi=inv[i];
			break;
		}
	}
	if(!anqi)
	{
		anqi=me->query_temp("weapon");
                tell_object(me,HIR"你的暗器已经打完了！\n"NOR);
	}
	level=random(sizeof(act));
	msg=act[level]["throw"];
        if( random(me->query_skill("guishoushe")*10) > random(victim->query_skill("dodge"))&&random(me->query("combat_exp")*10)>random(victim->query_skill("combat_exp")) )
        {
        		if(!anqi)
        		damage=random(act[level]["damage"]*3+me->query_skill("guishoushe",1)/2+me->query_skill("throwing",1)/2+damage_bonus*2);
else
damage=act[level]["damage"]*3+me->query_skill("guishoushe",1)/2+me->query_skill("throwing",1)/2+damage_bonus*2+anqi->query("weapon_prop/damage")/4;
damage = random(damage);
			victim->add("qi",0-damage);
			victim->add("eff_qi",0-damage/3);
			msg+=act[level]["shoot"];
			if(act[level]["poison"])
			{
				msg+=HIB"$n"+HIB"觉得伤口一麻，看来暗器上涂有巨毒!\n"NOR;
				victim->add("jing",0-act[level]["damage"]);
				victim->add("eff_jing",0-act[level]["damage"]/3);
				me->add("shen",-1);
			}
			msg+="($n"+COMBAT_D->eff_status_msg(victim->query("eff_qi")*100/victim->query("max_qi"))+")\n";
			msg=replace_string(msg,"$w",anqi->query("name"));
			anqi->move(victim);
			victim->set_temp("last_damage_from", me);
        }
                else if(objectp(anqi))
		{
			msg+=act[level]["dodge"];
			msg=replace_string(msg,"$w",anqi->query("name"));
			destruct(anqi);
		}
		message_vision(msg,me,victim);
		return ;
		
}
int is_skip_action()
{
	return 1;
}

string query_yinyang()
{
	return "太阴";
}