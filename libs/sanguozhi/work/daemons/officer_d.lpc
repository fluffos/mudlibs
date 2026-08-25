// officer_d.c by fire on June 30, 1998
#include <mudlib.h>
#define SAVE_FILE "/data/daemons/officer_d"
inherit M_ACCESS;
private mapping offs=([]);
nosave protected int *lst;
nosave protected mapping area_offs=([]);
nosave protected mapping nation_offs=([]);

void save_data()
{
	unguarded(1, (: save_object, SAVE_FILE, 1 :));
	return;
}
void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	lst=keys(offs);
    return;
}

int query_max_officer_number(int p_title)
{
	if(member_array(p_title,lst)==-1)
		return 0;
	return offs[p_title]["num"];
}
int query_level(int p_title)
{
	if(member_array(p_title,lst)==-1)
		return 0;
	return offs[p_title]["level"];
}
int query_salary(int p_title)
{
	int p_level;
	p_level=query_level(p_title);
	switch(p_level)
	{
	case 0: return 0;
	case 1:	return 1;
	case 2:	return 2;
	case 3:	return 3;
	case 4:	return 5;
	case 5:	return 10;
	case 6:	return 20;
	case 7:	return 50;
	case 8:	return 100;
	default: return 0;
	}
}
int* fill_nation_officer_title(int p_nationlevel,int p_type,int p_officerlevel) {
	mapping rs;
	int *ret=({});
	//write("进了fill_nation_officer_title()函数 p_nationlevel="+p_nationlevel+" p_type="+p_type+" p_officerlevel="+p_officerlevel+"\n");
	foreach(int rk in lst) {
		rs=offs[rk]["assign"];
		if(!mapp(rs)) continue;
		if(rs["pos"]!="nation") continue;
		if(rs["nation_level"]!=p_nationlevel) continue;
		if(rs["typ"]!=p_type) continue;
		if(rs["off_lev"]!=p_officerlevel) continue;
		ret-=({rk});
		ret+=({rk});
	}
	/*printf("ret = ");
	foreach(int temp in ret)
		printf("%d ", temp);
	printf("\n");*/
	return ret;
}

// nationlevel is the level of the area
// p_type = 0 means leader
// p_type = 1 means wen guan p_type =2 means wu guan
// p_officerlevel=0 means the highest level in these nation
int* query_nation_officer_title(int p_nationlevel,int p_type,int p_officerlevel)
{
	string idx;
	if(p_type==0) return ({R_KING});

	idx=sprintf("%d_%d_%d",p_nationlevel,p_type,p_officerlevel);
	if(!arrayp(nation_offs[idx])) 
		nation_offs[idx] = fill_nation_officer_title(p_nationlevel,p_type,p_officerlevel);
	return nation_offs[idx];
}

int* query_nation_officer_title_all(int p_nationlevel)
{
	int *p_res;
	int *p_tmp;
	int i;
	p_res=({});
	{
		p_tmp=query_nation_officer_title(p_nationlevel,0,0);
		p_res+=p_tmp;
		for(i=0;i<10;++i)
		{
			p_tmp=query_nation_officer_title(p_nationlevel,1,i);
			p_res+=p_tmp;
		}
		for(i=0;i<10;++i)
		{
			p_tmp=query_nation_officer_title(p_nationlevel,2,i);
			p_res+=p_tmp;
		}
	}
	/*printf("p_res = ");
	foreach(int temp4 in p_res)
		printf("%d ", temp4);
	printf("\n");*/
	return p_res;
}


