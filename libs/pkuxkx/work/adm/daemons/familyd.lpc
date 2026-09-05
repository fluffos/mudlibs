//门派资料维护。其他任务如果要修改门派的资料，统一使用这个接口
//Designed by Jason@pkuxkx

inherit F_DBASE;
inherit F_SAVE;

#include <ansi.h>
#include <localtime.h>

#include <family.h>

string query_save_file()
{
    return "/data/familyd";
}

void create()
{
    seteuid(getuid());
    restore();
}

void add_repute(string family,int amount)
{		
    add("family_repute/"+family,amount);
    save();    	
}

void set_repute(string family,int amount)
{		
    set("family_repute/"+family,amount);
    save();	
}

int get_repute(string family)
{		
    return query("family_repute/"+family);	
}

//return the first n top families
string* get_repute_top(int n)
{
    string* families;    
    mapping data = query("family_repute");
    if(!mapp(data)) return ({});
    families = keys(data);
    families = sort_array(families,"sort_family",this_object());
    if(n<=0) n = 1;
    if(n > sizeof(families)) n = sizeof(families);
    return families[0..(n-1)];
}

string get_repute_top1()
{
    string* families = get_repute_top(1);
    if(sizeof(families) == 0) return "";
    return families[0];
}

int get_family_order(string fam)
{
	int order;
    string* families;    
    mapping data = query("family_repute");
    if(!mapp(data)) return -1;
    families = keys(data);
    families = sort_array(families,"sort_family",this_object());
	order = member_array(fam,families);
	if(order != -1) return order + 1;
	return -1;
}


int sort_family(string fam1,string fam2)
{
    if(query("family_repute/"+fam1) > query("family_repute/"+fam2)) return -1;
    else if (query("family_repute/"+fam1) < query("family_repute/"+fam2)) return 1;
    return 0;
}

string get_dadizi(string fam)
{
	if(query("dadizi/"+fam+"/id")) return query("dadizi/"+fam+"/id");
	return "";
}

string get_dadizi_name(string fam)
{
	if(query("dadizi/"+fam+"/name")) return query("dadizi/"+fam+"/name");
	return "";
}

void set_dadizi(string fam,string id,string name)
{
	set("dadizi/"+fam+"/id",id);
	set("dadizi/"+fam+"/name",name);
	save();
}

int get_top_score(string fam)
{
	if(query("dadizi/"+fam+"/score")) return query("dadizi/"+fam+"/score");
	return 0;
}

void set_top_score(string fam,int score)
{
	set("dadizi/"+fam+"/score",score);	
	save();
}

//设置侠客行任务帮门派争胜模式的获胜者
void set_task_winner_family(string win_family)
{
	set("task/win_family",win_family);
}

string get_task_winner_family()
{
	return query("task/win_family");
}