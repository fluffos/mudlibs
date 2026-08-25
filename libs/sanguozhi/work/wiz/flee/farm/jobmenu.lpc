#include <mudlib.h>

inherit M_INPUT;

void do_fire();
void do_water();
void do_rats();
void do_help();
void do_bugs();
void get_input_from_main(string arg);

void start_menu()
{
        modal_push( (: get_input_from_main :), "bfrwhq-->" );
        return;
}
void quit_jobmenu()
{
        modal_pop();
        destruct( this_object() );
        return;
}
void get_input_from_main(string arg)
{
	if( arg=="f" ) do_fire();
	else if( arg=="r" ) do_rats();
	else if( arg=="h" ) do_help();
	else if( arg=="q" ) quit_jobmenu();
	else if( arg=="w" ) do_water();
	else if( arg=="b" ) do_bugs();
	else write("非法命令。\n");
	return;
}
void do_fire()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("你已经太累了，还是休息一会再干吧。\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "你正忙着指挥农夫们劳动呢。");
	ob->award_exp(50+random(21), "sk_meili");
	if( job["job"]!="fire" ){
		ob->simple_action("大家都以奇怪的眼光看着$N。\n");
		return;
	}
	ob->simple_action("$N大喊一声：大家跟我来，说着就奋不顾身的向火丛冲去。\n");
	ob->simple_action("大伙儿跟着$N一涌而上，想把火扑灭。\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("大火反而越烧越大了。\n");
	} else if( !random(4) ){
		write("可惜火势依旧不可控制。\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("火势渐渐的受到了控制。\n");
		if( (job["job_d"]-1)<= 0 ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("火苗挣扎着跳动了几下，熄灭了。\n");
		}
	}
}
void do_water()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("你已经太累了，还是休息一会再干吧。\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "你正忙着指挥农夫们劳动呢。");
	ob->award_exp(10+random(51), "sk_meili");
	if( job["job"]!="water" ){
		ob->simple_action("大家都以奇怪的眼光看着$N。\n");
		return;
	}
	ob->simple_action("$N大喊一声：大家跟我来，说着就奋不顾身的向洪水冲去。\n");
	ob->simple_action("大伙儿跟着$N一涌而上，想把河流决口堵住。\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("积水反而越来越多了。。\n");
	} else if( !random(4) ){
		write("庄稼地里依旧全是积水。。\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("积水渐渐的受到了控制。\n");
		if( !(job["job_d"]-1) ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("终于，所有的积水都排净了。\n");
		}
	}
}
void do_rats()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("你已经太累了，还是休息一会再干吧。\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "你正忙着指挥农夫们劳动呢。");
	ob->award_exp(30+random(51), "sk_meili");
	if( job["job"]!="rats" ){
		ob->simple_action("大家都以奇怪的眼光看着$N。\n");
		return;
	}
	ob->simple_action("$N大喊一声：大家跟我来，说着就奋不顾身的向鼠群冲去。\n");
	ob->simple_action("大伙儿跟着$N一涌而上，想把老鼠消灭。\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("反而被老鼠咬的遍体鳞伤。。\n");
	} else if( !random(4) ){
		write("可惜老鼠依旧到处肆虐。。\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("鼠群渐渐的受到了控制。。\n");
		if( !(job["job_d"]-1) ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("终于，整个鼠群都被消灭了。\n");
		}
	}

}
void do_bugs()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("你已经太累了，还是休息一会再干吧。\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "你正忙着指挥农夫们劳动呢。");
	ob->award_exp(10+random(51), "sk_meili");
	if( job["job"]!="bugs" ){
		ob->simple_action("大家都以奇怪的眼光看着$N。\n");
		return;
	}
	ob->simple_action("$N大喊一声：大家跟我来，说着就奋不顾身的向成群的蝗虫冲去。\n");
	ob->simple_action("大伙儿跟着$N一涌而上，想把蝗虫消灭掉。\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("蝗虫反而越来越密集了。\n");
	} else if( !random(4) ){
		write("可惜蝗虫依旧不可控制。\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("蝗虫渐渐的受到了控制。\n");
		if( !(job["job_d"]-1) ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("终于，整个蝗虫群都被消灭了。\n");
		}
	}

}
void do_help()
{
	write("b-> bugs    灭蝗\n");
	write("f-> fire    灭火\n");
	write("w-> water   防水\n");
	write("r-> rats    灭鼠\n");
	write("h-> help    显示本帮助\n");
	write("q-> quit    离开本帮助\n");
}

