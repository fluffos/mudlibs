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
		for(i=0;i<5;++i)
		{
			p_tmp=query_nation_officer_title(p_nationlevel,1,i);
			p_res+=p_tmp;
		}
		for(i=0;i<5;++i)
		{
			p_tmp=query_nation_officer_title(p_nationlevel,2,i);
			p_res+=p_tmp;
		}
	}
	return p_res;
}


int* fill_area_officer_title(int p_arealevel,int p_type,int p_officerlevel) {
	mapping rs;
	int *ret=({});
	foreach(int rk in lst) {
		rs=offs[rk]["assign"];
		if(!mapp(rs)) continue;
		if(rs["pos"]!="area") continue;
		if(rs["area_level"]!=p_arealevel) continue;
		if(rs["typ"]!=p_type) continue;
		if(rs["off_lev"]!=p_officerlevel) continue;
		ret-=({rk});
		ret+=({rk});
	}
	return ret;
}

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
		for(i=0;i<5;++i)
		{
			p_tmp=query_area_officer_title(p_arealevel,1,i);
			p_res+=p_tmp;
		}
		for(i=0;i<5;++i)
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
	ret=
"ＩＤ 官衔名称 等级 ＩＤ 官衔名称 等级 ＩＤ 官衔名称 等级 ＩＤ 官衔名称 等级 \n";
	ts=1;
	for(i=0;i<sum;++i,ts++) {
		ret+=sprintf("%4d %-8s (%2d) ",rks[i],
		offs[rks[i]]["name"],
		offs[rks[i]]["level"]);
		if(ts>=4) {
			ret+="\n";ts=0;
		}
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
string show_off(int r) {
	string ret;
	mapping res;
	if(!mapp(offs[r])) return "没有这个官衔。\n";
	ret=sprintf("ID: %d 名称：%s 等级：%d 俸禄：%d\n",
		r,offs[r]["name"],offs[r]["level"],
		query_salary(r));
	res=offs[r]["assign"];
	if(mapp(res)) {
		if(res["pos"]=="area") {
			ret+=sprintf("类别：地区 地区等级：%d 类别：%s 管理级：%d  配置数：%d\n",
				res["area_level"],typ_str(res["typ"]),
				res["off_lev"],offs[r]["num"]);
		}
		else {
			ret+=sprintf("类别：国家 国家等级：%d 类别：%s 管理级：%d  配置数：%d\n",
				res["nation_level"],typ_str(res["typ"]),
				res["off_lev"],offs[r]["num"]);
		}
	}
	ret+="要求：\n";
	return ret;
}
string stat_me(string what, mixed par) {
	int *rks=({});
	int i;
	if((!what)||(what=="")) what="list";
	switch(what) {
		case "list":
			return list_off(lst);
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
			return list_off(rks);
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