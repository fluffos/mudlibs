// consider.c
// by fire on Aug 11, 1998
// this is used give not online char to think
mixed agree_sb(int task_id,string my_id,string t_id);
mixed disagree_sb(int task_id,string my_id,string t_id);
mixed neutral_sb(int task_id,string my_id,string t_id);

int war_consider(string p_id,string p_area,string p_target)
{
	string t_nation;
	string *t_chars,a_name;
	int t_soldier,m_soldier;
	mixed skills;
	int s,i;
	object o_id=CHAR_D->find_char(p_id);
	
	o_id->simple_action("$N道：测试阶段，没有损失，应该多打仗。\n");
	return 0; // this is in test time
	if(!objectp(o_id)) return -1; // strange
	t_nation=AREA_D->get_area(p_target,"nation");
	t_chars=CHAR_D->check_char_area("nation",t_nation,p_target);
	a_name=AREA_D->get_area(p_target,"name");
	if(sizeof(t_chars)) {
		skills=map_array(t_chars,(: CHAR_D->get_char($1,"skills"):));
		s=sizeof(t_chars);
		for(i=0;i<s;++i) 
		{
			if(skills[i]["sk_wuli"]>90) {
				o_id->simple_action(
					"$N道：听说"+a_name+"的"+CHAR_D->get_char(t_chars[i],"name")
					+"有万夫不挡之勇，草率出兵，只怕不妥。\n");
				return 1;
			}
			if(skills[i]["sk_zhimou"]>90) {
				o_id->simple_action(
					"$N道：听说"+a_name+"的"+CHAR_D->get_char(t_chars[i],"name")
					+"精于用兵之道，草率出兵，只怕不妥。\n");
				return 1;
			}
			if(skills[i]["sk_meili"]>90) {
				o_id->simple_action(
					"$N道：听说"+a_name+"的"+CHAR_D->get_char(t_chars[i],"name")
					+"精于治国之道，草率出兵，只怕不妥。\n");
				return 1;
			}

		}

	}
	t_soldier=AREA_D->get_area(p_target,"soldier");
	m_soldier=AREA_D->get_area(p_area,"soldier");
	if((t_soldier*2)>m_soldier) {
		o_id->simple_action(
			"$N道：听说"+a_name+"有重兵把守，草率出兵，只怕不妥。\n");
		return 1;
	}
	return 0;
}

