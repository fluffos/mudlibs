// ev_learnskills.c
// by fire on Aug 16, 1998
// this is used to handle learn skills from other char
string subject_name(string matt)
{
	switch(matt)
	{
		case "bfxy":
			return "用兵之道";
		case "zgxy":
			return "治国之道";
		case "wxxy":
			return "武学之道";
		default:
			return "旁边左道";
	}
}
string subject_title(string matt)
{
	switch(matt)
	{
		case "bfxy":
			return "sk_zhimou";
		case "zgxy":
			return "sk_meili";
		case "wxxy":
			return "sk_wuli";
		default:
			return matt;
	}
}
void learn_skill(object student,string skill)
{
	int mas_level;
	string p_id;
	string p_st;
	int res;
	p_id=student->query_id()[0];
        mas_level=CHAR_D->get_skill(p_id,skill)+1;
	res=LEARNCHECK_D->check_can_learn_skills(skill,mas_level);
	switch(res)
	{
		case TOO_TIRED:
                        student->simple_action("$N听了半天，瞌睡得连眼睛都睁不开了。\n");
			return;
		case CAN_LEARN:
	                p_st=SG_SKILL_D->query_get(skill);
	                student->simple_action(p_st);
			return;
                case LESS_EXP:
                        student->simple_action("$N听了半天，却好象在听天书一般，什么也没有听懂。\n");
			return;
		case LESS_GIFT_MEILI:
		case LESS_GIFT_ZHIMOU:
		case LESS_GIFT_WULI:
		case LESS_GIFT:
                        student->simple_action("$N听了半天，好象听懂了却又记不住，也许是天赋不足。\n");
			return;
		case LESS_LITERATE:
                        student->simple_action("$N听了半天，好象听懂了却又记不住，也许是文学修养不够。\n");
			return;
	        default :
tell_user("fire",sprintf("the return is %O\n",res));
        	        write("不知为什么你学不会，问问巫师吧。\n");
			return;
	}
}
void ask_skills(object student,object master,string matt)
{
	string s_id,m_id;
	string p_nation;
	string sub,tit;
	sub=subject_name(matt);
	tit=subject_title(matt);
	s_id=(student->query_id())[0];
	m_id=(master->query_id())[0];
	p_nation=CHAR_D->get_char(s_id,"nation");
	
	if(!p_nation)
	{
		master->targetted_action
("$N对$T摇头道：$m$R似乎并非世俗中好勇斗狠之辈，这"+sub+
"我看就不必学了吧。\n",student);
		return;
	}
	if(p_nation!=CHAR_D->get_char(m_id,"nation"))
	{
		master->targetted_action
("$N对$T摇头道：$m$R乃"+COUNTRY_D->get_country(p_nation,"name")+
"高官，因此这"+sub+"还是不便相传。。。\n",student);
		return;
	}
	if((CHAR_D->get_skill(s_id,tit))>=(CHAR_D->get_skill(m_id,tit)))
	{
		master->targetted_action
("$N对$T笑道：$m$c何必过谦，你的"+sub+"已不输于$C我了。\n",student);
		return;
	}
	master->targetted_action
("$N对$T笑道：$m$c若不嫌弃$C我才学疏浅，便一同探讨探讨这"+sub+"吧。\n",student);
        master->targetted_action("$N向$T详解了一番"+sub+"。\n",student);
	call_out("learn_skill",random(3)+1,student,tit);
}
