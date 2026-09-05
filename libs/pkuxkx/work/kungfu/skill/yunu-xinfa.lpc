// yunu-xinfa 古墓 玉女心法
// create by dingdang
// 统一古墓内功，男女都可以使用，非女性效果略差。 by jpei 10102008
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
        //if(me->query("gender")!="女性"&&(int)me->query_skill("yunu-xinfa",1)>100)
                //return notify_fail("你不是女性，对「玉女心法」的阴柔的内功。\n");                                 
        
        if ( nf < 10)
                return notify_fail("你的基本内功火候还不够，无法领会玉女心法\n");
        
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("玉女心法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"yunu-xinfa/" + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
	  case "TYPE_MIN_SPD":  //TYPE_MIN_SPD
	  	return 250;
	  case "TYPE_MAX_SPD":  //TYPE_MAX_SPD
	  	return 500;
	  case "TYPE_SPEED":  //TYPE_SPEED
	  	return 5;
	  default:
	  	return recv;
	}
}