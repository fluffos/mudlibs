#include <ansi.h>
#include <mudlib.h>

inherit M_INPUT;

private string refuse = "露出不屑的表情，糟糕他的工作效率降低了。\n";
private string accept = "沉思了片刻，加倍努力的干起活来。\n";
private mapping workers = ([ ]);

void get_input_from_main(string arg);
void quit_jobmenu();
int check_busy();

void create_worker();
void do_list_worker(mapping ww);

void do_distribute(mixed str);
void do_award(mixed str);
void do_praise(mixed str);
void do_scold(mixed str);
void do_list();
void do_view();
void do_help();

void start_menu()
{
        modal_push( (: get_input_from_main :), "ad"HIY"h"NOR"lqpsv-->" );
        return;
}
void quit_jobmenu()
{
        modal_pop();
        destruct( this_object() );
        return;
}
void get_input_from_main(mixed arg)
{
	string *tmp;
		
	tmp = explode(arg, " ");
	if( !tmp||!sizeof(tmp)||!arrayp(tmp) ){
		write("非法命令。\n");
		return;
	} else if( tmp[0]=="a"&&sizeof(tmp)>1 ) do_award( tmp[1..] );
	else if( tmp[0]=="d"&&sizeof(tmp)>1 )   do_distribute( tmp[1..] ); 
	else if( tmp[0]=="p"&&sizeof(tmp)>1 ) 	do_praise( tmp[1..] );
	else if( tmp[0]=="s"&&sizeof(tmp)>1 ) 	do_scold( tmp[1..] );
	else if( tmp[0]=="l" ) do_list();
	else if( tmp[0]=="v" ) do_view();
	else if( tmp[0]=="q" ) quit_jobmenu();
	else do_help();

	return;
}
void do_help()
{
	printf("1) a 给手下物资奖励。\n");
        printf("2) d 分配工作给手下。\n");
        printf("3) h 显示本帮助文件。\n");
	printf("4) l 列出可供选择的农夫。\n");
        printf("5) p 称赞手下的工作。\n");
	printf("6) q 离开本菜单。\n");
        printf("7) s 责骂手下办事不力。\n");
        printf("8) v 查看工作状况。\n");
        return;
}
void create_worker()
{
	int i;
	string c_name, id;

	string *first = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈","刘","林" });
	string *words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
        	"孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同","满",
        	"富","万","龙","隆","祥","栋","国","亿","寿" });
	string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri"});
	string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});
	
	workers = ([ ]);
	for( i=0; i<4; i++){
		c_name = first[random(sizeof(first))]+words[random(sizeof(words))];
		if( random(6)>2 ) c_name+=words[random(sizeof(words))];
		id = rnd_id[random(sizeof(rnd_id))];
        	if( random(10) > 4 ) id+=rnd_id[random(sizeof(rnd_id))];
        	id+=rnd_id_tail[random(sizeof(rnd_id_tail))];
		workers[id] = (["name":c_name,"str":10+random(10),"tire":random(5),
			"int":10+random(10),"exp":10+random(10),"eff":5+random(5)]);
	}
}
void do_distribute(mixed str)
{
	string who, what, *jobs;
	mapping oldw, now;

	jobs = ({ "砍树", "整地", "灌溉", });
	oldw = this_body()->query_job("landlord","worker");

	if( !check_busy() )return;
	write("现在的工作有：砍树，整地，灌溉。\n");
	if( sizeof(oldw)>=3 ){
		write("你已经指挥着足够的农夫了。\n");
	} else if( !sizeof(workers) ){
		write("请先列出可供选择的农夫。\n");
	} else if( !arrayp(str)||sizeof(str)!=2||!stringp(who=str[0])||!stringp(what=str[1]) ){
		write("命令格式不对。\n");
		write("格式：d 农夫的英文名 工作的中文名\n");
	} else if( member_array(who, keys(workers))==-1 ){
		write("没有这个农夫。\n");
	} else if( member_array(what, jobs)==-1 ){
		write("\n没有这种工作。");
	} else {
		if( !oldw||!mapp(oldw)||!sizeof(oldw) )oldw = ([ ]);
		foreach(string ss in keys(oldw)){
			if( oldw[ss]["job"]==what ){
				write(oldw[ss]["name"]+"正在作这相工作。\n");
				return;
			}
		}
		now = workers[who];
		map_delete(workers, who);
		now["job"] = what;
		oldw[who] = now;
		this_body()->set_job("landlord", "worker", oldw);
		this_body()->simple_action("$N下令让农夫"+now["name"]+"去作的"+now["job"]+"工作。\n");
	}
	return;
}
void do_award(mixed str)
{
	string who, what;
	mapping oldw, one;

	oldw = this_body()->query_job("landlord", "worker");

	if( !check_busy() )return;
	if( !mapp(oldw)||!sizeof(oldw) ){
		write("但你现在没有一个农夫。\n");
	} else if( !arrayp(str)||sizeof(str)!=2 ){
		write("命令格式不对。\n");
                write("格式：a 农夫的英文名 多少两银子\n");
	} else if( !stringp(who=str[0])||member_array(who, keys(oldw))==-1 ){
		write("并没有一个叫“"+who+"”的农夫。\n");
	} else if( !stringp(what=str[1])||to_int(what)<=0 ){
		write("你要赏给他多少两银子呢。\n");
	} else if( to_int(what)>this_body()->query_all_con_money() ){
                write("在看看你身上有那么多钱吗？\n");
                return;
        } else {
		this_body()->set_all_con_money(this_body()->query_all_con_money()-to_int(what)*100);
		one = oldw[who];
		this_body()->simple_action("$N对"+one["name"]+"说道：好好干，$S赏你"+chinese_number(to_int(what))+"两银子。\n");
		if( random(this_body()->query_sk_level("sk_zhimou"))>=random((50-to_int(what)<=0?0:50-to_int(what))) ){
			write(one["name"]+accept);
			one["tire"] = 0;
			one["eff"]+=4+random(3);
			if( one["eff"]>10 ) one["eff"]=10;
		} else {
			write(one["name"]+refuse);
                        one["tire"]-=4+random(2);
			if( one["tire"]<0 ) one["tire"] = 1;
		}
		oldw[who] = one;
		this_body()->set_job("landlord", "worker", oldw);
	}
	return;
}
void do_praise(mixed str)
{
	string who;
        mapping oldw, one;

        oldw = this_body()->query_job("landlord", "worker");

	if( !check_busy() )return;
        if( !mapp(oldw)||!sizeof(oldw) ){
                write("但你现在没有一个农夫。\n");
        } else if( !arrayp(str)||sizeof(str)!=1 ){
                write("命令格式不对。\n");
                write("格式：p 农夫的英文名\n");
        } else if( !stringp(who=str[0])||member_array(who, keys(oldw))==-1 ){
                write("并没有一个叫“"+who+"”的农夫。\n");
	} else {
		one = oldw[who];
		this_body()->simple_action("$N大声的称赞"+one["name"]+"：干的好。\n");
		if( one["eff"]<7 ){
			write( one["name"]+"不满的看了你一眼。\n");
			write( one["name"]+refuse );
			one["eff"]-=2+random(2);
			if( one["eff"]<=0 ) one["eff"]=0;
		} else if( random(this_body()->query_sk_level("sk_zhimou"))+one["eff"] > random(20) ){
                	write( one["name"]+accept );
			one["eff"]+=2+random(2);
			if( one["eff"]>10 ) one["eff"]=10;
		} else write(one["name"]+"根本不理你\n");
		oldw[who] = one;
		this_body()->set_job("landlord", "worker", oldw);
	};

	return;
}
void do_scold(mixed str)
{
        string who;
        mapping oldw, one;

        oldw = this_body()->query_job("landlord", "worker");

	if( !check_busy() )return;
        if( !mapp(oldw)||!sizeof(oldw) ){
                write("但你现在没有一个农夫。\n");
        } else if( !arrayp(str)||sizeof(str)!=1 ){
                write("命令格式不对。\n");
                write("格式：s 农夫的英文名\n");
        } else if( !stringp(who=str[0])||member_array(who, keys(oldw))==-1 ){
                write("并没有一个叫“"+who+"”的农夫。\n");
        } else {
                one = oldw[who];
                this_body()->simple_action("$N责骂"+one["name"]+"：天哪，瞧瞧你都干了什么！\n");
		if( one["eff"]>7 ){
                        write( one["name"]+"不满的看了你一眼。\n");
                        write( one["name"]+refuse );
                        one["eff"]-=2+random(2);
                        if( one["eff"]<=0 ) one["eff"]=0;
                } else if( random(this_body()->query_sk_level("sk_zhimou"))-one["eff"]>random(10) ){
                        write( one["name"]+accept );
                        one["eff"]+=2+random(2);
                        if( one["eff"]>10 ) one["eff"]=10;
                } else write(one["name"]+"根本不理你\n");
                oldw[who] = one;
                this_body()->set_job("landlord", "worker", oldw);
	};

	return;
}
void do_list()
{
	mapping oldw;

        oldw = this_body()->query_job("landlord", "worker");
	if( sizeof(oldw)>=3 ){
		write("你已经有足够的农夫了。\n");
		return;
	};
	create_worker();
	do_list_worker( workers );

	return;
}
void do_view()
{
	mapping oldw;

	oldw = this_body()->query_job("landlord", "worker");

        if( !mapp(oldw)||!sizeof(oldw) )
                write("但你现在没有一个农夫。\n");
	else do_list_worker( oldw );

	return;
}
void do_list_worker(mapping ww)
{
	string out;
	mapping one;

	out = " 姓名      代号    智力  经验  力量  效率  疲劳    工作\n";
	out+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	foreach(string ss in keys(ww) ){
		one = ww[ss];
		out+=sprintf("%-10s%-10s%-6d%-6d%-6d%-6d%-7d%-8s\n",
			one["name"],ss,one["int"],one["exp"],one["str"],one["eff"],one["tire"],(one["job"]?one["job"]:"----"));
	};
	out+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	out+="总工作量："+chinese_number(this_body()->query_job("landlord","")["done"])+"。\n";
	write(out);

	return;
}
int check_busy()
{
	int hp;

	hp = this_body()->query_cur_hp();
	if( hp< 20 ){
		write("你已经太累了，还是休息一会再干吧。\n");
		return 0;
	}
	if( this_body()->query_busy(1)!="不忙。"){
		write("你正忙着呢。\n"); 
		return 0;
	}
	this_body()->set_cur_hp(hp-10-random(10));
	this_body()->start_busy(3+random(2),"你正忙着呢。");
	return 1;
}
