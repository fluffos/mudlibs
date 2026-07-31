// kumu-shengong.c 枯木神功
// cleansword
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname,master;
    int i;
    int lvl = (int)me->query_skill("kumu-shengong", 1);
    master=me->query("family/master_id");
    
                    
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的枯木神功。\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("你的基本内功火候还不够，无法领会枯木神功。\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够扎实，再学下去会走火入魔的。\n");
    if (me->query("family/family_name")!="大理段家")
   return notify_fail("你不是大理段家弟子，无法学习本门技能。\n");		
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="kumu-shengong") continue;	
if (sname[i]=="xixing-dafa") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
return notify_fail("你不先散了别派内功，怎能学枯木神功？！\n");	
}
 return 1;
}
string exert_function_file(string func)
{
    return __DIR__"kumu-shengong/" + func;
}
int practice_skill(object me)
{
        return notify_fail("枯木神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage2,ap,dp;
	damage2 = (int)me->query_skill("kumu-shengong",1);
	ap = me->query_skill("kumu-shengong",1);
	dp = victim->query_skill("force",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("kumu-shengong",1) < 100)	 return 0;
	if ( me->query("neili") < 100 || me->query_skill_mapped("force") != "kumu-shengong") return 0;	
	if (damage2<10) damage2=10;	
	if ( random(ap) > dp/20 && random(6)==0 && me->query("jiali") > 0) 
	{
		victim->receive_wound("qi", 100+damage2+damage_bonus/2,me);
		me->add("neili", -100 );
		return HIB "$N发挥出"+HIR+"枯木神功"NOR HIB"的精髓,$n顿时颜容枯槁，寿元大损！！！！\n" NOR;
	}
}