int* fill_area_officer_title(int p_arealevel,int p_type,int p_officerlevel) {
	mapping rs;
	int *ret=({});
	//write("进了fill_area_officer_title()函数 p_arealevel="+p_arealevel+" p_type="+p_type+" p_officerlevel="+p_officerlevel+"\n");
	foreach(int rk in lst) {
		//write("rk = " + rk + "\n");
		rs=offs[rk]["assign"];
		if(!mapp(rs)) continue;
		if(rs["pos"]!="area") continue;
		if(rs["area_level"]!=p_arealevel) continue;
		if(rs["typ"]!=p_type) continue;
		if(rs["off_lev"]!=p_officerlevel) continue;   //还不知道这个等级是怎么定的。该地区一把手就是0
		ret-=({rk});
		ret+=({rk});
	}
	/*write("ret = ");
	foreach(int temp in ret)
		write(temp + " ");
	write("\n");*/
	return ret;
}

//p_arealevel是地区area的等级
//p_type是类型(文官武官首领)，取值有0，1，2
//p_officerlevel是官职的等级
int* query_area_officer_title(int p_arealevel,int p_type,int p_officerlevel)
{
	string idx;
	idx=sprintf("%d_%d_%d",p_arealevel,p_type,p_officerlevel);
	if(!arrayp(area_offs[idx])) 
		area_offs[idx] = fill_area_officer_title(p_arealevel,p_type,p_officerlevel);
	return area_offs[idx];

}
int* query_area_officer_title_all(int p_arealevel)
{
	int *p_res;
	int *p_tmp;
	int i;
	p_res=({});
	{
		p_tmp=query_area_officer_title(p_arealevel,0,0);
		p_res+=p_tmp;
		for(i=0;i<7;++i)
		{
			p_tmp=query_area_officer_title(p_arealevel,1,i);
			p_res+=p_tmp;
		}
		for(i=0;i<7;++i)
		{
			p_tmp=query_area_officer_title(p_arealevel,2,i);
			p_res+=p_tmp;
		}
	}
	return p_res;
}
string query_rank_name(int p_rank)
{
	if(member_array(p_rank,lst)==-1)
		return "━━";
	return offs[p_rank]["name"];
}
int init_offs() {
/*	mapping as;
	foreach(int r in lst) {
		if(r==1) continue;
		if(r==1000) continue;
		as=offs[r]["assign"];
		if(!mapp(as)) continue;
		if(as["pos"]=="area") 
			offs[r]["level"]++;
	
	}
	save_data(); */
	return 1;
}
mixed get_officer(mixed tit,string par) {
	if(tit=="list") return lst;
	if(!tit) return offs;
	if(!mapp(offs[tit])) return 0;
	if(!par) return offs[tit];
	return offs[tit][par];
}
string list_off(int *rks) {
	int i,sum,ts;
	string ret;
	sum=sizeof(rks);
	if(!sum) 
		return "没有查到相应官职。\n";
	//write("sum = " + sum + "\n");
	ret=
"ＩＤ 官衔名称 等级|ＩＤ 官衔名称 等级|ＩＤ 官衔名称 等级|ＩＤ 官衔名称 等级 \n";
	ts=1;
	for(i=0;i<sum;++i,ts++) {
		//write("rks[i] = " + rks[i] + "\n");
		//write("offs[rks[i]][name] = " + offs[rks[i]]["name"] + "\n");
		ret+=sprintf("%4d %-8s  %2s ",rks[i],
		offs[rks[i]]["name"],
		chinese_number(offs[rks[i]]["level"]));
		if(ts>=4) {
			ret+="\n";ts=0;
		}
		else ret+="|";
	}
	return ret;
}
string typ_str(int s) {
	switch(s) {
		case 1: return "文官";
		case 2: return "武官";
		default: return "首领";
	}
}
int reputation_req(int level) {
	switch(level) {
		case 1: return 10;
		case 2: return 100;
		case 3: return 1000;
		case 4: return 5000;
		case 5: return 10000;
		case 6: return 20000;
		case 7: return 50000;
		case 8: return 100000;
		case 9: return 10000; // make independ easier
		default: return 8000;
	}
}
int loyalty_req(int level) {
	switch(level) {
		case 1: return 45;
		case 2: return 50;
		case 3: return 55;
		case 4: return 60;
		case 5: return 70;
		case 6: return 80;
		case 7: return 90;
		case 8: return 100;
		default: return 80;
	}
}

