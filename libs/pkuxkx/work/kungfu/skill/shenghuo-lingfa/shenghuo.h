
#include <ansi.h>
int custom_power(object me,string arg)
{
	return me->query("mingjiao/skill/shenghuo_lingfa/"+arg)*10;
}
string custom_color_dny(object me)
{
	string *colors=({CYN,HIC,WHT,HIW,HIG,HIY,HIM,HIR});
	if (!intp(me->query("mingjiao/skill/danuoyi/level"))||me->query("mingjiao/skill/danuoyi/level")<0||me->query("mingjiao/skill/danuoyi/level")>7)
	return CYN;
	return colors[me->query("mingjiao/skill/danuoyi/level")];
}
string custom_color(object me)
{
	int n;
	string *colors,*attributes;
	colors=({HIC,HIB,HIR,HIY,HIM,HIG,HIW,CYN,BLU,RED,YEL,MAG,GRN,WHT});
	attributes=({"p_neili","p_jingli","p_qi","p_jing","p_parry","p_dodge","p_strength","neili","jingli","qi","jing","parry","dodge","strength"});
	if (!me||!userp(me))
	{
		return NOR;
	}
	if (!me->query("mingjiao/skill/shenghuo_lingfa/attribute"))
	{
		return NOR;
	}
	if (n=member_array(me->query("mingjiao/skill/shenghuo_lingfa/attribute"),attributes)==-1)
	{
		return NOR;
	}
	return colors[n];
}
int improve_chance(object me)
{
	return me->query_skill("shenghuo-lingfa",1)/100-me->query("mingjiao/skill/shenghuo_lingfa/improved_times");
}
int custom_improve(object me)
{
	int n;
	string *attributes,*desc,the_desc;
	if (improve_chance(me)>0&&time()-me->query_temp("mj_improve_notice")>1200)
	{
		me->set_temp("mj_improve_notice",time());
		tell_object(me,"你尚有"+chinese_number(improve_chance(me))+"次提升圣火令法的机会，可在明教密道获得提升(improve)。\n");
	}
	if (me->query_skill("shenghuo-lingfa",1)<500||me->query("mingjiao/skill/shenghuo_lingfa/attribute"))
	return 1;
	attributes=({"p_neili","p_jingli","p_qi","p_jing","p_parry","p_dodge","p_strength","neili","jingli","qi","jing","parry","dodge","strength"});
	desc=({"内力","精力","气血","精血","招架","闪躲","臂力","内力","精力","气血","精血","招架","闪躲","臂力"});
	n=random(sizeof(attributes));
	me->set("mingjiao/skill/shenghuo_lingfa/attribute",attributes[n]);
	tell_object(me,"你对"+custom_color(me)+"圣火令法"+NOR+"的研究有了一些独到之处。\n");
	if (n>6)
	the_desc="降低对手"+desc[n];
	else
	the_desc="增加自身"+desc[n];
	tell_object(me,custom_color(me)+"你的圣火令法获得了战斗中"+U+custom_color(me)+the_desc+NOR+custom_color(me)+"方面的功效。\n"+NOR);
	return 1;
}

int pure_degree(object me)
{
	if (me->query("family/family_name")!="明教"||me->query("betrayer"))
	return 95;//非明教
	else if (me->query("reborn/chushi") || me->query("chushi/done"))
	return 100;//出师id
	else
	return 115;
}