int my_importance_consider(string p_area)
{
	int p_safe;
	int p_goldin,p_goldout;
	int p_foodin,p_foodout;
	int p_stuffin,p_stuffout;
	int p_bing,p_population;
	p_safe=AREA_D->get_area(p_area,"safe");
	p_goldin=AREA_D->get_area(p_area,"goldin");
	p_goldout=AREA_D->get_area(p_area,"goldout")+AREA_D->get_area(p_area,"salary");
	p_foodin=AREA_D->get_area(p_area,"foodin")/12;
	p_foodout=AREA_D->get_area(p_area,"foodout");
	p_stuffin=AREA_D->get_area(p_area,"stuffin");
	p_stuffout=AREA_D->get_area(p_area,"stuffout");
	p_bing=AREA_D->get_area(p_area,"soldier");
	p_population=AREA_D->get_area(p_area,"population");	
	
	if(p_safe<40)
		return AI_SAFE;
	if(p_goldin<p_goldout)
		return AI_BUSINESS;
	if(p_foodin<p_foodout)
		return AI_AGRICULTURE;
	if(p_stuffin<p_stuffout)
		return AI_INDUSTRY;
	if(p_bing<(p_population/100))
		return AI_MILITARY;
	return AI_BALANCE;
}
int importance_consider(string p_id,string p_area,int p_inp)
{
	int my_inp;
	object o_id;
	string p_dis;
	my_inp=my_importance_consider(p_area);
	if(my_inp==p_inp)
		return 0;
	o_id=CHAR_D->find_char(p_id);
	if(objectp(o_id))
	{
		switch(my_inp)
		{
                case AI_BALANCE: p_dis="$N自言自语道：似乎本地应当均衡发展……\n";break;
                case AI_AGRICULTURE:p_dis="$N自言自语道：似乎本地粮草不足……\n";break;
                case AI_INDUSTRY:p_dis="$N自言自语道：似乎本地物资不足……\n";break;
                case AI_BUSINESS:p_dis="$N自言自语道：似乎本地军资不足……\n";break;
                case AI_SAFE: p_dis="$N自言自语道：似乎本地不够安定……\n";break;
                case AI_MILITARY: p_dis="$N自言自语道：似乎地区兵士还不足．\n";break;
		}
		o_id->simple_action(p_dis);
	}
	return 1;
}
int recruit_consider(string p_id,string p_area,mixed new_soldier,int old_soldier)
{
    int p_goldin,p_foodin;
        int p_goldout,p_foodout;
	int p_stuffin,p_stuffout;
	int p_gold,p_food,p_stuff,p_month;
        object o_id;
        mixed * p_date;
	int p_safe;
	int sol;
	p_safe=AREA_D->get_area(p_area,"safe");
        p_date=DAY_D->query_date();
        p_month=p_date[2];
        o_id=CHAR_D->find_char(p_id);
        p_goldin=AREA_D->get_area(p_area,"goldin")+AREA_D->get_area(p_area,"salary");
        p_goldout=AREA_D->get_area(p_area,"goldout");
        p_foodin=AREA_D->get_area(p_area,"foodin");
        p_foodout=AREA_D->get_area(p_area,"foodout");
	p_stuffout=AREA_D->get_area(p_area,"stuffout");
	p_stuffin=AREA_D->get_area(p_area,"stuffin");
	p_gold=AREA_D->get_area(p_area,"gold");
	p_food=AREA_D->get_area(p_area,"food");
	p_stuff=AREA_D->get_area(p_area,"stuff");
	if( mapp(new_soldier) )new_soldier = new_soldier["no"];
        if(new_soldier>0)
        {
		if((p_goldin-p_goldout)*12+p_gold<new_soldier/10*12)
                {
                        if(objectp(o_id))
                                o_id->simple_action("$N自言自语道：似乎金不足呀……\n");
                        return 1;
                }
		if((p_stuffin-p_stuffout)*12+p_stuff<new_soldier/100*12)
                {
                        if(objectp(o_id))
                                o_id->simple_action("$N自言自语道：似乎物资不足呀……\n");
                        return 1;
                }
                if(p_foodin-p_foodout*12+p_food<new_soldier*12)
                {
                        if(objectp(o_id))
                                o_id->simple_action("$N自言自语道：似乎粮食不足呀……\n");
                        return 1;
                }
		if(p_safe<20)
		{
                        if(objectp(o_id))
                                o_id->simple_action("$N自言自语道：百姓已不满朝政，此时再征兵……\n");
                        return 1;
		}
                return 0;
        }
	if(p_goldin-p_goldout*1.1<0)
	{
                if(objectp(o_id))
                        o_id->simple_action("$N自言自语道：金确实不足呀。\n");
		return 0;
	}
	if(p_foodin-p_foodout*12*1.1<0)
	{
                if(objectp(o_id))
                        o_id->simple_action("$N自言自语道：粮食确实不足呀。\n");
		return 0;
	}
	if(p_stuffin-p_stuffout*1.1<0)
	{
                if(objectp(o_id))
                        o_id->simple_action("$N自言自语道：物资确实不足呀。\n");
		return 0;
	}
	if(p_month<=9)
		p_month=9-p_month;
	else
		p_month=17-p_month;
	if(p_food-p_foodout*(p_month+3)<0)
	{
                if(objectp(o_id))
                        o_id->simple_action("$N自言自语道：粮食确实不足呀。\n");
		return 0;
	}
        if(objectp(o_id))
                o_id->simple_action("$N自言自语道：似乎金粮物充足呀。\n");
        return 1;
}
int localbuy_consider(string p_id,string p_area,string p_what)
{
	int p_gold;
	object o_id=CHAR_D->find_char(p_id);
	p_gold=AREA_D->get_area(p_area,"gold");
	if(p_gold<20)
		if(objectp(o_id))
		{	o_id->simple_action("$N自言自语道：金似乎不足呀。\n");
			return 1;
		}
	return 0;
}

