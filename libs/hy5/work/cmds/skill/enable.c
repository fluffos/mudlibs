// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
	"dagger":	"匕法",
	"unarmed":	"拳脚",
	"sword":	"剑法",
	"hammer":     "锤法",
	"blade":	"刀法",
	"stick":	"棒法",
	"staff":	"杖法",
	"club" :        "棍法",
"spear" :        "枪法",
	"throwing":	"暗器",
	"force":	"内功",
	"parry":	"招架",
	"dodge":	"轻功",
	"magic":	"法术",
	"spells":	"魔法",
        "leg":	"腿法",
	
	"axe":	"斧法",
	"move":	"行动",
	"array":	"阵法",
	"whip":     "鞭法",
	"lingfa":  "令法",

//	shaolin skills

	"finger":   "指法",
	"hand":     "手法",
	"cuff":     "拳法",
	"claw":     "爪法",
	"strike":   "掌法",

//	"club":     "棍法",
]);

int main(object me, string arg)
{
	mapping map;
	string *types, *skill, ski, map_to;
	int i, modify;

	seteuid(getuid());

	if( !arg ) {
		map = me->query_skill_map();
		if( !mapp(map) || sizeof(map)==0 )
			return notify_fail("你现在没有使用任何特殊技能。\n");

		skill = keys(valid_types);
		write("以下是你目前使用中的特殊技能。\n");
		for (i=0; i<sizeof(skill); i++) {
			if( undefinedp(valid_types[skill[i]]) ) {
				map_delete(map, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
if (!undefinedp(map[skill[i]]) && me->query_skill(map[skill[i]],1)<=0)
{
		me->map_skill("unarmed");
		me->map_skill("hammer");
		me->map_skill("blade");
		me->map_skill("sword");
		me->map_skill("staff");
		me->map_skill("club");
		me->map_skill("throwing");
		me->map_skill("parry");
		me->map_skill("dodge");
		me->map_skill("magic");
		me->map_skill("spells");
		me->map_skill("leg");
		me->map_skill("axe");
		me->map_skill("array");
		me->map_skill("whip");	
		me->map_skill("finger");
		me->map_skill("hand");	
		me->map_skill("cuff");	
		me->map_skill("claw");	
		me->map_skill("strike");	
		me->map_skill("force");	
		me->map_skill("dagger");	
		me->prepare_skill("unarmed");
		me->prepare_skill("hammer");
		me->prepare_skill("blade");
		me->prepare_skill("sword");
		me->prepare_skill("staff");
		me->prepare_skill("club");
		me->prepare_skill("throwing");
		me->prepare_skill("parry");
		me->prepare_skill("dodge");
		me->prepare_skill("magic");
		me->prepare_skill("spells");
		me->prepare_skill("leg");
		me->prepare_skill("axe");
		me->prepare_skill("array");
		me->prepare_skill("whip");	
		me->prepare_skill("finger");
		me->prepare_skill("hand");	
		me->prepare_skill("cuff");	
		me->prepare_skill("claw");	
		me->prepare_skill("strike");	
                me->reset_action();
return notify_fail(HIR"你的武功有问题!请重新enable所有武功\n"NOR);
}
			modify = me->query_temp("apply/" + skill[i]);
			printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
				valid_types[skill[i]] + " (" + skill[i] + ")",
				undefinedp(map[skill[i]]) ? "无" : to_chinese(map[skill[i]]),
				(modify==0 ? "" : (modify>0 ? HIC : HIR)),
				me->query_skill(skill[i]));
		}
		return 1;
	}

	if( arg=="?" ) {
		write("以下是可以使用特殊技能的种类：\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );
		for(i=0; i<sizeof(skill); i++) {
			printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
		}
		return 1;
	}

	if( sscanf(arg, "%s %s", ski, map_to)!=2 )
		return notify_fail("指令格式：enable|jifa [<技能种类> <技能名称>|none]\n");

	if( undefinedp(valid_types[ski]) )
		return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");

	if( map_to=="none" ) {
if (ski=="force")
{
if (me->query_temp("powerup"))
return notify_fail("这个内功你不是还用着吗?\n");
if (me->query_temp("linji"))
return notify_fail("这个内功你不是还用着吗?\n");
if (me->query_temp("yun_riyue"))
return notify_fail("这个内功你不是还用着吗?\n");
if (me->query_temp("yun_yinyang"))
return notify_fail("这个内功你不是还用着吗?\n");
        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("你已经在先天大法了。\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("你已经在运太玄功了。\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("你已经在运葵花无敌功了。\n");
        if(me->query_temp("wdpowerup") )
        return notify_fail("你现在正在使用「五毒神功」的绝技，请在正常状态下放弃武功!\n"); 
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了，请在正常状态下放弃武功!\n");

}
		me->map_skill(ski);
		me->reset_action();
		write("Ok.\n");
		return 1;
	} else if( map_to==ski ) {
		write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
		return 1;
	}

	if( !me->query_skill(map_to, 1) )
		return notify_fail("你不会这种技能。\n");

//	if( !me->query_skill(ski, 1) )
//		return notify_fail("你连「" + to_chinese(ski) + "」都没学会，更别提"
//			+ to_chinese(map_to) + "了。\n");

	if( !SKILL_D(map_to)->valid_enable(ski) )
		return notify_fail("这个技能不能当成这种用途。\n");

	
	if( ski=="magic" ) {
		write("你改用另一种法术系，精力必须重新锻练。\n");
		me->set("jingli", 0);
		me->receive_damage("jing", 0);
	} 
	else if( ski=="force" ) {
if (me->query_temp("powerup"))
return notify_fail("这个内功你不是还用着吗?\n");
if (me->query_temp("powerup"))
return notify_fail("这个内功你不是还用着吗?\n");
if (me->query_temp("linji"))
return notify_fail("这个内功你不是还用着吗?\n");
if (me->query_temp("yun_riyue"))
return notify_fail("这个内功你不是还用着吗?\n");
if (me->query_temp("yun_yinyang"))
return notify_fail("这个内功你不是还用着吗?\n");
        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("你已经在先天大法了。\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("你已经在运太玄功了。\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("你已经在运葵花无敌功了。\n");
        if(me->query_temp("wdpowerup") )
        return notify_fail("你现在正在使用「五毒神功」的绝技，请在正常状态下放弃武功!\n"); 
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了，请在正常状态下放弃武功!\n");

		write("你改用另一种内功，内力必须重新锻练。\n");
		me->set("neili", 0);
		me->receive_damage("qi", 0);
	}
	me->map_skill(ski, map_to);
	me->reset_action();
	write("Ok.\n");

	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : enable|jifa [<技能种类> <技能名称> | none]
           enable|jifa ?

这个指令让你指定所要用的技能，需指明技能种类和技能名称。如果不加参
数则会显示出技能种类及你目前所使用的技能名称 ，如果加一个？会列出
所有能使用特殊技能的技能种类。
 
HELP
        );
        return 1;
}
