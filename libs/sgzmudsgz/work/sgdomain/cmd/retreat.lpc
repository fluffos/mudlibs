void start()
{
	int troop, task, *ts;
	string who, side, area, *chars;
	object env;
	mixed target;

	who = this_body()->query_id()[0];
	env = environment(this_body());
	if( !env->is_troop() ){
           	write("只有身在军中才能指挥撤退。\n");
           	return ;
	}
	troop = env->get_id();
	task = TROOP_D->get_troops(troop, "task_id");
	side = TROOP_D->get_troops(troop, "side");
	if( (side=="a"&&who!=TASK_D->get_task(task, "att_leader")) || 
	    (side=="d"&&who!=TASK_D->get_task(task, "def_leader")) ){
		write("只有主将才可以下达撤退的命令。\n");
		return;
	}
	if( TASK_D->get_task(task, "def_stage") != "enter_warfield" ){
		write("还没开战就要逃跑啊？\n");
		return;
	}
	if( TASK_D->get_task(task, "type") == 3 ){
		write("这是训练啊，你也想逃跑！\n");
		return;
	}
	if( side == "a" ){
		area = TROOP_D->get_troops(troop, "source_area");
		if( AREA_D->get_area(area, "nation") != CHAR_D->get_char(who, "nation") ){
			write(AREA_D->get_area(area,"name")+"已落入敌手，你无城可退。\n");
			return;
		}
		WARAI_D->war_inf(task, CHAR_D->get_char(who, "name")+"大叫道：情况不妙，暂且收兵吧。\n", "");
		CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(who,"name"),"今日且放过你们，下次定要血洗"+AREA_D->get_area(TROOP_D->get_troops(troop, "area"), "name")+"！");
		CHANNEL_D->deliver_tell("rumor","system",CHAR_D->get_char(who,"name")+"不敌而退，撤回"+AREA_D->get_area(area, "name")+"了！");
		(EV_WAR)->war_def_win(task);
	} else {
		area = TROOP_D->get_troops(troop, "def_area");
		target = AREA_D->get_area(area, "neighbor");
		if( !arrayp(target) ){
			write("你已无处可退，还是决一死战吧。\n");
			return;
		}
		foreach(string tt in target){
			if( AREA_D->get_area(tt, "nation") == CHAR_D->get_char(who, "nation") ){
				ts = TASK_D->get_task(task,"def_army");
				foreach(int t in ts)TROOP_D->set_troops(t,"source_area",tt);
				chars = TASK_D->get_task(task,"def_party");
				foreach(string cc in chars){
					CHAR_D->set_char(cc, "area", tt);
					CHAR_D->set_char(cc,"ranklocal",R_SG);
				};
				WARAI_D->war_inf(task, CHAR_D->get_char(who, "name")+"大叫道：情况不妙，暂且退往"+AREA_D->get_area(tt, "name")+"吧。", "");
				CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(who,"name"),"臭贼别猖狂，来日定要再起甲兵收复失地！\n");
				CHANNEL_D->deliver_tell("rumor", "system",CHAR_D->get_char(who, "name")+"不战而退，撤往"+AREA_D->get_area(tt, "name")+"了！");
				(EV_WAR)->war_att_win(task);
				return;
			}
		}
		write("你已无处可退，还是决一死战吧。\n");
	};

	return;
}
