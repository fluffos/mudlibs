#include <mudlib.h>

inherit M_INPUT;

string refuse = "$N露出不屑的表情，糟糕他的工作效率降低了。\n";
string accept = "$N沉思了片刻，加倍努力的干起活来。\n";
object *workers;

void get_input_from_main(string arg);
void quit_jobmenu();

void do_distribute(string *str);
void do_view();
void do_award(string *str);
void do_praise(string str);
void do_scold(string str);
void do_help();

void set_workers(object *obs)
{
	workers = obs;
}

void start_menu()
{
	modal_push( (: get_input_from_main :), "acdhqsv-->" );
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
	string *tmp;

	tmp = explode( arg, " " );

	if( !arg || arg == "" || arg == "h" || tmp[0] == "h" )do_help();
	else if( tmp[0] == "d"&&sizeof(tmp)>1 )do_distribute( tmp[1..] );
	else if( tmp[0] == "p"&&sizeof(tmp)>1 )do_praise( tmp[1] );
	else if( tmp[0] == "s"&&sizeof(tmp)>1 )do_scold( tmp[1] );
	else if( tmp[0] == "a"&&sizeof(tmp)>1 )do_award( tmp[1..] );
	else if( tmp[0] == "v" )do_view();
	else if( tmp[0] == "q" )quit_jobmenu();
	else {
		write("非法命令。\n");
        	return;
	};
	return;
}
void do_distribute(string *str)
{
	int who, job;
	object ob;

	mapping jobs = (["kanshu":"砍树","zhengdi":"整地","guangai":"灌溉"]);

	if( !this_body()->query_job("landlord", "start") ){
                printf("你还没有召集一个手下呢。\n");
                return;
        };
	printf("开发新田所做的工作有：\n1) 砍树：力气活。\n2) 整地：工夫活。\n3) 灌溉：脑力活。\n");
	if( sizeof(str) < 2 || sscanf(str[0], "%d", who) != 1|| sscanf(str[1], "%d", job) != 1
		|| job < 1 || job > 3 || who < 1 || who > 3 ){
		printf("看起来大家听不懂你在说什么。\n");
		printf("d [No of worker] [No of job] \n");
		return;
	};
	ob = workers[who-1];
	if( ob->query("job")&&ob->query("job")!="none" ){
		printf("他正忙在呢。\n");
		return;
	};
	ob->set("job", values(jobs)[job-1]);
	this_body()->targetted_action("$N下令让$T去"+values(jobs)[job-1]+"。\n", ob);
	return;
}
void do_view()
{
	int i;
	string out;
	mapping att;
	object ob;

	if( !this_body()->query_job("landlord", "start") ){
		printf("你还没有召集一个手下呢。\n");
		return;
	};
	out = " 姓名      代号    智力  经验  力量  效率   成绩   工作\n";
	out = out + "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	for( i = 0; i < sizeof(workers); i++){
		ob = workers[i];
		if ( !ob->query_link() ){
			out = out + sprintf("%-10s%-10s%-6d%-6d%-6d%-6d%-7d%-10s\n",
				ob->query_id()[1], ob->query_id()[0],
				ob->query("int"), ob->query("exp"), ob->query("str"), 
				ob->query("eff"),
				ob->query("wrk"), 
				ob->query("job") );
		} else {
			att = ob->query_job("land_dp", "att");
			out = out + sprintf("%-10s%-10s%-6d%-6d%-6d%-6d%-7d%-10s\n",
				ob->query_id()[1], ob->query_id()[0],
				att["int"], att["exp"], att["str"],
				att["eff"], att["wrk"], att["job"] );
		};
	};
	out = out + "\n";
	write( out );
	return;
}
void do_help()
{
	printf("1) a 给手下物资奖励。\n");
	printf("2) d 分配工作给手下。\n");
	printf("3) h 显示本帮助文件。\n");
	printf("4) p 称赞手下的工作。\n");
	printf("5) s 责骂手下办事不力。\n");
	printf("6) v 查看工作状况。\n");
	return;
}
void do_award(string *str)
{
	int who, amount, hp;
	mapping att2;
	object ob;

	if( !this_body()->query_job("landlord", "start") ){
                printf("你还没有召集一个手下呢。\n");
                return;
        };	
	if( sizeof(str) < 2 || sscanf(str[0], "%d", who) != 1|| sscanf(str[1], "%d", amount) != 1
                || amount < 1 || who < 1 || who > sizeof(workers) ){
                printf("看起来大家听不懂你在说什么。\n");
                printf("a [No of worker] [amount of silver] \n");
                return;
        };
	hp = this_body()->query_cur_hp();
	if( hp < 70 ){
		printf("你已经太累了，还是先休息一下再干吧。\n");
                return;
        };
	this_body()->set_cur_hp( hp - 50 - random(10) );
	if( amount*100 > this_body()->query_all_con_money() ){
		write("在看看你身上有那么多钱吗？\n");
	        return;
	};

        ob = workers[who-1];
	this_body()->set_all_con_money(this_body()->query_all_con_money()-amount*100);
	if ( ob->query_link() ) ob->set_all_con_money(ob->query_all_con_money()+amount*100);

	this_body()->targetted_action("$N对$T说道：好好干，$S赏你"+chinese_number(amount)+"两银子。\n", ob);
	if( random(this_body()->query_sk_level("sk_zhimou")) >= 
		random((50-amount<=0?0:50-amount)) ){
		ob->simple_action( accept ); 
		if( ob->query_link() ){
			att2 = ob->query_job("land_dp", "att");
			att2["eff"] = att2["eff"]+1+random(2);
			ob->set_job("land_dp", "att", att2);
		}
		else ob->set("eff", ob->query("eff")+1+random(2));
	} else {
		ob->simple_action( refuse );
	};
	return;
}
void do_praise(string str)
{
	int who, hp;
	mapping att2;
	object ob;

        if( !this_body()->query_job("landlord", "start") ){
                printf("你还没有召集一个手下呢。\n");
                return;
        };
	if( sscanf(str, "%d", who) != 1 || who < 1 || who > sizeof(workers) ){
		printf("看起来大家听不懂你在说什么。\n");
		printf("p [No of worker] \n");
		return;
	};
	hp = this_body()->query_cur_hp();
        if( hp < 70 ){
                printf("你已经太累了，还是先休息一下再干吧。\n");
                return;
        };
	ob = workers[who-1];
        this_body()->set_cur_hp( hp - 50 - random(10) );	
	this_body()->targetted_action("$N大声的称赞$T：干的好。\n", ob);

	if( ob->query("eff") < 7 ){
		ob->targetted_action("$N不满的看了$T一眼。\n", this_body());
		ob->simple_action( refuse );
		if ( ob->query_link() ){
			att2 = ob->query_job("land_dp", "att");
			att2["eff"] = att2["eff"]-1;
			ob->set_job("land_dp", "att", att2);
		} else ob->set("eff", ob->query("eff")-1);
	} else if( random(this_body()->query_sk_level("sk_zhimou"))
		+ob->query("eff") > random(20) ){
		ob->simple_action( accept );
		if ( ob->query_link() ){
                        att2 = ob->query_job("land_dp", "att");
			att2["eff"] = att2["eff"]+1;
			ob->set_job("land_dp", "att", att2);
		} else ob->set("eff", ob->query("eff")+1);
	} else {
		ob->targetted_action("$N根本不理$T。\n", this_body()); 
	};
	return;

}
void do_scold(string str)
{
	int who, hp;
	mapping att2;
        object ob;

        if( !this_body()->query_job("landlord", "start") ){
                printf("你还没有召集一个手下呢。\n");
                return;
        };
        if( sscanf(str, "%d", who) != 1 || who < 1 || who > 3 ){
                printf("看起来大家听不懂你在说什么。\n");
                printf("p [No of worker] \n");
	        return;
        };
        hp = this_body()->query_cur_hp();
        if( hp < 70 ){
                printf("你已经太累了，还是先休息一下再干吧。\n");
                return;
        };
        ob = workers[who-1];
        this_body()->set_cur_hp( hp - 50 - random(10) );
	this_body()->targetted_action("$N责骂$T：天哪，瞧瞧你都干了什么！\n", ob);
	if( ob->query("eff") > 7 ){
		ob->targetted_action("$N不满的看了$T一眼。\n", this_body());
                ob->simple_action( refuse );
                if ( ob->query_link() ){
                        att2 = ob->query_job("land_dp", "att");
                        att2["eff"] = att2["eff"]-1;
			ob->set_job("land_dp", "att", att2);
		} else ob->set("eff", ob->query("eff")-1);
        } else if( random(this_body()->query_sk_level("sk_zhimou"))
                -ob->query("eff") > random(10) ){
		ob->simple_action( accept );
		if ( ob->query_link() ){
                        att2 = ob->query_job("land_dp", "att");
                        att2["eff"] = att2["eff"]+1;
                        ob->set_job("land_dp", "att", att2);
                } else ob->set("eff", ob->query("eff")+1);
        } else {
                ob->targetted_action("$N根本不理$T。\n", this_body());
	};
        return;

}
