//xixing-dafa 吸星大法
//by bing
// Modified by iszt@pkuxkx, 2007-03-20, no other force allowed

inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
	mapping skills;
	int i;

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的基本内功火候不足，不能学吸星大法。\n");
        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
                return notify_fail("你练了秃驴牛鼻子们的心法，还学吸星大法做什麽！\n");
	skills = me->query_skills();
	for(i=0; i<sizeof(skills); i++)
		if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("force")
			&& keys(skills)[i] != "xixing-dafa"
			&& keys(skills)[i] != "yijin-jing"
			&& keys(skills)[i] != "riyue-shengong")
                return notify_fail("你不先散了别派内功，怎能学吸星大法？！\n");

        return 1;
}
int practice_skill(object me)
{
        return notify_fail("吸星大法只能用学(learn)或读(study)来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"xixing-dafa/" + func;
}

void disable_skill(object me)
{
	string gm = exert_function_file("guangming");
	if (me->query_temp("daguangming/apply"))
		gm->remove_effect(me);
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);

	switch(char_type)
	{
		case "TYPE_RECOVER":     //TYPE_RECOVER
			return 80;
	  case "TYPE_REC_CD":     //TYPE_REC_CD
	  	return 8;
    case "TYPE_SUCK_EFF":
      return 20;
	  case "TYPE_SPECIAL_NEILI_EFF": // corporeity 特技对内力最大值的影响
	    return 75;
	  default:
	  	return recv;
	}
}

//吸星大法的最大内力为特别设置
int query_max_neili(object ob)
{
  return ob->query_skill("force")*(ob->query("con")+20)/3;
}