int literate_req(int level) {
	switch(level) {
		//case 1: return 10;
//change by listen cause we raise the lit to 30
		case 1: return 30;
		case 2: return 50;
		case 3: return 100;
		case 4: return 200;
		case 5: return 500;
		case 6: return 1000;
		case 7: return 2000;
		case 8: return 5000;
		default: return 300;
	}
}
int skill_req(int level) {
	switch(level) {
		case 1: return 30;
		case 2: return 35;
		case 3: return 40;
		case 4: return 45;
		case 5: return 50;
		case 6: return 60;
		case 7: return 70;
		case 8: return 80;
		default: return 45;
	}
}
int contribution_req(int level) {
	switch(level) {
		case 1: return 10;
		case 2: return 50;
		case 3: return 100;
		case 4: return 200;
		case 5: return 400;
		case 6: return 700;
		case 7: return 1000;
		case 8: return 1500;
		default: return 500;
	}
}
string req_str(string wt) {
	switch(wt) {
		case "reputation": return "声望";
		case "literate": return "文学";
		case "loyalty": return "忠诚";
		case "nationcontribution": return "国家贡献";
		case "localcontribution": return "地区贡献";
		case "sk_wuli": return "武学修养";
		case "sk_meili": return "治国修养";
		case "sk_zhimou": return "兵法修养";
		default: return "未知";
	}
}
mixed query_requirement(int r) {
	mapping req=([]);
	int level;
	int reputation,loyalty,literate,contribution,skill;
	int typ,is_area;
	string sk;
	if(!mapp(offs[r])) return "no such officer rank\n";
	level=offs[r]["level"];

	reputation=reputation_req(level);
	loyalty=loyalty_req(level);
	literate=literate_req(level);
	contribution=contribution_req(level);
	skill=skill_req(level);

	if((r==R_KING)||(r==R_SG)) {
		typ=0;
		is_area=1;
		
	} else {
		typ=offs[r]["assign"]["typ"];
		is_area=(offs[r]["assign"]["area_level"]>0 ? 1 :0);
	}

	switch(typ) {
		case 0:	sk="sk_meili";	break;
		case 1: sk="sk_zhimou"; break;
		case 2: sk="sk_wuli"; break;
	}
	req["literate"]=literate;
	req["reputation"]=reputation;
	req["loyalty"]=loyalty;
	if(is_area) req["localcontribution"]=contribution;
	else req["nationcontribution"]=contribution;
	req[sk]=skill;
	return req;
}
string show_off(int r) {
	string ret;
	mapping res;
	mapping req;
	if(!mapp(offs[r])) return "没有这个官衔。\n";
	ret="基本信息：\n";
	ret+=COLOR_D->right_string("%^H_GREEN%^ID：",12)+"  "+COLOR_D->left_string(""+r+"%^RESET%^",30)+"\n";
	ret+=COLOR_D->right_string("%^H_RED%^名称：",12)+"  "+COLOR_D->left_string(offs[r]["name"]+"%^RESET%^",30)+"\n";
	ret+=COLOR_D->right_string("%^H_RED%^等级：",12)+"  "+COLOR_D->left_string(""+offs[r]["level"]+"%^RESET%^",30)+"\n";
	ret+=COLOR_D->right_string("%^H_RED%^俸禄：",12)+"  "+COLOR_D->left_string(""+query_salary(r)+"%^RESET%^",30)+"\n";

	res=offs[r]["assign"];
	if(mapp(res)) {

		if(res["pos"]=="area"){
			ret+=COLOR_D->right_string("%^YELLOW%^类别：",12)+"  "+COLOR_D->left_string("地区%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^地区级别：",12)+"  "+COLOR_D->left_string(""+res["area_level"]+"%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^类型：",12)+"  "+COLOR_D->left_string(""+typ_str(res["typ"])+"%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^管理级：",12)+"  "+COLOR_D->left_string(""+res["off_lev"]+"%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^配置数：",12)+"  "+COLOR_D->left_string(""+offs[r]["num"]+"%^RESET%^",30)+"\n";
		}
		else {
			ret+=COLOR_D->right_string("%^YELLOW%^类别：",12)+"  "+COLOR_D->left_string("国家%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^国家级别：",12)+"  "+COLOR_D->left_string(""+res["nation_level"]+"%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^类型：",12)+"  "+COLOR_D->left_string(""+typ_str(res["typ"])+"%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^管理级：",12)+"  "+COLOR_D->left_string(""+res["off_lev"]+"%^RESET%^",30)+"\n";
			ret+=COLOR_D->right_string("%^YELLOW%^配置数：",12)+"  "+COLOR_D->left_string(""+offs[r]["num"]+"%^RESET%^",30)+"\n";
		}
	}
	ret+="要求：\n";
	req=query_requirement(r);
	foreach(string wt, int val in req) {
		ret+=COLOR_D->right_string("%^H_BLUE%^"+req_str(wt)+"：",12)+"  "+COLOR_D->left_string(""+val+"%^RESET%^",30)+"\n";
	}
	return ret;
}

