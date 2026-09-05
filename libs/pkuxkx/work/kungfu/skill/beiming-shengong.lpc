// beiming-shengong.c 北冥神功.c
// by paladin
// Modified by iszt@pkuxkx, 2007-03-19, no other force allowed
inherit FORCE;

int valid_enable(string usage) { return usage == "force" ||(usage == "parry");}
int valid_learn(object me)
{
	mapping fam;
	mapping skills;
	int i;

/*
        if (!(fam = this_player()->query("family"))
        || (fam["family_name"] != "天龙寺" 
        && fam["family_name"] != "灵鹫宫"
        && this_player()->query("chushi/last_family") != "天龙寺"
        && this_player()->query("chushi/last_family") != "灵鹫宫"
        ))
		return notify_fail("你的师傅会这个吗？\n");
*/
        if (this_player()->query("family/family_name") != "天龙寺" 
         && this_player()->query("family/family_name") != "灵鹫宫"
         && this_player()->query("chushi/last_family") != "天龙寺"
         && this_player()->query("chushi/last_family") != "灵鹫宫" )
                return notify_fail("你的师傅会这个吗？\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("你的基本内功火候不足，不能学北冥神功。\n");

	skills = me->query_skills();
	for(i=0; i<sizeof(skills); i++)
		if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("force")
			&& keys(skills)[i] != "beiming-shengong"
      && keys(skills)[i] != "bahuang-gong"
      && keys(skills)[i] != "xiaowuxiang-gong"
      && keys(skills)[i] != "kurong-shengong"
      && keys(skills)[i] != "yijin-jing"
      && this_player()->query("reborn/all")!=1)
			return notify_fail("北冥神功举世无双，你必须先放弃普通的内功。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("北冥神功只能用学(learn)的来增加熟练度。\n");
}
string *parry_msg = ({
	"只见$n将手中$v左一带，右一带，轻轻的将$N的$w各了开去。\n",
	"$n用手中$v在$N的$w上轻轻一搭，\n$N的$w就如着了魔法一般，荡了开去。\n",
});

string *unarmed_parry_msg = ({
	"但是$n用左手轻轻一推$N的$w，\n$N的$w就如着了魔法一般，荡了开去。\n",
	"$n左手轻轻推出，拍向$N的$w，$N的攻击被移的无影无踪。\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string exert_function_file(string func)
{
	return __DIR__"beiming-shengong/" + func;
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
      return 25;
	  case "TYPE_SPECIAL_NEILI_EFF": // corporeity 特技对内力最大值的影响
	    return 25;
	  default:
	  	return recv;
	}
}

//北冥神功的最大内力为特别设置
int query_max_neili(object ob)
{
  int maxn;
  maxn=ob->query_skill("force")*(ob->query("con")+10)/2;
  if ( 20*ob->query_skill("force") + 200*ob->query("con") < maxn )
    maxn=20*ob->query_skill("force") + 200*ob->query("con");
  return maxn;
}
