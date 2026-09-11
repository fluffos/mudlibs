//farm_head_menu.c
#define LOG_FILE "/sgdomain/base/base.log"

inherit __DIR__+"farm_menu";
protected string p_workername;
protected string r_id;

int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}

void do_query() {
	poped=0;
   	modal_pop();

    call_out("quit_menu_application",5);

	if(objectp(slave)&&objectp(master)) {
	    master->targetted_action("$N对$T道：这里情况怎么样啊？\n",slave);
	    DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道："+get_master()->stat_me(r_id),2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
	}
}

void do_addworker() {
	string p_ld=master->query_primary_id();
	mixed ret;
	string job_id="getppl";
	poped=0;
   	modal_pop();
	
    call_out("quit_menu_application",5);

	if(objectp(slave)&&objectp(master)) 
	{
	    master->targetted_action("$N对$T道：这个"+p_roomname+
			"的"+p_workername+"人数不够，还需要在增加一些"+p_workername+
			"。\n",slave);
//Modified by Listen on Aug 20th,2001
//A rank checker is added in case of get fake ppl to destory the farm
//Level to do getppl is setted at >= level 3
	    if((CHAR_D->get_char(p_id,"level")<3) && (!wizardp(p_id)))
	    {
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道：$R的官职等级不够，不能做"+JOB_D->query_job(job_id,"name")
			+"的工作。\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	    }
//End of modification
	    ret=get_master()->can_have_more_ppl( r_id);
	    if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道："+ret,2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	    } else if ( master->query_job(job_id,"count_lasttimes") > 
            JOB_D->query_job(job_id,"count_lasttimes")){
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道：$R今天做的"+JOB_D->query_job(job_id,"name")+
			"已经够多的了，应该休息一下了。\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	    } else {
		master->resign_job(job_id);
		master->add_job(job_id);
		master->set_job(job_id,"p_area",p_area);
		master->set_job(job_id,"f_id",f_id);
		master->set_job(job_id,"r_id",r_id);
		DELAY_D->delay_targetted_action(slave,master,"$N对$T道：$R之言甚是有理，\n"+
			"那就麻烦$R再去招一些"+p_workername+"吧。\n具体方法详细见 help getppl\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	    }
	}

}


void do_orderworker() {
    string p_ld;
    mixed ret;
    string job_id="basejob";
    poped=0;
    modal_pop();

	call_out("sp_quit_menu_application",5);

    if(objectp(slave)&&objectp(master)) {
        master->targetted_action("$N对$T道：生产还不够努力嘛。让$S来亲自指挥一下。\n",slave);
		if ( master->query_job(job_id,"count_lasttimes") > 
			JOB_D->query_job(job_id,"count_lasttimes")){
            DELAY_D->delay_targetted_action(slave,master,
                    "$N对$T道：$R今天做的"+JOB_D->query_job(job_id,"name")+
                    "已经够多的了，应该休息一下了。\n",2);
            DELAY_D->delay_simple_action(master,
                    "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
            return;
        } else {
            master->resign_job(job_id);
            master->add_job(job_id);
            master->set_job(job_id,"status","begin");
            master->set_job(job_id,"score",0);
            master->set_job("buildbase","memo","指挥"+AREA_D->get_area(p_area,"name")+p_workername);

            DELAY_D->delay_targetted_action(slave,master,
                    "$N对$T一边连忙鞠躬道：$R亲自指挥，那真是太好不过了。\n"+
					"一边暗自道：这个$r，真是吃饱了撑的。\n",2);
            DELAY_D->delay_targetted_action(master,slave,
                    "$N对$T瞪了一眼道：你说什么？\n",3);
            DELAY_D->delay_simple_action(slave,
                    "$N连忙赔笑道：没说什么，没说什么，小的这就去叫人。\n",4);
			{
				object job=new(__DIR__+"basejob");
				job->init(master,slave);
			}
            return;
        }
    }
}
void do_dealworker() {
	do_nothing();
}



void create( )
{
    set_privilege(1);
}


mixed can_sub_worker(int val) {
	int pplnum;
	if(val<10) 
		return "一次至少裁减十名。";

	pplnum=get_master()->get_room(r_id,"pplnum");
	if(val>pplnum)
		return "本"+p_roomname+"没有那么多"+p_workername+"。";

	if(CHAR_D->get_char(p_id,"level")<3)
		return "$R职位不高，这样的事，下人也做不得主呀。";
	return 1;
	
}

void do_subworker(int val) {
	int pplnum,gold;
	mixed ret;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",5);

    master->targetted_action("$N对$T道：我看这里"+p_workername+"过剩，应该裁减"+val+"名"
			"。\n",slave);
	val=to_int(val);
	ret=can_sub_worker(val);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道："+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	}
	pplnum=get_master()->get_room(r_id,"pplnum");
	pplnum-=val;
	get_master()->set_room(r_id,"pplnum",pplnum);

	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：这些"+p_workername+"会闹事的。\n",2);
	DELAY_D->delay_targetted_action(master,slave,
		"$N对$T道：给他们每人一两金子的遣散费。\n",3);
	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：$R放心，$s这就去办。\n",4);
	DELAY_D->delay_simple_action(master,
		"$N满意地点了点头。\n",5);

	gold=AREA_D->get_area(p_area,"gold");
	gold-=val;
	AREA_D->set_area(p_area,"gold",gold);
	set_rumor(AREA_D->get_area(p_area,"name")+"解雇了一批"+p_workername+"。");
	log_me(AREA_D->get_area(p_area,"name")+"解雇了一批"+p_workername+"。");
	return;

}



mixed can_sub_stuff(string stf,int val) {
	string stfname,prod,prodname;
	mapping consume;
	mapping src;
	if(!BASE_D->stuff_exist(stf))
		return "没有"+stf+"这种物资。";
	stfname=BASE_D->get_stuff(stf,"name");
	if(val<=0) 
		return "要减少多少"+stfname+"？";

	src=get_master()->get_room(r_id,"src");
	if(!mapp(src)) src=([]);
	
	if(src[stf]["num"]<val) return "库里没有这么多"+stfname+"。";//suicide 2000.02.26

	if(CHAR_D->get_char(p_id,"level")<3)
		return "$R职位不高，这样的事，下人也做不得主呀。";
	return 1;
	
}

void done_substuff(string stf, int val) {
	int area_have;
	string stfname;
	mixed ret;
	mapping src;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",5);

	stfname=BASE_D->get_stuff(stf,"name");
	if(!stringp(stfname)) stfname=stf; 
	else stfname=BASE_D->get_stuff(stf,"unit")+stfname;

    master->targetted_action("$N对$T道：我看这里原料过剩，应该再调出"+val +stfname+
			"。\n",slave);
	val=to_int(val);
	ret=can_sub_stuff(stf,val);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道："+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	}
	area_have=AREA_D->get_area(p_area,stf);
        //modified by suicide in 2000.02.20 for keep the price of the src
	//to calculate the cost of product

	//AREA_D->set_area(p_area,stf,area_have+val);
	src=get_master()->get_room(r_id,"src");
	if(!mapp(src)) src=([]);
	if(!mapp(src[stf])) src[stf]=([]);
	src[stf]["num"]-=val;
	AREA_D->add_area_st(p_area,stf,val,src[stf]["price"]);
	get_master()->set_room(r_id,"src",src);

	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：$R放心，$s这就去办。\n",2);
	DELAY_D->delay_simple_action(master,
		"$N满意地点了点头。\n",3);
	return;
}

void do_substuff(string stf) {
	get_input_then_call
     ((: done_substuff, stf:), "减少多少？");
}
mixed can_add_stuff(string stf,int val) {
	string stfname,prod,prodname;
	mapping consume;
	mapping src;
	int areahave;
	if(!BASE_D->stuff_exist(stf))
		return "没有"+stf+"这种物资。";
	stfname=BASE_D->get_stuff(stf,"name");
	if(val<=0) 
		return "要增加多少"+stfname+"？";
	prod=get_master()->get_product(r_id);
	prodname=BASE_D->get_stuff(prod,"name");
	consume=BASE_D->get_stuff(prod,"consume");
	if(!sizeof(consume))
		return "生产"+prodname+"不需要任何其他物资。";
	if(!consume[stf])
		return "生产"+prodname+"不需要"+stfname+"。";
	areahave=AREA_D->get_area(p_area,stf);
	if(areahave<val)
		return "本地区没有那么多的"+stfname+"储备。";
	if(CHAR_D->get_char(p_id,"level")<2)
		return "$R职位不高，这样的事，下人也做不得主呀。";

	return 1;
	
}
void done_addstuff(string stf, int val) {
	int area_have;
	string stfname;
	mixed ret;
	mapping src;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",5);

	stfname=BASE_D->get_stuff(stf,"name");
	if(!stringp(stfname)) stfname=stf; 
	else stfname=BASE_D->get_stuff(stf,"unit")+stfname;

    master->targetted_action("$N对$T道：我看这里原料不足，应该再调进"+val +stfname+
			"。\n",slave);
	val=to_int(val);
	ret=can_add_stuff(stf,val);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道："+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	}
	area_have=AREA_D->get_area(p_area,stf);
	//modified by suicide in 2000.02.20 for keep the price of the src
	//to calculate the cost of product
	AREA_D->add_area_st(p_area,stf,-val,0);
	//AREA_D->set_area(p_area,stf,area_have-val);
	src=get_master()->get_room(r_id,"src");
	if(!mapp(src)) src=([]);
	if(!mapp(src[stf])) src[stf]=([]);
	src[stf]["num"]+=val;
	src[stf]["price"]=AREA_D->get_area_st_price(p_area,stf);
	get_master()->set_room(r_id,"src",src);

	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：$R放心，$s这就去办。\n",2);
	DELAY_D->delay_simple_action(master,
		"$N满意地点了点头。\n",3);
	return;

	
}
void do_addstuff (string stf) {
	get_input_then_call
     ((: done_addstuff, stf:), "增加多少？");
}
mixed can_changestuff (string stf) {
	string stfname;
	string curstf;
	int lv,mylv;
	if(!BASE_D->stuff_exist(stf))
		return "没有听说过"+stf+"这种东西，那是什么东西呀？";
	stfname=BASE_D->get_stuff(stf,"name");
	lv=BASE_D->get_product_level(f_id,stf);
	if(lv==0) return p_basename+"不能生产"+stfname+"。";
	mylv=get_master()->get_level();
	curstf=get_master()->get_room(r_id,"pro");
	if(curstf==stf) return "目前本"+p_roomname+"的产品正是"+stfname+"嘛。";
	if(mylv<lv)
		return "本"+p_basename+"等级太低，无法生产"+stfname;
	if(CHAR_D->get_char(p_id,"level")<2)
		return "$R职位不高，这样的事，下人也做不得主呀。";
	return 1;

}
void do_changestuff (string stf) {
	string stfname;
	mixed ret;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",6);

	stfname=BASE_D->get_stuff(stf,"name");
	if(!stringp(stfname)) stfname=stf; 

    master->targetted_action("$N对$T道：我建议本"+p_roomname+"改生产"+stfname+"。\n",slave);
	ret=can_changestuff(stf);

	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道："+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	}
	get_master()->set_room(r_id,"pro",stf);
	get_master()->set_room(r_id,"work",0);

	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：那这里以前积累的生产就作废了。\n",2);
	DELAY_D->delay_targetted_action(master,slave,
		"$N对$T道：没有办法，生产"+stfname+"更重要。\n",3);
	
	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：$R放心，$s这就去办。\n",4);
	DELAY_D->delay_simple_action(master,
		"$N满意地点了点头。\n",5);
	set_rumor(AREA_D->get_area(p_area,"name")+p_basename+"开始生产"+stfname+"。");

	return;

}
void init_base_menu() {
    toplevel = new_menu("\n请问有和贵干：");
    quit_item = new_menu_item("退下", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("询问情况",	(: do_query :) ,"1"));
    add_menu_item(toplevel, new_menu_item("增加"+p_workername,	(: do_addworker :) ,"2"));

    add_menu_item(toplevel, new_menu_item("裁减"+p_workername,	(: get_input_then_call,
		(: do_subworker :) ,"裁减多少"+p_workername :), "3"));

	add_menu_item(toplevel, new_menu_item("指挥"+p_workername,	(: do_orderworker :)  ,"4"));

    add_menu_item(toplevel, new_menu_item("处理问题",	(: do_dealworker :)  ,"5"));

    add_menu_item(toplevel, new_menu_item("增加原料",	(: get_input_then_call,
		(: do_addstuff :) ,"增加何种原料：" :), "6"));

    add_menu_item(toplevel, new_menu_item("减少原料",	(: get_input_then_call,
		(: do_substuff :) ,"减少何种原料：" :), "7"));

    add_menu_item(toplevel, new_menu_item("改变产品",	(: get_input_then_call,
		(: do_changestuff :) ,"改为何种产品：" :), "8"));
    
	add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[1234568q]: ");

}
void start_head_menu (object m, object s, string a, string f, string r) {
	r_id=r;
	p_workername=BASE_D->get_base(f,"workername");
	start_menu(m,s,a,f);

//	init_base_menu();

}
