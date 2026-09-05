// linji-zhuang.c 峨嵋 临济十二庄
// create bye cuer
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_learn(object me)
{
	int i, nf, ns;
	
	nf = (int)me->query_skill("force", 1);
	
	ns = (int)me->query("guilty");                                    
	if ( me->query("gender") != "女性" )
		return notify_fail("你非纯阴体质，不能修习临济十二庄。\n");
        if(!undefinedp(me->query("marry")) && (int)me->query_skill("linji-zhuang",1) > 79)
                return notify_fail("由于你不是处女之身，不能继续修习临济十二庄。\n");
        if (me->query("class")!="bonze" 
        	&& me->query("chushi/last_family")!="峨嵋派" 
        	&& (int)me->query_skill("linji-zhuang",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会临济十二庄。\n");
	
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("临济十二庄只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"linji-zhuang/" + func;
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level, lv2;
    
    level=ob->query_skill("linji-zhuang",1);
    lv2=ob->query_skill("mahayana",1);
    buf=([]);

//attribute的版本低于140913则效果无法生效    
    if ( ob->query_attr_version()<140913 )
      return buf;

    if ( level<=40 || lv2<=40 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/linji-zhuang")) )
      return buf;
    
    buf["max_qi"]=(level/2-20)*level/50;
    buf["max_jing"]=(lv2/2-20)*level/30;
    ob->set_temp("passive/linji-zhuang", buf);
    ob->set_temp("active_force_buffer/linji-zhuang/name", "临济十二庄");                       //buff名称
    ob->set_temp("active_force_buffer/linji-zhuang/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    ob->set_temp("active_force_buffer/linji-zhuang/effect2", "最大精神+"+(buf["max_jing"])+"点");     //效果描述2
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/linji-zhuang");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
      buf["max_jing"]=buf["max_jing"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/linji-zhuang");
    ob->delete_temp("active_force_buffer/linji-zhuang");
    return buf;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":          //TYPE_RECOVER
			return 150;
	  case "TYPE_REC_CD":          //TYPE_REC_CD
	  	return 4;
	  case "TYPE_SPEED":          //TYPE_SPEED
	  	return 6;
	  case "TYPE_DEC_SPD":          //TYPE_DEC_SPD
	  	return 50;
    case "TYPE_SHIELD_DEF":
      return 4;
    case "TYPE_SHIELD_NEILI":
      return 4;
	  default:
	  	return recv;
	}
}