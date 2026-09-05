// huntian-qigong.c
// written by Xiang

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
	return notify_fail("混天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D("huntian-qigong/") + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
    case "TYPE_ENFORCE":
      return 12;
	  default:
	  	return recv;
	}
}