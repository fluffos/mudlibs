//jiuyang-shenggong.c
//changed by fast
inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}

/*
int valid_learn()
// need more limit here
{
	return 1;
}
*/

int practice_skill(object me)
{
return notify_fail("九阳神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
       return SKILL_D("jiuyang-shengong/") + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":          //TYPE_RECOVER
			return 120;
	  case "TYPE_MIN_SPD":          //TYPE_MIN_SPD
	  	return 350;
	  case "TYPE_MAX_SPD":          //TYPE_MAX_SPD
	  	return 700;
	  case "TYPE_SPEED":          //TYPE_SPEED
	  	return 7;
	  case "TYPE_DEC_SPD":          //TYPE_DEC_SPD
	  	return 20;
	  default:
	  	return recv;
	}
}