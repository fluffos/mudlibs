//jiuyin-shenggong.c
//changed by lianxing
inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}
int practice_skill(object me)
{
return notify_fail("九阴神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"jiuyin-shengong/" + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
	  case "TYPE_MIN_SPD":     //TYPE_MIN_SPD
	  	return 250;
	  case "TYPE_MAX_SPD":     //TYPE_MAX_SPD
	  	return 500;
	  case "TYPE_SPEED":       //TYPE_SPEED
	  	return 5;
	  default:
	  	return recv;
	}
}