//what代表area还是nation, par代表area的等级
string stat_me(string what, mixed par) {
	int *rks=({});
	int i;
	string ret="";
	if((!what)||(what=="")) what="list";

	switch(what) {
		case "list":
			ret+="%^H_GREEN%^关口地区官员：%^RESET%^\n"; ret+=stat_me("area",1)+"\n";
			ret+="%^H_GREEN%^村庄地区官员：%^RESET%^\n"; ret+=stat_me("area",2)+"\n";
			ret+="%^H_GREEN%^城镇地区官员：%^RESET%^\n"; ret+=stat_me("area",3)+"\n";
			ret+="%^H_GREEN%^城市地区官员：%^RESET%^\n"; ret+=stat_me("area",4)+"\n";
			ret+="%^H_GREEN%^大城地区官员：%^RESET%^\n"; ret+=stat_me("area",5)+"\n";
			ret+="%^H_GREEN%^一般国家官员：%^RESET%^\n"; ret+=stat_me("nation",0)+"\n";
			ret+="%^H_GREEN%^帝国国家官员：%^RESET%^\n"; ret+=stat_me("nation",1);
			
			return ret;
		case "nation":
			if(par!=-1) {
				rks=query_nation_officer_title_all(par);
			}
			else {
				for(i=0 ; i<2 ; ++i) {
					rks-=query_nation_officer_title_all(i);
					rks+=query_nation_officer_title_all(i);
				}
			}
			return list_off(rks);
		case "area":
			if(par!=-1) {
				rks=query_area_officer_title_all(par);
			}
			else {
				for(i=1;i<6;++i) {
					rks-=query_area_officer_title_all(i);
					rks+=query_area_officer_title_all(i);
				}
			}
			/*write("rks = ");
			foreach(int temp in rks)
				write(temp + " ");
			write("\n");*/
			return list_off(rks+({R_SG}));
		default :
			i=to_int(what);
			if(i>0) return show_off(i);
			return "非法参数，请查阅help。\n";
	}
}
void clear_officer() {
	lst=keys(offs);
	area_offs=([]);
	nation_offs=([]);

}
mixed remove_officer(int r) {
	mixed tmp;
	if(!mapp(offs[r])) return "no such officer rank.\n";
	tmp=offs[r];
	map_delete(offs,r);
	save_data();
	clear_officer();
	return tmp;
}
mixed add_officer(int r) {
	if(mapp(offs[r])) return "such officer rank exist already.\n";
	offs[r]=([]);
	save_data();
	clear_officer();
	return offs[r];
	
}
mixed set_officer(int r,string what,mixed val) {
	if(!mapp(offs[r])) return "no such officer rank use add_officer first.\n";
	offs[r][what]=val;
	save_data();
	clear_officer();
	return offs[r];
}
