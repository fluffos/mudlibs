// infor.c
// by fire on 7 July 1998
// this is used to 
// give detailed information for
// a cetain char, country, or area
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;
string bar="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
void infoa(string a_id)
{
	string mess="";
	string mess_tmp;
	mixed p_tmp;
	int *list_title;
	string *list_char;
	string s_tmp;
	array a_tmp;
	int i,j,v_left;
	if(!(AREA_D->area_exist(a_id)))
	{
		mess="该地区不存在，用listarea列出地区清单．\n";
		write(mess);
		return;
	}
	mess_tmp=sprintf("地区代号：%8s    名称：%s\n",a_id,AREA_D->get_area(a_id,"name"));
	mess+=mess_tmp;
        mess+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	mess_tmp=sprintf("等级：%d 天气：%4s  人口：%d\n",
		AREA_D->get_area(a_id,"level"),
		DAY_D->get_weather_short(AREA_D->get_area(a_id,"weather")),
		AREA_D->get_area(a_id,"population"));
	mess+=mess_tmp;
	mess_tmp=sprintf("安定：%3d 工业：%3d 农业：%3d 商业：%3d 重点：%s\n",
		AREA_D->get_area(a_id,"safe"),
		AREA_D->get_area(a_id,"industry"),
		AREA_D->get_area(a_id,"agriculture"),
		AREA_D->get_area(a_id,"business"),
		AREA_D->get_area(a_id,"importancestr"));
	mess+=mess_tmp;
	mess_tmp=sprintf("物资：%d 粮草：%d 金：%d\n",
		AREA_D->get_area(a_id,"stuff"),
		AREA_D->get_area(a_id,"food"),
		AREA_D->get_area(a_id,"gold"));
	mess+=mess_tmp;
	mess_tmp=sprintf("国君：%s 太守：%s 国税：%d 地税：%d\n",
		CHAR_D->get_char(AREA_D->get_area(a_id,"nation"),"name"),
		(stringp(CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name")) ?
		CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name") : "━━"),
		AREA_D->get_area(a_id,"taxnation"),
		AREA_D->get_area(a_id,"taxlocal"));
	mess+=mess_tmp;
	mess_tmp=sprintf("预计金月收入：%d 粮年收入：%d 物月收入：%d\n",
		AREA_D->get_area(a_id,"goldin"),
		AREA_D->get_area(a_id,"foodin"),
		AREA_D->get_area(a_id,"stuffin"));
	mess+=mess_tmp;
	mess_tmp=sprintf("金月支出（士兵：%d 官员：%d ）粮月支出：%d 物月支出：%d\n",
		AREA_D->get_area(a_id,"goldout"),
		AREA_D->get_area(a_id,"salary"),
		AREA_D->get_area(a_id,"foodout"),
		AREA_D->get_area(a_id,"stuffout"));
	mess+=mess_tmp;
    mess_tmp=sprintf("士兵：%d 训练：%d 士气：%d 马匹：%d 弓箭：%d 匪人：%d\n",
                AREA_D->get_area(a_id,"soldier"),
                AREA_D->get_area(a_id,"train"),
                AREA_D->get_area(a_id,"morale"),
                AREA_D->get_area(a_id,"horse"),
                AREA_D->get_area(a_id,"bow"),
                AREA_D->get_area(a_id,"bandit"));
	mess+=mess_tmp;
	mess+="官员：\n";
	list_title=OFFICER_D->query_area_officer_title_all(AREA_D->get_area(a_id,"level"));
	list_char=CHAR_D->check_char("area",a_id);
	for(i=0;i<sizeof(list_title);++i)
	{
		mess_tmp=OFFICER_D->query_rank_name(list_title[i])+"：";
		a_tmp=filter_array(list_char,
			(:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
		for(j=0;j<sizeof(a_tmp);++j)
		{
			mess_tmp+=CHAR_D->get_char(a_tmp[j],"name");
			mess_tmp+=" ";
		}
		v_left=OFFICER_D->query_max_officer_number(list_title[i]);
		v_left-=sizeof(a_tmp);
		for(j=0;j<v_left;++j)
		{
			mess_tmp+="━━ ";
		}
		mess_tmp+="\n";
		mess+=mess_tmp;
	}
	mess+="相邻地区：";
	a_tmp=AREA_D->get_area(a_id,"neighbor");
	for(j=0;j<sizeof(a_tmp);++j)
		mess+=(AREA_D->get_area(a_tmp[j],"name")+" ");
	mess+="\n";
	mess+="本地隐居贤人：";
	for(j=0;j<sizeof(list_char);++j)
	{
		p_tmp=CHAR_D->get_char(list_char[j],"nation");
		if((!p_tmp)||(p_tmp==""))
			mess+=(CHAR_D->get_char(list_char[j],"name")+" ");
	}
	mess+="\n";
	more(mess);
}
void infon(string n_id)
{
	string mess="";
	string mess_tmp;
	mixed p_tmp;
	string *list_area;
	string s_tmp;
	array a_tmp;
	int i,j,v_left;
	int *list_title;
	string *list_char;
	if(!(COUNTRY_D->nation_exist(n_id)))
	{
		mess="该国家不存在，用listcountry列出国家清单．\n";
		write(mess);
		return;
	}
	mess_tmp=sprintf("国家代号：%s  名称：%s\n",n_id,COUNTRY_D->get_country(n_id,"name"));
	mess+=mess_tmp;
	mess+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	mess_tmp=sprintf("总人口：%d 总兵力：%d\n",
		COUNTRY_D->get_country(n_id,"population"),
		COUNTRY_D->get_country(n_id,"soldier"));
	mess+=mess_tmp;
	mess+=sprintf("国库(金：%d 粮：%d 物：%d)\n",
		COUNTRY_D->get_country(n_id,"gold"),
		COUNTRY_D->get_country(n_id,"food"),
		COUNTRY_D->get_country(n_id,"stuff"));
	mess+=sprintf("地方(金：%d 粮：%d 物：%d)\n",
		COUNTRY_D->get_country(n_id,"goldlocal"),
		COUNTRY_D->get_country(n_id,"foodlocal"),
		COUNTRY_D->get_country(n_id,"stufflocal"));
	mess+=sprintf("领地：");
	list_area=AREA_D->check_area("nation",n_id);
	for(i=0;i<sizeof(list_area);++i)
	{
		mess+=sprintf("%s ",AREA_D->get_area(list_area[i],"name"));
	}
	mess+="\n";
	mess+="朝廷官员\n";
	list_title=OFFICER_D->query_nation_officer_title_all(COUNTRY_D->get_country(n_id,"level"));
	list_char=CHAR_D->check_char("nation",n_id);
	for(i=0;i<sizeof(list_title);++i)
	{
		mess_tmp=OFFICER_D->query_rank_name(list_title[i])+"：";
		a_tmp=filter_array(list_char,
			(:CHAR_D->get_char($1,"ranknation")==$(list_title[i]):));
		for(j=0;j<sizeof(a_tmp);++j)
		{
			mess_tmp+=CHAR_D->get_char(a_tmp[j],"name");
			mess_tmp+=" ";
		}
		v_left=OFFICER_D->query_max_officer_number(list_title[i]);
		v_left-=sizeof(a_tmp);
		for(j=0;j<v_left;++j)
		{
			mess_tmp+="━━ ";
		}
		mess_tmp+="\n";
		mess+=mess_tmp;
	}
	mess+="地方官员：\n";
	a_tmp=filter_array(list_char,
		(:CHAR_D->get_char($1,"ranknation")==0:));
// sort_array(a_tmp,(:OFFICER_D->query_level(CHAR_D->get_char($1,"ranklocal")):);
	for(i=0;i<sizeof(a_tmp);++i)
		mess+=sprintf("%s ",CHAR_D->get_char(a_tmp[i],"name"));
	mess+="\n";
	more(mess);
}
void infoc(string c_id)
{
	string mess="";
	string mess_tmp;
	mixed p_tmp;
	string *list;
	string s_tmp;
	array a_tmp;
	int s_wuli,s_zhimou,s_meili;
       if(c_id=="me")
          c_id=this_body()->query_id()[0];
	if(!(CHAR_D->char_exist(c_id)))
	{
		mess="该角色不存在，用listchar列出角色清单．\n";
		write(mess);
		return;
	}
	mess_tmp=sprintf("角色代号：%12s    名称：%s\n",c_id,CHAR_D->get_char(c_id,"name"));
	mess+=mess_tmp;
	mess+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	p_tmp=CHAR_D->get_char(c_id,"skills");
	s_wuli=p_tmp["sk_wuli"];
	s_zhimou=p_tmp["sk_zhimou"];
	s_meili=p_tmp["sk_meili"];
	p_tmp=CHAR_D->get_char(c_id,"gift");
	
	mess_tmp=sprintf("字：%4s  性别：%2s  年龄：%3d 容貌：%d\n",
		CHAR_D->get_char(c_id,"zi"),
		(CHAR_D->get_char(c_id,"gender")==1 ? "男" :"女"),
		CHAR_D->get_char(c_id,"age"),p_tmp["rongmao"]);
	mess+=mess_tmp;
	mess_tmp=sprintf("武力：%3d 智谋：%3d 魅力：%3d 类型：%s \n",
		s_wuli,s_zhimou,s_meili,
		(CHAR_D->get_char(c_id,"type")==TYPE_NPC ? "NPC" :"PLY"));
	mess+=mess_tmp;
	mess_tmp=sprintf("所属国：%6s  所在地：%6s  忠诚：%d\n",
		COUNTRY_D->get_country(CHAR_D->get_char(c_id,"nation"),"name"),
		AREA_D->get_area(CHAR_D->get_char(c_id,"area"),"name"),
		CHAR_D->get_char(c_id,"loyalty"));
	mess+=mess_tmp;
	mess_tmp=sprintf("朝廷官职：%8s  地方官职：%6s%s\n",
		OFFICER_D->query_rank_name(CHAR_D->get_char(c_id,"ranknation")),
		AREA_D->get_area(CHAR_D->get_char(c_id,"area"),"name"),
		OFFICER_D->query_rank_name(CHAR_D->get_char(c_id,"ranklocal")));
	mess+=mess_tmp;
	mess_tmp=sprintf("俸禄：%6d    声望：%8s(%d)\n",
		CHAR_D->get_char(c_id,"salary"),
		CHAR_D->get_char(c_id,"reputationstr"),
		CHAR_D->get_char(c_id,"reputation"));
	mess+=mess_tmp;
	mess_tmp=sprintf("状态：%s\n",(CHAR_D->get_char(c_id,"statustr")));
	mess+=mess_tmp;
	mess_tmp=sprintf("与他国关系：\n");
	mess+=mess_tmp;
	list=COUNTRY_D->list_countries();
	s_tmp=CHAR_D->get_char(c_id,"nation");
	list=filter_array(list,(:$1!=$(s_tmp):));
	a_tmp=({});
	foreach(string n_id in list)
	{
		s_tmp=sprintf("%6s：%3d ",
			COUNTRY_D->get_country(n_id,"name"),
			CHAR_D->get_char_loyalty(c_id,n_id));
		a_tmp+=({s_tmp});
	}
	mess_tmp=sprintf("%-#50s\n",implode(a_tmp,"\n"));
	mess+=mess_tmp;
	mess_tmp=sprintf("特殊技能：\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("宝物：\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("武器：\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("服装：\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("座骑：\n");
	mess+=mess_tmp;
	more(mess);
}
private void main(string arg)
{
	string p_type,p_name;
	int p_c=1;
	if(!arg)
		arg="";
    if(sscanf(arg, "%s %s", p_type,p_name)!=2)
	{
		p_c=0; // doesn't use propoly
	}
	if ((p_type!="n")&&(p_type!="c")&&(p_type!="a"))
	{
		p_c=0;
	}
	if(!p_c)
	{
		write("用法：	info n <country_id> 查阅某一国家信息\n"+
			"	info c <char_id> 查阅某一角色信息\n"+
			"	info a <area_id> 查阅某一地区信息\n"+
			"例子：  info c lv bu \n"+
			"	将列出有关吕布的一些信息．\n"+
			"参考：	可用listcountry, listchar 和 listarea 列出\n"+
			"	国家，角色和地区清单．\n");
		return;
	}
	switch(p_type)
	{
	case "a":
		infoa(p_name);
		return;
	case "c":
		infoc(p_name);
		return;
	case "n":
		infon(p_name);
		return;
	}
}
