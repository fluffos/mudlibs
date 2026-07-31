// wizlian.c 巫师专用
#include <globals.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void    restore_condition(object );
void    restore_origin(object );

mapping attrib =([
	"qi"	    : "",
	"气"	    : "qi",
	"eff_qi"	: "",
	"有效气"	: "eff_qi",
	"max_qi"	: "",
	"最大气"	: "max_qi",
	"jingli"		: "",
	"精"	    : "jingli",
	"eff_jing"      : "",
	"有效精"	: "eff_jingli",
	"max_jing"      : "",
	"最大精"	: "max_jingli",
	"food"	  : "",
	"食物"	  : "food",
	"water"	 : "",
	"饮水"	  : "water",
	"neili"	 : "",
	"内力"	  : "neili",
	"max_neili"     : "",
	"最大内力"      : "max_neili",
	"jingli"	: "",
	"精力"	  : "jingli",
	"max_jingli"    : "",
	"最大精力"      : "max_jingli",
	"weiwang"       : "",
	"威望"	  : "weiwang",
	"江湖威望"      : "weiwang",
	"score"	 : "",
	"阅历"	  : "score",
	"江湖阅历"      : "score",
	"shen"	  : "",
	"神"	    : "shen",
	"mud_age"       : "",
	"年龄"	  : "mud_age",
	"str"	   : "",
	"臂力"	  : "str",
	"int"	   : "",
	"悟性"	  : "int",
	"智力"	  : "int",
	"con"	   : "",
	"根骨"	  : "con",
	"dex"	   : "",
	"身法"	  : "dex",
	"MKS"	   : "",   
	"PKS"	   : "",
	"potential"     : "",
	"pot"	   : "potential",
	"潜力"	  : "potential",
	"潜能"	  : "potential",
	"combat_exp"    : "",
	"exp"	   : "combat_exp",
	"修为"	  : "combat_exp",
	"learned_points": "",
	"学习点数"      : "learned_points",
	"学习点数"      : "learnd_points",
]);

int main(object me, string arg)
{
	string pack, argn, argm;	// 属性/武功  参数1  参数2:暂时不用
	int argnum;		     // 参数的个数 (包括属性)

	string attrs;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	log_file("static/wizlian", sprintf("%s: %s: %s\n", log_time(), log_id(me), arg));
	// 恢复状态，精、气、内力
	if (! arg)
	{
		message_vision(HIW "$N喃喃的念了一会咒语，一股烟雾笼罩了$N。"NOR"\n", me);
		restore_condition(me);
		return 1;
	}

	// 恢复成原始数据，放弃武功
	if (arg == "org")
	{
		message_vision(HIW "$N喃喃的念了一会咒语，一股烟雾笼罩了$N。"NOR"\n", me);
		restore_origin(me);
		return 1;
	}

	argnum = sscanf(arg, "%s %d %d", pack, argn, argm);

	if (argnum < 2)
	{
		// 没有指定属性
		message_vision(HIW "$N喃喃的念了一会咒语，什么也没发生。"NOR"\n", me);
		return 1;
	}

	if (! undefinedp(attrs = attrib[pack]))
	{
		// 修改属性
		if (attrs == "") attrs = pack;
		message_vision(HIW "$N喃喃的念叨：天灵灵，地灵灵，各路神仙快显灵！"NOR"\n", me);
		if (attrs == "potential")
			argn += me->query("learned_points");

		me->set(attrs, argn);
		message_vision(HIY "天上轰隆隆的响了一会，$N呵呵的笑了两声说道：真是灵验。"NOR"\n", me);
		return 1;
	} else
	{
		// 修改武功
		message_vision(HIW "$N点燃一张符咒，喝道：太上老君急急如律敕令！"NOR"\n", me);
		
		if (! find_object(SKILL_D(pack)) &&
		    file_size(SKILL_D(pack) + ".c") < 0)
		{
			message_vision(HIR "天上轰隆隆的响了一会，太上老君怒喝道：你搞什么鬼！"NOR"\n", me);
			return 1;
		}

		if (argn >= 0)
		{
			me->set_skill(pack, argn);
			message_vision(HIY "一道金光从天上射下来，隐入$N的体内。"NOR"\n", me);
		} else
		{
			message_vision(HIR "天上轰隆隆的响了一会，太上老君怒喝道：不要乱来！"NOR"\n", me);
		}
		return 1;
	}
}

void restore_condition(object me)
{
	message_vision(HIY "$N变得神采奕奕！"NOR"\n", me);
	// 恢复气
	me->set("qi", me->query("max_qi")+me->query_gain_qi());
	me->set("eff_qi", me->query("max_qi")+me->query_gain_qi());

	// 恢复精
	me->set("jing", me->query("max_jing"));
	me->set("eff_jing", me->query("max_jing"));

	// 恢复内力
	me->set("neili", me->query("max_neili"));

	// 恢复精力
	me->set("jingli", me->query("max_jingli"));

	// 恢复食物
	me->set("food", me->max_food_capacity());

	// 恢复饮水
	me->set("water",me->max_water_capacity());

	// 解毒
	me->set("noposion", 1);
}

void restore_origin(object me)
{
	int i;
	mapping pmap;
	string* sk;

	message_vision(HIY "咦，$N变得天真无邪，一脸无辜状！"NOR"\n", me);
	
	// 恢复神， PK, MPK
	me->set("shen", 0);
	me->set("PKS", 0);
	me->set("MKS", 0);

	// disbale并且放弃各种武功

	pmap = me->query_skill_prepare();	       // 准备的技能
	if (!pmap) pmap = ([]);

	if( mapp(pmap) && sizeof(pmap) > 0 )
	{
		sk = keys(pmap);
		for (i=0; i<sizeof(sk); i++)
		{
			me->prepare_skill(sk[i]);       // 清除准备的技能
		}
	}
	
	sk = keys(me->query_skills());		  // 所学武功的名称集合
	for(i = 0; i<sizeof(sk); i++)
	{
		me->map_skill(sk[i]);		   // 取消激发某项武功
		map_delete(me->query_skills(), sk[i]);  // 放弃所学的武功
	}


	me->reset_action();			     // 完成
}

int help()
{
write(@HELP
指令格式 : wizlian <武功/属性> 值

此命令提升巫师的武功，或是修改各项属性，包括气，精，神...

wizlian	  : 恢复所有属性包括气，精，精力，内力，食物，饮水。
wizlian org      : 初始化个人数据，放弃所有武功，神降到0。
wizlian [属性] n : 修改某项属性为n。
wizlian [武功] n : 修改某项武功为n级，点数为m，如果小于零就不修改。

HELP
    );
    return 1;
}