int local_tax_consider(string p_id,string p_area,int new_tax,int old_tax)
{
	int p_goldin,p_foodin;
	int p_goldout,p_foodout;
	object o_id;
	int p_safe;
	p_safe=AREA_D->get_area(p_area,"safe");
	o_id=CHAR_D->find_char(p_id);
	p_goldin=AREA_D->get_area(p_area,"goldin")+AREA_D->get_area(p_area,"salary");
	p_goldout=AREA_D->get_area(p_area,"goldout");
	p_foodin=AREA_D->get_area(p_area,"foodin");
	p_foodout=AREA_D->get_area(p_area,"foodout");
	if(new_tax>old_tax)
	{
		if((p_goldin/(p_goldout+1.0)>1.3)&&(p_goldin-p_goldout>100)&&
		   (p_foodin/(p_foodout+1.0)/12>1.3)&&(p_foodin/12-p_foodout>1000))
		{
			if(objectp(o_id))
                                o_id->simple_action("$N自言自语道：似乎不需提高税率。\n");
			return 1;
		}
		if(new_tax-old_tax>20)
		{
			if(objectp(o_id))
                                o_id->simple_action("$N自言自语道：税率不应波动过大呀。\n");
			return 1;
		}
		if(p_safe<10+(new_tax-old_tax)*2)
                {
                        if(objectp(o_id))
                                o_id->simple_action("$N自言自语道：提高税率的话，百姓们会不满的。\n");
                        return 1;
                }
		return 0;
	}
        if((p_goldin/(p_goldout+1.0)<1.5)||
           (p_foodin/(p_foodout+1.0)/12<1.5))
	{
		if(objectp(o_id))
                        o_id->simple_action("$N自言自语道：似乎金粮不足呀。\n");
		return 1;
	}
	if(old_tax-new_tax>20)
	{
		if(objectp(o_id))
                        o_id->simple_action("$N自言自语道：税率不应波动过大。\n");
		return 1;
	}
	return 0;
}
int real_consider(string p_id)
{
        int *p_task;
        string s_suggestion;
        int task_id;
        mixed p_para;
        int res;
        p_task=TASK_D->get_char_task(p_id);
        if(p_task[0]==-1) // no task some thing wrong
                return -1;
        task_id=p_task[0];
        s_suggestion=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        switch (s_suggestion)
        {
           case "localtax": 
            {
                    int p_taxold;
                    p_taxold=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"taxlocal");
                    res=local_tax_consider
                            (p_id,CHAR_D->get_char(p_id,"area"),p_para,p_taxold);
            }
            break;
		case "recruit":
		{
			int p_soldierold;
			p_soldierold=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"soldier");
                        res=recruit_consider
                                (p_id,CHAR_D->get_char(p_id,"area"),p_para,p_soldierold);
		}
		break;
		case "importance":
			res=importance_consider(p_id,CHAR_D->get_char(p_id,"area"),p_para);
			break;
		case "localbuy":
			res=localbuy_consider(p_id,CHAR_D->get_char(p_id,"area"),p_para);
			break;
		case "war":
			res=war_consider(p_id,CHAR_D->get_char(p_id,"area"),p_para);
			break;
		default:
                        res=0;

        }
        return res;
}
void show_consider(string p_id)
{
        object o_id;
        int p_rand;
        o_id=CHAR_D->find_char(p_id);
        if(objectp(o_id))
        {
                p_rand=random(3);
                switch(p_rand)
                {
                        case 0:
                                o_id->responda("consider");
                                break;
                        case 1:
                                o_id->responda("hmm");
                                break;
                        default:
                                o_id->responda("wake");
                }
        }
        if((CHAR_D->get_char(p_id,"status"))!=STATUS_ONLINE)
        {   int res;
            int task_id;
			int p_zhimou;
            task_id=(TASK_D->get_char_task(p_id))[0];
		p_zhimou=CHAR_D->get_skill(p_id,"sk_zhimou");
		res=random(3);
		if(p_zhimou>random(100)) // realconsider
	                res=real_consider( p_id);
                switch(res)
                {       
                        case 0: //agree;
                                agree_sb(task_id,p_id,"");
                                break;
                        case 1: // disagree;
                                disagree_sb(task_id,p_id,"");
                                break;
                        case 2: //neutral;
                                neutral_sb(task_id,p_id,"");
                                break;
        
                }
        }
}
void do_consider(string p_id)
{
        call_out("show_consider",random(3)+1,p_id);
}
